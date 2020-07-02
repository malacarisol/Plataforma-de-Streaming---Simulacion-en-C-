#pragma oNce
#include <string>
#define NMAX 1000
#include <string>
#include <string>
#include <string>
#include <string>

using namespace std;

template<class T>
class  cListaT
{
protected:
	T** lista;

	unsigned int CA, TAM;

public:
	cListaT(unsigned int TAM = NMAX);
	~cListaT();

	bool Agregar(T* item);
	void Eliminar(string nombre);
	void Listar(int cantidadAlistar);
	T* get(int pos);
	T* Buscar(string nombre);
	unsigned int GetPos(string nombre);
	unsigned int getTamanio();
	unsigned int getCA();
};

