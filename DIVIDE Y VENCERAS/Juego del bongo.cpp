// Nombre del alumno miguel robledo
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>


int Bongo(std::vector<int>v, int ini, int fin, int cantado)
{
	if (ini + 1 == fin)
	{
		if (cantado + fin == v[fin])
			return v[fin];
		else if (cantado + ini == v[ini])
			return v[ini];
		else
			return 0;
	}
	else
	{
		int mitad = (ini + fin) / 2;
		if (cantado + mitad <= v[mitad])
			 return Bongo(v, ini, mitad, cantado);
		else
			return  Bongo(v, mitad , fin, cantado);
	}
}

void resuelveCaso() {
	// leer los datos de la entrada
	int tamanio, cantado;
	std::cin >> tamanio >> cantado;
	std::vector<int>vector(tamanio);
	for (int i = 0; i < tamanio; i++)
		std::cin >> vector[i];
	int numero=Bongo(vector, 0, tamanio,cantado);
	if (numero == 0)
		std::cout << "NO \n";
	else
		std::cout << numero<<"\n";

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