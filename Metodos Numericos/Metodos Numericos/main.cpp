#include <iostream>
#include "CalcMetodos.h"

void Stop() {
	std::cin.ignore();
	std::cin.get();
}


int main() {
	CalcMetodos calc;

	calc.InterpolacionLagrange();

	Stop();

	return 0;
}