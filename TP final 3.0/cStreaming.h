#pragma once
#include <iostream>
#include <iomanip>
#include "stdlib.h"
#include <string>
#include "cListaT.h"
#include "Logger.h"
#include "cService.h"
#include "cUsuario.h"
#include "time.h"
#include <random>

using namespace std;

class cStreaming
{
	cListaT<cService> Servicios;
	cListaT<cUsuario> Usuarios;
	string nombre;

public:
	cStreaming(string nombre);
	~cStreaming();
	void AgregarService(cService* algo);
	void AgregarUsuario(cUsuario* user);
	bool Loguearse(string username, string password);
	void Explorar(cUsuario* user, int tipoS);                           //muestra el contenido al usuario
	void Simulacion(int pos,int pos2,int dia,Mes mes,int anio);                                     //conecta 1 usuario y inicia un servicio al azar creando log
	void Listarnovedades(int serv);    //solo se implementa si el usuario es free, le muestra las novedades

};



//inline void print(int tipoS) {
//	switch (tipoS) {
//	case 0: cout << "juegos"; break;
//	case 1: cout << "peliculas"; break;
//	case 2: cout << "musica"; break;
//	}
//	
//}

//typedef enum {juegos,peliculas,musica} tipoServicio;