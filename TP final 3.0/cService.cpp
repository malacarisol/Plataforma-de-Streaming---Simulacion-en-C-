#include "cService.h"


cService::cService(string nombre, bool mayorEdad, tipoServicio tipoS, vector<string> paisesProhibidos)
{
	this->nombre = nombre;
	this->mayorEdad = mayorEdad;
	this->tipoS = tipoS;
	this->paisesprohibidos = paisesProhibidos;    
}

cService::~cService()
{
}

void cService::Iniciar()
{

}

void cService::Pausar(int segundos)
{
}

void cService::Apagar()
{
}

void cService::Descargar()
{
}

bool cService::paisesprohibidos(string pais)
{
	if (find(this->paisesprohibidos.begin(), this->paisesprohibidos.end(), pais) != this->paisesprohibidos.end())
	{
		return true;
	}
	
	return false;
}
