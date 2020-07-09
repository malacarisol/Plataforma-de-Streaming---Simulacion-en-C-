#include "Logger.h"
using namespace std;


Logger::Logger(int a)
{
	tam = a;
	historial = new Log * [tam];
	for (unsigned int i = 0; i < tam; i++)
	{
		historial[i] = NULL;
	}

	this->tam = tam;
	ca = 0;
};


Logger Logger::logger;


Logger::~Logger()
{
	if (historial != NULL)
	{
		for (unsigned int i = 0; i < ca; i++)
		{
			if (historial[i] != NULL)
				delete historial[i];
		}
		delete[] historial;
	}

}

bool Logger::agregar(Log *newlog)
{
	if (ca < (tam-1))
	{
		this->historial[ca++] = newlog;
		return true;          
	}

	else return false;
}


void Logger::MasVisto(Mes desde, int desde_,int hasta_,int anio_)
{
	int cont = 0;
	OrdenarHistorial();
	cout << "MAS VISTAS: ";
	cout << "PERIODO " << desde_ << "/" << desde << "/" << anio_ << "--" << hasta_ << "/" << desde << "/" << anio_ << endl << endl;
	                                         
	for (int i = 0;i < ca;i++)             
	{
		if (historial[i]->getTipoServicio() == 1 && historial[i]->getdia() >= desde_ && historial[i]->getdia() <= hasta_ && historial[i]->getmes() == desde&& historial[i]->getanio() == anio_)
		{
			while (i < ca - 1 && historial[i + 1]->getnombreS().compare(historial[i]->getnombreS()) == 0)
			{
				i++;      //Salteamos si son iguales los servicios
			} 
			cout << historial[i]->getnombreS() << endl;

			cont++;
		}
	}
	if (cont == 0)
		throw new exception("No se vieron peliculas en ese periodo ");

}

void Logger::MasJugados(Mes desde, int desde_, int hasta_, int anio_)
{
	int cont = 0;
	OrdenarHistorial();
	cout << "MAS JUGADOS: ";
	cout << "PERIODO " << desde_ << "/" << desde << "/" << anio_ << "--" << hasta_ << "/" << desde << "/" << anio_ << endl << endl;

	                                  
	for (int i = 0;i < ca;i++)               
	{
			if (historial[i]->getTipoServicio() ==0  && historial[i]->getdia() >= desde_ && historial[i]->getdia() <= hasta_ && historial[i]->getmes() == desde  && historial[i]->getanio() == anio_)
			{
				while (i < ca - 1 && historial[i + 1]->getnombreS().compare(historial[i]->getnombreS()) == 0)
				{
					i++;      //Salteamos si son iguales los servicios
				} 
				cout<<historial[i]->getnombreS()<<endl;
				cont++;
			}
	}	if (cont == 0)
		throw new exception("No se jugaron juegos en ese periodo ");
		
	
}

void Logger::MasEscuchados(Mes desde, int desde_, int hasta_, int anio_)
{
	int cont = 0;
	OrdenarHistorial();
	cout << "MAS ESCUCHADAS: ";
	cout << "PERIODO " << desde_ << "/" << desde << "/" << anio_ << "--" << hasta_ << "/" << desde << "/" << anio_ << endl << endl;


		for (int i = 0;i < (int)(ca );i++)          
		{
			if (historial[i]->getTipoServicio() == 2 && historial[i]->getdia() >= desde_ && historial[i]->getdia() <= hasta_ && historial[i]->getmes() == desde && historial[i]->getanio() == anio_)
			{
				while (i < ca - 1 && historial[i + 1]->getnombreS().compare(historial[i]->getnombreS()) == 0)
				{
					i++;      //Salteamos si son iguales los servicios
				} 
				cout<<(historial[i]->getnombreS())<<endl;
				cont++;
			}
		}
		if (cont == 0)
			throw new exception("No se escucharon canciones en ese periodo ");
		
	
} 

void Logger::PromUsuarioEspecifico(Mes desde, int desde_,  int hasta_, int anio,string username)
{
	int acum = 0;              //acumula tiempo de uso de usuarios
	int cont = 0;
	int acum2 = 0;
	int cont2 = 0;


	for (int i = 0;i < ca;i++)
	{
		if (historial[i]->getdia() >= desde_ && historial[i]->getdia() <= hasta_ && historial[i]->getmes() >= desde && historial[i]->getnombre().compare(username)==0)   //encuenctra el tiempo de la primer musica d ela lista
		{
			acum = acum + historial[i]->gettiempo();
			cont++;
			//break;
		}
		if (historial[i]->getdia() >= desde_ && historial[i]->getdia() <= hasta_ && historial[i]->getmes() == desde )  //promedio general
		{
			acum2 = acum2 + historial[i]->gettiempo();
			cont2++;
			//break;
		}
	}
	if (cont == 0||cont2==0)
		throw new exception("El usuario no ha pasado tiempo en la plataforma");
	cout << "El usuario " << username << " tiene un tiempo promedio en la plataforma acumulado de: "<<acum / cont << " segundos" << endl<<endl;
	cout << "promedio conexion general de todos los usuarios: " << acum2 / cont2 << " segundos" << endl<<endl;

}

void Logger::PromTipoUsuario(Mes desde,int desde_,int hasta_, int anio,int type)
{

	int acum = 0;              //acumula tiempo de uso de usuarios
	int cont = 0;

	if (type == 0)
		cout << "Promedio de tiempo conexion para usuarios free: ";
	if (type == 1)
		cout << "Promedio de tiempo conexion para usuarios basic: ";
	if (type == 2)
		cout << "Promedio de tiempo conexion para usuarios premium: ";

	for (int i = 0;i < ca;i++)
	{
		if (historial[i]->getdia() >= desde_ && historial[i]->getdia() <= hasta_ && historial[i]->getmes() ==desde && type == historial[i]->getTipoUsuario())   		{
			acum = acum +historial[i]->gettiempo();
			cont++;
		}
	}
	if (cont == 0)
		throw new exception("0");  //No hubo tiempo de conexion para ese tipo de usuario

	cout << acum / cont <<"segundos"<<endl<<endl;
}

void Logger::OrdenarHistorial()
{	
	int cont ;
	Log* aux = NULL;
	for (int i = 0;i <ca ;i++)
	{
		cont = 0;

		for (int j = 0;j < ca-1;j++)
		{ 
			if (historial[j+1]->gettiempo()>historial[j]->gettiempo())
			{
				aux = historial[j];
				historial[j] = historial[j + 1];
				historial[j + 1] = aux;
			}
			cont++;
		}
		if (cont == 0)
		break;
	}
}

string Logger::getNombreRandom()
{
	return historial[rand()%ca]->getnombre();
}
