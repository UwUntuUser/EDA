#ifndef elem_minimo_h
#define elem_minimo_h

#include "bintree_eda.h"
#include<string>
#include <algorithm> // min

#include<memory>

template<class T>
class minimo_elemento : public bintree<T>
{

    using Link = typename bintree<T>::Link;


public:
    minimo_elemento<T>(bintree<T> izda, T raiz, bintree<T> drcha) : bintree<T>(izda, raiz, drcha) {}
//  frontera       <T>(bintree<T> izda, T raiz, bintree<T> drcha) : bintree<T>(izda, raiz, drcha) {}

    minimo_elemento<T>()
    {
        this->raiz = nullptr;
    }
    minimo_elemento<T> leerDatos(char tipo,T vacio)
    {
        if (tipo == 'N')
        {
            T raiz;
            std::cin >> raiz;
            if (raiz == vacio)
                return {};
            else
            {
                auto izda = leerArbol(vacio);
                auto drcha = leerArbol(vacio);
                return minimo_elemento<T>(izda, raiz, drcha);
            }
        }
        else
        {
            T raiz;
            std::cin >> raiz;
            if (raiz == vacio)
                return {};
            else
            {
                auto izda = leerArbol(vacio);
                auto drcha = leerArbol(vacio);
                return minimo_elemento<T>(izda, raiz, drcha);
                //return { izda,raiz,drcha };
            }
        }

     
    }


    T encontrar_minimo()
    {
        T minimo;

        minimo = elemento_minimo(this->raiz);

        return minimo;
    }

    T elemento_minimo(Link raiz)
    {

        typename bintree<T>::const_iterator it = this->begin();
        T minimum;
        minimum = *it;
        for (++it; it != this->end(); ++it)
            minimum = std::min(minimum, *it);
        return minimum;

    }
};

#endif