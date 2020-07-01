#include "Logger.h"

Logger::Logger(int a,int CA=0)
{
	this->ca = CA;
	this->tam = a;
	log[tam];  // ver si compila sin esta lnea

	for(int i=0;i<tam;i++)
	{
		log[i] = NULL;
	}

};

Logger::~Logger()
{

};

bool Logger::agregar(Log* log)
{
	return false;
}

time_t Logger::tconexion(string user)//METODO NO STATIC CON LISTA STATIC
{
	time_t time = 0;
	for (int i =0;i<ca;i++)
	{
		if (Logger::log[i]->getnombre().compare(user) == 0)
			time = time + Logger::log[i]->gettiempo();
	}
	return time;

}



string Logger::MasVisto(Mes desde, Dia desde_, Mes hasta, Dia hasta_)
{
	long int max;
	max = static_cast<long int> (log[0]->gettiempo());
	

	for (int i=0;i<ca;i++)
	{
			if(log[i]->gettiempo())
			long int t = static_cast<long int> (log[i]->gettiempo());
			if (t > max)
				max = t;
	}
	return string();
}

string Logger::MasJugados(Mes desde, Dia desde_, Mes hasta, Dia hasta_)
{
	return string();
}

string Logger::MasEscuchados(Mes desde, Dia desde_, Mes hasta, Dia hasta_)
{
	return string();
}

float Logger::PromedioUsuarios(Mes desde, Dia desde_, Mes hasta, Dia hasta_)
{
	return 0.0f;
}
