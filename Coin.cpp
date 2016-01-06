/* 
 * File:   Coin.cpp
 * Author: Rafa
 * 
 * Created on 25 de diciembre de 2015, 18:29
 */

#include "Coin.hpp"
#include "Tile.hpp"

Coin::Coin() {
    setColor(sf::Color::Red);
}


Coin::~Coin() {
}

Tile::Type Coin::getType() {
    return POWERUP;
}
