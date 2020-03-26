// Nombre del alumno miguel robledo
// Usuario del Juez f47


#include <iostream>
#include <iomanip>
#include <fstream>
#include"insercion.h"


// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

bool resuelveCaso() {
	// leer los datos de la entrada
	int tamOriginal, tamNueva, pos, pivote;
	insercion<int> original , nueva;
	std::cin >> tamOriginal;
	if (!std::cin)
		return false;
	for (int i = 0; i < tamOriginal; i++)	// cargo la original
	{
		std::cin >> pivote;
		original.push(pivote);
	}

	std::cin >> tamNueva >> pos;

	for (int i = 0; i < tamNueva; i++)	//cargo sobre la que extraigo
	{
		std::cin >> pivote;
		nueva.push(pivote);
	}

	original.insertar(nueva, pos);

	original.mostrar();

	std::cout << "\n";


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}