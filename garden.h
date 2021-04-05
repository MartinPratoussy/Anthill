/*****************************************************************//**
 * \file   .h
 * \brief  
 * 
 * \author Martin
 * \date   April 2021
 *********************************************************************/

#pragma once

#include <string.h>
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#define SDL_MAIN_HANDLED
#include <SDL\SDL.h>
#include <SDL\SDL_image.h>

#include "ant.h"

class Garden
{
private:
	const char* name;
	int nbAnthills;
	std::vector<Anthill*> anthills;
	std::vector<Ant*> colony;
	std::vector<Food**> meals;

	SDL_Window* window;
	SDL_Renderer* renderer;

	void InitiateAnthills();
	void InitiateAnts();
	void InitiateFood();

	void InitiateWindow();
	
public:
	Garden(const char* name, int nbAnthills);

	void InitiateGarden();
	void DropTheCrumbs();
};

