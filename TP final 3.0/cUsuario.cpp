#include "cUsuario.h"


cUsuario::cUsuario(int edad, string usuario, string hashpassword, bool conectado, string pais, string apellido, string nombre, eTipoUsuario tipo) :pais(pais),apellido(apellido),nombre(nombre)
{
	this->edad = edad;
	this->usuario = usuario;
	this->hashpassword = hashpassword;
	this->conectado = conectado;
	this->tipo = tipo;
	this->tiempoON=0;
	this->tiempoOFF=0;
	setCuota();
}

cUsuario::~cUsuario()
{
}



time_t cUsuario::online()//cambia el estado del usuario a online 
{
	if (conectado)
		return 0;
	else
		conectado = true;
	
	time_t timeON = time(0);
	return timeON;
	
}

void cUsuario::setCuota()
{
	this->cuota = static_cast<int>(tipo);
}

time_t cUsuario::offline()//cambia el estado a offline
{
	if (!conectado)
		return 0;
	else
		conectado = false;
	time_t timeOFF = time(0);
	return timeOFF;
}


string cUsuario::getPassword()
{
	return hashpassword;

}

