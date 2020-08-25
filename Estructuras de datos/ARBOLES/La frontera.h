#pragma once
#ifndef frontera_h
#define frontera_h
#include"bintree_eda.h"
#include<vector>

template<class T>
class frontera :  public bintree<T>{

	using Link = typename bintree<T>::Link;



public :
	frontera<T>(bintree<T> izda, T raiz, bintree<T>drcha) : bintree<T>(izda, raiz, drcha) {}

	frontera<T>()
	{
		this->raiz = NULL;
	}

	void pintar_frontera(Link raiz, std::vector<int> &sol)
	{
		if (raiz == NULL)
			return;
		if (raiz->right == NULL && raiz->left == NULL)
			sol.push_back(raiz->elem);
		else
		{
			pintar_frontera(raiz->left, sol);
			pintar_frontera(raiz->right, sol);
		}
	}

	void pintar_frontera(std::vector<int>& sol)
	{
		Link raiz = this->raiz;
		pintar_frontera(raiz, sol);
	}

	frontera<T> leer_arbol(T vacio)
	{
		T raiz;
		std::cin >> raiz;
		if (raiz == vacio)
			return {};
		else
		{
			auto izda = leerArbol(vacio);
			auto drcha = leerArbol(vacio);
			return frontera<T>(izda,raiz,drcha);
		}
	}
	/*
	datos_arbol<T> leerDatosArbol(T hoja)
	{
		T raiz;
		std::cin >> raiz;
		if (raiz == hoja)
			return {};
		else
		{
			auto izda = leerArbol(hoja);
			auto drcha = leerArbol(hoja);
			return datos_arbol<T>(izda, raiz, drcha);
		}
	}
	*/

};




#endif
