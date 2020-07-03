#pragma once
#include "cListaT.h"
#include "Log.h"
#include<ctime>
#include <iostream>
#include <string>
#define nmax 10

class Logger
{
	int ca;
	int tam;
	Log** historial;
public:
	static Logger logger;
	Logger();
	~Logger();
	bool agregar(Log* log);
	time_t tconexion(string user);                                                   //los t adelante significan que devuelve el tiempo acumulado
	string MasVisto(Mes desde, Dia desde_, Mes hasta, Dia hasta_, int anio);            // le paso el rango de la fechas donde quiero buscar los mas vistos, los lista
	string MasJugados(Mes desde, Dia desde_, Mes hasta, Dia hasta_, int anio);          //los lista
	string MasEscuchados(Mes desde, Dia desde_, Mes hasta, Dia hasta_, int anio);       //los lista
	float PromedioUsuarios(Mes desde, Dia desde_, Mes hasta, Dia hasta_, int anio);     //devuelve el promedio de usuarios conectados


};

