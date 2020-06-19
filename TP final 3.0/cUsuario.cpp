#include "cUsuario.h"

cUsuario::cUsuario(int edad, string usuario, string hashpassword, bool conectado, string pais, string apellido, string nombre, eTipoUsuario tipo)
{
}

cUsuario::~cUsuario()
{
}


void cUsuario::online()//cambia el estado del usuario a online 
{
	if (conectado)//Una vez q se la llama ya cambia el estado del usuario a online, metodo inutil
		return;
	else
		conectado = true;
}

void cUsuario::setCuota(int c)
{
	this->cuota = c;
}

void cUsuario::offline()//cambia el estado a offline
{
	if (!conectado)
		return;
	else
		conectado = false;
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

