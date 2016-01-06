/* 
 * File:   GameBoard.cpp
 * Author: Rafa
 * 
 * Created on 24 de diciembre de 2015, 0:03
 */

#include "GameBoard.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>

GameBoard::GameBoard(int cols, int rows, int tileW, int tileH) :
cols(cols),rows(rows),tileW(tileW),tileH(tileH)
    {
    for (int i = 0; i < rows; ++i) {
        
        //Se construye una nueva fila.
        std::vector<Tile*> row;
        
        for (int j = 0; j < cols; j++) {
            row.push_back(nullptr);
        }
        
        tiles.push_back(row);
    }
}

GameBoard::~GameBoard() {
    clean();
}

void GameBoard::draw(sf::RenderTarget & target, sf::RenderStates states) const {
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            Tile const * tile = this->tileAt(x,y);
            
            if (tile) {
                target.draw(*tile,states);
            }
            
        }
    }
}

void GameBoard::moveTile(Tile* tile, int col, int row) {
    if (tilePos(tile)==sf::Vector2i(col,row)) return;
    
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            if (tiles.at(y).at(x)==tile) {
                tiles.at(y).at(x) = nullptr;
                break;
            }
        }
    }
    addTile(col,row,tile);
}

const sf::Vector2i GameBoard::tilePos(Tile*tile) const {
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            if (tiles.at(y).at(x)==tile) {
                return sf::Vector2i(x,y);
            }
        }
    }
    return sf::Vector2i(-1,-1);
}

void GameBoard::advanceTime(float deltaTime) {
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
           Tile *t = tileAt(x,y);
           if (t) {
               t->advanceTime(deltaTime);
           }
        }
    }
}

Tile* GameBoard::tileAt(int col, int row) {
    return tiles.at(row).at(col);
}

Tile const * GameBoard::tileAt(int col, int row) const {
    return tiles.at(row).at(col);
}

void GameBoard::addTile(int col, int row, Tile* tile) {
    if (col<0 || col>=cols || row<0 || row>=rows) return;
    
    delete tiles.at(row).at(col);
    tiles.at(row).at(col) = tile;
    tile->setPosition((float)col*tileW,(float)row*tileH);
    tile->setDimensions(tileW,tileH);
}

void GameBoard::deleteTile(Tile* tile) {
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            
            if (tiles.at(y).at(x)==tile) {
                delete tile;
                tiles.at(y).at(x) = nullptr;
                break;
            }
            
        }
    }
}

int GameBoard::countFreeTiles() const {
    int counter = 0;
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            if (tileAt(x,y)==nullptr) counter++;
        }
    }
    return counter;
}

int GameBoard::getCols() const {
    return cols;
}

int GameBoard::getRows() const {
    return rows;
}

sf::Vector2i GameBoard::getFreeTile() const {
    
    int free = countFreeTiles();
    if (!free) return sf::Vector2i(-1,-1);
    
    int t = rand()%(free+1);
    int x,y;
    
    for (y = 0; y < rows; ++y) {
        for (x = 0; x < cols; ++x) {
            if (tileAt(x,y)==nullptr) {
                t--;
                if (t==0) {
                    return sf::Vector2i(x,y);
                }
            }
        }
    }
    return sf::Vector2i(-1,-1); //Inalcanzable.
    
    
}

void GameBoard::clean(Tile* head) {
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            if (tileAt(x,y)!=head) {
                delete tiles.at(y).at(x);
                tiles.at(y).at(x) = nullptr;
            }
        }
    }
}