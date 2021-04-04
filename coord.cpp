#include "coord.h"

Coord::Coord(int X, int Y)
{
	this->X = X;
	this->Y = Y;
}

int Coord::GetX()
{
	return this->X;
}

int Coord::GetY()
{
	return this->Y;
}
