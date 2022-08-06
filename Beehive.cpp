#include "Header Files/Beehive.h"
#include <iostream>

Beehive *Beehive::beehive = nullptr;
Beehive *Beehive::GetInstance(const int* width, const int* height, const int* breadth, const int* volume, const bool& produce)
{
	if (beehive == nullptr) {
		beehive = new Beehive(*width, *height, *breadth, *volume, &produce);
	}
	return beehive;
}


