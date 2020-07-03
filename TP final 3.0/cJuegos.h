#pragma once
#include "cService.h"
#include <iostream>

//ERROR: CLASS TYPE REDEFINITION


class cJuegos : public cService
{
	int nivel;
	eJuegos catJuegos;
	//enum class eJuegos { accion, puzzle, aventura, azar, multijugadores, estrategia };

public:
	cJuegos(int nivel, eJuegos juego, string nombre, bool mayorEdad, tipoServicio tipoS,vector<string> paisesProhibidos);
	~cJuegos();
	void GuardarPartida(int nivelactual);                                    //se guarda el nivel actual
	void Iniciar();
	void Apagar();

	friend ostream& operator<<(ostream& out, cJuegos& m);
};
