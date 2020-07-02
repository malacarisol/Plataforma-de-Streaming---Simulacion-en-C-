#include <iostream>
#include <stdlib.h>
#include <string>
#include "cUsuario.h"
#include <vector>
//#include "cService.h"
#include "time.h"
#include "generator.h"
#include "cListaT.h"
#include "Log.h"
#include "Logger.h"
#include "cStreaming.h"
#include <ctime>
#define x 15
#define NMAX 100

using namespace std;


int main()
{	
	
	cUsuario* user[NMAX];
	cService* vector2[NMAX];

	cListaT<cUsuario> listaU(NMAX);
	cListaT<cService> listaS(NMAX);

	for(int i = 0;i < NMAX;i++)
	{
	generatorU(user[i]);                                 //agrego UN solo usuario
	generatorS(vector2[i]);                                 //ERROR: argument of type "cUsuario*" is incompatible con  type cUsuario*
	listaU.Agregar(user[i]);
	listaS.Agregar(vector2[i]);
	}
	vector2[0]->Descargar(user[0], "jeje");
	//cStreaming(string nombre, cListaT<cService> ListaServicios, cListaT<cUsuario> ListaUsuarios);
	
	cStreaming *Labflix=new cStreaming("Labflix",listaU,listaS);       //ERROR: no instance of constructor matches the argument list

	Logger historial;
	try 
	{	
		Labflix->Simulacion();
		
	}

	catch (exception * e)
	{
		cout << e->what() << endl;
	}


	Mes mesI = static_cast<Mes>(2);//mes inicio y mes final
	Mes mesF = static_cast<Mes>(2);
	Dia diaI = static_cast<Dia>(0);
	Dia diaF = static_cast<Dia>(7);
	int anio = rand() % (2000 + 2021);
	
	//estadisticas diarias y semanales

	historial.MasEscuchados(mesI,diaI,mesF,diaF,anio);
	historial.MasJugados(mesI, diaI, mesF, diaF,anio);
	historial.MasVisto(mesI, diaI, mesF, diaF,anio);
	historial.PromedioUsuarios(mesI, diaI, mesF, diaF,anio);

}



//if (find(this->paisesprohibidos.begin(), this->paisesprohibidos.end(), pais) != this->paisesprohibidos.end())  

// sintaxis para encontrar un string en un vector