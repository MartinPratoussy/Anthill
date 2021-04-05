/*****************************************************************//**
 * \file   main.cpp
 * \brief  
 * 
 * \author Martin
 * \date   April 2021
 *********************************************************************/

#include <SDL\SDL.h>
#include <iostream>

#include "garden.h"

int main(int argc, char* argv[]) {

	Garden* garden = new Garden("Octopus's garden", 4);
	garden->InitiateGarden();
	
	return 0;
}