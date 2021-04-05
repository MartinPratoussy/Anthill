/*****************************************************************//**
 * \file   .cpp
 * \brief  
 * 
 * \author Martin
 * \date   April 2021
 *********************************************************************/

#include "garden.h"

void Garden::InitiateAnthills()
{
	for (int i = 0; i < this->nbAnthills; i++) {
		anthills.push_back(new Anthill(new Coord(rand() % 100, rand() % 100)));
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

void Garden::InitiateWindow()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow(this->name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);

	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
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

void Garden::DropTheCrumbs()
{
	while (true) {
		InitiateWindow();
		SDL_Delay(3000);

		/* Graphical simulation to come */
	}
}
