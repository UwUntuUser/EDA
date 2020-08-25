#ifndef listaM_h
#define listaM_h

#include"queue_eda.h"
#include<iostream>


template<class T>
class listaMezclada : public queue<T>{
	using Nodo = typename queue<T>::Nodo;

public :

	void insertar(listaMezclada & cola)
	{
		Nodo *actual, *a, *b; 
//actual va a ser min(this->prim,cola->prim), a se va a mover en aquella cola en la que no empieze, b va a ser el siguiente al actual
		if (this->nelems == 0)
		{
			this->prim = cola.prim;
			this->ult = cola.ult;
			this->nelems = cola.nelems;
		}
		else 
		{

			if ((this->prim->elem) <= (cola.prim->elem))
			{
				actual = this->prim;
				a = cola.prim;
				b = actual->sig;
			}
			else {
				actual = cola.prim;
				b = actual->sig;
				a = this->prim;
				this->prim = actual;
			}
			while (a != NULL && b != NULL)
			{
				if (a->elem <= b->elem)
				{
					actual->sig = a;
					actual = a;
					a = a->sig;
				}
				else
				{
					actual->sig = b;
					actual = b;
					b = b->sig;
				}
			}

			//llegados a este punto tengo que ver q¡cual de las dos listas a acabado 
			if (a == NULL)
				actual->sig = b;
			if (b == NULL)
				actual->sig = a;
		}
		cola.prim = NULL;
		cola.libera();
	}

	void mostar()
	{
		if (!this->empty())
		{
			Nodo * aux = this->prim;
			for (; aux != NULL;)
			{
				std::cout << aux->elem<<" ";
				aux = aux->sig;
			}
		}
	}



};





#endif
