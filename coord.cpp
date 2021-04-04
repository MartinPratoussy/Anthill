#include "coord.h"

Coord::Coord(int X, int Y)
{
	this->X = X;
	this->Y = Y;
}

Coord* Coord::GetCoord()
{
	return this;
}
