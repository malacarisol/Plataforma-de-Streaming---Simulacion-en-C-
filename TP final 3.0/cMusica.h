#pragma once
#include "iostream"
#include "cService.h"
#include "time.h"
class cMusica : public cService
{
	eMusica categoria;
public:
	cMusica(int duracion,eMusica categoria, string nombre, tipoServicio tipoS, vector<string> paisesProhibidos, bool mayorEdad = false);
	~cMusica();
	void Fastforward();
	void Backward();
	void Iniciar(cUsuario* user);
	void Pausar(int segundos);
	string getCategoria();
	void Apagar(cUsuario* user);
	void Descargar();
	
};

