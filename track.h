#pragma once

#include "coord.h"

class Track
{
private:
	Coord* currentTrackCoord;
	Coord* nextTrackCoord;
	Coord* previousCoord;

public:
	Track(Coord* initialCoord);

	Coord* GetNextTrackCoord();
	Coord* GetPreviousTrackCoord();
	Coord* GetCurrentTrackCoord();

	void SetCoord(Coord* newCoord);
};
