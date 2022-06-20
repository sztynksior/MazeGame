#include "MazeElement.h"

MazeElement::MazeElement(sf::Texture& pTexture)
{
	this->sprite.setTexture(pTexture);
	this->sprite.setPosition({ 0, 0 });
}

void MazeElement::draw(sf::RenderTarget& pTarget, sf::RenderStates pStates) const
{
	pTarget.draw(this->sprite, pStates);
}

void MazeElement::setPosition(sf::Vector2f pPositon)
{
	this->sprite.setPosition(pPositon);
}

sf::Vector2u MazeElement::getSpriteSize()
{
	return this->sprite.getTexture()->getSize();
}
