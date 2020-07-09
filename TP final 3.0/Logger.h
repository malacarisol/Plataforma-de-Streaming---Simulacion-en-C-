#pragma once
#include "cListaT.h"
#include "Log.h"
#include <iostream>
#include <string>
#define nmax 50

class Logger
{ 
 public:
	Log** historial;
	Logger(int a=nmax);
	~Logger();
	int ca;
    int tam;
	static Logger logger;
	bool agregar(Log* log);
	void MasVisto(Mes desde, int desde_,int hasta_, int anio);               // le paso el rango de la fechas donde quiero buscar los mas vistos, los lista
	void MasJugados(Mes desde, int desde_,int hasta_,int anio);             //los lista
	void MasEscuchados(Mes desde, int desde_,int hasta_, int anio);   
	void PromUsuarioEspecifico(Mes desde, int desde_, int hasta_,int anio,string username);
	void PromTipoUsuario(Mes desde, int desde_, int hasta_,int anio,int type);
	void OrdenarHistorial();
	string getNombreRandom();
};

