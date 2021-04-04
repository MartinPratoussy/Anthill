#pragma once

#include "coord.h"

class Anthill
{
private:
	Coord* location;

public:
	Anthill(Coord* location);

	Coord* GetLocation();
};

