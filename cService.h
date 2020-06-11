#ifndef CSERVICE_H
#define CSERVICE_H

class cService
{
	static float tiempoUso;
	string nombre;
	bool mayorEdad;
	vector<string> paisesProhibidos;

public:

	cService();
	~cService();
	virtual void Iniciar();
	virtual void Pausar(int segundos);
	virtual void Apagar();
	virtual void Descargar();
};//yo pondria solo virtual el Descargar();

#endif