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
	this->reserve->insert(reserve->begin(),food);
}
