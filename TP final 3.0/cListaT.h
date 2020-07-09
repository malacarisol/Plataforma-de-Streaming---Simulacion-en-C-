#pragma once
#include <iostream>
#include "cUsuario.h"
#include "cService.h"
#include <string>
#define NMAX 50

using namespace std;

template<class T>

class  cListaT
{
protected:
	T** lista;

	 int CA, TAM;

public:
	cListaT( int TAM = NMAX);
	~cListaT();
	bool Agregar(T* item);
	void Eliminar(string nombre);
	T* get( int pos);
	T* Buscar(string nombre);
	 int GetPos(string nombre);
	 int getTamanio();
	 int getCA();
	T* operator[](int pos);
	void operator - (T* item);
	void operator + (T* item);
};


template<class T>
cListaT<T>::cListaT( int TAM)
{	lista = new T * [TAM];
	for ( int i = 0; i < TAM; i++)
	{
		lista[i] = NULL;
	}

	this->TAM = TAM;
	CA = 0;

}

template<class T>
cListaT<T>::~cListaT()
{
	if (lista != NULL)
	{
		for ( int i = 0; i < CA; i++)
		{
			if (lista[i] != NULL)
				delete lista[i];
		}
		delete[] lista;
	}

}

template<class T>
bool cListaT<T>::Agregar(T* item)
{
	
	T* i_f = Buscar(item->getNombre());       
	if (i_f != NULL)throw new exception("Ya se encuentra en la lista");

	if (CA < TAM-1)
		lista[CA++] = item;
	else throw new exception("No hay tamanio suficiente para agregar el item");
	return true;
	
}

template<class T>
void cListaT<T>::Eliminar(string nombre)
{
	T* aux = Buscar(nombre);
	if (aux == NULL)
		throw new exception("No se encuentra en la lista");
	else
	{
		for ( int i = GetPos(nombre);i < CA - 1;i++)
		{
			lista[i] = lista[i + 1];
		} lista[CA--] = NULL;
		CA--;
		delete aux;
	}
}



template<class T>
T* cListaT<T>::get( int pos)
{
	if (pos < CA)
		return lista[pos];
	else throw new exception("No esta esa posicion en la lista");
}

template<class T>
T* cListaT<T>::Buscar(string nombre)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (lista[i]->getNombre().compare(nombre)==0)
		{
			return lista[i];
		}
	}
	return NULL;
}


template<class T>
 int cListaT<T>::getTamanio()
{
	return TAM;
}

template<class T>
int cListaT<T>::getCA()
{
	return CA;
}

template<class T>
 int cListaT<T>::GetPos(string nombre)
{

	for (unsigned int i = 0; i < CA; i++)
	{
		if (lista[i]->getNombre() == nombre)
			return i;
	}
	return 0; // para no tener que agarrar todas las excepciones en el main
}
template <class T>
T* cListaT<T>::operator[](int pos)
{
	if (pos < CA)
		return lista[pos];
	else return NULL;

}

template<class T>
inline void cListaT<T>::operator-(T* item)
{
	Eliminar(item->getNombre());
}

template<class T>
inline void cListaT<T>::operator+(T* item)
{
	Agregar(item);
}

