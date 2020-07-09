#include <iostream>
#include <stdlib.h>
#include <string>
#include "cUsuario.h"
#include <vector>
#include "time.h"
#include "cListaT.h"
#include "Log.h"
#include "Logger.h"
#include "cStreaming.h"
#include "cJuegos.h"
#include "cMusica.h"
#include "cPeliculas.h"
#include <random>
#include "generator.h"
#define x 15

using namespace std;


int main()
{
	srand(time(NULL));
	Mes mes = julio;        //mes x defecto                                                       
	int dia1 = 15;
	int dia2 = 22;
	int anio = 2020;
	int aux;

	cStreaming* Labflix = new cStreaming("Labflix");

	generator(Labflix);

	cout << "················ Simulacion ··················" << endl << endl << endl;

	for (int i = 0;i < 30;i++)          //Se crean 30 sesiones
	{
		srand(time(NULL));
		if (dia1 > 22)
			dia1 = 15;
		Labflix->Simulacion(rand() % 15, rand() % 45, dia1, mes, anio);   //random de posicion de usuarios y servicios para seleccionar algunos de la lista de streaming
		dia1++;
	}

	dia1 = 15;            //Para hacer estadistica semanal

	int diaRandom = rand() % (dia2 + 1 - dia1) + dia1;        //Para hacer estadistica diaria


	cout << "ESTADISTICAS" << endl << endl << endl;


	try {
		cout << "PERIODO " << dia1 << "/" << mes << "/" << anio << "--" << dia2 << "/" << mes << "/" << anio << endl << endl;
		Logger::logger.PromTipoUsuario(mes, dia1, dia2, 2020, 0);      //promedio segun los usuarios free semanal
		cout << endl << endl;

	}
	catch (exception * e)
	{
		cout << e->what() << endl;
	}


	try {
		cout << "PERIODO " << dia1 << "/" << mes << "/" << anio << "--" << dia2 << "/" << mes << "/" << anio << endl << endl;
		Logger::logger.PromTipoUsuario(mes, dia1, dia2, 2020, 1);      //promedio segun los usuarios basic semanal
		cout << endl << endl;
	}

	catch (exception * e)
	{
		cout << e->what() << endl;
	}


	try {
		cout << "PERIODO " << dia1 << "/" << mes << "/" << anio << "--" << dia2 << "/" << mes << "/" << anio << endl << endl;
		Logger::logger.PromTipoUsuario(mes, dia1, dia2, 2020, 2);      //promedio segun los usuarios premium semanal
		cout << endl << endl;

	}
	catch (exception * e)
	{
		cout << e->what() << endl;
	}


	try {
		cout << "DIA " << diaRandom << "/" << mes << "/" << anio << endl << endl;

		Logger::logger.PromTipoUsuario(mes, diaRandom, diaRandom, 2020, 0);      //promedio segun los usuarios free diario
		cout << endl << endl;

	}

	catch (exception * e)
	{
		cout << e->what() << endl;
	}


	try {
		cout << "DIA " << diaRandom << "/" << mes << "/" << anio << endl << endl;
		Logger::logger.PromTipoUsuario(mes, diaRandom, diaRandom, 2020, 1);      //promedio segun los usuarios basic diario
		cout << endl << endl;

	}
	catch (exception * e)
	{
		cout << e->what() << endl;
	}


	try {
		cout << "DIA " << diaRandom << "/" << mes << "/" << anio << endl << endl;
		Logger::logger.PromTipoUsuario(mes, diaRandom, diaRandom, 2020, 2);      //promedio segun los usuarios premium diario
		cout << endl << endl;
	}
	catch (exception * e)
	{
		cout << e->what() << endl;
	}


	try {
		cout << "PERIODO " << dia1 << "/" << mes << "/" << anio << "--" << dia2 << "/" << mes << "/" << anio << endl << endl;
		Logger::logger.PromUsuarioEspecifico(mes, dia1, dia2, 2020, Logger::logger.getNombreRandom());      //promedio segun usuario random
		cout << endl << endl;

	}
	catch (exception * e)
	{
		cout << e->what() << endl;
	}


	try {
		cout << "DIA " << diaRandom << "/" << mes << "/" << anio << endl << endl;
		Logger::logger.PromUsuarioEspecifico(mes, diaRandom, diaRandom, 2020, Logger::logger.getNombreRandom());      //lo mismo pero diario
		cout << endl << endl;

	}
	catch (exception * e)
	{
		cout << e->what() << endl;
	}


	try {
		Logger::logger.MasJugados(mes, dia1, dia2, 2020);
	}
	catch (exception * e)
	{
		cout << e->what() << endl;
	}


	try {

		Logger::logger.MasVisto(mes, dia1, dia2, 2020);
	}
	catch (exception * e)
	{
		cout << e->what() << endl;
	}



	try {
		Logger::logger.MasEscuchados(mes, dia1, dia2, 2020);
	}
	catch (exception * e)
	{
		cout << e->what() << endl;
	}

	delete Labflix;

	system("pause");
	return 0;
}