#include "SquareMaze.h"

void SquareMaze::createMaze()
{
	this->defaultMazeInicialization();

	this->makingPaths();

	this->setingPositionsOfSprites();
}

void SquareMaze::defaultMazeInicialization()
{
	for (int i = 0; i < (this->maxMazeX * 2) + 1; i++)
	{
		this->mazeLayout.push_back(std::vector<MazeElement*>());

		for (int j = 0; j < (this->maxMazeY * 2) + 1; j++);
		{
			MazeElement* tPointer; //TO DO: zrobi� to eleganciej
			this->mazeLayout[i].push_back(tPointer);
		}
	}

	for (int i = 0; i < this->maxMazeX; i++)
	{
		for (int j = 0; j < this->maxMazeY; j++)
		{
			for (int n = 0; n < 2; n++)
			{
				for (int m = 0; m < 2; m++)
				{
					if (n == 1 and m == 1)
					{
						this->mazeLayout[2 * i + n][2 * j + m] = this->floor->copy();
					}
					else
					{
						this->mazeLayout[2 * i + n][2 * j + m] = this->wall->copy();
					}
				}
			}
		}
	}

	for (int i = 0; i < this->maxMazeX * 2 + 1; i++)
	{
		this->mazeLayout[i][this->maxMazeY * 2] = this->wall->copy();
	}

	for (int i = 0; i < this->maxMazeY * 2 + 1; i++)
	{
		this->mazeLayout[this->maxMazeX * 2][i] = this->wall->copy();
	}

	this->mazeLayout[this->maxMazeX * 2][this->maxMazeY * 2] = this->wall->copy();

	this->mazeLayout[this->maxMazeX][0] = this->door->copy();

	this->mazeLayout[this->maxMazeX][this->maxMazeY * 2] = this->door->copy();
}

void SquareMaze::makingPaths()
{
	for (int i = 0; i < this->maxMazeX; i++)
	{
		for (int j = 0; j < this->maxMazeY; j++)
		{
			for (int n = 0; this->mazePlan->getAccessToCellWithGivenCoordinates({ i , j })->numberOfNeigbours(); n++)
			{
				int tX = 2 * i + this->mazePlan->getAccessToCellWithGivenCoordinates({ i, j })->getNeigbourFromTable(n).first + 1;
				int tY = 2 * j + this->mazePlan->getAccessToCellWithGivenCoordinates({ i, j })->getNeigbourFromTable(n).second + 1;

				delete this->mazeLayout[tX][tY];

				this->mazeLayout[tX][tY] = this->floor->copy();
			}
		}
	}

}

void SquareMaze::setingPositionsOfSprites()
{
	for (int i = 0; i < this->maxMazeX * 2 + 1; i++)
	{
		for (int j = 0; j < this->maxMazeY * 2 + 1; j++)
		{
			this->mazeLayout[i][j]->setPosition({ this->initialPosition.x + ( i * this->spritesSize.x), this->initialPosition.y + (j * this->spritesSize.y) });
		}
	}
}

SquareMaze::SquareMaze(MazeElement* pFloor, MazeElement* pWall, MazeElement* pDoor, sf::Vector2f pInitialPosition, int pMaxMazeX, int pMaxMazeY)
	: Maze(pFloor, pWall, pDoor, pInitialPosition, pMaxMazeX, pMaxMazeY)
{
	this->mazePlan = new SquareMazeGenerator(pMaxMazeX, pMaxMazeY, { (pMaxMazeX / 2) - 1, 0 }, { (pMaxMazeX / 2) - 1, pMaxMazeY - 1 });

	this->createMaze();
}

void SquareMaze::draw(sf::RenderTarget& pTarget, sf::RenderStates pStates) const
{
	for (int i = 0; i < this->maxMazeX * 2 + 1; i++)
	{
		for (int j = 0; j < this->maxMazeY * 2 + 1; j++)
		{
			this->mazeLayout[i][j]->draw(pTarget, pStates);
		}
	}
}
