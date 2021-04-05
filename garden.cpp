/*****************************************************************//**
 * \file   .cpp
 * \brief  
 * 
 * \author Martin
 * \date   April 2021
 *********************************************************************/

#include "garden.h"

Garden::Garden(const char* name, int nbAnthills)
{
	this->name = name;
	this->nbAnthills = nbAnthills;
}

void Garden::InitiateAnthills()
{
	for (int i = 0; i < this->nbAnthills; i++) {
		anthills.push_back(new Anthill(new Coord(rand() % 100, rand() % 100)));
	}
}

void Garden::InitiateAnts()
{
	for (Anthill* anthill : this->anthills) {
		for (int j = 0; j < rand() % 1000; j++) {
			colony.push_back(new Ant(anthill));
		}
	}
}

void Garden::InitiateFood()
{
}

void Garden::InitiateWindow()
{
	try {
		if (SDL_Init(SDL_INIT_VIDEO) == -1) throw "SDL Init error: ";
	}
	catch (const char* e) {
		std::cerr << e << SDL_GetError();
	}
	
	this->window = SDL_CreateWindow(this->name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_SetWindowIcon(this->window, IMG_Load("Ressources/Ant.bmp"));
	this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void Garden::InitiateGarden()
{
	InitiateAnthills();
	InitiateAnts();
	InitiateFood();	
}

void Garden::DropTheCrumbs()
{
	InitiateWindow();

	SDL_Event events;
	bool isOpen = true;
	while (isOpen) {
		while (SDL_PollEvent(&events)) {
			switch (events.type) {
			case SDL_QUIT: isOpen = false; break;
			}
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
	SDL_Quit();
}
