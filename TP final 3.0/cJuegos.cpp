#include "cJuegos.h"

cJuegos::cJuegos(int duracion,int nivel, eJuegos juego, string nombre, bool mayorEdad, tipoServicio tipoS, vector<string> paisesProhibidos) :cService(duracion,nombre, mayorEdad, tipoS, paisesProhibidos)
{
	this->niveles = nivel;
	this->catJuegos = juego;
};

cJuegos::~cJuegos()
{
}

void cJuegos::GuardarPartida(cUsuario* user,int nivelactual)
{
	int i;
	for ( i = 0;i < user->juegos.size();i++)
	{
		if (user->juegos[i].compare(getNombre()) == 0)
		{
			user->niveles[i] = nivelactual;
			break;
		}
	} if (i == user->juegos.size())
	{
		user->niveles.push_back(nivelactual);
		user->juegos.push_back(getNombre());
	}

}
void cJuegos::Iniciar(cUsuario* user)
{	
	cout << "Que comience el juego" << endl;
	int i,nivelDelUsurioInicial;
	cout << "Su nivel actual es " << getNivelUser(user) << endl;
	

	cout << "Record level?" << '\n' << "0) Si 1) No" << endl << endl;    // se consulta antes de iniciar la partida si la quiere grabar
	srand(time(NULL));
	int opcion = rand() % 2;
	if (opcion == 0)
		Record();
	else return;
}

void cJuegos::Record()
{
	cout << "Starting recording..." << endl;
}


void cJuegos::Pausar(int segundos)
{
	cService::Pausar(segundos);
}


string cJuegos::getCategoria()
{
	if (catJuegos == 0)
		return "accion";
	else if (catJuegos == 1)
		return "estrategia";
	else if (catJuegos == 2)
		return "aventura";
	else if (catJuegos == 3)
		return "ninios";
}

void cJuegos::Apagar(cUsuario* user)
{
	int n = getNivelUser(user);
	srand(time(NULL));

	cService::Apagar(user);
	cout << "Desea guardar la partida? 1=si, 0=no" << endl;
	
	int opcion = 1;//rand() % (2);
	if (opcion == 1)                                          // (maximum_number + 1 - minimum_number)) + minimum_number;/ niveles+1-n))+n-1); 
		GuardarPartida(user,(rand() %(niveles + 1 - n)) + n );     //RANDOM NIVEL: SE ELIJE UN NIVEL ENTRE EL ULTIMO ALCANZADO Y EL TOTAL DE LOS NIVELES DEL JUEGO
	else if (opcion == 2)
		return;

}

int cJuegos::getNivelUser(cUsuario* user)
{
	int nivelDelUsurioInicial, i;
	for (i = 0;i < user->juegos.size();i++)
	{
		if (user->juegos[i].compare(getNombre()) == 0)
		{
			nivelDelUsurioInicial = user->niveles[i];
			return nivelDelUsurioInicial;
		}
	}
	if (i == user->juegos.size())
		return 1;

}



