#include "cJuegos.h"

cJuegos::cJuegos(int nivel, eJuegos juego, string nombre, bool mayorEdad, tipoServicio tipoS,vector<string> paisesProhibidos) :cService(nombre, mayorEdad, tipoS, paisesProhibidos)
{
	this->nivel = nivel;
	this->catJuegos = juego;
}

cJuegos::~cJuegos()
{
}

void cJuegos::GuardarPartida()
{
}

void cJuegos::Iniciar()
{
}

void cJuegos::Pausar(int segundos)
{
}

void cJuegos::Apagar()
{
}

void cJuegos::Descargar()
{
}
