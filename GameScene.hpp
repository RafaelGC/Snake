/* 
 * File:   GameScene.hpp
 * Author: Rafa
 *
 * Created on 23 de diciembre de 2015, 23:54
 */

#ifndef GAMESCENE_HPP
#define	GAMESCENE_HPP

#include <ESE/Core/Scene.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "GameBoard.hpp"
#include "GameConfig.hpp"
#include "HeadListener.hpp"

class Head;

class GameScene : public ESE::Scene, public HeadListener {
public:
    GameScene(sf::RenderWindow*window, int width, int height, GameConfig gameConfig);
    virtual ~GameScene();
    
    void render();
    void logic(float deltaTime);
    void manageEvents(float deltaTime);
    
    void addRandomCoin();
    
    void powerUpTaken();
    void dead();
    
    void setup();
    
private:
    GameBoard board;
    Head *head;
    
    sf::Text scoreText;
    float currVisibleScore;
    int score;
    
    float multiplier;
    
    void updateScore();
    
};

#endif	/* GAMESCENE_HPP */

