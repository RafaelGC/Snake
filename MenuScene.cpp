/* 
 * File:   MenuScene.cpp
 * Author: Rafa
 * 
 * Created on 30 de diciembre de 2015, 2:02
 */

#include "MenuScene.hpp"
#include "ESE/Core/ResourceManager.hpp"
#include "GameScene.hpp"
#include "GameConfig.hpp"

MenuScene::MenuScene(sf::RenderWindow * window) : ESE::Scene("MenuScene", window){
    gameScene = nullptr;
    GameConfig::Difficulty d = GameConfig::EASY;
    difficulties[(GameConfig::Difficulty) GameConfig::EASY] = "Easy >";
    difficulties[(GameConfig::Difficulty) GameConfig::NORMAL] = "< Normal >";
    difficulties[(GameConfig::Difficulty) GameConfig::HARD] = "< Hard >";
    difficulties[(GameConfig::Difficulty) GameConfig::PSYCHOPATH] = "< Psychopath";
    
    skins[(GameConfig::Skin) GameConfig::STANDARD] = "Normal >";
    skins[(GameConfig::Skin) GameConfig::RANDOM] = "< Random colors >";
    skins[(GameConfig::Skin) GameConfig::EPILEPTIC] = "< Epileptic";
    
    currDifficulty = GameConfig::EASY;
    currSkin = GameConfig::STANDARD;
    
    title.setFont(*ESE::ResourceManager::instance()->fonts()->getResource("font"));
    title.setCharacterSize(42);
    title.setString("Snake");
    title.setPosition(window->getSize().x/2-title.getGlobalBounds().width/2,
                      100);
    
    difficulty.setFont(*ESE::ResourceManager::instance()->fonts()->getResource("font"));
    difficulty.setCharacterSize(24);
    
    skin.setFont(*ESE::ResourceManager::instance()->fonts()->getResource("font"));
    skin.setCharacterSize(24);
    
    updateTextDifficulty();
    updateTextSkin();
    
    setSelectionMode(DIFFICULTY);
    
}

MenuScene::~MenuScene() {
    delete gameScene;
}

void MenuScene::onActivate() {
    ESE::Scene::onActivate();
}

void MenuScene::logic(float deltaTime) {
    
}

void MenuScene::manageEvents(float deltaTime) {
    while (window->pollEvent(events)) {
        checkIfWindowClosed();
        
        if (events.type==sf::Event::KeyPressed) {
            
            switch (events.key.code) {
                case sf::Keyboard::Left:
                    
                    if (selectionMode==DIFFICULTY) {
                        previousDifficulty();
                    }
                    else {
                        previousSkin();
                    }
                    break;
                case sf::Keyboard::Right:
                    if (selectionMode==DIFFICULTY) {
                        nextDifficulty();
                    }
                    else {
                        nextSkin();
                    }
                    break;
                case sf::Keyboard::Up:
                    setSelectionMode(DIFFICULTY);
                    break;
                case sf::Keyboard::Down:
                    setSelectionMode(SKIN);
                    
                    break;
                case sf::Keyboard::Return:
                    ESE::SceneManager::instance()->removeScene("GameScene");
                    delete gameScene; //Se elimina la instancia anterior.
                    
                    GameConfig config(currDifficulty,currSkin);
                    
                    gameScene = new GameScene(window,25,25,config);
                    
                    
                    ESE::SceneManager::instance()->addScene(*gameScene);
                    ESE::SceneManager::instance()->activateSceneAndDeactivateTheRest("GameScene");
                    break;
            }
            
        }
    }
}

void MenuScene::render() {
    draw(title);
    draw(difficulty);
    draw(skin);
}

void MenuScene::nextDifficulty() {
    if (currDifficulty<GameConfig::getMaxDifficulty()) {
        currDifficulty++;
    }
    
    updateTextDifficulty();
}

void MenuScene::previousDifficulty() {
    
    if (currDifficulty>GameConfig::getMinDifficulty()) {
        currDifficulty--;
    }
    
    updateTextDifficulty();
}

void MenuScene::nextSkin() {
    
    if (currSkin<GameConfig::getMaxSkin()) {
        currSkin++;
    }
    
    updateTextSkin();
}

void MenuScene::previousSkin() {
    
    if (currSkin>GameConfig::getMinSkin()) {
        currSkin--;
    }
    
    updateTextSkin();
}

void MenuScene::updateTextDifficulty() {
    difficulty.setString(difficulties[currDifficulty]);
    difficulty.setPosition(window->getSize().x/2-difficulty.getGlobalBounds().width/2,250);
}

void MenuScene::updateTextSkin() {
    skin.setString(skins[currSkin]);
    skin.setPosition(window->getSize().x/2-skin.getGlobalBounds().width/2,350);
}

void MenuScene::setSelectionMode(SelectionMode selectionMode) {
    this->selectionMode = selectionMode;
    
    if (selectionMode==DIFFICULTY) {
        difficulty.setColor(sf::Color::Red);
        skin.setColor(sf::Color::White);
    }
    else {
        difficulty.setColor(sf::Color::White);
        skin.setColor(sf::Color::Red);
    }
}
