#include "Wall.h"

Wall::Wall(const Wall& pWall)
{
	this->sprite = pWall.sprite;
}

Wall::Wall(sf::Texture& pTexture) : MazeElement(pTexture)
{
}

void Wall::onCollision()
{
	//TO DO: napisæ funkcje
}

MazeElement* Wall::copy()
{
	return new Wall(*this);
}
