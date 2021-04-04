#pragma once

#include <ctime>
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

	void CreateNextTrack();
	void TakeFood();
	void DropFood();

public:
	Ant(Anthill* home);	
	
	bool IsHungry();
	void GoToNextTrack();
	void GoToPreviousTrack();
};