// Nombre del alumno miguel robledo blanco
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

struct tDatos {
	std::vector<int>tiposAbrigos;
	std::vector<int>probPrecipitacion;
};

bool esValida(int etapa, int i, tDatos const & d, std::vector <int > const & sol, std::vector <int > const & marcas) {

	if (d.tiposAbrigos[i] < d.probPrecipitacion[etapa])
		return false;
	if (etapa > 0 && sol[etapa] == sol[etapa - 1])
		return false;
	if (marcas[i] > etapa / 3 + 2)
		return false;
	return true;
}
int abrigos(tDatos &d, int etapa, std::vector<int>&sol, std::vector <int> &marcas)
{
	int numSoluciones = 0; 
	for (int i = 0; i < d.tiposAbrigos.size(); ++i) {
		sol[etapa] = i;
		++marcas[i];
		if (esValida(etapa, i, d, sol, marcas)) { 
			if (etapa == d.probPrecipitacion.size() - 1)
			{ // es solucion
				if (sol[0] != sol[etapa])
				{ // El primer abrigo no coincide con el  ́ultimo
					++numSoluciones;
					// Para escribir las soluciones cuando se pidan
					// for ( int x : sol) std :: cout << x << ’ ’;
					// std :: cout << ’\n ’;
				}
			}
			else {
				numSoluciones += abrigos(d, etapa + 1, sol, marcas);
			}
		}
		--marcas[i];
	}
	return numSoluciones;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numDias, numAbrigos;
	tDatos d;
	std::cin >> numDias >> numAbrigos;
	if (numDias == 0 && numAbrigos == 0)
		return false;
	else
	{
		d.probPrecipitacion.resize(numDias);
		for (int &i : d.probPrecipitacion)
			std::cin >> i;
		d.tiposAbrigos.resize(numAbrigos);
		for (int &i : d.tiposAbrigos)
			std::cin >> i;
		int etapa = 0;
		std::vector<int>sol(numDias);
		std::vector<int>marcas(numAbrigos);
		int numSoluciones = abrigos(d, etapa, sol, marcas);
		if (numSoluciones == 0)
			std::cout << "Lo puedes comprar\n";
		else
			std::cout << numSoluciones << std::endl;
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
