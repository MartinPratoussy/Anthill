/*****************************************************************//**
 * \file   main.cpp
 * \brief  
 * 
 * \author Martin
 * \date   April 2021
 *********************************************************************/

#include <iostream>

#include "garden.h"

int main() {

	Garden* garden = new Garden("Octopus's garden", 4);
	garden->InitiateGarden();
	
	return 0;
}