#pragma once
#include <cmath>
#include <iostream>
#include <vector>
#include <ratio>


using std::cin;

class CalcMetodos
{
public:
	CalcMetodos();
	~CalcMetodos();
public: // Metodos 
	double InterpolacionLagrange();
	double InterpolacionDeNewton();
};

