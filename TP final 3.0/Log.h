#pragma once
#include "iostream"
#include "cUsuario.h"
#include "cService.h"
#include "string"

using namespace std;

class Log
{
	string username;
	string nombreServicio;
	int tiempoUso;
	int tipoU;       //usuario
	int tipoS;        //tipo servicio
	Mes mes;
	int dia;
	int anio;

public:
	Log(string username, string nombreServicio, int tiempo, int tipoU, int tipoS, Mes mes, int dia,int anio);   //Se guardan los datos despues de acceder de acada servicio
	~Log();
	string getnombre();
	string getnombreS();
	int getTipoUsuario();
	int getTipoServicio();
	int gettiempo();
	int getmes(); 
	int getdia();       
	int getanio();
	//bool operator ==(Log* logAComparar);
	//bool operator !=(Log* logAComparar);

};
