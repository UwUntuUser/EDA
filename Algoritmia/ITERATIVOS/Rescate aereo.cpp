// Nombre del alumno miguel robledo blanco
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

// función que resuelve el problema

struct tSegmento
{
	int inicio, fin, tamanio;
};

tSegmento rescateAereo(std::vector<int>const& sol, int altura)
{
	tSegmento segmento;
	segmento.fin = 0, segmento.inicio = 0, segmento.tamanio = 0;
	int ini = 0, fin = 0, tActual = 0;
	for (int i = 0; i < (int)sol.size(); i++)
	{
		if (sol[i] > altura)
		{
			fin++;
			tActual++;
			if (tActual > segmento.tamanio)
			{
				segmento.inicio = ini;
				segmento.fin = i;
				segmento.tamanio = tActual;
			}
		}
		else
		{
			ini = i+1;
			fin=i+1;
			tActual = 0;
		}
	}
	return segmento;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int tamanio, alturaT;
	std::cin >> tamanio >> alturaT;
	std::vector<int>sol(tamanio);
	for (int i = 0; i < tamanio; i++)
		std::cin >> sol[i];
	tSegmento seg = rescateAereo(sol, alturaT);
	std::cout << seg.inicio << " " << seg.fin << "\n";

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