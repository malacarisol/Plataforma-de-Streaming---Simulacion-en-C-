#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "cUsuario.h"
using namespace std;

typedef enum  {pop, rock, cumbia, reggaeton, reggae, softPop, ritmosUrbanos, metal, sleep, workOut, chill, electronica, jazz} eCategoria ;
typedef enum { enero = 1, febrero = 2, marzo = 3, abril = 4, mayo = 5, junio = 6, julio = 7, agosto = 8, septiembre = 9, octubre = 10, noviembre = 11, diciembre = 12 } Mes;
typedef enum { lunes = 1, martes = 2, miercoles = 3, jueves = 4, viernes = 5, sabado = 6, domingo = 7 } Dia;
typedef enum {juegos,peliculas,musica} tipoServicio;
typedef enum {terror, comedia, suspenso,  drama, romantica, cienciaFiccion, policial, infantil, clasica, musical} ePeliculas;
typedef enum { accion, puzzle, aventura, azar, multijugadores, estrategia } eJuegos ;
class cUsuario;
class cService
{
	string nombre;
	bool mayorEdad;
	tipoServicio tipoS;
	
public:	
	vector<string> paisesprohibidos;
	cService(string nombre, bool mayorEdad,tipoServicio tipoS, vector<string> paisesProhibidos);
	virtual ~cService();
	virtual void Iniciar() ;// A revisar
	virtual void Pausar(int segundos);
	virtual void Apagar() ;
	void Descargar(cUsuario *nombre1, string nombre);
	bool AgregarFavoritos(cUsuario *nombre2, string nombre);
	bool IsProhibidoPais(string pais);                            // retorna true si el pais pasado x parametro no es prohibido del servicio
	string getNombre() { return nombre; };
	string getTipo() { return to_string(tipoS); };
	void setNombre(string nombre) { this->nombre = nombre; };
	ostream& operator<<(ostream& out);
	istream& operator>>(istream& in);
};
