#include "Door.h"

Door::Door(const Door& pDoor)
{
	this->sprite = pDoor.sprite;
}

Door::Door(sf::Texture& pTexture)
	: MazeElement(pTexture)
{
}

void Door::onCollision()
{
	//TO DO: napisæ funkcje
}

MazeElement* Door::copy()
{
	return new Door(*this);
}
