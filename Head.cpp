/* 
 * File:   Head.cpp
 * Author: Rafa
 * 
 * Created on 24 de diciembre de 2015, 17:43
 */
#include <iostream>
#include <queue>
#include "Head.hpp"
#include "ESE/Core/Animatable.hpp"
#include "GameBoard.hpp"
#include "Body.hpp"
#include "HeadListener.hpp"
#include "GameConfig.hpp"

Head::Head(GameBoard &gameBoard, GameConfig gameConfig, HeadListener *headListener) : headListener(headListener){
    this->gameBoard = &gameBoard;
    
    switch (gameConfig.getDifficulty()) {
        case GameConfig::EASY:
            speed = 0.1;
            break;
        case GameConfig::NORMAL:
            speed = 0.05;
            break;
        case GameConfig::HARD:
            speed = 0.03;
            break;
        case GameConfig::PSYCHOPATH:
            speed = 0.02;
            break;
    }
    
    skin = gameConfig.getSkin();
    
    go(DOWN);
    
    setColor(sf::Color::Green);
    
    bodyLifeExpectancy = 0.5f;
}

Head::~Head() {
}

void Head::go(Direction direction) {
    if (movements.size()>0) {
        if (movements.back()==direction) return;
        
        if (movements.back()==Direction::DOWN && direction==Direction::UP) return;
        if (movements.back()==Direction::LEFT && direction==Direction::RIGHT) return;
        if (movements.back()==Direction::UP && direction==Direction::DOWN) return;
        if (movements.back()==Direction::RIGHT && direction==Direction::LEFT) return;
        
    }
    movements.push(direction);
    
}

void Head::advanceTime(float deltaTime) {
    if (movementClock.getElapsedTime().asSeconds()>speed) {
        
        direction = movements.front();
        if (movements.size()>1) {
            movements.pop();
        }
        
        sf::Vector2i pos = gameBoard->tilePos(this);
        sf::Vector2i prevPos = pos;
        switch (direction) {
            case UP:
                pos.y--;
                break;
            case DOWN:
                pos.y++;
                break;
            case LEFT:
                pos.x--;
                break;
            case RIGHT:
                pos.x++;
                break;
        }
        
        if (pos.x<0 || pos.x >= gameBoard->getCols() || pos.y < 0 || pos.y >= gameBoard->getRows()) {
            if (headListener) headListener->dead();
            return;
        }
        
        Tile *currentTile = gameBoard->tileAt(pos.x,pos.y);
        if (currentTile) {
            switch (currentTile->getType()) {
                case POWERUP:
                    bodyLifeExpectancy+=0.5f;
                    if (headListener) headListener->powerUpTaken();
                    break;
                case BODY:
                    if (headListener) headListener->dead();
                    return;
                    break;
            }
        }
        
        Body * body = new Body(*gameBoard,bodyLifeExpectancy,skin);
        gameBoard->moveTile(this,pos.x,pos.y);
        gameBoard->addTile(prevPos.x,prevPos.y,body);
        
        movementClock.restart();
        
    }
    
}

void Head::resetMovement(Direction direction) {
    while (!movements.empty()) movements.pop();
    
    go(direction);
}