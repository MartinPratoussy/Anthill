/*****************************************************************//**
 * \file   anthill.h
 * \brief  
 * 
 * \author Martin
 * \date   April 2021
 *********************************************************************/

#pragma once

#include <vector>

#include "coord.h"

class Anthill
{
private:
	Coord* location;
	std::vector<Food*>* reserve;

public:
	Anthill(Coord* location);

	Coord* GetLocation();
	void AddFoodToReserve(Food* food);
};

