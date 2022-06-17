#include "Floor.h"

Floor::Floor(TextureMenager& pTextureMenager, const std::string& pTextureName, sf::Vector2f pPosition)
	: MazeElement(pTextureMenager, pTextureName, pPosition)
{
}

void Floor::onCollision()
{
	//TO DO: napisæ funkcje
}
