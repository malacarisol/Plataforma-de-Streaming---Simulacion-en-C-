#include <iostream>
#include "stdlib.h"
#include <string>
#include "cListaT.h"
#include "Logger.h"
#include "cService.h"
#include "cUsuario.h"
#include "time.h"
#include <random>

using namespace std;

class cJuegos;
class cPeliculas;
class cMusica;

class cStreaming
{
	cListaT<cService>* Servicios;
	cListaT<cUsuario>* Usuarios;
	string nombre;

	static string masEscuchados;
	static string masVistas;
	static string masJugados;

public:
	cStreaming(string nombre, cListaT<cService> ListaServicios, cListaT<cUsuario> ListaUsuarios);
	~cStreaming();
	bool Loguearse(string username, string password);
	void Explorar(cUsuario* user, tipoServicio tipoS);                 //muestra el contenido al usuario
	void Simulacion();                                             //conecta usuarios y inicia un servicio al azar creando logs
	void Listarnovedades(tipoServicio serv);                 //solo se implementa si el usuario es free, le muestra las novedades

};




