#include "Log.h"

Log::Log(string username, string nombreServicio, int tiempo, int tipoU, int tipoS, Mes mes, int dia, int anio)
{
	this->username = username;
	this->nombreServicio = nombreServicio;
	this->tiempoUso = tiempo;
	this->tipoU = tipoU;
	this->tipoS = tipoS;
	this->mes = mes;
	this->dia = dia;
	this->anio = anio;
};

Log::~Log()
{
}

string Log::getnombre()
{
	return username;
}

string Log::getnombreS()
{
	return nombreServicio;
}

int Log::getTipoUsuario()
{
	return tipoU;
}

int Log::getTipoServicio()
{
	return tipoS;
}

int Log::gettiempo()
{
	return tiempoUso;
}

int Log::getmes()
{
	return mes;
}

int Log::getdia()
{
	return dia;
}

int Log::getanio()
{
	return anio;
}

//bool Log::operator==(Log* logAComparar)
//{
//	if(nombreServicio.compare(logAComparar->nombreServicio)==0)
//		return true;
//	return false;
//}
//
//bool Log::operator!=(Log* logAComparar)
//{
//	if (nombreServicio.compare(logAComparar->nombreServicio) == 0)
//		return false;
//	return true;
//}
