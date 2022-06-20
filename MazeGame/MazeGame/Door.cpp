#include "Door.h"

Door::Door(const Door& pDoor)
{
	this->sprite = pDoor.sprite;
}

Door::Door(TextureMenager& pTextureMenager, const std::string& pTextureName, sf::Vector2f pPosition)
	: MazeElement(pTextureMenager, pTextureName, pPosition)
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
