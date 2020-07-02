#include "iostream"
#include "string"
#include <vector>
//#include "cUsuario.h"
//#include "Log.h"
class cUsuario;
enum tipoServicio { juegos, peliculas, musica };

using namespace std;

class cService
{
	string nombre;
	bool mayorEdad;
	tipoServicio tipoS;
	
public:
	
	virtual void Descargar(cUsuario* user1, string nombre);
	vector<string> paisesprohibidos;
	cService(string nombre, bool mayorEdad,tipoServicio tipoS, vector<string> paisesProhibidos);
	~cService();
	virtual void Iniciar() ;// A revisar
	virtual void Pausar(int segundos);
	virtual void Apagar() ;
	bool AgregarFavoritos(cUsuario* user1, string nombre);
	virtual bool IsProhibidoPais(string pais);// retorna true si el pais pasado x parametro no es prohibido del servicio
	virtual string getNombre(){return nombre;}
	virtual tipoServicio getTipo() { return tipoS; };
};

