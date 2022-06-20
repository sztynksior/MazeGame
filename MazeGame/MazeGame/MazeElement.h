#ifndef MAZEELEMENT_H
#define MAZEELEMENT_H

#include "TextureMenager.h"
#include <SFML/Graphics.hpp>

class MazeElement : sf::Drawable
{
protected:

	sf::Sprite sprite;

public:

	MazeElement();
	MazeElement(TextureMenager& pTextureMenager, const std::string& pTextureName, sf::Vector2f pPosition);

	void draw(sf::RenderTarget& pTarget, sf::RenderStates pStates) const override;
	void setPosition(sf::Vector2f pPositon);
	sf::Vector2u getSpriteSize();
	virtual MazeElement* copy() = 0;
	virtual void onCollision() = 0;

};

#endif // !MAZEELEMENT_H