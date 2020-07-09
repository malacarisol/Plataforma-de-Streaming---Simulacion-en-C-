#pragma once
#include "cService.h"
#include <iostream>
#include <time.h>


class cJuegos : public cService
{
	int niveles;      //cantida de niveles en el juego
	eJuegos catJuegos;
public:
	cJuegos(int duracion, int niveles, eJuegos juego, string nombre, bool mayorEdad, tipoServicio tipoS,vector<string> paisesProhibidos);
	~cJuegos();
	void GuardarPartida(cUsuario* user,int nivelactual);                                    //se guarda el nivel actual
	void Iniciar(cUsuario* user);
	void Pausar(int segundos);
	string getCategoria();
	void Apagar(cUsuario* user);        
	int getNivelUser(cUsuario* user);
	void Record();
};
