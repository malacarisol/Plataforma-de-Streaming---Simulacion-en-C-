#include "cJuegos.h"

cJuegos::cJuegos(int nivel, eJuegos juego, string nombre, bool mayorEdad, tipoServicio tipoS, vector<string> paisesProhibidos) :cService(nombre, mayorEdad, tipoS, paisesProhibidos)
{
	this->nivel = nivel;
	this->catJuegos = juego;
};

cJuegos::~cJuegos()
{
}

void cJuegos::GuardarPartida(int nivelactual)
{
	this->nivel = nivelactual;
}

void cJuegos::Iniciar()
{
	cout << "Que comience el juego" << endl;
}


void cJuegos::Apagar()
{
	
	cout << "Desea guardar la partida? 1=si, 2=no" << endl;
	srand(time(NULL));
	int opcion = rand() % (2 - 1);
	if (opcion == 1)
		GuardarPartida(rand() % 20);       //hasta 20 niveles en todos los juegos
	else if (opcion == 2)
		return;

}



ostream& operator<<(ostream& out, cJuegos& m)
{
	
	//out << (cService&)m;   //ERROR:: bynary << no operator found which tackes a right hand opeator of type cservice
	out << m.getNombre() << endl;
	return out;
}
