#include "MazeElement.h"

MazeElement::MazeElement(TextureMenager& pTextureMenager, const std::string& pTextureName, sf::Vector2f pPosition)
{
	this->position = pPosition;
	this->sprite.setTexture(pTextureMenager.getTextureWithGivenName(pTextureName));
}

void MazeElement::draw(sf::RenderTarget& pTarget)
{
	pTarget.draw(this->sprite);
}

void MazeElement::setPosition(sf::Vector2f pPositon)
{
	this->position = pPositon;
}
