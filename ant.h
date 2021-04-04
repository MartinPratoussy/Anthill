#pragma once

#include "track.h"

class Ant
{
private:
	Track targetTrack;
	bool haveFood = false;

public:
	bool IsHungry();
};