#include "cStreaming.h"
#include "cService.h"
#include <ctime>

cStreaming::cStreaming(string nombre, cListaT<cService> ListaServicios, cListaT<cUsuario> ListaUsuarios)
{
	this->nombre = nombre;
	this->ListaServicios = ListaServicios;
	this->ListaUsuarios = ListaUsuarios;
	
}

cStreaming::~cStreaming()
{
}

bool cStreaming::Loguearse(string username, string password)  /////TERMINAR
{
	return false;
}

void cStreaming::Simulacion()
{
	
	//if (ListaUsuarios == NULL && ListaServicios == NULL) /////// CHECKKKKKK//// //Si el primero es NULL, la lista esta vacia. Si no, el streaming ya puede comenzar a correr

		//throw new exception("Error al cargar el servicio");
	{
		srand((unsigned)time(NULL));
		Mes mes = static_cast<Mes>(rand() % diciembre);
		Dia dia = static_cast<Dia>(rand() % domingo);
		int anio = rand() % 21+ 2000;

		int pos = rand() % ListaUsuarios.getCA();
		int pos2 = rand() % ListaServicios.getCA();

		cUsuario* user = ListaUsuarios.get(pos);//Elige un usuario al azar

		if (Loguearse(user->getUsername(), user->getPassword()))//Checkea password
		{
			time_t inicio=user->online();
			cService* serv = ListaServicios.get(pos2);//Elige un servicio al azar
			if (user->getTipo() == 0)//Si el tipo de User es Free, se listan las novedades
			{
				Listarnovedades(serv->getTipo());
				user->getanuncios();//se prenden los anuncios para los usuarios free
			}
			Explorar(user,serv->getTipo());//muestra el servicio segun el tipo de usuario y pais
			//user->Play(serv);
			serv->Iniciar();
			serv->Apagar();
			time_t fin=user->offline();
			time_t time= difftime(inicio, fin);
			static Log *log=new Log(user->getUsername, serv->getNombre, time, user->getTipo, serv->getTipo, mes, dia,anio);
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


}

void cStreaming::Explorar(cUsuario* user, tipoServicio tipoS)                              //es un ejemplo, la idea es que pueda explorar con mas filtros
{
	
	if (user->getTipo == 0)                                                              // free muestra menos contenido
	{
		for (int i = 0;i <( ListaServicios.getCA()/3);i++)                                   //la division limita los servicios mostrados
		{
			
			cService* serv = ListaServicios.get(i);                             //El get de lista<t> devuelve un puntero tomando una posicion como referencia
				
			if(serv->getTipo()==tipoS&&!serv->paisesprohibidos(user->getPais()))                 //si es el tipo de servicio que quiere explorar y si el pais del usuario no se encuentra entre los prohibidos
			cout<<serv->getNombre()<<endl;                                                       //Lista solo los nombres disponibles
			
		}
	}
	if (user->getTipo==1)                                                     //basic muestra un poco mas de contenido
		for (int i = 0;i < (ListaServicios.getCA()/2);i++)                   //la division limita los servicios mostrados
		{
			cService* serv = ListaServicios.get(i);
			
			if(serv->getTipo()==tipoS)
				if(!serv->paisesprohibidos(user->getPais()))                //si es el tipo de servicio que quiere explorar y si el pais del usuario no se encuentra entre los prohibidos
			cout<<serv->getNombre<<endl;                                    //Lista solo los nombres disponibles
			
		}

	if (user->getTipo == 2)//muestra todo el contenido
	{
		for (int i = 0;i < ListaServicios.getCA();i++)
		{
			cService *serv = ListaServicios.get(i);
			if (serv->getTipo == tipoS && !serv->paisesprohibidos(user->getPais()))//si es el tipo de servicio que quiere explorar y si el pais del usuario no se encuentra entre los prohibidos
				cout << serv->getNombre() << endl; //Lista solo los nombres disponibles
		}
		
	}
}