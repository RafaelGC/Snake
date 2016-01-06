/* 
 * File:   Tile.cpp
 * Author: Rafa
 * 
 * Created on 24 de diciembre de 2015, 16:29
 */

#include "Tile.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
Tile::Tile() {
    rectangle.setFillColor(sf::Color::Red);
}

Tile::~Tile() {
}

void Tile::draw(sf::RenderTarget & target, sf::RenderStates states) const{
    target.draw(rectangle,states.transform*getTransform());
}

void Tile::setDimensions(int width, int height) {
    rectangle.setSize(sf::Vector2f(width,height));
}

void Tile::setColor(const sf::Color& color) {
    rectangle.setFillColor(color);
}