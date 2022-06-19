#include "Wall.h"

Wall::Wall(const Wall& pWall)
{
	this->position = pWall.position;
	this->sprite = pWall.sprite;
}

Wall::Wall(TextureMenager& pTextureMenager, const std::string& pTextureName, sf::Vector2f pPosition)
	: MazeElement(pTextureMenager, pTextureName, pPosition)
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
