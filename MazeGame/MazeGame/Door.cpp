#include "Door.h"

Door::Door(const Door& pDoor)
{
	this->sprite = pDoor.sprite;
}

Door::Door(sf::Texture& pTexture) : MazeElement(pTexture)
{
}

std::string Door::onCollision()
{
	return "door";
}

MazeElement* Door::copy()
{
	return new Door(*this);
}
