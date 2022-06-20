#include "Floor.h"

Floor::Floor(const Floor& pFloor)
{
	this->sprite = pFloor.sprite;
}

Floor::Floor(sf::Texture& pTexture) : MazeElement(pTexture)
{
}

std::string Floor::onCollision()
{
	return "floor";
}

MazeElement* Floor::copy()
{
	return new Floor(*this);
}
