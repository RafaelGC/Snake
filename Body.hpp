/* 
 * File:   Body.hpp
 * Author: Rafa
 *
 * Created on 25 de diciembre de 2015, 17:22
 */

#ifndef BODY_HPP
#define	BODY_HPP

#include "Tile.hpp"
#include "GameConfig.hpp"

class GameBoard;

class Body : public Tile {
public:
    Body(GameBoard & gameBoard, float lifeExpectancy, GameConfig::Skin skin);
    virtual ~Body();
    void advanceTime(float deltaTime);
    Type getType() {return BODY;}
private:
    GameBoard *gameBoard;
    sf::Clock deadClock, changeColor;
    float life, lifeExpectancy;
    GameConfig::Skin skin;
};

#endif	/* BODY_HPP */

