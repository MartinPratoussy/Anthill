/*****************************************************************//**
 * \file   coord.cpp
 * \brief  
 * 
 * \author Martin
 * \date   April 2021
 *********************************************************************/

#include "coord.h"

Coord::Coord(int X, int Y)
{
	this->X = X;
	this->Y = Y;
	this->food = (rand() % 10 == 1) ? new Food() : nullptr;
	if (this->food) this->isFoodPresent = true;
}

int Coord::GetX()
{
	return this->X;
}

int Coord::GetY()
{
	return this->Y;
}

bool Coord::IsFoodPresent()
{
	return this->isFoodPresent;
}
