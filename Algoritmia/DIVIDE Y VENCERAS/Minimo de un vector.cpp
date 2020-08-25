// Nombre del alumno Miguel robledo blanco
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

/*

					{ c0          si n=2
Recursividad; T(n)= {
					{T(n/2)+ c1   si n>2


O(n)= Log(n)

*/

// función que resuelve el problema
int minimo(std::vector<int>const &v, int inicio, int fin)
{
	int min;
	if (inicio + 1 >= fin) //  >= o ==
	{
		if (v[inicio] > v[fin])
			min = v[inicio + 1];
		else
			min = v[inicio];
	}
	else
	{
		int mitad = (inicio + fin) / 2;
		if (v[inicio] > v[mitad])
			min = minimo(v, mitad, fin);
		else
			min = minimo(v, inicio, mitad);
	}
	return min;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tamanio;
	std::cin >> tamanio;
	if (!std::cin)
		return false;
	else
	{
		std::vector<int>vector(tamanio);
		for (int i = 0; i < tamanio; i++)
			std::cin >> vector[i];
		int menor = minimo(vector, 0, vector.size() - 1);
		std::cout << menor << std::endl;
	}

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