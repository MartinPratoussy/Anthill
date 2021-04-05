/*****************************************************************//**
 * \file   ant.h
 * \brief  
 * 
 * \author Martin
 * \date   April 2021
 *********************************************************************/

#pragma once

#include <ctime>
#include <SDL/SDL_image.h>
#include "track.h"
#include "anthill.h"

class Ant
{
private:
	Track* trackTargeted;
	Track* lastTrackReached;
	Coord* antLocation;
	bool haveFood = false;
	Anthill* home;

	SDL_Surface* image;

	void CreateNextTrack();
	void TakeFood();
	void DropFood();

public:
	Ant(Anthill* home);	
	
	bool IsHungry();
	void GoToNextTrack();
	void GoToPreviousTrack();
	Anthill* GetHome();
	SDL_Surface* GetImage();
};