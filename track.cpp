#include "track.h"

Track::Track(Coord* initialCoord)
{
    this->currentTrackCoord = initialCoord;
}

Coord* Track::GetNextTrackCoord()
{
    return this->nextTrackCoord;
}

Coord* Track::GetPreviousTrackCoord()
{
    return this->previousCoord;
}

Coord* Track::GetCurrentTrackCoord()
{
    return this->currentTrackCoord;
}

void Track::SetCoord(Coord* newCoord)
{
    this->currentTrackCoord = newCoord;
}
