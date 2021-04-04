#pragma once

#include <string.h>
#include <stdio.h>

#include "ant.h"

class Garden
{
private:
	const char* name;
	int nbAnthills;
	std::vector<Anthill*> anthills;
	std::vector<Ant*> colony;
	std::vector<Food**> meals;

	void InitiateAnthills();
	void InitiateAnts();
	void InitiateFood();

public:
	Garden(const char* name, int nbAnthills);

	void InitiateGarden();
};

