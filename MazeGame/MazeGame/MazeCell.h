#ifndef MAZECELL_H
#define MAZECELL_H

#include <vector>
#include <utility>
#include <unordered_map>

class MazeCell
{
protected:

	std::pair<int, int> coordinates;
	bool isVisited;
	std::vector<std::pair<int, int>> neighbours;

public:

	MazeCell(const std::pair<int, int> pCoordinates);
	~MazeCell();

	virtual std::pair<int, int> getCoordinates() = 0;
	virtual void wasVisited() = 0;
	virtual bool whetherItWasVisited() = 0;
	virtual int numberOfNeigbours() = 0;
	virtual std::pair<int, int> getNeigbourFromTable(const int pIterator) = 0;
	virtual void addNeighbour(std::pair<int, int> pNeighbourVector) = 0;
};

#endif // !MAZECELL_H

