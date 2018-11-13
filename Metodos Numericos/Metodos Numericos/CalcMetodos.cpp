#include "CalcMetodos.h"

CalcMetodos::CalcMetodos()
{
}


CalcMetodos::~CalcMetodos()
{
}


double CalcMetodos::InterpolacionLagrange()
{
	// esta variable determina cuantos 
	// ciclo vamos a hacer 
	unsigned int CantidadDeDatos = 0;
	
	double_t ValorDeX = 1;
	// los valores que ingresa el usario 
	double Xn, Yn;
	// Tendra los valores X, Y 
	std::vector<std::pair<double, double>> DatosDeUsario;
	//  operaciones 
	std::vector<double> OperacionesCiclo;
	// Resultados Final 
	double ResultadoFinal = 0;

	std::cout << "Porfavor Digame el valor que conreponde a X \n";
	std::cin >> ValorDeX;
	
	std::cout << "Cuantos pares de 'xn' en combinacion de 'yn' vas a ingresar\n";
	std::cin >> CantidadDeDatos;


	for (int i = 0; i < CantidadDeDatos; ++i)
	{
		printf("Ingresa el valor de X%d con el valor de Y%d \n \n ", i, i);
		std::cin >> Xn >> Yn;
		DatosDeUsario.emplace_back(std::make_pair(Xn, Yn));
	}

	for (int i = 0; i < CantidadDeDatos; ++i)
	{
		for(int j = 0 ; j < CantidadDeDatos; ++j)
		{
			if(i != j)
			{
				// aqui hacemos unas diviciones para luego multiplicar
				// los resultados de cada una 
				double tempNumerador = ValorDeX - DatosDeUsario[j].first;
				double tempDenominador = DatosDeUsario[i].first - DatosDeUsario[j].first;
				// ponemos los resultados en este arreglo 
				OperacionesCiclo.emplace_back(tempNumerador / tempDenominador);
			}
		}
		// este valor esta aqui para que 
		// se renicie cada ciclo
		double tempMulti = 1;

		// Aqui multiplicamos la diviciones 
		for (double Valor : OperacionesCiclo) {
			tempMulti *= Valor;
		}
		// luego multiplicamos todo por el 
		// valor de 'yn' 
		tempMulti *= DatosDeUsario[i].second;
		// vaciamos el arreglo para los proximos  
		// resultados que va a tener 
		OperacionesCiclo.clear();
		ResultadoFinal += tempMulti;
	}

	std::cout <<"El resultado es ["<< ResultadoFinal<<"]\n";
	return ResultadoFinal;
}
