#ifndef WALL_H
#define WALL_H

#include "MazeElement.h"
class Wall : public MazeElement
{
private:

	Wall(const Wall& pWall);

public:

	Wall(TextureMenager& pTextureMenager, const std::string& pTextureName, sf::Vector2f pPosition);
	void onCollision();
	MazeElement* copy() override;
};

#endif WALL_H