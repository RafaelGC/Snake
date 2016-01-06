/* 
 * File:   Coin.hpp
 * Author: Rafa
 *
 * Created on 25 de diciembre de 2015, 18:29
 */

#ifndef COIN_HPP
#define	COIN_HPP

#include "Tile.hpp"

class Coin : public Tile {
public:
    Coin();
    virtual ~Coin();
    
    Type getType();
    void advanceTime(float deltaTime) {}
private:

};

#endif	/* COIN_HPP */

