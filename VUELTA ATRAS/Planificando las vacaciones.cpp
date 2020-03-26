// Nombre del alumno miguel robledo 
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

// función que resuelve el problema
void viaje(int numCiudades, std::vector<std::vector<int>>const&billetes, int etapa, int costeA, int costeMejor, 
	std::vector<bool>&marcas, std::vector<int>&sol,int &MinCoste)
{
	for (int i = 1; i < numCiudades; i++)
	{
		sol[etapa] = i;
		costeA += billetes[sol[etapa - 1]][i];
		if (!marcas[i])
		{
			marcas[i] = true;
			if (etapa == numCiudades - 1)
			{
				if (costeA + billetes[i][0] < costeMejor)
					MinCoste = costeMejor = costeA + billetes[i][0];
			}
			else 
			{
				if ((numCiudades - etapa)*MinCoste + costeA < costeMejor)
					viaje(numCiudades, billetes, etapa + 1, costeA, costeMejor, marcas, sol, MinCoste);
			}
			marcas[i] = false;
		}
		costeA -= billetes[sol[etapa - 1]] [i];
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numCiudades, min=100000;
	std::cin >> numCiudades;
	if (numCiudades == 0) return false;
	std::vector<int>sol(numCiudades,0);
	std::vector<bool>marcas(numCiudades, false);
	std::vector<std::vector<int>>billetes (numCiudades, std::vector<int>(numCiudades));
	for (int i = 0; i < numCiudades; i++)
		for (int j = 0; j < numCiudades; j++)
			std::cin >> billetes[i][j];
	for (int i = 0; i < numCiudades; i++)
	{
		for (int j = 0; j < numCiudades; j++)
			if (billetes[i][j] != 0 && billetes[i][j] < min)
				min = billetes[i][j];
	}
	viaje(numCiudades, billetes, 1, 0, 100000, marcas, sol, min);
	std::cout << min << "\n";
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
