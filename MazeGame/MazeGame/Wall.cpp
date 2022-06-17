#include "Wall.h"

Wall::Wall(TextureMenager& pTextureMenager, const std::string& pTextureName, sf::Vector2f pPosition)
	: MazeElement(pTextureMenager, pTextureName, pPosition)
{
}

void Wall::onCollision()
{
	//TO DO: napisæ funkcje
}
