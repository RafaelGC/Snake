/* 
 * File:   Head.hpp
 * Author: Rafa
 *
 * Created on 24 de diciembre de 2015, 17:43
 */

#ifndef HEAD_HPP
#define	HEAD_HPP

#include "Tile.hpp"
#include "GameConfig.hpp"
#include <SFML/System/Clock.hpp>
#include <queue>

class GameBoard;
class HeadListener;

class Head : public Tile{
public:
    enum Direction {UP, DOWN, LEFT, RIGHT};
    
    Head(GameBoard & gameBoard, GameConfig gameConfig, HeadListener * headListener = nullptr);
    virtual ~Head();
    
    void go(Direction direction);
    void resetMovement(Direction direction);
    void setBodyLifeExpectancy(float expectancy) { this->bodyLifeExpectancy = expectancy; }
    
    void advanceTime(float deltaTime);
    Type getType() {return HEAD;}
private:
    sf::Clock movementClock;
    Direction direction;
    GameBoard* gameBoard;
    std::queue<Direction> movements;
    float bodyLifeExpectancy, speed;
    HeadListener *headListener;
    GameConfig::Skin skin;
};

#endif	/* HEAD_HPP */

