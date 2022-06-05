#ifndef MAZECELL_H
#define MAZECELL_H

#include "Neighbour.h"
#include <vector>
#include <utility>
#include <unordered_map>

class MazeCell
{
private:

	std::pair<int, int> coordinates;
	bool isVisited;
	std::unordered_map<std::string, Neighbour*> posibleNeighbours;
	std::vector<Neighbour*> neighbours;

public:

	MazeCell(const std::pair<int, int> pCoordinates);
	~MazeCell();

	virtual std::pair<int, int> getCoordinates() = 0;
	virtual void wasVisited() = 0;
	virtual bool whetherItWasVisited() = 0;
	virtual int numberOfNeigbours() = 0;
	virtual Neighbour* getNeigbourFromTable(const int pIterator) = 0;
	virtual void addNeighbour(std::string pNeighbourType) = 0;

	//TO DO: rozdziel klase MazeCell na:
	//1. MazeCell klase szablonowa
	//2. SquareMazeCell klasa dziedzicz¹ca
	//Pozwoli to w przysz³oœci na dodawanie klas MazeCell o ró¿nych kszta³tach
	//np: TriangularMazeCell, PentagonalMazeCell itd.

};

#endif // !MAZECELL_H

