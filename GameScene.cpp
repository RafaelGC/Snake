/* 
 * File:   GameScene.cpp
 * Author: Rafa
 * 
 * Created on 23 de diciembre de 2015, 23:54
 */

#include "GameScene.hpp"
#include "ESE/Core/Scene.hpp"
#include "Head.hpp"
#include "Coin.hpp"
#include "ESE/Core/ResourceManager.hpp"
#include "GameConfig.hpp"

GameScene::GameScene(sf::RenderWindow *window, int width, int height, GameConfig config) : ESE::Scene("GameScene",window),
        board(width,height,window->getSize().x/width,window->getSize().y/height)
{
    head = new Head(board,config,this);
    board.addTile(5,5,head);
    
    scoreText.setFont(*ESE::ResourceManager::instance()->fonts()->getResource("font"));
    scoreText.setColor(sf::Color::White);
    scoreText.setCharacterSize(20);
    scoreText.setPosition(10,10);
    scoreText.setString("0");
    
    setup();
}

GameScene::~GameScene() {
}

void GameScene::render() {
    window->clear(sf::Color(100,100,100));
    draw(board);
    draw(scoreText);
}
void GameScene::logic(float deltaTime) {    
    board.advanceTime(deltaTime);
    
    multiplier-=deltaTime;
    
    if (currVisibleScore<score) {
        currVisibleScore+=2000.f*deltaTime;
        updateScore();
    }
    
}
void GameScene::manageEvents(float deltaTime) {
    while (window->pollEvent(events)) {
        
        this->checkIfWindowClosed();
        
        if (events.type==sf::Event::KeyPressed) {
            
            switch (events.key.code) {
                
                case sf::Keyboard::Up:
                    head->go(Head::UP);
                    break;
                case sf::Keyboard::Down:
                    head->go(Head::DOWN);
                    break;
                case sf::Keyboard::Left:
                    head->go(Head::LEFT);
                    break;
                case sf::Keyboard::Right:
                    head->go(Head::RIGHT);
                    break;
                case sf::Keyboard::C:
                    addRandomCoin();
                    break;
                case sf::Keyboard::Escape:
                    ESE::SceneManager::instance()->activateSceneAndDeactivateTheRest("MenuScene");
            }
            
        }
        
    }
    
    
}

void GameScene::addRandomCoin() {
    
    Coin *coin = new Coin();
    sf::Vector2i pos = board.getFreeTile();
    if (pos.x>=0) {
        board.addTile(pos.x,pos.y,coin);
        
    }
}

void GameScene::powerUpTaken() {
    addRandomCoin();
    score+=std::max(1.f,multiplier*1000.f);
    multiplier = 4.f;
    updateScore();
}

void GameScene::dead() {
    setup();
}

void GameScene::updateScore() {
    scoreText.setString(std::to_string((int)currVisibleScore));
}

void GameScene::setup() {
    score = 0;
    currVisibleScore = 0;
    updateScore();
    
    board.clean(head); //Limpiar tablero.
    
    board.moveTile(head,board.getCols()/2,board.getRows()/2); //Centrar cabeza
    
    addRandomCoin();
    head->setBodyLifeExpectancy(0.5f);
    head->resetMovement(Head::RIGHT);
    
    multiplier = 4;
}