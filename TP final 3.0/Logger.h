#pragma once
#include "cListaT.h"
#include "Log.h"
#include<ctime>
#include <iostream>
#include <string>
#define nmax 10

class Logger
{
 public:	
	Logger();
	~Logger();
	static int ca;
    static int tam;
	static Log** historial;
	

	static bool agregar(Log* log);
	time_t tconexion(string user);                                                   //los t adelante significan que devuelve el tiempo acumulado
	static string MasVisto(Mes desde, Dia desde_, Mes hasta, Dia hasta_,int anio);            // le paso el rango de la fechas donde quiero buscar los mas vistos, los lista
	static string MasJugados(Mes desde, Dia desde_, Mes hasta, Dia hasta_,int anio);          //los lista
	static string MasEscuchados(Mes desde, Dia desde_, Mes hasta, Dia hasta_,int anio);       //los lista
	static float PromedioUsuarios(Mes desde, Dia desde_, Mes hasta, Dia hasta_,int anio);     //devuelve el promedio de usuarios conectados
	

};

