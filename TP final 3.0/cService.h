#pragma once
#include "iostream"

#include "string"
#include <vector>

//#include "Log.h"
//static enum class tipoServicio
using namespace std;

enum tipoServicio {juegos,peliculas,musica};

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
	void Descargar(cUsuario* user1, string nombre);
	bool AgregarFavoritos(cUsuario* user1, string nombre);
	bool IsProhibidoPais(string pais);// retorna true si el pais pasado x parametro no es prohibido del servicio
	string getNombre() { return nombre; };
	tipoServicio getTipo() { return tipoS; };
};

