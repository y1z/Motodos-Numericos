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
	unsigned int CantidadDatos = 0;
	
	double_t PuntoEvaluar = 1;
	// los valores que ingresa el usario 
	double Xn, Yn;
	// Tendra los valores X, Y 
	std::vector<std::pair<double, double>> DatosUsario;
	//  operaciones 
	std::vector<double> OperacionesCiclo;
	// Resultados Final 
	double ResultadoFinal = 0;

	std::cout << "Porfavor Digame el Punto a evaluar \n";
	std::cin >> PuntoEvaluar;
	
	std::cout << "Cuantos pares de 'xn' en combinacion de 'yn' vas a ingresar\n";
	std::cin >> CantidadDatos;


	for (int i = 0; i < CantidadDatos; ++i)
	{
		printf("Ingresa el valor de X%d con el valor de Y%d \n \n ", i, i);
		std::cin >> Xn >> Yn;
		DatosUsario.emplace_back(std::make_pair(Xn, Yn));
	}

	for (int i = 0; i < CantidadDatos; ++i)
	{
		// Para Presentar el polinomio al usario 
		std::vector<double> ResultadosDenominador;
	
		for(int j = 0 ; j < CantidadDatos; ++j)
		{
			if(i != j)
			{
				// aqui hacemos unas diviciones para luego multiplicar
				// los resultados de cada una 
				double tempNumerador = PuntoEvaluar - DatosUsario[j].first;
				double tempDenominador = DatosUsario[i].first - DatosUsario[j].first;
				// para luego demostar esto al usario 
				ResultadosDenominador.emplace_back(tempDenominador);
				// ponemos los resultados en este arreglo 
				OperacionesCiclo.emplace_back(tempNumerador / tempDenominador);
			}
		}
		// este valor esta aqui para que 
		// se renicie cada ciclo
		double tempMulti = 1;

		// este valor esta aqui solo para 
		// que el usario pueda ver el polinomio
		double tempDenominador = 1;

		// Aqui multiplicamos la diviciones 
		for (double Valor : OperacionesCiclo) {
			tempMulti *= Valor;
		}

		// luego multiplicamos todo por el 
		// valor de 'yn' 
		tempMulti *= DatosUsario[i].second;
		// vaciamos el arreglo para los proximos  
		// resultados que va a tener 
		OperacionesCiclo.clear();
		ResultadoFinal += tempMulti;


		for(double Denominadores : ResultadosDenominador)
		{
			tempDenominador *= Denominadores;
		}

		// Aqui intentamos enseñar el polinomio al 
		// usario 
		std::cout << DatosUsario[i].second << " * ";

		for(int k = 0; k < CantidadDatos;++k)
		{
			// sacamos la potencia de -1 al numero 
			if (k == 0) {
				std::cout << '(' << pow(tempDenominador, -1) << ')';
			}
			if (k != i)
			std::cout << "(" << 'x' << " - " << DatosUsario[k].first<< ")";
		}
		if (!(i == CantidadDatos - 1))
		printf(" + ");
	}

	std::cout <<"\nEl resultado es ["<< ResultadoFinal<<"]\n";
	return ResultadoFinal;
}


// TODO : hacer que pueda crear escalones 
// para la operacion y investigar la 
// operacion en si 
double CalcMetodos::InterpolacionDeNewton()
{
	// sin este no podemos hacer esta operacion 
	double PuntoEvaluar = 0.0;
	// aqui esta lo punto que require la funcion 
	double Xn, Yn;
	// para saber cuantos veces tendre que repetir la funcion
	int CantidadDeDatos = 0;

	std::vector<double> ContenedorDeXn;

	std::vector<double> ContenedorDeYn;

	std::vector<double> ArregloMenor;

	std::vector<double> Polynomio;

	int IteradorDeX = 0;

	double ResultadoFinal = 0.0;

	printf("hola vamos a hacer la Interpolacion de Newton \n conteste las siguentes preguntas \n\n");

	printf("Cual es el valor de 'X'\n");

	cin >> PuntoEvaluar;

	printf("?Cuantos Valores quiere ingresar?\n");

	cin >> CantidadDeDatos;

	
	for (int i = 0; i < CantidadDeDatos; ++i) {

		printf("Porfavor ingrese el Valor de X%d \n", i + 1);
		cin >> Xn;
		printf("\nPorfavor ingrese el Valor de Y%d \n", i + 1);
		cin >> Yn;

		ContenedorDeXn.emplace_back(Xn);
		ContenedorDeYn.emplace_back(Yn);
	}

	ResultadoFinal += ContenedorDeYn[0];

	// creacion del primer escalon 

	for (int i = 1; i < ContenedorDeYn.size() - 1; ++i)
	{
		double tempNumerador = ContenedorDeYn[i] - ContenedorDeYn[i - 1];
		double tempDenominador = ContenedorDeXn[i] - ContenedorDeXn[i - 1];
		ArregloMenor.emplace_back(tempNumerador / tempDenominador);
	}

	ResultadoFinal += ArregloMenor[0];

	while (ArregloMenor.size() > 1) {
		std::vector<double> ProximoEscalon;
		
		for(int i= 0; i< ArregloMenor.size(); ++i)
		{
			double tempNumerador = ArregloMenor[(i + IteradorDeX)] - ArregloMenor[(i - 1) + IteradorDeX];
			double tempDenominador = ContenedorDeXn[(i + IteradorDeX)] - ContenedorDeXn[(i - 1) +IteradorDeX];
			ProximoEscalon.emplace_back(tempNumerador / tempDenominador);
		}
		ArregloMenor = ProximoEscalon;
		ResultadoFinal += ArregloMenor[0];
	}

	return ResultadoFinal;
}
