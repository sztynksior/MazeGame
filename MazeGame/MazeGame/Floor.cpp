#include "Floor.h"

Floor::Floor(const Floor& pFloor)
{
	this->sprite = pFloor.sprite;
}

Floor::Floor(sf::Texture& pTexture)
	: MazeElement(pTexture)
{
}

void Floor::onCollision()
{
	//TO DO: napisæ funkcje
}

MazeElement* Floor::copy()
{
	return new Floor(*this);
}
