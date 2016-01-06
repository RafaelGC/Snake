/* 
 * File:   MenuScene.hpp
 * Author: Rafa
 *
 * Created on 30 de diciembre de 2015, 2:02
 */

#ifndef MENUSCENE_HPP
#define	MENUSCENE_HPP

#include <ESE/Core/Scene.hpp>

#include "GameConfig.hpp"
#include <map>

class GameScene;

class MenuScene : public ESE::Scene{
public:
    MenuScene(sf::RenderWindow * window);
    virtual ~MenuScene();
    
    void logic(float deltaTime);
    void manageEvents(float deltaTime);
    void render();
    
protected:
    void onActivate();   
    
private:
    enum SelectionMode {DIFFICULTY, SKIN};
    SelectionMode selectionMode;
    
    sf::Text title, pressEnter, difficulty, skin;
    std::map<GameConfig::Difficulty,std::string> difficulties;
    std::map<GameConfig::Skin, std::string> skins;
    GameConfig::Difficulty currDifficulty;
    GameConfig::Skin currSkin;
    
    GameScene *gameScene;
    
    void setSelectionMode(SelectionMode);
    
    void nextDifficulty();
    void previousDifficulty();
    
    void nextSkin();
    void previousSkin();
    
    void updateTextDifficulty();
    void updateTextSkin();
    
};

#endif	/* MENUSCENE_HPP */

