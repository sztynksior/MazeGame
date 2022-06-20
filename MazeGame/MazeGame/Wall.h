#ifndef WALL_H
#define WALL_H

#include "MazeElement.h"
class Wall : public MazeElement
{
private:

	Wall(const Wall& pWall);

public:

	Wall(sf::Texture& pTexture);
	void onCollision();
	MazeElement* copy() override;
};

#endif WALL_H