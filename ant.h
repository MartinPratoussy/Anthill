#pragma once

#include "track.h"
#include "anthill.h"
#include <ctime>
#include <cstdlib>

class Ant
{
private:
	Track* trackTargeted;
	Track* lastTrackReached;
	Coord* antLocation;
	bool haveFood = false;
	Anthill* home;


	void CreateNextTrack();
	void TakeFood();

public:
	Ant(Anthill* home);	
	
	bool IsHungry();
	void GoToNextTrack();
	void GoToPreviousTrack();
};