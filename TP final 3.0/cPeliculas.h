#pragma once
#include "cService.h"



class cPeliculas : public cService
{
	int duracion;//minutos
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
	
	
};
