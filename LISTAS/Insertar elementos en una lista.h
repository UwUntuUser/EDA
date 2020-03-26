#ifndef insercion_h
#define insercion_h

#include"queue_eda.h"
#include<iostream>


template<class T>
class insercion : public queue<T>{
	using Nodo = typename queue<T>::Nodo;

public :


	void insertar(insercion<T> &q, int pos)
	{
		if (pos != 0)
		{
			Nodo* ini = this->prim;
			Nodo* fin;
			for (int i = 0; i < pos - 1; i++)
				ini = ini->sig;		//posiciono el nodo donde quiero insertar el valor
			fin = ini->sig;
			ini->sig = q.prim;
			q.ult->sig = fin;
		}
		else
		{
			Nodo* aux = this->prim;
			this->prim = q.prim;
			q.ult->sig = aux;
		}
		this->nelems += q.nelems;
		q.prim = NULL;
		q.ult = NULL;
	}


	void mostrar()
	{
		if (!this->empty())
		{
			Nodo* aux = this->prim;
			for (int i = 0; i < this->nelems; i++)
			{
				std::cout << aux->elem<<" ";
				aux = aux->sig;
			}
		}
	}


};


#endif 