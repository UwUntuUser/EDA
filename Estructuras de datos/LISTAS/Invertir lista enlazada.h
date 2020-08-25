#ifndef lista_h
#define lista_h

#include"queue_eda.h"
#include<iostream>

template<class T>
class listaInvertida : public queue<T> {
	using Nodo = typename queue<T>::Nodo;

public:

	void invierte()
	{
		Nodo *prev, *curr, *next;
		curr = this->prim;
		prev = NULL;
		this->ult = this->prim;
		while (curr != NULL)
		{
			next = curr->sig;
			curr->sig = prev;
			prev = curr;
			curr = next;
		}
		this->prim = prev;

	}


	void mostrar()
	{
		if (!this->empty())
		{
			Nodo *p = this->prim;
			for (int i = 0; i < this->nelems; i++)
			{
				std::cout << p->elem << " ";
				p = p->sig;
			}
		}
	}
};


#endif
