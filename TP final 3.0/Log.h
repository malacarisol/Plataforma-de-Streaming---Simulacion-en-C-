#include "iostream"
#include "cUsuario.h"
#include "cService.h"
#include "string"


using namespace std;

enum tipoServicio { juegos, peliculas, musica };
enum Mes { enero, febrero, marzo, abril, mayo, junio, julio, agosto, septiembre, octubre, noviembre, diciembre };
enum Dia { lunes, martes, miercoles, jueves, viernes, sabado, domingo };

class Log
{//friend int laOtraClase::metodo(); 
	friend class Logger;

	string username;
	string nombreServicio;
	int tiempoUso;
	eTipoUsuario tipoU;
	tipoServicio tipoS;
	Mes mes;
	Dia dia;

public:
	Log(string username, string nombreServicio, int tiempo, eTipoUsuario tipoU, tipoServicio tipoS, Mes mes, Dia dia);
	~Log();

};
