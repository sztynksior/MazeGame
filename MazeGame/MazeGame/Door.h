#ifndef DOOR_H
#define DOOR_H

#include "MazeElement.h"

class Door : public MazeElement
{
private:

	Door(const Door& pDoor);

public:

	Door(sf::Texture& pTexture);
	std::string onCollision();
	MazeElement* copy() override;
};

#endif // !DOOR_H