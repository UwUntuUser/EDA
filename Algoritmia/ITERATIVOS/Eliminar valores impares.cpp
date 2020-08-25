// Nombre del alumno miguel robledo
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

void EliminaImpares(std::vector<int>&sol)
{
	int buenos = 0;
	for (int i = 0; i < sol.size(); i++)
	{
		if (sol[i] % 2 == 0) // si no es impar
		{
			sol[buenos] = sol[i];
			buenos++;
		}	
	}
	sol.resize(buenos);
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int tamanio;
	std::cin >> tamanio;
	std::vector<int>sol(tamanio);
	for (int i = 0; i < tamanio; i++)
		std::cin >> sol[i];
	EliminaImpares(sol);
	for (int i = 0; i < sol.size(); i++)
		std::cout << sol[i]<<" ";
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