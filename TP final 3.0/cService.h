#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "cUsuario.h"


using namespace std;

typedef enum { enero = 1, febrero = 2, marzo = 3, abril = 4, mayo = 5, junio = 6, julio = 7, agosto = 8, septiembre = 9, octubre = 10, noviembre = 11, diciembre = 12 } Mes;
typedef enum {juegos,peliculas,musica} tipoServicio;
typedef enum { pop, rock, cumbia } eMusica;
typedef enum {terror, cienciaFiccion, comedia,infantil} ePeliculas;
typedef enum { accion, estrategia,aventura,  ninios } eJuegos ;

class cUsuario;

class cService
{
string nombre;                                  //publico para acceder desde las hijas (desde juegos)
	bool mayorEdad;                             //Si el servicio es apto para todo publico esto es falso sino es verdadero
	tipoServicio tipoS;
	int duracion;
public:	
	
	int TiempoActual;
	vector<string> paisesprohibidos;
	cService(int tiempoDuracion,string nombre, bool mayorEdad, tipoServicio tipoS, vector<string> paisesProhibidos);
	virtual ~cService();
	virtual void Iniciar(cUsuario* user) ;// A revisar
	virtual void Pausar(int segundos);
	virtual void Apagar(cUsuario* user);
	bool MayorEdad();
	void Descargar(cUsuario *nombre1, string nombre);
	void AgregarFavoritos(cUsuario *nombre2, string nombre);
	bool IsProhibidoPais(string pais);                      // retorna true si el pais pasado x parametro no es prohibido del servicio
	string getNombre();
	int getTipo();
	void setNombre(string nombre);
	int getTiempoActual();
	int getduracion();
};


ostream& operator<<(ostream &out, cService*);


