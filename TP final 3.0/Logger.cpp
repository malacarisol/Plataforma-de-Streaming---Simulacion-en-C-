#include "Logger.h"
using namespace std;


Logger::Logger()
{

}
int Logger::ca = 0;
int Logger::tam = nmax;




Logger::~Logger()
{

}

bool Logger::agregar(Log *probando)
{
	if (ca < tam)
	{
		historial[ca] = probando;
		return true;          //checkear
	}

	else return false;
}

time_t Logger::tconexion(string user)//METODO NO STATIC CON LISTA STATIC
{
	time_t time = 0;
	for (int i =0;i<ca;i++)
	{
		if (Logger::historial[i]->getnombre().compare(user) == 0)
			time = time + Logger::historial[i]->gettiempo();
	}
	return static_cast<long int> (time);

}

string Logger::MasVisto(Mes desde, Dia desde_, Mes hasta, Dia hasta_,int anio_)
{
	long int max=0;
	int a = 0;

	for (int i = 0;i < ca;i++)
	{
		if (historial[i]->getTipoServicio().compare("peliculas")==0&&historial[i]->getdia()>=desde_&&historial[i]->getdia()<=hasta_&&historial[i]->getmes()>=desde&&historial[i]->getmes()<=hasta&&historial[i]->getanio()==anio_)    //encuenctra el tiempo de la primer pelicula d ela lista
		{
			max = static_cast<long int> (historial[i]->gettiempo());
			break;
		}
	}

	for (int i=0;i<ca;i++)//compara los tiempos de las peliculas con el primero encontrado 
	{
		if ((historial[i]->getTipoServicio().compare("peliculas")==0&&historial[i]->getdia()>=desde_&&historial[i]->getdia()<=hasta_&&historial[i]->getmes()>=desde&&historial[i]->getmes()<=hasta&&historial[i]->getanio()==anio_))
		{
			long int t = static_cast<long int> (historial[i]->gettiempo());     //Estamos viendo cual fue la pelicula mas vista
			if (t > max)         
			{	max = t;
				a=i;
			}

		}
	}
	return historial[a]->getnombreS();  //devolvemos nombre pelicula
}

string Logger::MasJugados(Mes desde, Dia desde_, Mes hasta, Dia hasta_,int anio_)
{
	long int max = 0;
	int a = 0;

	for (int i = 0;i < ca;i++)
	{
		if (historial[i]->getTipoServicio().compare("juegos")==0&&historial[i]->getdia()>=desde_&&historial[i]->getdia()<=hasta_&&historial[i]->getmes()>=desde&&historial[i]->getmes()<=hasta&&historial[i]->getanio()==anio_)   //encuenctra el tiempo de la primer pelicula d ela lista
		{
			max = static_cast<long int> (historial[i]->gettiempo());
			break;
		}
	}

	for (int i = 0;i < ca;i++)//compara los tiempos de las peliculas con el primero encontrado 
	{
		if (historial[i]->getTipoServicio().compare("juegos")==0&&historial[i]->getdia()>=desde_&&historial[i]->getdia()<=hasta_&&historial[i]->getmes()>=desde&&historial[i]->getmes()<=hasta&&historial[i]->getanio()==anio_) 
		{
			long int t = static_cast<long int> (historial[i]->gettiempo());     //Estamos viendo cual fue la pelicula mas vista
			if (t > max)
			{
				max = t;
				a = i;
			}

		}
	}
	return historial[a]->getnombreS();  //devolvemos nombre pelicula
}

string Logger::MasEscuchados(Mes desde, Dia desde_, Mes hasta, Dia hasta_,int anio_)
{
	long int max = 0;
	int a = 0;
	//for (int i = 0;i < ca;i++)
	//{
	//	if (log[i]->getTipoServicio == musica&&log[i]->getdia()>=static_cast<int>(desde_)&&log[i]->getdia()<= static_cast<int>(hasta_) &&log[i]->getmes()>= static_cast<int>(desde) &&log[i]->getmes()<= static_cast<int>(hasta) &&log[i]->getanio()==anio_)   //encuenctra el tiempo de la primer musica d ela lista
	//	{
	//		max = static_cast<long int> (log[i]->gettiempo());
	//		break;
	//	}
	//}

	for (int i = 0;i < ca;i++)//compara los tiempos de la musica con el primero encontrado 
	{
		if (historial[i]->getTipoServicio().compare("musica")==0&&historial[i]->getdia()>=desde_&&historial[i]->getdia()<=hasta_&&historial[i]->getmes()>=desde&&historial[i]->getmes()<=hasta&&historial[i]->getanio()==anio_)
		{
			long int t = static_cast<long int> (historial[i]->gettiempo());     //Estamos viendo cual fue la pelicula mas vista
			if (t > max)
			{
				max = t;
				a = i;
			}

		}
	}
	return historial[a]->getnombreS();  //devolvemos nombre musica
}

float Logger::PromedioUsuarios(Mes desde, Dia desde_, Mes hasta, Dia hasta_, int anio)
{
	long int acum = 0;              //acumula tiempo de uso de usuarios
	int cont = 0;

	for (int i = 0;i < ca;i++)
	{
		if (historial[i]->getdia() >= desde_ && historial[i]->getdia() <= hasta_ && historial[i]->getmes() >= desde && historial[i]->getmes() <= hasta && historial[i]->getanio() == anio)   //encuenctra el tiempo de la primer musica d ela lista
		{
			acum = acum + static_cast<long int> (historial[i]->gettiempo());
			cont++;
			break;
		}
	}
	if (cont == 0)
		throw new exception("DIV_ZERO");

	return acum / cont;

}
