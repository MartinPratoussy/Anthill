#pragma once

#include <cstdlib>
#include "food.h"

class Coord
{
private:
	int X;
	int Y;
	Food* food;
	bool isFoodPresent = false;

public:
	Coord(int X, int Y);

	int GetX();
	int GetY();
	bool IsFoodPresent();
};

