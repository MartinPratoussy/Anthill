#include "track.h"

Coord Track::GetNextTrackCoord()
{
    return this->nextTrackCoord;
}

Coord Track::GetPreviousTrackCoord()
{
    return this->previousCoord;
}

Coord Track::GetCurrentTrackCoord()
{
    return this->currentTrackCoord;
}
