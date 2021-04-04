#include "garden.h"

void Garden::InitiateAnthills()
{
	for (int i = 0; i < this->nbAnthills; i++) {
		anthills.insert(anthills.end(), new Anthill(new Coord(rand() % 100, rand() % 100)));
	}
}

void Garden::InitiateAnts()
{
	for (int i = 0; i < this->nbAnthills; i++) {
		for (int j = 0; j < rand() % 1000; j++) {
			colony.push_back(new Ant(anthills.at(i)));
		}
	}
}

void Garden::InitiateFood()
{
}

Garden::Garden(const char* name, int nbAnthills)
{
	this->name = name;
	this->nbAnthills = nbAnthills;
}

void Garden::InitiateGarden()
{
	InitiateAnthills();
	InitiateAnts();
	InitiateFood();	
}