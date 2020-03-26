// Nombre del alumno miguel robledo
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

void mostrarSolucion(std::vector<int>&sol)
{
	for (int i = 0; i < (int)sol.size() ; i++)
	{
		if (sol[i] == 0)
			std::cout << "azul ";
		else if (sol[i] == 1)
			std::cout << "rojo ";
		else
			std::cout << "verde ";
	}
	std::cout << "\n";
}
bool esValida(std::vector<int>&sol,int color, int ronda)
{
	if (color == 2 && sol[ronda] == sol[ronda - 1])
		return false;
	return true;
}
void torresA(std::vector<int>&sol,int tamanio,int actual)
{
	for (int i = 0; i < 3; i++)
	{
		sol[actual] = i;
		if (esValida(sol, i, actual))
		{
			if (actual == tamanio - 1)
				mostrarSolucion(sol);
			else
				torresA(sol, tamanio, actual + 1);
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tamanio;
	std::cin >> tamanio;
	if (tamanio == 0)
		return false;
	else
	{
		std::vector<int>sol(tamanio);
		sol[0] = 1;
		if (tamanio == 1)
			mostrarSolucion(sol);
		else
			torresA(sol,tamanio,1);
		std::cout << "\n";
	}

	// escribir sol

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
