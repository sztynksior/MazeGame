#include "Door.h"

Door::Door(const Door& pDoor)
{
	this->position = pDoor.position;
	this->sprite = pDoor.sprite;
}

Door::Door(TextureMenager& pTextureMenager, const std::string& pTextureName, sf::Vector2f pPosition)
	: MazeElement(pTextureMenager, pTextureName, pPosition)
{
}

void Door::onCollision()
{
	return new Door(*this);
}

MazeElement* Door::copy()
{
	return new Door(*this);
}
