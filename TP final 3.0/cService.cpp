#include "cService.h"
include "cUsuario.h"


cService::cService(string nombre, bool mayorEdad, tipoServicio tipoS, vector<string> paisesProhibidos):tipoS(tipoS)
{
	this->nombre = nombre;
	this->mayorEdad = mayorEdad;
//	this->tipoS::tipoS;
	this->paisesprohibidos = paisesProhibidos;    
}

cService::~cService()
{
}

void cService::Iniciar()
{
	cout << "Begin" << endl;
}

void cService::Pausar(int segundos)   //implementado en las hijas
{
	cout << "Pause" << endl;
}

void cService::Apagar()
{
	cout << "End" << endl;
}

void cService::Descargar(cUsuario* user1, string nombre)
{
	user1->getVectorDescargas().push_back(nombre);
}
bool cService::AgregarFavoritos(cUsuario* user1,string nombre)
{
	if (user1->favoritos.push_back(nombre))
		return true;
	else return false;
}
bool cService::IsProhibidoPais(string pais)
{
	if (find(this->paisesprohibidos.begin(), this->paisesprohibidos.end(), pais) != this->paisesprohibidos.end())
	{
		return true;
	}
	
	return false;
}
