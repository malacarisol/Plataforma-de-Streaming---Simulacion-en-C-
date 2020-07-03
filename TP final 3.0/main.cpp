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
	Logger::logger.agregar(new Log("", "", 5, "", "", Mes::abril, Dia::jueves, 1997));

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

		 //estadisticas diarias y semanales , los mas vistos etc estan en estadisticas semanales
	Logger::PromedioUsuarios(mesI, diaI, mesF, diaF, year);



}

