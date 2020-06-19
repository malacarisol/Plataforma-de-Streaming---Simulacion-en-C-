#pragma once
#define NMAX 1000

#include <string>

using namespace std;

template<class T>
class cListaT 
{
protected:
	T** lista;

	unsigned int CA, TAM;
	void Redimensionalizar();

public:
	cListaT(unsigned int TAM = NMAX);
	~cListaT();

	bool Agregar(T* serv);
	void Eliminar(string nombre);
	void Listar(int cantidadAlistar);
	T* Buscar(string nombre);
	T* get(unsigned int pos);
	unsigned int GetPos(string nombre);
	unsigned int getTamanio();
	unsigned int getCA();
};
