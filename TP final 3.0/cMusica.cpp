#include "cMusica.h"

cMusica::cMusica(int duracion, eCategoria categoria, string nombre, bool mayorEdad, tipoServicio tipoS, vector<string> paisesProhibidos):cService(nombre,mayorEdad,tipoS,paisesProhibidos)
{
	this->duracion = duracion;
	this->categoria = categoria;
	tiempo = 0;
}

cMusica::~cMusica()
{
}

void cMusica::Record()
{
	cout << "Grabacion de video iniciada" << endl;
}

void cMusica::Fastforward()
{
	this->tiempo += 15;
}

void cMusica::Backward()
{
	this->tiempo -= 15;
}

void cMusica::Iniciar()
{
	cout << "Cancion iniciada" << endl;
}

void cMusica::Pausar(int segundos)
{
	this->tiempo = segundos;
}

void cMusica::Apagar()
{
	this->tiempo = duracion;
}

void cMusica::Descargar()
{
	cout << "Descargando.." << endl;
}

ostream& operator<<(ostream& out, cMusica& m)
{
	//out << (cService&)m;   //no operator << matches this operands
	out << m.getNombre() << endl;
	return out;
	// TODO: insert return statement here
}
