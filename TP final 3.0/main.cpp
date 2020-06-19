#include <iostream>
#include <stdlib.h>
#include <string>
#include "cUsuario.h"
#include <vector>
#include "cService.h"
#include "time.h"
#include "generator.h"
#include "cListaT.h"
#include "Log.h"
#include "Logger.h"
#include "cStreaming.h"
#define x 15
#define NMAX 100


using namespace std;


int main()
{	
	
	cUsuario* vector[NMAX];
	cService* vector2[NMAX];

	cListaT<cUsuario> listaU;
	cListaT<cService> listaS;

	for (int i = 0;i < NMAX;i++)
	{
	generatorU(vector[i]);
	generatorS(vector2[i]);
	listaU.Agregar(vector[i]);
	listaS.Agregar(vector2[i]);
	}
	
	cStreaming Labflix("Labflix",listaU,listaS);

	Logger historial;
	
	Labflix.Simulacion();

	Mes mesI = static_cast<Mes>(2);//mes inicio y mes final
	Mes mesF = static_cast<Mes>(2);
	Dia diaI = static_cast<Dia>(0);
	Dia diaF = static_cast<Dia>(7);
	//estadisticas diarias y semanales

	historial.MasEscuchados(mesI,diaI,mesF,diaF);
	historial.MasJugados(mesI, diaI, mesF, diaF);
	historial.MasVisto(mesI, diaI, mesF, diaF);
	historial.PromedioUsuarios(mesI, diaI, mesF, diaF);

}
