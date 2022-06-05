#ifndef SQUAREMAZECELL_H
#define SQUAREMAZECELL_H

#include "MazeCell.h"
#include "SquareNeighbour.h"
#include <utility>
#include <unordered_map>

class SquareMazeCell : public MazeCell
{
private:

	std::pair<int, int> coordinates;
	bool isVisited;
	std::unordered_map<std::string, Neighbour*> posibleNeighbours;
	std::vector<Neighbour*> neighbours;

public:

	SquareMazeCell(const std::pair<int, int> pCoordinates);
	~SquareMazeCell();

	std::pair<int, int> getCoordinates();
	void wasVisited();
	bool whetherItWasVisited();
	int numberOfNeigbours();
	Neighbour* getNeigbourFromTable(const int pIterator);
	void addNeighbour(std::string pNeighbourType);
};

#endif // !SQUAREMAZECELL_H