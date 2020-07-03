#include "cPeliculas.h"

cPeliculas::cPeliculas(int duracion, ePeliculas peli, string nombre, bool mayorEdad, tipoServicio tipoS, vector<string> paisesProhibidos) :cService(nombre, mayorEdad, tipoS, paisesProhibidos)
{
	this->duracion = duracion;
	this->peli = peli;
	tiempo = 0;
}

cPeliculas::~cPeliculas()
{
}

void cPeliculas::Record()
{
	cout << "Grabacion de pelicula iniciada" << endl;
}

void cPeliculas::Fastforward()
{
	this->tiempo += 15;
}

void cPeliculas::Backward()
{
	this->tiempo -= 15;
}

void cPeliculas::Iniciar()
{
	cout << "Iniciando.." << endl;
	//this->tiempo = 0;
}

void cPeliculas::Pausar(int segundos)
{
	this->tiempo = segundos;
}

void cPeliculas::Apagar()
{
	this->tiempo = duracion;                                  //Se asuma que se apaga el servicio al finalizar la pelicula
	                                                                      
}


ostream& operator<<(ostream& out, cPeliculas& m)
{
	//out << (cService&)m;     //ERROR:no operator << matches this operands!!
	out << m.getNombre() << endl;
	return out;
	// TODO: insert return statement here
}
