/* 
 * File:   GameBoard.hpp
 * Author: Rafa
 *
 * Created on 24 de diciembre de 2015, 0:03
 */

#ifndef GAMEBOARD_HPP
#define	GAMEBOARD_HPP

#include <SFML/Graphics/Drawable.hpp>
#include "Tile.hpp"
#include <ESE/Core/Animatable.hpp>

class GameBoard : public sf::Drawable, public ESE::Animatable{
public:
    GameBoard(int cols, int rows, int tileW, int tileH);
    virtual ~GameBoard();
    
    virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
    
    void addTile(int col, int row, Tile *tile);
    void moveTile(Tile*tile, int col, int row);
    void deleteTile(Tile*tile);
    
    const sf::Vector2i tilePos(Tile*tile) const;
    Tile* tileAt(int col, int row);
    Tile const * tileAt(int col, int row) const;
    
    void advanceTime(float deltaTime);
    
    int countFreeTiles() const;
    int getCols() const;
    int getRows() const;
    
    sf::Vector2i getFreeTile() const;
    
    void clean(Tile *head = nullptr);
    
private:
    int cols, rows;
    int tileW, tileH;
    std::vector<std::vector<Tile*>> tiles;
};

#endif	/* GAMEBOARD_HPP */

