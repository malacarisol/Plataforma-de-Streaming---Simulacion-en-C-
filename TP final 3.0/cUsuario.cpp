#include "cUsuario.h"


double cUsuario::difftime(time_t time2, time_t time1)
{
	return 0.0;
}

cUsuario::cUsuario(int edad, string usuario, string hashpassword, bool conectado, string pais, string apellido, string nombre, eTipoUsuario tipo) :pais(pais),apellido(apellido),nombre(nombre)
{
	this->edad = edad;
	this->usuario = usuario;
	this->hashpassword = hashpassword;
	this->conectado = conectado;
	this->tipo = tipo;
	this->tiempoON=0;
	this->tiempoOFF=0;
}

cUsuario::~cUsuario()
{
}
//
//void cUsuario::Play(cService serv)
//{
//	serv.
//}


time_t cUsuario::online()//cambia el estado del usuario a online 
{
	if (conectado)//Una vez q se la llama ya cambia el estado del usuario a online, metodo inutil
		return;
	else
		conectado = true;
	
	time_t timeON = time(0);
	return timeON;
	
}


bool cUsuario::AgregarFavoritos(cService* ser)
{
	favoritos.push_back(ser->getNombre());
}

void cUsuario::setCuota(int c)
{
	this->cuota = c;
}

time_t cUsuario::offline()//cambia el estado a offline
{
	if (!conectado)
		return;
	else
		conectado = false;
	time_t timeOFF = time(0);
	return timeOFF;
}

string cUsuario::getUsername()//Para acceder al nombre de usuario desde Streaming y asi checkear password
{
	return usuario;
}
string cUsuario::getPassword()
{
	return hashpassword;

}
eTipoUsuario cUsuario::getTipo()
{
	return tipo;
}

