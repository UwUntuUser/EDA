// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include"elem_minimo.h"


// función que resuelve el problema
bool resuelveCaso() {
    // leer los datos de la entrada
    char tipo;
    std::cin>>tipo;
    if (!std::cin)
        return false;
	else
	{
        if (tipo == 'N')
        {
            minimo_elemento<int> arbol;

            arbol = arbol.leerDatos(tipo,-1);
            int minimo = arbol.encontrar_minimo();
            std::cout << minimo;

        }
        else
        {
            minimo_elemento<std::string> arbol;
            arbol = arbol.leerDatos(tipo,"#");
            std::string minimo = arbol.encontrar_minimo();
            std::cout << minimo;

        }

		std::cout << std::endl;



		return true;
	}
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}