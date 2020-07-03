#include "cListaT.h"


template<class T>
cListaT<T>::cListaT(unsigned int TAM)
{
	lista = new T *[TAM];
	for (unsigned int i = 0; i < TAM; i++)
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
		for (unsigned int i = 0; i < CA; i++)
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

	T* i_f = BuscarItem(item->getNombre());        //getnomre en usuario y serv
	if (i_f != NULL)throw new exception("Ya se encuentra en la lista");

	if (CA < TAM)
		lista[CA++] = item;
	else throw new exception("No hay tamanio suficiente para agregar el item");;
	return true;
}

template<class T>
 void cListaT<T>::Eliminar(string nombre)
{
	T* aux = Buscar(nombre);
	if (aux == NULL)
		throw new exception("No se encuentra en la lista"); //Hacer el try en el main
	else
	{
		for (unsigned int i = GetPos(nombre);i < CA - 1;i++)
		{
			lista[i] = lista[i + 1];
		} lista[CA--] = NULL;
		CA--;
		delete aux;
	}
}

template<class T>
 void cListaT<T>::Listar(int cantidadAlistar)
{
	cout << lista[0]->getNombre() << endl;
}

template<class T>
T* cListaT<T>::get(int pos)
{
	if (pos < CA)
		return lista[pos];
	else return NULL;
}

template<class T>
 T* cListaT<T>::Buscar(string nombre)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (lista[i]->getNombre() == nombre)
			return lista[i];
	}
	return NULL;
}


template<class T>
 unsigned int cListaT<T>::getTamanio()
{
	return TAM;
}

template<class T>
  int cListaT<T>::getCA()
{
	return CA;
}

template<class T>
 unsigned int cListaT<T>::GetPos(string nombre)
{

	for (unsigned int i = 0; i < CA; i++)
	{
		if (lista[i]->getNombre() == nombre)
			return i;
	}
	return 0; // para no tener que agarrar todas las excepciones en el main
}
 //template <class T>
 //T* cListaT<T>::operator[](int pos)
 //{
	// if (pos < CA)
	//	 return lista[pos];
	// else return NULL;

 //}


