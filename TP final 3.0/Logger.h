#pragma once
#include "Log.h"
#include<ctime>
#include <iostream>
#define nmax 50
class Logger
{	
	int ca;
    int tam;
	//	Log(string username, tipoDeUsuario,tipoServicio,mes,dia);
public:
	static Log** log;

	Logger(int a=nmax,int CA=0);
	~Logger();

	static bool agregar(Log* log);
	time_t tconexion(string user);//los t adelante significan que devuelve el tiempo acumulado
	string MasVisto(Mes desde, Dia desde_, Mes hasta, Dia hasta_);// le paso el rango de la fechas donde quiero buscar los mas vistos, los lista
	string MasJugados(Mes desde, Dia desde_, Mes hasta, Dia hasta_);//los lista
	string MasEscuchados(Mes desde, Dia desde_, Mes hasta, Dia hasta_);//los lista
	float PromedioUsuarios(Mes desde, Dia desde_, Mes hasta, Dia hasta_);//devuelve el promedio de usuarios conectados
};
