/*****************************************************************//**
 * \file   ant.cpp
 * \brief  
 * 
 * \author Martin
 * \date   April 2021
 *********************************************************************/

#include "ant.h"

Ant::Ant(Anthill* home)
{
    this->antLocation = this->home->GetLocation();
    this->home = home;
}

void Ant::CreateNextTrack()
{
    int direction = rand() % 4+1;
    Coord* newCoord;
    switch (direction)
    {
    case 1:
        newCoord = new Coord(this->antLocation->GetX() + 5, this->antLocation->GetY());
        this->trackTargeted = new Track(newCoord);
        this->lastTrackReached->SetNextTrack(this->trackTargeted);
        break;
    case 2:
        newCoord = new Coord(this->antLocation->GetX() - 5, this->antLocation->GetY());
        this->trackTargeted = new Track(newCoord);
        this->lastTrackReached->SetNextTrack(this->trackTargeted);
        break;
    case 3:
        newCoord = new Coord(this->antLocation->GetX(), this->antLocation->GetY() + 5);
        this->trackTargeted = new Track(newCoord);
        this->lastTrackReached->SetNextTrack(this->trackTargeted);
        break;
    case 4:
        newCoord = new Coord(this->antLocation->GetX(), this->antLocation->GetY() - 5);
        this->trackTargeted = new Track(newCoord);
        this->lastTrackReached->SetNextTrack(this->trackTargeted);
        break;
    default:
        break;
    }
}

void Ant::TakeFood()
{
    this->haveFood = true;
}

void Ant::DropFood()
{
    this->home->AddFoodToReserve(new Food());
    this->haveFood = false;
}

bool Ant::IsHungry()
{
    return this->haveFood;
}

void Ant::GoToNextTrack()
{

    if (this->antLocation->IsFoodPresent()) { // TODO: move to a controller class
        this->haveFood = true;
        return;
    }

    if (!this->lastTrackReached->GetNextTrack()->GetCurrentTrackCoord()) { // TODO: move to a controller class
        this->CreateNextTrack();
        return;
    }

    this->trackTargeted->SetCoord(this->lastTrackReached->GetNextTrack()->GetCurrentTrackCoord());
    while (this->antLocation != this->trackTargeted->GetCurrentTrackCoord()) { // TODO: move to a controller class
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
    if (this->antLocation == this->home->GetLocation()) {
        DropFood();
    }

    if (this->haveFood) { // TODO: move to a controller class
        this->trackTargeted->SetCoord(this->lastTrackReached->GetPreviousTrack()->GetCurrentTrackCoord());
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
