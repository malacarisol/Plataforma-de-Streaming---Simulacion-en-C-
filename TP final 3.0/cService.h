#include "iostream"
#include "string"
#include "vector"


class cService
{
	static float tiempoUso;
	string nombre;
	bool mayorEdad;
	tipoServicio tipoS;
	vector<string> paisesProhibidos;
	

public:
		

	cService(string nombre, bool mayorEdad,tipoServicio tipoS, vector<string> paisesProhibidos);
	~cService();
	void Iniciar();
	void Pausar(int segundos);
	void Apagar();
	virtual void Descargar();
	bool paisesprohibidos(string pais);// retorna true si el pais pasado x parametro no es prohibido del servicio
	string getNombre(){
	return nombre;
	}
	tipoServicio getTipo() {
		return tipoS;
	}
};

