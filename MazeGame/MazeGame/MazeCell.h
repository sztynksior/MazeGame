#ifndef MAZECELL_H
#define MAZECELL_H

#include <vector>
#include <utility>

enum class fromWhichSide { Top, Right, Bottom, Left };

class MazeCell
{
private:

	std::pair<int, int> coordinates;
	bool isVisited;
	std::vector<fromWhichSide> neighbours;

public:

	MazeCell(const std::pair<int, int> pCoordinates);
	~MazeCell();

	std::pair<int, int> getCoordinates();
	void wasVisited();
	bool whetherItWasVisited();
	int numberOfNeigbours();
	fromWhichSide getNeigbourFromVector(const int pIterator);
	void addNeighbour(fromWhichSide pFromWhichSide);

	//TO DO: rozdziel klase MazeCell na:
	//1. MazeCell klase szablonowa
	//2. SquareMazeCell klasa dziedzicz¹ca
	//Pozwoli to w przysz³oœci na dodawanie klas MazeCell o ró¿nych kszta³tach
	//np: TriangularMazeCell, PentagonalMazeCell itd.

};

#endif // !MAZECELL_H

