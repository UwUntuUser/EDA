// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

// función que resuelve el problema
int lost(std::vector<int>const& datos, const int perdido, int inicio, int final)
{
	if (inicio + 1 == final) // un elemento
		return datos[inicio];
	else if (inicio + 2 == final) // dos elementos
		return (abs(datos[inicio] - perdido) <= abs(datos[inicio + 1] - perdido)) ? datos[inicio] : datos[inicio + 1];
	else
	{
		int mitad = (inicio + final) / 2;
		if (perdido > datos[mitad])
			return lost(datos, perdido, mitad, final);
		else
			return lost(datos, perdido, inicio, mitad);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numero, tamanio;
	std::cin >> numero >> tamanio;
	std::vector<int>datos(tamanio);
	for (int i = 0; i < tamanio; i++)
		std::cin >> datos[i];
	int cercano = lost(datos, numero,0,tamanio);
	std::cout << cercano << "\n";

	// escribir sol


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