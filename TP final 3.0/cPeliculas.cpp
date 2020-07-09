#include "cPeliculas.h"

cPeliculas::cPeliculas(int duracion, ePeliculas peli, string nombre, bool mayorEdad, tipoServicio tipoS, vector<string> paisesProhibidos) :cService(duracion,nombre, mayorEdad, tipoS, paisesProhibidos)
{
	
	this->peli = peli;

};

cPeliculas::~cPeliculas()
{
}


void cPeliculas::Fastforward()
{
	this->TiempoActual += 15;
	cout << "+15..." << endl;
}

void cPeliculas::Backward()
{
	this->TiempoActual -= 15;
	cout << "-15..." << endl;
}

void cPeliculas::Iniciar(cUsuario* user)
{
	cout << "Busquese unos pochoclos la pelicula esta a punto de empezar.." << endl<<endl;

}

void cPeliculas::Pausar(int segundos)
{
	this->TiempoActual = segundos;
	cout << "Desea volver hacia atras o avanzar?" << endl;

	srand(time(NULL));
	int opcion = rand() % (2 );

	if (opcion == 1)
	{	
		Fastforward();
	}	
 
	else if (opcion == 2)
	{
		Backward();
	}
	return;
}

void cPeliculas::Apagar(cUsuario* user)
{
	cService::Apagar(user);                               //Se asuma que se apaga el servicio al finalizar la pelicula
	
}

string cPeliculas::getCategoria()
{
	if (peli == 0)
		return "terror";
	else if (peli == 1)
		return "ciencia Ficcion";
	else if (peli == 2)
		return "comedia";
	else if (peli == 3)
		return "infantil";

}
//typedef enum {terror, cienciaFiccion, comedia,infantil} ePeliculas;

