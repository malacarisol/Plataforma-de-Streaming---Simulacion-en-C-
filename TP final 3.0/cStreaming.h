#include <iostream>
#include "stdlib.h"
#include "string"
#include "cListaT.h"
#include "cService.h"
#include "cUsuario.h"
#include "time.h"
#include <random>
using namespace std;

class cJuegos;
class cPeliculas;
class cMusica;

class cStreaming
{
	cListaT<cService>* ListaServicios;
	cListaT<cUsuario>* ListaUsuarios;
	string nombre;
	Logger historial;
	static string masEscuchados;
	static string masVistas;
	static string masJugados;

public:
	cStreaming(string nombre, cListaT<cService> ListaServicios,cListaT<cUsuario> ListaUsuarios);
	~cStreaming();
	bool Loguearse(string username, string password);
	void Explorar(cUsuario* user, tipoServicio tipoS);//muestra el contenido al usuario
	void Simulacion();//conecta usuarios y inicia un servicio al azar creando logs
	void Listarnovedades(tipoServicio serv);//solo se implementa si el usuario es free, le muestra las novedades

};

void cStreaming::Simulacion()
{
	if (ListaUsuarios == NULL && ListaServicios == NULL)//no estamos seguras, fue la mejor forma que encontramos de comprobar que existan las listas y tengan contenido
		throw new exception("Error al cargar el servicio");
	{
		srand((unsigned)time(NULL));
		Mes mes = static_cast<Mes>(rand() % diciembre);
		Dia dia = static_cast<Dia>(rand() % domingo);

		int pos = rand() % ListaUsuarios->getCA();
		int pos2 = rand() % ListaServicios->getCA();

		cUsuario* user = ListaUsuarios->get(pos);//Elige un usuario al azar

		if (Loguearse(user->getUsername(), user->getPassword()))//Checkea password
		{
			user->online();
			cService* serv = ListaServicios->get(pos2);//Elige un servicio al azar
			if (user->getTipo() == 0)//Si el tipo de User es Free, se listan las novedades
			{
				Listarnovedades(serv->getTipo());
				user->anuncios();//se prenden los anuncios para los usuarios free
			}
			Explorar(user,serv->getTipo());//muestra el servicio segun el tipo de usuario y pais
			user->Play(*serv);
			serv->Iniciar();
			serv->Apagar();
			user->offline;
			int time=rand()%10;
			static Log *log=new Log(user->getUsername, serv->getNombre, time, user->getTipo, serv->getTipo, mes, dia);//Log(string username, string nombreServicio, int tiempo, eTipoUsuario tipoU, tipoServicio tipoS, Mes mes, Dia dia);
			historial.agregar(log);
		}

	}
	
}



void cStreaming::Listarnovedades(tipoServicio serv)
{

	srand((unsigned)time(NULL));//agarro dos fechas al azar 
	Mes mes = static_cast<Mes>(rand() % diciembre);
	Dia dia = static_cast<Dia>(rand() % domingo);
	Mes mes2 = static_cast<Mes>(rand() % diciembre);
	Dia dia2 = static_cast<Dia>(rand() % domingo);

	//enum tipoServicio { juegos, peliculas, musica };
	if(serv==0)
	static string lista = cStreaming::historial.MasJugados(mes, dia, mes2, dia2);
	if(serv==1)
	static string lista = cStreaming::historial.MasVisto(mes, dia, mes2, dia2);
	if(serv==2)
	static string lista = cStreaming::historial.MasEscuchados(mes, dia, mes2, dia2);


} //	Log(string username, string nombreServicio, int tiempo, eTipoUsuario tipoU, tipoServicio tipoS, Mes mes, Dia dia);

void cStreaming::Explorar(cUsuario* user, tipoServicio tipoS)//es un ejemplo, la idea es que pueda explorar con mas filtros
{
	
	if (user->getTipo == 0)// free muestra menos contenido
	{
		for (int i = 0;i <( ListaServicios->getCA()/10);i++)//la division limita los servicios mostrados
		{
			cService* serv = ListaServicios->get(i);
			if(serv->getTipo==tipoS&&!serv->paisesprohibidos(user->getPais()))//si es el tipo de servicio que quiere explorar y si el pais del usuario no se encuentra entre los prohibidos
			cout<<serv->getNombre<<endl; //Lista solo los nombres disponibles
			
		}
	}
	if (user->getTipo==1)//basic muestra un poco mas de contenido
		for (int i = 0;i < (ListaServicios->getCA()/5);i++)//la division limita los servicios mostrados
		{
			cService* serv = ListaServicios->get(i);
			if(serv->getTipo==tipoS&&!serv->paisesprohibidos(user->getPais()))//si es el tipo de servicio que quiere explorar y si el pais del usuario no se encuentra entre los prohibidos
			cout<<serv->getNombre<<endl; //Lista solo los nombres disponibles
			
		}

	if (user->getTipo == 2)//muestra todo el contenido
	{
		for (int i = 0;i < ListaServicios->getCA;i++)
		{
			cService* serv = ListaServicios->get(i);
			if (serv->getTipo == tipoS && !serv->paisesprohibidos(user->getPais()))//si es el tipo de servicio que quiere explorar y si el pais del usuario no se encuentra entre los prohibidos
				cout << serv->getNombre << endl; //Lista solo los nombres disponibles
		}
		
	}
}