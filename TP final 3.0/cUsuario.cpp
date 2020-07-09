#include "cUsuario.h"



cUsuario::cUsuario(int edad, string usuario, string hashpassword, bool conectado, string pais, string apellido, string nombre, eTipoUsuario tipo) :pais(pais), apellido(apellido)
{
	this->nombre = nombre;
	this->edad = edad;
	this->usuario = usuario;
	this->hashpassword = hashpassword;
	this->conectado = conectado;
	this->tipo = tipo;
	setCuota(tipo);

};

cUsuario::~cUsuario()
{
	
}


void cUsuario::setCuota(eTipoUsuario tipo)
{
	if (tipo == 0)
		this->cuota = 100;
	else if (tipo == 1)
		this->cuota = 200;
	else
		this->cuota =300;
}



int cUsuario::getTipo()
{
	return tipo;
}

string cUsuario::getPais()
{
	return pais;
}

string cUsuario::getNombre()
{
 	return usuario;
}

void cUsuario::getanuncios()
{
	if (anuncios != true)
		anuncios = true;
}


int cUsuario::getedad()
{
	return edad;
}

string cUsuario::getPassword()
{
	return hashpassword;
}

