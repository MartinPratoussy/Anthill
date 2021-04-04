#pragma once

#include "coord.h"

class Food
{
private:
	Coord location;
	bool isTaken = false;

public:
	bool IsTaken();
};

