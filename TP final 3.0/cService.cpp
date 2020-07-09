#include "cService.h"



cService::cService(int tiempoDuracion, string nombre, bool mayorEdad, tipoServicio tipoS, vector<string> paisesProhibidos) :tipoS(tipoS)
{
	this->nombre = nombre;
	this->mayorEdad = mayorEdad;
	this->paisesprohibidos = paisesProhibidos;
	this->duracion = tiempoDuracion;
	this->TiempoActual = 0;
};

cService::~cService()
{
}

void cService::Iniciar(cUsuario* user)
{
	user->conectado = true;
}

void cService::Pausar(int segundos) 
{
	this->TiempoActual = segundos;
}

void cService::Apagar(cUsuario* user)
{
	user->conectado = false;
	this->TiempoActual = duracion; //Al cortar el servicio, el tiempo pasado en la plataforma es igual al tiempo de duracion del servicio
}

bool cService::MayorEdad()
{
	return mayorEdad; 
}

void cService::Descargar(cUsuario *nombre1, string nombre)
{
	nombre1->descargas.push_back(nombre);

}
void cService::AgregarFavoritos(cUsuario* nombre2,string nombre)
{
	nombre2->favoritos.push_back(nombre);

}
bool cService::IsProhibidoPais(string pais)
{
	if (find(this->paisesprohibidos.begin(), this->paisesprohibidos.end(), pais) != this->paisesprohibidos.end())
	{
		return true;
	}
	
	return false;
}

string cService::getNombre()
{
	return nombre;
}

int cService::getTipo()
{
	return tipoS;
}

void cService::setNombre(string nombre)
{
	this->nombre = nombre;
}

int cService::getTiempoActual()
{
	return TiempoActual;
}

int cService::getduracion()
{
	return duracion;
}

ostream& operator<<(ostream &out, cService* serv)
{
	out << serv->getNombre() << endl;
	return out;
}