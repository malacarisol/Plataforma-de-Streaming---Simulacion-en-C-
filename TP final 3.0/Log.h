#include "iostream"
#include "cUsuario.h"
#include "cService.h"
#include "string"
#include <ctime>

using namespace std;

enum tipoServicio { juegos, peliculas, musica };
enum Mes { enero, febrero, marzo, abril, mayo, junio, julio, agosto, septiembre, octubre, noviembre, diciembre };
enum Dia { lunes, martes, miercoles, jueves, viernes, sabado, domingo };

class Log
{//friend int laOtraClase::metodo(); 
	friend class Logger;

	string username;
	string nombreServicio;
	time_t tiempoUso;
	eTipoUsuario tipoU;
	tipoServicio tipoS;
	Mes mes;
	Dia dia;
	int anio;

public:
	Log(string username, string nombreServicio, time_t tiempo, eTipoUsuario tipoU, tipoServicio tipoS, Mes mes, Dia dia,int anio);//Se guardan los datos despues de acceder de acada servicio
	~Log();
	string getnombre() { return username; };
	string getnombreS() { return nombreServicio; };
	time_t gettiempo() { return tiempoUso; };
	int getmes();      //castear enum a  int
	int getdia();

};
