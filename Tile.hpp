/* 
 * File:   Tile.hpp
 * Author: Rafa
 *
 * Created on 24 de diciembre de 2015, 16:29
 */

#ifndef TILE_HPP
#define	TILE_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <ESE/Core/Animatable.hpp>

class Tile : public sf::Drawable, public sf::Transformable, public ESE::Animatable{
protected:
    sf::RectangleShape rectangle;
public:
    enum Type {HEAD, BODY, POWERUP};
    Tile();
    virtual ~Tile();
    
    virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
    virtual void setDimensions(int width, int height);
    virtual void setColor(const sf::Color & color);
    virtual Type getType() = 0;
private:

};

#endif	/* TILE_HPP */

