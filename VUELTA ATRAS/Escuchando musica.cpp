// Nombre del alumno Miguel robledo blanco
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

struct tTiempos {
	int ida;
	int vuelta;
};
struct tSatisfaccion {
	int actual;
	int maxima;
};

void escuchandoMusica(std::vector<int>&sol, std::vector<std::pair<int, int>>const& datosCanciones, tTiempos const& t,
				tSatisfaccion  s, int etapa,int IDA,int VUELTA, int tiempoMaximo,int tiempoActual, int numCanciones,bool posible)
{
	//first = duracion, second = satisfaccion
	for (int i = 0; i < 3; i++) 
	{
		sol.push_back(etapa);
		tiempoActual += datosCanciones[etapa].first;
		if (tiempoActual < tiempoMaximo) // si de alguna forma puedo meter la cancion
		{
			s.actual = datosCanciones[etapa].second;
			if (etapa == numCanciones - 1 )
			{
				s.maxima = (s.actual > s.maxima) ? s.actual : s.maxima;
		}
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numCanciones;
	tTiempos t;
	tSatisfaccion s;
	std::cin >> numCanciones >> t.ida >> t.vuelta;
	if (numCanciones == 0) return false;

	std::vector<std::pair<int, int>>datosCanciones;
	for (int i = 0; i < numCanciones; i++)
	{
		std::cin >> datosCanciones[i].first; // duracion
		std::cin >> datosCanciones[i].second; // satisfaccion
	}

	std::vector<int>sol;
	s.actual = 0;
	s.maxima = -100000;
	int IDA, VUELTA;
	int tiempoMaximo = t.ida + t.vuelta;
	int tiempoActual = 0;
	bool posible = false;
	escuchandoMusica(sol, datosCanciones, t, s, 0, IDA,VUELTA,tiempoMaximo,tiempoActual,numCanciones,posible);
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
