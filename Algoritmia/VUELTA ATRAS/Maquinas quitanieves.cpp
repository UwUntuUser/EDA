// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

// función que resuelve el problema

void quitanieves(std::vector<std::vector<int>>const&satisfaccion, std::vector<int>const&anchoMaquinas, std::vector<int>const&anchoCarreteras, int &actual
					,int &mejor,int etapa, int numCarreteras, int numMaquinas, std::vector<bool>&solucion)
{
	for (int i = 0; i < numCarreteras; i++)
	{
		actual += satisfaccion[etapa][i];
		if (!solucion[i] && anchoMaquinas[etapa] <= anchoCarreteras[i]) // es valida si la maquina entra en la carretera
		{
			solucion[i] = true; //esta carretera se esta usando
			if (etapa == numMaquinas - 1)
			{
				if (actual > mejor)
					mejor = actual;
			}
			else 
				quitanieves(satisfaccion, anchoMaquinas, anchoCarreteras, actual,mejor, etapa + 1, numCarreteras, numMaquinas, solucion);
			solucion[i] = false;
		}
		actual -= satisfaccion[etapa][i];
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numMaquinas, numCarreteras;
	std::cin >> numMaquinas >> numCarreteras;
	std::vector<int>anchoMaquinas(numMaquinas);
	std::vector<int>anchoCarreteras(numCarreteras);

	for (int i = 0; i< numMaquinas; i++)
		std::cin >> anchoMaquinas[i];

	for (int i = 0; i< numCarreteras; i++)
		std::cin >> anchoCarreteras[i];

	std::vector<std::vector<int>>satisfaccion(numMaquinas, std::vector<int>(numCarreteras));
	for (int i = 0; i< numMaquinas; i++)
		for (int j = 0; j < numCarreteras; j++)
			std::cin >> satisfaccion[i][j];
	int actual = 0;
	int etapa = 0;
	int mejor = 0;
	std::vector<bool>solucion(numCarreteras); // el primero entero es maquina el seguno carretera
	quitanieves(satisfaccion, anchoMaquinas, anchoCarreteras,actual,mejor,etapa, numCarreteras,numMaquinas, solucion);
	std::cout << mejor << "\n";
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