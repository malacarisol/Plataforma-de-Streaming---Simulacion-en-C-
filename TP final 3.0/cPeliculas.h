#pragma once
#include "cService.h"
#include <iostream>
#include "time.h"

class cPeliculas : public cService
{
	ePeliculas peli;
public:
	cPeliculas(int duracion, ePeliculas peli, string nombre, bool mayorEdad, tipoServicio tipoS, vector<string> paisesProhibidos);
	~cPeliculas();
	void Fastforward();
	void Backward();
	void Iniciar(cUsuario* user);
	void Pausar(int segundos);
	void Apagar(cUsuario* user);
	string getCategoria();
};

