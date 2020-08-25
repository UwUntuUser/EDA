// Nombre del alumno miguel robledo
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>


struct tDatos
{
	int MaxSeguidosGanados;
	int numVeces;
	int partidosDesde;
};

tDatos seleccion(std::vector<int>const& sol)
{
	tDatos solucion = { 0 };
	int contador = 0;
	for (int i = 0; i < sol.size(); i++)
	{
		if (sol[i] <= 0) // si perdieron
		{
			solucion.partidosDesde++;
			contador = 0;
		}
		else // si han ganado
		{
			contador++;
			if (contador > solucion.MaxSeguidosGanados) // si tenemos una racha ganadora mas grande
			{
				solucion.MaxSeguidosGanados = contador ;
				solucion.numVeces=1;
				solucion.partidosDesde = 0;

			}
			else if (contador == solucion.MaxSeguidosGanados) // si la racha ganadora es la misma
			{
				solucion.numVeces++;
				solucion.partidosDesde = 0;
			}
			else
				solucion.partidosDesde++;
		}
	}
	return solucion;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tamanio;
	std::cin >> tamanio;
	if (!std::cin) return false;
	std::vector<int>partidos(tamanio);
	for (int i = 0; i < tamanio; i++)
		std::cin >> partidos[i];

	tDatos d = seleccion(partidos);
	std::cout << d.MaxSeguidosGanados << " " << d.numVeces << " " << d.partidosDesde << "\n";


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