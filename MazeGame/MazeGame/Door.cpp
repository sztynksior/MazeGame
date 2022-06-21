#include "Door.h"

Door::Door(const Door& pDoor)
{
	this->sprite = pDoor.sprite;
	this->isFinish = false;
}

Door::Door(sf::Texture& pTexture) : MazeElement(pTexture)
{
}

std::string Door::onCollision()
{
	if (isFinish)
	{
		return "finish";
	}
	else
	{
		return "notPassable";
	}
}

MazeElement* Door::copy()
{
	return new Door(*this);
}
