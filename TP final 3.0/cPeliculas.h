#pragma once
#include "cService.h"
#include <iostream>


class cPeliculas : public cService
{
	int duracion;//minutos
	int tiempo;
	ePeliculas peli;
public:
	cPeliculas(int duracion, ePeliculas peli, string nombre, bool mayorEdad, tipoServicio tipoS, vector<string> paisesProhibidos);
	~cPeliculas();
	void Record();
	void Fastforward();
	void Backward();
	void Iniciar();
	void Pausar(int segundos);
	void Apagar();
	friend ostream& operator<<(ostream& out,cPeliculas& m);
	
};
