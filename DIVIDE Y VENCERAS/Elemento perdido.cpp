// Nombre del alumno Miguel robledo blanco
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

int elementoPerdido(std::vector<int> const&lleno, std::vector<int> const&faltante, int inicio, int fin)
{
	int perdido;
	if (inicio == fin)  //caso base de un elemento
		perdido = lleno[inicio];
	else if (inicio + 1 == fin) //casi base de dos elementos
	{
		if (lleno[inicio] == faltante[inicio])
			perdido = lleno[inicio + 1];
		else
			perdido = lleno[inicio];
	}
	else
	{
		int mitad = (inicio + fin) / 2;
		if (lleno[mitad] == faltante[mitad])								// falta por la derecha
			perdido = elementoPerdido(lleno, faltante, mitad + 1, fin);
		else																//falta por la izquierda
			perdido = elementoPerdido(lleno, faltante, inicio, mitad);
	}
	return perdido;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int tamanio;
	std::cin >> tamanio;
	std::vector<int> lleno(tamanio);
	for (int i = 0; i < tamanio; i++)
		std::cin >> lleno[i];
	std::vector<int>faltante(tamanio - 1);
	for (int i = 0; i < tamanio - 1; i++) 
		std::cin >> faltante[i];
	int falta = elementoPerdido(lleno, faltante, 0, lleno.size() - 1);
	std::cout << falta << std::endl;
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
