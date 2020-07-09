#include "cStreaming.h"
#include "cService.h"
#include "Log.h"
#include <ctime>
#include "cPeliculas.h"
#include "cJuegos.h"
#include "cMusica.h"
#include <exception>

using namespace std;


cStreaming::cStreaming(string nombre)
{	
	this->nombre = nombre;
};


cStreaming::~cStreaming()
{
}

void cStreaming::AgregarService(cService* algo)
{
	Servicios + algo;         //sobrecarga +
}

void cStreaming::AgregarUsuario(cUsuario* user)
{
	Usuarios + user;
}

bool cStreaming::Loguearse(string username, string password)
{
	cUsuario* aux= Usuarios.Buscar(username);
	if (aux != NULL && aux->getPassword().compare(password)==0)
	{
		return true;
	}
	throw new exception("Wrong password :(");
	
	return false;
}


void cStreaming::Listarnovedades(int serv)
{

	srand(time(NULL));
	int cont = 0;

	cout<<"----------------NOVEDADES------------------"<<endl<<endl;

	for (int i = 0;i < Servicios.getCA();i++)            //Se listan las primeras posiciones encontradas de el tipo de servicio seleccionado. Esas son las novedades
	{
		if (Servicios[i]->getTipo() == serv)
		{
			cout << Servicios[i]->getNombre() << endl;
			cont++;
		}if (cont == 5)break;
	}
	cout << endl << endl;
	
}


void cStreaming::Explorar(cUsuario* user, int tipoS)
{
	int seguro = 0;           //El seguro es para que se pare el servicio si el pais del uuario coincide con la lista de paisesprohbidos.
	int contFree = 0;
	int contBasic = 0;

	for (unsigned int i = 0;i < Servicios.getCA();i++)
	{
		if (Servicios[i]->getTipo() == tipoS && !Servicios[i]->IsProhibidoPais(user->getPais()) && user->getedad() > 18)  //si es el tipo de servicio que quiere explorar y si el pais del usuario no se encuentra entre los prohibidos
		{

			cout << left << Servicios[i];
			cout << setw(40);
			cout << right << "CATEGORIA:";
			if (Servicios[i]->getTipo() == juegos) {
				cJuegos* juego = dynamic_cast<cJuegos*>(Servicios[i]);
				cout << juego->getCategoria() << endl;
			}
			else if (Servicios[i]->getTipo() == peliculas) {
				cPeliculas* pelicula = dynamic_cast<cPeliculas*>(Servicios[i]);
				cout << pelicula->getCategoria() << endl;
			}
			else if (Servicios[i]->getTipo() == musica) {
				cMusica* cancion = dynamic_cast<cMusica*>(Servicios[i]);
				cout << cancion->getCategoria() << endl;
			}
			if (user->getTipo() == 0)
				contFree++;
			else if (user->getTipo() == 1)
				contBasic++;
			seguro++;
		}                                                //Lista solo los nombres disponibles
		else if (Servicios[i]->getTipo() == tipoS && !Servicios[i]->IsProhibidoPais(user->getPais()) && !Servicios[i]->MayorEdad() && user->getedad() < 18)
		{
			cout << left << Servicios[i];
			cout << setw(40);
			cout << right << "CATEGORIA:";
			if (Servicios[i]->getTipo() == juegos) {
				cJuegos* juego = dynamic_cast<cJuegos*>(Servicios[i]);
				cout << juego->getCategoria() << endl;
			}
			else if (Servicios[i]->getTipo() == peliculas) {
				cPeliculas* pelicula = dynamic_cast<cPeliculas*>(Servicios[i]);
				cout << pelicula->getCategoria() << endl;
			}
			else if (Servicios[i]->getTipo() == musica) {
				cMusica* cancion = dynamic_cast<cMusica*>(Servicios[i]);
				cout << cancion->getCategoria() << endl;
			}
			if (user->getTipo() == 0)
				contFree++;
			else if (user->getTipo() == 1)
				contBasic++;
			seguro++;
		}

		if (contFree == 8)               //FREE muestra menos contenido
			break;
		else if (contBasic == 20)
			break;
	}
	if (seguro == 0)
		throw new exception("Este servicio no se encuentra disponible para su pais");
	//	cout << "La categoria ";
	//print(tipoS);
	//	cout<< " no se encuentra disponible para su pais" << endl;

}
void cStreaming::Simulacion(int pos,int pos2, int dia, Mes mes, int anio)
{
		srand(time(NULL));
		
		cUsuario* user = Usuarios.get(pos);                         //Elige un usuario al azar
		cService* serv = Servicios.get(pos2);                   //Elige un servicio al azar
	
		try {
			 Loguearse(user->getNombre(), user->getPassword());             //Checkea password
			 system("color 0B");
	
			if (serv->getTipo() == 0)
				cout << "················ G A M E S ··················"<<endl<<endl;
			if (serv->getTipo() == 1)
				cout << "··············· M O V I E S ·················"<<endl<<endl;
			if (serv->getTipo() == 2)
				cout << "················ M U S I C ··················"<<endl<<endl;


			if (user->getTipo() == 0)                  
			{ 
				Listarnovedades(serv->getTipo());                 //Si el tipo de User es Free, se listan las novedades.
				user->getanuncios();                             //se prenden los anuncios para los usuarios free
			}

			Explorar(user, serv->getTipo());                   //muestra el servicio segun el tipo de usuario, pais y edad

			serv->Iniciar(user);
			cout << endl << endl;

			serv->Pausar(rand() % serv->getduracion());                        //se pausa dento del tiempo de duracion del servicio

			serv->Apagar(user);

			cout << "Desea agregar a favoritos?" << endl<<endl;

			srand(time(NULL));

			int opcion = rand() %(2);

			if (opcion == 1)
			{
				serv->AgregarFavoritos(user, serv->getNombre());          //si sale opcion 0 no agrega a favoritos!!!
			}                                                        

			if (user->getTipo() == 2 && (serv->getTipo()==musica||serv->getTipo()==peliculas))                             //solo los PREMIUM pueden descargar (2==enum==PREMIUM) 
			{
				cout << "Desea agregar a descargas?" << endl<<endl;
				srand(time(NULL));

				int opcion = rand() % (2 );                    //la opcion de descarga es random no va a implementarse siempre descargar !!!
				if (opcion == 1)
				{
					serv->Descargar(user, serv->getNombre());
				}                                                          //si sale opcion 0 no agrega a descargas
			}

			int tiemppo = serv->getTiempoActual();                      

			Logger::logger.agregar(new Log(user->getNombre(), serv->getNombre(), tiemppo, user->getTipo(), serv->getTipo(), mes, dia, anio));
		}
		catch (exception * e)
		{
			cout << e->what() << endl;
		}
		user = NULL;
		serv = NULL;
	
};
