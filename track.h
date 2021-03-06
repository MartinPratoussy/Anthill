/*****************************************************************//**
 * \file   track.h
 * \brief  
 * 
 * \author Martin
 * \date   April 2021
 *********************************************************************/

#pragma once

#include "coord.h"

class Track
{
private:
	Coord* currentTrackCoord;
	Track* nextTrack;
	Track* previousTrack;

public:
	Track(Coord* initialCoord);

	Track* GetNextTrack();
	Track* GetPreviousTrack();
	Coord* GetCurrentTrackCoord();

	void SetCoord(Coord* newCoord);
	void SetNextTrack(Track* track);
};
