#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include "cService.h"
#include <vector>
#include <ctime>

using namespace std;

typedef enum { gratis , basic, premium } eTipoUsuario;  //CAMBIAMOS FREE A GRATIS POR PROBLEMAS DE REDEFINICION

class cUsuario
{
	private:
		//friend class cService;
	int edad;
	string usuario;
	string hashpassword;
	bool conectado;

	const string pais;
	const string apellido;
	const string nombre;

	bool anuncios;
	int cuota;
	time_t tiempoON;//registra la hora cuando ingresa a un servicio
	time_t tiempoOFF;//registra la hora cuando sale del mismo
	//double difftime(time_t time2, time_t time1);
	int  tiempoLimite;
	
	vector<string> descargas;
	vector<string> favoritos;
public:
	
	eTipoUsuario tipo;

	//void Play(cService *serv);
	//eTipoUsuario col = eTipoUsuario::basic;

	void setCuota(int c);
	time_t offline();
	time_t online();

	string getPassword();
	string getTipo() {
		return to_string (tipo);
	};

	string getPais()const { return pais; };
	string getUsername()const { return usuario; };     //Para acceder al nombre de usuario desde Streaming y asi checkear password
	string getNombre() const { return nombre; };

	void getanuncios() {
		if (anuncios != true)
			anuncios = true;
	};

	cUsuario(int edad, string usuario, string hashpassword, bool conectado, string pais, string apellido, string nombre, eTipoUsuario tipo);
	~cUsuario();
};
