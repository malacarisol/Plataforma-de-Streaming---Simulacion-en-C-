#include "cPeliculas.h"

cPeliculas::cPeliculas(int duracion, ePeliculas peli, string nombre, bool mayorEdad, tipoServicio tipoS, vector<string> paisesProhibidos) :cService(nombre, mayorEdad, tipoS, paisesProhibidos)
{
	this->duracion = duracion;
	this->peli = peli;
}

cPeliculas::~cPeliculas()
{
}

void cPeliculas::Record()
{
}

void cPeliculas::Fastforward()
{
}

void cPeliculas::Backward()
{
}

void cPeliculas::Iniciar()
{
}

void cPeliculas::Pausar(int segundos)
{
}

void cPeliculas::Apagar()
{
}

void cPeliculas::Descargar()
{
}
