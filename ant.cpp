#include "ant.h"

void Ant::CreateNextTrack()
{

}

Ant::Ant(Anthill* home)
{
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
