#include "iostream"
#include "cUsuario.h"
#include "cService.h"
#include "string"
#include <ctime>

using namespace std;

typedef enum  { enero=1, febrero=2, marzo=3, abril=4, mayo=5, junio=6, julio=7, agosto=8, septiembre=9, octubre=10, noviembre=11, diciembre=12 } Mes;
typedef enum { lunes=1, martes=2, miercoles=3, jueves=4, viernes=5, sabado=6, domingo=7 } Dia ;

class Log
{//friend int laOtraClase::metodo() 
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
	Log(string username, string nombreServicio, time_t tiempo, eTipoUsuario tipoU, tipoServicio tipoS, Mes mes, Dia dia,int anio);   //Se guardan los datos despues de acceder de acada servicio
	~Log();
	string getnombre() { return username; };
	string getnombreS() { return nombreServicio; };
	tipoServicio getTipoServicio() { return tipoS; };
	time_t gettiempo() { return tiempoUso; };
	int getmes() { return  mes; };    //castear enum a  int
	int getdia() { return dia; };          //return  static_cast<int>(dia); };
	int getanio() {return anio; };

};
