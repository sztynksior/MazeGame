#include "Door.h"

Door::Door(TextureMenager& pTextureMenager, const std::string& pTextureName, sf::Vector2f pPosition) 
	: MazeElement(pTextureMenager, pTextureName, pPosition)
{
}

void Door::onCollision()
{
	//TO DO: napisæ funkcje
}
