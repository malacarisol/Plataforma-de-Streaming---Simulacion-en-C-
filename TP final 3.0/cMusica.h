#pragma once
#include "iostream"
#include "cService.h"

class cMusica : public cService
{
	int duracion;
	eCategoria categoria;
public:
	cMusica(int duracion,eCategoria categoria, string nombre, bool mayorEdad, tipoServicio tipoS, vector<string> paisesProhibidos);
	~cMusica();
	void Record();
	void Fastforward();
	void Backward();
	void Iniciar();
	void Pausar(int segundos);
	void Apagar();
	void Descargar();
};

