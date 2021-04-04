#include "anthill.h"

Anthill::Anthill(Coord* location)
{
	this->location = location;
}

Coord* Anthill::GetLocation()
{
	return this->location;
}

void Anthill::AddFoodToReserve(Food* food)
{
	this->reserve->push_back(food);
}
