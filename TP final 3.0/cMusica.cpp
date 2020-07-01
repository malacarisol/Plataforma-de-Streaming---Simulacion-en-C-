#include "cMusica.h"

cMusica::cMusica(int duracion, eCategoria categoria, string nombre, bool mayorEdad, tipoServicio tipoS, vector<string> paisesProhibidos):cService(nombre,mayorEdad,tipoS,paisesProhibidos)
{
	this->duracion = duracion;
	this->categoria = categoria;
}

cMusica::~cMusica()
{
}

void cMusica::Record()
{
}

void cMusica::Fastforward()
{
}

void cMusica::Backward()
{
}

void cMusica::Iniciar()
{
}

void cMusica::Pausar(int segundos)
{
}

void cMusica::Apagar()
{
}

void cMusica::Descargar()
{
}
