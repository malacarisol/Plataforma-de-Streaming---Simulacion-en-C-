#include "iostream"

class cService;
enum  eCategoria 
{pop, rock, cumbia, reggaeton, reggae, softPop, ritmosUrbanos, metal, sleep, workOut, chill, electronica, jazz};


class cMusica : public cService
{
	int duracion;
	eCategoria categoria;
public:
	cMusica(int duracion,eCategoria categoria, string nombre, bool mayorEdad, tipoServicio tipoS);
	~cMusica();
	void Record();
	void Fastforward();
	void Backward();
	void Iniciar();
	void Pausar(int segundos);
	void Apagar();
	void Descargar();
};

