/* 
 * File:   Body.cpp
 * Author: Rafa
 * 
 * Created on 25 de diciembre de 2015, 17:22
 */

#include <SFML/System/Clock.hpp>

#include "Body.hpp"
#include "GameBoard.hpp"

Body::Body(GameBoard & gameBoard, float lifeExpectancy, GameConfig::Skin skin) : gameBoard(&gameBoard), skin(skin) {
    
    if (skin==GameConfig::STANDARD) {
        setColor(sf::Color(0,180,0));
    }
    else {
        setColor(sf::Color(rand()%256,rand()%256,rand()%256));
    }
    
    life = 0.f;
    this->lifeExpectancy = lifeExpectancy;
}

Body::~Body() {
}

void Body::advanceTime(float deltaTime) {
    
    if (deadClock.getElapsedTime().asSeconds()>lifeExpectancy) {
        gameBoard->deleteTile(this);
        return;
    }
    
    life+=deltaTime;
    
    if (skin==GameConfig::EPILEPTIC) {
        if (changeColor.getElapsedTime().asMilliseconds()>100) {
            setColor(sf::Color(rand()%256,rand()%256,rand()%256));
            changeColor.restart();
        }
    }
    
}
