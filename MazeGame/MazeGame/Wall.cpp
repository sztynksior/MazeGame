#include "Wall.h"

Wall::Wall(const Wall& pWall)
{
	this->sprite = pWall.sprite;
}

Wall::Wall(sf::Texture& pTexture) : MazeElement(pTexture)
{
}

std::string Wall::onCollision()
{
	return "wall";
}

MazeElement* Wall::copy()
{
	return new Wall(*this);
}
