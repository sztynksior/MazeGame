#ifndef FLOOR_H
#define FLOOR_H

#include "MazeElement.h"

class Floor : public MazeElement
{
private:

	Floor(const Floor& pFloor);

public:

	Floor(TextureMenager& pTextureMenager, const std::string& pTextureName, sf::Vector2f pPosition);
	void onCollision();
	MazeElement* copy() override;
};

#endif FLOOR_H