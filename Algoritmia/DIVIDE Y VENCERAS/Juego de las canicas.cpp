// Nombre del alumno Miguel robledo
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include<string>

struct tSol {
	std::string nombre;
	int canicas;
};

tSol ganadorCanicas(std::vector<tSol> const&vector, int inicio, int fin)
{
	tSol sol;
	if (inicio + 2 == fin)
	{
		if (vector[inicio].canicas >= vector[inicio+1].canicas)
		{
			sol.nombre = vector[inicio].nombre;
			sol.canicas = vector[inicio].canicas + (vector[inicio + 1].canicas) / 2;
		}
		else
		{
			sol.nombre = vector[inicio + 1].nombre;
			sol.canicas = vector[inicio + 1].canicas + (vector[inicio].canicas) / 2;
		}
	}
	else
	{
		int mitad = (inicio + fin) / 2;
		tSol drcha = ganadorCanicas(vector, mitad, fin);
		tSol izda = ganadorCanicas(vector, inicio, mitad);
		if (izda.canicas >= drcha.canicas)
		{
			sol.nombre = izda.nombre;
			sol.canicas = izda.canicas + (drcha.canicas) / 2;
		}
		else
		{
			sol.nombre = drcha.nombre;
			sol.canicas = drcha.canicas + (izda.canicas) / 2;
		}
		
	}
	return sol;
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
		std::vector<tSol>sol(tamanio);
		for (int i = 0; i < tamanio; i++)
		{
			std::cin >> sol[i].nombre;
			std::cin >> sol[i].canicas;
		}
		tSol solucion = ganadorCanicas(sol, 0, sol.size());
		std::cout << solucion.nombre << " " << solucion.canicas << std::endl;
		return true;
	}
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