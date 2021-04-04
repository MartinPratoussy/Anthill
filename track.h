#pragma once

#include "coord.h"

class Track
{
private:
	Coord currentTrackCoord;
	Coord nextTrackCoord;
	Coord previousCoord;

private:
	Coord GetNextTrackCoord();
	Coord GetPreviousTrackCoord();
	Coord GetCurrentTrackCoord();
};

