#include <iostream>
#include <stdlib.h>
#include <string>
#include "cUsuario.h"
#include <vector>
#include "time.h"
#include "cListaT.h"
#include "Log.h"
#include "Logger.h"
#include "cStreaming.h"
#include <ctime>
#include "cJuegos.h"
#include "cMusica.h"
#include "cPeliculas.h"
#include <random>
#include "generator.h"
#define x 15

using namespace std;


int main()
{
	Logger::historial;

	for (int i = 0; i < Logger::tam; i++)
	{
		Logger::historial[i] = NULL;
	}

	cStreaming* Labflix = new cStreaming("Labflix");  
	
	generator(Labflix);
	try
	{
		Labflix->Simulacion();
	}

	catch (exception * e)
	{
		cout << e->what() << endl;
	}
		
	Mes mesI = static_cast<Mes>(2);           //mes inicio y mes final
	Mes mesF = static_cast<Mes>(2);
	Dia diaI = static_cast<Dia>(0);
	Dia diaF = static_cast<Dia>(7);
	int year = rand() % (2000 + 2021);

		 //estadisticas diarias y semanales
	Logger::MasJugados(mesI, diaI, mesF, diaF, year);
	Logger::MasVisto(mesI, diaI, mesF, diaF, year);
	Logger::MasEscuchados(mesI, diaI, mesF, diaF, year);
	Logger::PromedioUsuarios(mesI, diaI, mesF, diaF, year);



}

