//#include "cUsuario.h"
//#include "cPeliculas.h"
//#include "cJuegos.h"
//#include "cMusica.h"
//#include <vector>
//#include <string>
//#include "time.h"
//#include <random>
//#include <map>
//using namespace std;
//
//#define x 15
//
//void generatorU(cUsuario *user)
//{
//	
//	vector<string> nombres;
//	string nombre = "Jasmine Piotr Norton Zakariyya Mack Campbell Coffey Madelyn Swift Billien Zubair Leroy Kline Lewys Coleman";
//	string aux("");
//	for (unsigned int i = 0;i < nombre.size();i++) {
//		if (nombre[i] != ' ') {
//			aux.push_back(nombre[i]);
//		}
//		else {
//			nombres.push_back(aux);
//			aux = "";
//		}
//	}
//	vector<string> apellidos;
//	string apellido = "Aziz Eberly Frei Bisi Sivaraja Reinsel Flanaga Woolley Childs Carr Sala Remey O'sullivan-snow Todd Buige";
//
//	for (unsigned int i = 0;i < apellido.size();i++) {
//		if (apellido[i] != ' ') {
//			aux.push_back( apellido[i]);
//		}
//		else {
//			apellidos.push_back(aux);
//			aux = "";
//		}
//	}
//	vector<int>edades;
//	string edad = "13 32 23 24 45 56 54 43 22 11 23 12 23 32 43";
//
//	for (unsigned int i = 0;i < edad.size();i++) {
//		if (edad[i] != ' ') {
//			aux.push_back( edad[i]);
//		}
//		else {
//			edades.push_back(stoi(aux));
//			aux = "";
//		}
//	}
//
//
//	vector<string> username;
//	string nombreuser = "viverra.Maecenas@egestas.com velit.eget@dolorquam.com vulputate@auctor.net dictum.sapien.Aenean@interdum.com egestas.hendrerit@utsemNulla.co.uk non.lacinia.at@quisturpis.co.uk nonummy.ipsum@egestasurnajusto.ca sollicitudin@elementum.com neque@idrisusquis.org lacinia@sitamet.org montes.nascetur.ridiculus@Integereu.co.uk nunc@euaugueporttitor.net feugiat@arcuCurabiturut.edu nec.imperdiet@temporbibendumDonec.ca blandit@pede.edu";
//
//	for (unsigned int i = 0;i < nombreuser.size();i++) {
//		if (nombreuser[i] != ' ') {
//			aux += nombreuser[i];
//		}
//		else {
//			username.push_back(aux);
//			aux = "";
//		}
//	}
//
//	vector<string>passwords;
//	string pass = "nxWzSBDK 2h4jpfsQ vWUhds2G hQpBXfjx 5BKCxwV6 UKnbtxJ2 62hfYER AqkbHWer HQqjFnsX JHc363nC BTUe4g SLk8Ezh5 EMbVceP fhCQAWzg qJexUFkm";
//
//	for (unsigned int i = 0;i < pass.size();i++) {
//		if (pass[i] != ' ') {
//			aux.push_back(pass[i]);
//		}
//		else {
//			passwords.push_back(aux);
//			aux = "";
//		}
//
//
//		vector<string>paises;
//		string pais = "romanian mexican swiss jordanian turkish austrian bulgarian indian greek liberian argentinian brasilian portuguese slovakian";
//
//		for (unsigned int i = 0;i < pais.size();i++) {
//			if (pais[i] != ' ') {
//				aux.push_back(pais[i]);
//			}
//			else {
//				paises.push_back(aux);
//				aux = "";
//			}
//		}
//
//	
//		
//		for (int i = 0;i < x;i++)
//		{
//			srand((unsigned)time(NULL));
//			int j = (rand() % x - 1);
//			eTipoUsuario type = static_cast<eTipoUsuario>(rand() % premium);//tendria que elegir un enum random
//			user= new cUsuario(edades[j],username[j], passwords[j], false, paises[j], apellidos[j], nombres[j], type);
//		}
//	}
//	
//}
//void generatorS(cService *serv)
//{
//	vector<string>paisesprohibidos;
//	string pais = "";
//	srand(time(NULL));
//	vector<string> peliculas;
//	string nombre = "Mad Max-Fury-Titanic-Maze Runner-Hunger Games-Jojo Rabbit-Hangover-21 Blackjack-Harry Potter-Zatura-El origen-Pets-Toy Story-The Lion King-the notebook-High school musical-Entrenando a mi dragon- cars-cars2-Lilo y stich- Hannah Montana-El conjuro.";
//	string aux = "";
//	for (int i = 0;i < nombre.length();i++) {
//		if (nombre[i] != '-') {
//			aux.push_back(nombre[i]);
//		}
//		else {
//			peliculas.push_back(aux);
//			aux = "";
//		}
//	}
//
//	
//
//	vector<string> juegos;
//	string juego ("PacMan-Call of Duty-Counter-Runner max-Alien store-Minecraft-Free fire-Guitar hero-The sims-Pokemon-Cooking with Stella-Play piano-Super Mario Bross-Hunter-Hairdresser-Ping pong-Football");
//	
//	for (unsigned int i = 0;i < juego.size();i++) {
//		if (juego[i] != '-') {
//			aux.push_back( juego[i]);
//		}
//		else {
//			juegos.push_back(aux);
//			aux = "";
//		}
//	}
//
//	vector<string> Musica;
//	string Music ( "When i was yor man-Just the way you are-Somebody to love-Duty love-Don't worry be happy-One way or another-Fresa-Sueltate el pelo-Oye-22-I'm yours-Lucky-Rolling in deep-Hello");
//
//	for (int i = 0;i < Music.length();i++) {
//		if (Music[i] != '-') {
//			aux.push_back( Music[i]);
//		}
//		else {
//			Musica.push_back(aux);
//			aux = "";
//		}
//	}
//	
//	vector<string>paisesprohibidosJ;
//	string paisJ ( "romania mexico switzerland jordania turkey austria bulgaria");
//
//	int i,a,b;
//	for ( i = 0;i < juegos.size();i++)
//	{
//		srand((unsigned)time(NULL));
//		bool b= 0 + (rand() % (1 - 0 + 1)) == 1;
//		int l = (rand() % 6);
//		for (int i = 0;i < l;i++) {
//			if (paisJ[i] != ' ') {
//				aux.push_back( paisJ[i]);
//			}
//			else {
//				paisesprohibidosJ.push_back(aux);
//				aux = "";
//			}
//		}
//
//		eJuegos type = static_cast<eJuegos>(rand() % estrategia);
//		tipoServicio type1 = static_cast<tipoServicio>(0);
//		serv = new cJuegos(1,type,juegos[i],b,type1, paisesprohibidosJ);//el nivel por deafult empieza en 1, luego el programa aumenta a medida que progresa el jugador
//		                                         //Juegos no necesita ser random, se actualiza en la lista de servicios a medida que se agregan juegos a  la lista
//	}
//
//
//	vector<string>paisesprohibidosM; // M de musica
//	string paisM("romania mexico switzerland jordania turkey austria bulgaria india greace liberia argentina brasil portugal slovakia");
//
//	for (a = i ;a < Musica.size();a++)
//	{
//		srand((unsigned)time(NULL));
//		eCategoria type = static_cast<eCategoria>(rand() % jazz);//tendria que elegir un enum random
//
//		int l = (rand() % 6);
//		
//
//		for (int i = 0;i < l;i++) {
//			if (paisM[i] != ' ') {
//				aux.push_back(paisM[i]);
//			}
//			else {
//				paisesprohibidosM.push_back(aux);
//				aux = "";
//			}
//		}
//
//		bool b = 0 + (rand() % (1 - 0 + 1)) == 1;
//		tipoServicio type2 = static_cast<tipoServicio>(2);//No sabiamos como escribir el enum de una forma mas facil en el constructor
//		serv= new cMusica(l,type,Musica[a],b,type2, paisesprohibidosM);	
//		
//	}
//
//
//	vector<string>paisesprohibidosP; //p de Pelicula
//	string paisP ( "Uruguay Turkia Japon China ");
//
//
//	for (b=a;b < peliculas.size() ;b++)
//	{
//		//bool b = 0 + (rand() % (1 - 0 + 1)) == 1;
//		ePeliculas type = static_cast<ePeliculas>(rand() % musical);
//		int c=(rand() % 180);//duracion en minutos
//		int l = (rand() % 3);
//		//push_back() The recommended approach is to use standard push_back() function which is overloaded for charsand appends a character to the end of the string.
//
//		for (int i = 0;i < l;i++) {
//			if (paisP[i] != ' ') {
//				aux.push_back(paisP[i]);
//			}
//			else {
//				paisesprohibidosM.push_back(aux);
//				aux = "";
//			}
//		}
//
//		tipoServicio type3 = static_cast<tipoServicio>(1);
//		serv = new cPeliculas(c,type,peliculas[i],b,type3, paisesprohibidosP);
//		
//	}
//}
//
//
