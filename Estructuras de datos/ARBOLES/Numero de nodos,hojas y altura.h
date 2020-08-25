#ifndef arbol_h
#define arbol_h
#include"bintree_eda.h"
#include<memory>
template<class T>
class datos_arbol : bintree<T> 
{
	using  Link = typename bintree<T>::Link;
private :

	void nodos(Link raiz, int&res)
	{
		if (raiz == NULL)
			res = 0;
		else
		{
			int izda, drcha;
			nodos(raiz->left, izda);
			nodos(raiz->right, drcha);
			res = izda + drcha + 1;
		}
	}

	void hojas(Link raiz, int &res)
	{
		if (raiz == NULL)
			res = 0;
		else if (raiz->left == NULL && raiz->right == NULL)
			res = 1;
		else
		{
			int izda, drcha;
			hojas(raiz->left, izda);
			hojas(raiz->right, drcha);
			res = izda+ drcha;
		}
	}

	void altura(Link raiz, int &res)
	{
		if (raiz == NULL )
			res = 0;
		else
		{
			int izda, drcha;
			altura(raiz->left, izda);
			altura(raiz->right, drcha);
			res = (izda > drcha) ? izda + 1 : drcha + 1;
		}
	}
public :

	datos_arbol(bintree<T>izda, T raiz, bintree<T>drcha) : bintree <T>(izda, raiz, drcha) {}
	datos_arbol() { this->raiz = NULL; }
	
	int getNodos()
	{
		int res;
		nodos(this->raiz, res);
		return res;
	}

	int getHojas()
	{
		int res;
		hojas(this->raiz, res);
		return res;
	}

	int getAltura()
	{
		int res;
		altura(this->raiz, res);
		return res;
	}



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
};



#endif 
