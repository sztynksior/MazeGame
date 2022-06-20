#include "MazeElement.h"

MazeElement::MazeElement(TextureMenager& pTextureMenager, const std::string& pTextureName, sf::Vector2f pPosition)
{
	this->sprite.setTexture(pTextureMenager.getTextureWithGivenName(pTextureName));
	this->sprite.setPosition(pPosition);
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
