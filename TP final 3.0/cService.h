#include "iostream"
#include "string"
#include <vector>
//#include "Log.h"

enum tipoServicio { juegos, peliculas, musica };

using namespace std;

class cService
{
	static float tiempoUso;
	string nombre;
	bool mayorEdad;
	tipoServicio tipoS;

public:
	vector<string> paisesprohibidos;
	cService(string nombre, bool mayorEdad,tipoServicio tipoS, vector<string> paisesProhibidos);
	~cService();
	virtual void Iniciar();// A revisar
	virtual void Pausar(int segundos);
	virtual void Apagar();
	virtual void Descargar();
	virtual bool paisesprohibidos(string pais);// retorna true si el pais pasado x parametro no es prohibido del servicio
	virtual string getNombre(){return nombre;}
	virtual tipoServicio getTipo() {return tipoS;}
};

