#ifndef DOOR_H
#define DOOR_H

#include "MazeElement.h"

class Door : public MazeElement
{
public:
	Door(TextureMenager& pTextureMenager, const std::string& pTextureName, sf::Vector2f pPosition);
	void onCollision();
};

#endif // !DOOR_H