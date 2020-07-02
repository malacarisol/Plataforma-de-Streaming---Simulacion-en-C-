#include "Log.h"

Log::Log(string username, string nombreServicio, time_t tiempo, eTipoUsuario tipoU, tipoServicio tipoS, Mes mes, Dia dia,int anio)
{
	this->username = username;
	this->nombreServicio = nombreServicio;
	this->tiempoUso = tiempo;
	this->tipoU = tipoU;
	this->tipoS = tipoS;
	this->mes = mes;
	this->dia = dia;
	this->anio = anio;
}

Log::~Log()
{
}
