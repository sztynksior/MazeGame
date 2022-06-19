#ifndef DOOR_H
#define DOOR_H

#include "MazeElement.h"

class Door : public MazeElement
{
private:

	Door(const Door& pDoor);

public:

	Door(TextureMenager& pTextureMenager, const std::string& pTextureName, sf::Vector2f pPosition);
	void onCollision();
	MazeElement* copy() override;
};

#endif // !DOOR_H