#pragma once
#include <iostream>

void Stop() {
	std::cin.ignore();
	std::cin.get();
}

void ExtraLine(int x)
{
	for (int i = 0; i < x; ++i) {
		printf("\n");
	}

}