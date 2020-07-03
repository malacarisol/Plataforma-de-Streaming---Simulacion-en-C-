#include "cService.h"


cService::cService(string nombre, bool mayorEdad, tipoServicio tipoS, vector<string> paisesProhibidos):tipoS(tipoS)
{
	this->nombre = nombre;
	this->mayorEdad = mayorEdad;
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

void cService::Descargar(cUsuario *nombre1, string nombre)
{
	nombre1->getdescargas().push_back(nombre);
}
bool cService::AgregarFavoritos(cUsuario* nombre2,string nombre)
{
	nombre2->getFavoritos().push_back(nombre);
	return true;

}
bool cService::IsProhibidoPais(string pais)
{
	if (find(this->paisesprohibidos.begin(), this->paisesprohibidos.end(), pais) != this->paisesprohibidos.end())
	{
		return true;
	}
	
	return false;
}


ostream& cService::operator<<(ostream& out)
{
	cout << getNombre() << endl;
	return out;
	// TODO: insert return statement here
}

istream& cService::operator>>(istream& in)
{
	// TODO: insert return statement here
	string a;
	cout << "Ingrese nombre del servicio" << endl;
	in >> a;
	setNombre(a);
	return in;
}

