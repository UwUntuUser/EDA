// Nombre del alumno migue robledo
// Usuario del Juez f47


#include <iostream>
#include <iomanip>
#include <fstream>
#include"ListaMezclada.h"



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	listaMezclada<int> lista1;
	listaMezclada<int>lista2;
	int pivote;
	std::cin >> pivote;
	while (pivote != 0)
	{
		lista1.push(pivote);
		std::cin >> pivote;
	}
	std::cin >> pivote;
	while (pivote != 0)
	{
		lista2.push(pivote);
		std::cin >> pivote;
	}
	if(!lista2.empty())
		lista1.insertar(lista2);

	lista1.mostar();

	std::cout << "\n";

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}