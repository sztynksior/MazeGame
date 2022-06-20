#ifndef MAZEELEMENT_H
#define MAZEELEMENT_H


#include "Player.h"
#include <SFML/Graphics.hpp>

class MazeElement : sf::Drawable
{
protected:

	sf::Sprite sprite;

public:

	MazeElement();
	MazeElement(sf::Texture& pTexture);

	void draw(sf::RenderTarget& pTarget, sf::RenderStates pStates) const override;
	void setPosition(sf::Vector2f pPositon);
	sf::Vector2u getSpriteSize();
	sf::Vector2f getSpritePosition();
	virtual MazeElement* copy() = 0;
	virtual std::string onCollision() = 0; // TO DO: ZMIENIÆ!!!!

};

#endif // !MAZEELEMENT_H