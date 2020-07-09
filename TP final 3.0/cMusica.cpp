#include "cMusica.h"


cMusica::cMusica(int duracion, eMusica categoria, string nombre, tipoServicio tipoS, vector<string> paisesProhibidos, bool mayorEdad) :cService(duracion, nombre, mayorEdad, tipoS, paisesProhibidos)
{
	//this->duracion = duracion;
	this->categoria = categoria;
	
};

cMusica::~cMusica()
{
}


void cMusica::Fastforward()
{
	this->TiempoActual += 15;
	cout << "+15...." << endl;
}

void cMusica::Backward()
{
	this->TiempoActual -= 15;
	cout << "-15...." << endl;
}

void cMusica::Iniciar(cUsuario* user)
{
	cout << "Cancion iniciada" << endl<<endl;

}

void cMusica::Pausar(int segundos)
{
	cService::Pausar(segundos);
	cout << "0) Backward 1) FastForward" << endl;
	srand(time(NULL));
	int opcion = rand() % 2;
	if (opcion == 0)
		Backward();
	else if (opcion == 1)
		Fastforward();
}


string cMusica::getCategoria()
{
	if (categoria == 0)
		return "pop";
	else if (categoria == 1)
		return "rock";
	else if (categoria == 2)
		return "cumbia";
}

void cMusica::Apagar(cUsuario* user)
{
	cService::Apagar(user);
}

void cMusica::Descargar()
{
	cout << "Descargando.." << endl;
}

//int cMusica::getcategoria()
//{
//	return categoria;
//}
