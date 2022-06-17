#pragma once
#include "MazeElement.h"
class Wall : public MazeElement
{
public:
	Wall(TextureMenager& pTextureMenager, const std::string& pTextureName, sf::Vector2f pPosition);
	void onCollision();
};

