
// Nombre del alumno miguel robledo
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>


struct tSol {
	int primero;
	int botin;
};

tSol Asalto(std::vector<int>const& tren, int numVagones)
{
	tSol aux, mejor;
	aux.primero = 0;
	aux.botin = 0;
	mejor.botin = 0;
	mejor.primero = 0;
	for (int i = 0; i < numVagones; i++)
	{
		aux.botin += tren[i];
		mejor.botin = aux.botin;
	}
	for (int i = 0; i < tren.size(); i++)
	{
		aux.botin -= tren[i - numVagones]; // le quito el anterior
		aux.botin += tren[i];			   // le sumo el nuevo vagon
		aux.primero = i - numVagones + 1;
		if (aux.botin >= mejor.botin)
		{
			mejor.botin = aux.botin;
			mejor.primero = aux.primero;
		}
	}
	return mejor;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int tamanio, numVagones;
	std::cin >> tamanio >> numVagones;
	std::vector<int>tren(tamanio);
	for (int i = 0; i < tamanio; ++i)
		std::cin >> tren[i];
	tSol sol = Asalto(tren, numVagones);
	std::cout << sol.primero << " " << sol.botin << "\n";


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