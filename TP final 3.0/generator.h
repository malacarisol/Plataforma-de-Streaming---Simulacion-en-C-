#include "cUsuario.h"
#include "cStreaming.h"
#include "cPeliculas.h"
#include "cJuegos.h"
#include "cMusica.h"
#include <vector>
#include <stdio.h>
#include <string.h>
#include "time.h"
#include <random>
#include <map>
#include <iostream>
using namespace std;

#define x 15

void generator(cStreaming *stream)
{
	vector<string> nombres = { "Jasmine", "Piotr", "Norton", "Zakariyya", "Mack"," Campbell"," Coffey"," Madelyn", "Swift", "Billien"," Zubair", "Leroy", "Kline", "Lewys"," Coleman" };
	
	vector<string> apellidos = { "Aziz", "Eberly", "Frei", "Bisi","Sivaraja"," Reinsel"," Flanaga"," Woolley", "Childs", "Carr", "Sala", "Remey"," O'sullivan-snow"," Todd Buige" ,"malacari"};
	
	vector<int>edades = { 13 ,32, 23,24,45, 56, 54, 43, 22, 11, 23, 12, 23, 32, 43 }; //vector aleatorio de edades

	vector<string> username{ "viverra.Maecenas@egestas.com", "velit.eget@dolorquam.com", "vulputate@auctor.net", "dictum.sapien.Aenean@interdum.com", "egestas.hendrerit@utsemNulla.co.uk", "non.lacinia.at@quisturpis.co.uk", "nonummy.ipsum@egestasurnajusto.ca", "sollicitudin@elementum.com","neque@idrisusquis.org", "perez@sitamet.org", "montes.nascetur.ridiculus@Integereu.co.uk", "nunc@euaugueporttitor.net", "feugiat@arcuCurabiturut.edu", "nec.imperdiet@temporbibendumDonec.ca", "malacarisol@gmail.com", "martinazgaiib@gmail.com", "blandit@pede.edu" };
	
	vector<string>passwords = { "nxWzSBDK", "2h4jpfsQ", "vWUhds2G", "hQpBXfjx","5BKCxwV6", "UKnbtxJ2", "62hfYER", "AqkbHWer", "HQqjFnsX", "JHc363nC", "BTUe4g", "SLk8Ezh5", "EMbVceP", "fhCQAWzg", "qJexUFkm" };

	vector<string>paises = { "romanian", "mexican", "swiss", "jordanian", "turkish","austrian", "bulgarian", "indian", "greek", "liberian", "argentinian", "brasilian", "portuguese", "slovakian", "russian" };
	
	vector<string> peliculas = { "El conjuro","Harry Potter","Zatura","Maze Runner","Hunger Games","Mad Max","Fury","Hangover","jojo rabbit","Pets" ,"Hannah Montana","lilo y stich","Moana","Cars","Toy Story"};	

	vector<string> juegos = {"Call of Duty", "Counter Runner", "max-Alien","Pokemon",  "Free fire","Minecraft", "PacMan","The sims","Super Mario Bross","Hunter","Hole io","Mowgli" ,"Hairdresser","Cooking with Stella","Guitar hero"};

	vector<string> Musica = { "When i was yor man","Just the way you are","Somebody to love","Duty love","Don't worry be happy","One way or another","I cant get no satisfaction","paint it black","carry","Paradise","me tiene mal","Tirate un paso","Porque te fuiste","Te Amo","Ven bailalo"};

	vector<string> paisesprohibidosRandom;//de los paises elegimos menos de 3 random para ser prohibidos
	
	srand(time(NULL));
	int b=rand()%(4);           
	for(int i=0;i<b;i++)
	{
		paisesprohibidosRandom.push_back(paises[i]);
	} 

	for (int j = 0;j < x;j++)
	{
		
		eTipoUsuario type = static_cast<eTipoUsuario>(rand() % 3);             //el tipo de usuario es random

		try {
			stream->AgregarUsuario(new cUsuario(edades[j], username[j], passwords[j], false, paises[j], apellidos[j], nombres[j], type));  // false si todos desconectados al inicio
		}
		catch (exception * e)
		{
			cout << e->what() << endl;
		}
	}
	

	for (int i = 0;i < x;i++)
	{
		eJuegos type;
		int b = rand() % 1;
		if (i < 4)
			type = accion;
		else if (i >= 4 && i < 7)
			type = estrategia;
		else if (i >= 7 && i < 12)
			type = aventura;
		else if (i >= 12 && i < 15)
			type = ninios;
		int segsDuraciones = rand() % 360;
		int niveles = rand() % (1+20);
		try { stream->AgregarService(new cJuegos(segsDuraciones,niveles, type, juegos[i], b, tipoServicio::juegos, paisesprohibidosRandom)); }        //Juegos no necesita ser random, se actualiza en la lista de servicios a medida que se agregan juegos a  la lista
		catch (exception * e)   //manejo de excepciones
		{
			cout << e->what() << endl;
		}
	}
	

	for (int a = 0 ;a < x;a++)
	{
	

		srand((unsigned)time(NULL));
		eMusica typeM;

		if (a < 6)
			typeM = pop;
		if (a >= 6 && a < 10)
			typeM = rock;
		if (a >= 10 && a < 15)
			typeM = cumbia;

		
		int segsDuracion = rand() % 360;       //segundos de duracion

		try { 
			stream->AgregarService(new cMusica(segsDuracion, typeM, Musica[a],tipoServicio::musica, paisesprohibidosRandom)); 
		}
		catch (exception * e)
		{
			cout << e->what() << endl;
		}
	}
	

	for (int i=0;i < x;i++)
	{
		bool mayor18 = rand() % (2);

		ePeliculas tipox;
	
		if (i < 1)
			tipox = terror;
		if (i >= 1 && i < 7)
			tipox = cienciaFiccion;
		if (i >= 7 && i < 9)
			tipox = comedia;
		if (i >= 9 && i < 15)
			tipox = infantil;

		int secsDuration=(rand() % 7200);        //duracion en segundos

		try { 
			stream->AgregarService(new cPeliculas(secsDuration, tipox, peliculas[i], mayor18, tipoServicio::peliculas, paisesprohibidosRandom));
		}
		catch (exception * e)
		{
			cout << e->what() << endl;
		}
	}
}	


