#include "cService.h"


enum ePeliculas {terror, comedia, suspenso, accion, aventura, drama, romantica, cienciaFiccion, policial, infantil, clasica, musical};


class cPeliculas : public cService
{
	int duracion;//minutos
	ePeliculas peli;
public:
	cPeliculas(int duracion, ePeliculas peli, string nombre, bool mayorEdad, tipoServicio tipoS);
	~cPeliculas();
	void Record();
	void Fastforward();
	void Backward();
	void Iniciar();
	void Pausar(int segundos);
	void Apagar();
	void Descargar();

};
