#include "Floor.h"

Floor::Floor(const Floor& pFloor)
{
	this->position = pFloor.position;
	this->sprite = pFloor.sprite;
}

Floor::Floor(TextureMenager& pTextureMenager, const std::string& pTextureName, sf::Vector2f pPosition)
	: MazeElement(pTextureMenager, pTextureName, pPosition)
{
}

void Floor::onCollision()
{
	//TO DO: napisæ funkcje
}

MazeElement* Floor::copy()
{
	return new Floor(*this);
}
