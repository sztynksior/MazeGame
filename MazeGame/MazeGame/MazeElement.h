#ifndef MAZEELEMENT_H
#define MAZEELEMENT_H

#include "TextureMenager.h"
#include <SFML/Graphics.hpp>

class MazeElement : sf::Drawable
{
protected:

	sf::Vector2f position;
	sf::Sprite sprite;

public:

	MazeElement(TextureMenager& pTextureMenager, const std::string& pTextureName, sf::Vector2f pPosition);

	void draw(sf::RenderTarget& pTarget);
	void setPosition(sf::Vector2f pPositon);
	virtual void onCollision() = 0;
};

#endif // !MAZEELEMENT_H