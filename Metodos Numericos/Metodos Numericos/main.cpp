#include <iostream>
#include "MisFunciones.h"
#include "CalcMetodos.h"


// TODO hacer un Menu como el de 
// Stack y Pilas 
void Menu(CalcMetodos &Calculadora);
void PrintOpciones();

int main() {


	CalcMetodos calc;

	//calc.InterpolacionLagrange();
	calc.InterpolacionLagrange();
	//calc.InterpolacionDeNewton();

	Stop();

	return 0;
}

void PrintOpciones() {
	printf("Tiene las siguentes opciones \n");
	printf("1) InterpolacionLagrange \n");
	printf("2) InterpolacionNewton \n");
	printf("0) Terminar \n");
}

// TODO:desarollar esta funcion 
void Menu(CalcMetodos &Calculadora)
{
	short Opciones = -1;

	bool IsActivo = true;

	double Resultado;

	PrintOpciones();

	while(IsActivo)
	{
		switch (Opciones)
		{
		case (1):
			Resultado = Calculadora.InterpolacionLagrange();
			break;
		case(2):
			Calculadora.InterpolacionDeNewton();
			break;
		default:
			break;
		}
	
	}
}