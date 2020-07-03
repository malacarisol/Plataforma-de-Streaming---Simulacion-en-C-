#pragma once
#include "iostream"
#include "cUsuario.h"
#include "cService.h"
#include "string"
#include <ctime>
//#include "cUsuario.h"

using namespace std;

class Log
{
	friend class Logger;

	string username;
	string nombreServicio;
	double tiempoUso;
	string tipoU; //usuario
	string tipoS;//tipo servicio
	Mes mes;
	Dia dia;
	int anio;

public:
	Log(string username, string nombreServicio, double tiempo, string tipoU, string tipoS, Mes mes, Dia dia,int anio);   //Se guardan los datos despues de acceder de acada servicio
	~Log();
	string getnombre() { return username; };
	string getnombreS() { return nombreServicio; };
	string getTipoServicio() { return tipoS; };
	double gettiempo() { return tiempoUso; };
	int getmes() { return static_cast<int>( mes); };    //castear enum a  int
	int getdia() { return static_cast<int>(dia); };          //return  static_cast<int>(dia); };
	int getanio() {return anio; };
};
