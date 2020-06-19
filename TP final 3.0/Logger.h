#pragma once
#include "Log.h"

class Logger
{
	static Log** log;
	//	Log(string username, tipoDeUsuario,tipoServicio,mes,dia);
public:
	Logger();
	~Logger();
	static bool agregar(Log* log);
	static float tconexion(string user);//los t adelante significan que devuelve el tiempo acumulado
	static string MasVisto(Mes desde, Dia desde_, Mes hasta, Dia hasta_);// le paso el rango de la fechas donde quiero buscar los mas vistos, los lista
	static string MasJugados(Mes desde, Dia desde_, Mes hasta, Dia hasta_);//los lista
	static string MasEscuchados(Mes desde, Dia desde_, Mes hasta, Dia hasta_);//los lista
	static float PromedioUsuarios(Mes desde, Dia desde_, Mes hasta, Dia hasta_);//devuelve el promedio de usuarios conectados
};
