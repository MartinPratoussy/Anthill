#include "ant.h"

void Ant::CreateNextTrack()
{
    int direction = rand() % 4+1;
    switch (direction)
    {
    case 1:
        Coord* newCoord = new Coord(this->antLocation->GetX() + 5, this->antLocation->GetY());
        this->trackTargeted = new Track(newCoord);
        break;
    case 2:
        Coord * newCoord = new Coord(this->antLocation->GetX() - 5, this->antLocation->GetY());
        this->trackTargeted = new Track(newCoord);
        break;
    case 3:
        Coord * newCoord = new Coord(this->antLocation->GetX(), this->antLocation->GetY() + 5);
        this->trackTargeted = new Track(newCoord);
        break;
    case 4:
        Coord * newCoord = new Coord(this->antLocation->GetX(), this->antLocation->GetY() - 5);
        this->trackTargeted = new Track(newCoord);
        break;
    default:
        break;
    }
}

Ant::Ant(Anthill* home)
{
    this->antLocation = this->home->GetLocation();
    this->home = home;
}

bool Ant::IsHungry()
{
    return this->haveFood;
}

void Ant::GoToNextTrack()
{
    if (!this->lastTrackReached->GetNextTrackCoord()) {
        this->CreateNextTrack();
        return;
    }

    this->trackTargeted->SetCoord(this->lastTrackReached->GetNextTrackCoord());
    while (this->antLocation != this->trackTargeted->GetCurrentTrackCoord()) {
        if (this->antLocation->GetX() > this->trackTargeted->GetCurrentTrackCoord()->GetX()) {
            this->antLocation = new Coord(this->antLocation->GetX() - 1, this->antLocation->GetY());
        }
        else if (this->antLocation->GetX() < this->trackTargeted->GetCurrentTrackCoord()->GetX()) {
            this->antLocation = new Coord(this->antLocation->GetX() + 1, this->antLocation->GetY());
        }
        if (this->antLocation->GetY() > this->trackTargeted->GetCurrentTrackCoord()->GetY()) {
            this->antLocation = new Coord(this->antLocation->GetX(), this->antLocation->GetY() - 1);
        }
        else if (this->antLocation->GetY() < this->trackTargeted->GetCurrentTrackCoord()->GetY()) {
            this->antLocation = new Coord(this->antLocation->GetX(), this->antLocation->GetY() + 1);
        }
    }
}

void Ant::GoToPreviousTrack()
{
    if (this->haveFood) {
        this->trackTargeted->SetCoord(this->lastTrackReached->GetPreviousTrackCoord());
        while (this->antLocation != this->trackTargeted->GetCurrentTrackCoord()) {
            if (this->antLocation->GetX() > this->trackTargeted->GetCurrentTrackCoord()->GetX()) {
                this->antLocation = new Coord(this->antLocation->GetX() - 1, this->antLocation->GetY());
            }
            else if (this->antLocation->GetX() < this->trackTargeted->GetCurrentTrackCoord()->GetX()) {
                this->antLocation = new Coord(this->antLocation->GetX() + 1, this->antLocation->GetY());
            }
            if (this->antLocation->GetY() > this->trackTargeted->GetCurrentTrackCoord()->GetY()) {
                this->antLocation = new Coord(this->antLocation->GetX(), this->antLocation->GetY() - 1);
            }
            else if (this->antLocation->GetY() < this->trackTargeted->GetCurrentTrackCoord()->GetY()) {
                this->antLocation = new Coord(this->antLocation->GetX(), this->antLocation->GetY() + 1);
            }
        }
    }
}
