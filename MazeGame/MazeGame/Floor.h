#pragma once
#include "MazeElement.h"

class Floor : public MazeElement
{
public:
	Floor(TextureMenager& pTextureMenager, const std::string& pTextureName, sf::Vector2f pPosition);
	void onCollision();
};

