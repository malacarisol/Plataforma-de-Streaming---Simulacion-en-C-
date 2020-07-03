#include "cStreaming.h"
#include "cService.h"
#include "Log.h"
#include <ctime>
//#include "main.cpp"

using namespace std;

cStreaming::cStreaming(string nombre)
{	
	this->nombre = nombre;
};

string cStreaming::masEscuchados = "";
string cStreaming::masJugados = "";
string cStreaming::masVistas = "";//inicializamos

cStreaming::~cStreaming()
{
}

void cStreaming::AgregarService(cService* algo)
{
	Servicios.Agregar(algo);
}

void cStreaming::AgregarUsuario(cUsuario* user)
{
	Usuarios.Agregar(user);
}

bool cStreaming::Loguearse(string username, string password)
{
	cUsuario* aux= Usuarios.Buscar(username);
	if (aux != NULL && aux->getPassword() == password)
	{
		return true;
	}
	throw new exception("Wrong password :(");
	
	return false;
}
void cStreaming::Listarnovedades(string serv)
{

	srand((unsigned)time(NULL));             //agarro dos fechas al azar  
	Mes mes = static_cast<Mes>(rand() % diciembre);
	Dia dia = static_cast<Dia>(rand() % domingo);
	Mes mes2 = static_cast<Mes>(rand() % diciembre);
	Dia dia2 = static_cast<Dia>(rand() % domingo);
	int anio = rand() % 2000 + 2021;
	enum tipoServicio { juegos, peliculas, musica };
	if(serv.compare("juegos"))
	static string lista = Logger::MasJugados(mes, dia, mes2, dia2,anio);
	if(serv.compare("peliculas"))
	static string lista = Logger::MasVisto(mes, dia, mes2, dia2,anio);
	if(serv.compare("musica"))
	static string lista = Logger::MasEscuchados(mes, dia, mes2, dia2,anio);
}

void cStreaming::Explorar(cUsuario* user, string tipoS)                              //es un ejemplo, la idea es que pueda explorar con mas filtros
{
	
	if (user->getTipo().compare( "gratis")==0)                                                         // free muestra menos contenido
	{
		for (unsigned int i = 0;i < Servicios.getCA() ;i++)                                   //la division limita los servicios mostrados
		{

			cService* serv = Servicios.get(i);                             //El get de lista<t> devuelve un puntero tomando una posicion como referencia

			if (serv->getTipo().compare(tipoS)==0 && !serv->IsProhibidoPais(user->getPais()))                 //si es el tipo de servicio que quiere explorar y si el pais del usuario no se encuentra entre los prohibidos
				cout << serv->getNombre() << endl;                                                       //Lista solo los nombres disponibles

		}
	}
	else if (user->getTipo().compare("basic")==0)                                                     //basic muestra un poco mas de contenido
		for (unsigned int i = 0;i <Servicios.getCA();i++)                   //la division limita los servicios mostrados
		{
			cService* serv =Servicios.get(i);
			
			if(serv->getTipo().compare(tipoS)==0)
				if(!serv->IsProhibidoPais(user->getPais()))                //si es el tipo de servicio que quiere explorar y si el pais del usuario no se encuentra entre los prohibidos
			cout<<serv->getNombre()<<endl;                                    //Lista solo los nombres disponibles
			
		}
	
	else if (user->getTipo().compare("premium")==0)                                 //muestra todo el contenido
	{
		for (unsigned int i = 0;i < Servicios.getCA();i++)
		{
			cService* serv = Servicios.get(i);
			if (serv->getTipo().compare(tipoS)==0&& !serv->IsProhibidoPais(user->getPais()))                 //si es el tipo de servicio que quiere explorar y si el pais del usuario no se encuentra entre los prohibidos
				cout << serv->getNombre() << endl;                                     //Lista solo los nombres disponibles
		}
		
	}
}
void cStreaming::Simulacion()
{
	//if (Servicios == NULL && Usuarios == NULL) /////// CHECKKKKKK//// //Si el primero es NULL, la lista esta vacia. Si no, el streaming ya puede comenzar a correr

		//throw new exception("Error al cargar el servicio");
	
		srand(time(NULL));
		Mes mes = static_cast<Mes>(rand() % diciembre);
		Dia dia = static_cast<Dia>(rand() % domingo);
		int anio = rand() % 21 + 2000;

		unsigned int pos = rand() % Usuarios.getCA();
		unsigned int pos2 = rand() % Servicios.getCA();

		cUsuario* user = Usuarios.get(pos);                         //Elige un usuario al azar

		if (Loguearse(user->getUsername(),user->getPassword()))                          //Checkea password
		{
			time_t inicio = user->online();
			cService* serv = Servicios.get(pos2);                  //Elige un servicio al azar //LE SAQUE EL DYNAMIC CAST, INNECESARIO(QUIZAS NO) -S.
			if (user->getTipo().compare("gratis")==0)                                       //Si el tipo de User es Free, se listan las novedades
			{
				Listarnovedades(serv->getTipo());
				user->getanuncios();                             //se prenden los anuncios para los usuarios free
			}
			Explorar(user, serv->getTipo());                   //muestra el servicio segun el tipo de usuario y pais
			//user->Play(serv);
			serv->Iniciar();
			serv->Apagar();
			time_t fin = user->offline();
			double tiemppo = static_cast<double>(difftime(inicio, fin));
			
			Log* ptr = new Log(user->getUsername(), serv->getNombre(), tiemppo, user->getTipo(), serv->getTipo(), mes, dia, anio);
			Logger::agregar(ptr);  //AAAAAAAAAAAAAAAAAAAAAAAAAAa ERROR: MUST HAVE POINTER TO CLASS TYPE!!!!!!!
		}

		throw new exception("Error al cargar el servicio");
		//HAY ECEPCIONES EN LOS METODOS QUE LLAMAMOS CHECKEAR QUE LOS AGARRE EN EL MAIN 
		delete user;

	
};
