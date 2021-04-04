#include "track.h"

Track::Track(Coord* initialCoord)
{
    this->currentTrackCoord = initialCoord;
}

Track* Track::GetNextTrack()
{
    return this->nextTrack;
}

Track* Track::GetPreviousTrack()
{
    return this->previousTrack;
}

Coord* Track::GetCurrentTrackCoord()
{
    return this->currentTrackCoord;
}

void Track::SetCoord(Coord* newCoord)
{
    this->currentTrackCoord = newCoord;
}

void Track::SetNextTrack(Track* track)
{
    this->previousTrack = this;
    this->nextTrack = track;
}