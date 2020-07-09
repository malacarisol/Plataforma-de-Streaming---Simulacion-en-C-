#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include "cService.h"
#include <vector>
#include <ctime>

using namespace std;

typedef enum { freee , basic, premium } eTipoUsuario;

class cUsuario
{
private:	
	int edad;
	string usuario;
	string hashpassword;
	bool conectado;
	const string pais;
	const string apellido;
	string nombre;
	bool anuncios;
	int cuota;
	int  tiempoLimite;
	vector<string> descargas;
	vector<string> juegos;
	vector<int> niveles;
	vector<string> favoritos;
public:
	friend class cService;
	friend class cJuegos;
	cUsuario(int edad, string usuario, string hashpassword, bool conectado, string pais, string apellido, string nombre, eTipoUsuario tipo);
	~cUsuario();
	eTipoUsuario tipo;
	void setCuota(eTipoUsuario tipo);
	string getPassword();
	int getTipo();
	string getPais();                 //Para acceder al nombre de usuario desde Streaming y asi checkear password
	string getNombre();            //GetNombre es generico para la listaT- buscar(); asi nos aseguramos que solo haya 1 username por usuario, no hay repeticiones
	void getanuncios();
	int getedad();


};
