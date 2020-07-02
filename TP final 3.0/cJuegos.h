#include "cService.h"
enum eJuegos { accion, puzzle, aventura, azar, multijugadores, estrategia };

class cJuegos : public cService
{
	int nivel;
	eJuegos catJuegos;
	//enum class eJuegos { accion, puzzle, aventura, azar, multijugadores, estrategia };

public:
	cJuegos(int nivel, eJuegos juego, string nombre, bool mayorEdad, tipoServicio tipoS,vector<string> paisesProhibidos);
	~cJuegos();
	void GuardarPartida();                                    //se guarda el nivel actual
	void Iniciar();
	void Pausar(int segundos);
	void Apagar();
	void Descargar();                                       //no se puede descargar un juego


};
