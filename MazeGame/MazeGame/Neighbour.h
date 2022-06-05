#ifndef NEIGHBOUR_H
#define NEIGHBOUR_H

#include <utility>

class Neighbour
{
	std::pair<int, int> pointingVector;

public:
	Neighbour(std::pair<int, int> pPointingVector);
	~Neighbour();

	virtual  std::pair<int, int> getPointingVector() = 0;
};
#endif // !NEIGHBOUR_H

