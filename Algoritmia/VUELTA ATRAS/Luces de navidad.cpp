// Nombre del alumno miguel robledo
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

bool esValida(std::vector<int>const& solucion, int etapa, int actual, int maximo,std::vector<int>const&consumo,int i)
{
	if (etapa >= 2)
		if (solucion[etapa] == solucion[etapa - 1] && solucion[etapa] == solucion[etapa - 2]) // no puede haber dos luces iguales seguidas
			return false;
	if (actual + consumo[i] > maximo) // no podemos consumir mas de lo permitido
		return false;
}
bool ok(std::vector<int>const&lucesUsadas) 
{
	// sirve para ver que no hayamos usados muchas luces de un tipo y pocas de otro
	for (int i = 0; i < lucesUsadas.size(); i++)
		for (int j = 0; j < lucesUsadas.size(); j++)
			return (lucesUsadas[i] - lucesUsadas[j]) <= 1;

}
void lucesNavidad(int consumoMax, std::vector<int>const& consumoLuces, int etapa, int tamanio,int numLuces,
					int consumoActual,std::vector<int>&solucion, std::vector<int>&lucesUsadas, int &combinaciones)
{
	int comb = 0;
	for (int i = 0; i < numLuces; i++)
	{
		solucion[etapa] = i;
		lucesUsadas[i]++;
		if (esValida(solucion,etapa,consumoActual,consumoMax,consumoLuces,i))
		{
			consumoActual += consumoLuces[i];
			if (etapa == tamanio - 1 && ok(lucesUsadas))// && consumoActual<=consumoMax)
			{
				combinaciones++;
			}
			else
				lucesNavidad(consumoMax, consumoLuces, etapa + 1, tamanio, numLuces, consumoActual, solucion, lucesUsadas, combinaciones);
			consumoActual -= consumoLuces[i];
		}
		lucesUsadas[i]--;
	}
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tamanio, numLuces, consumoMax;
	std::cin >> tamanio;

	if (tamanio == 0)
		return false;

	std::cin >> numLuces >> consumoMax;
	std::vector<int>consumoLuces(numLuces);
	std::vector<int>solucion(tamanio);
	std::vector<int>lucesUsadas(numLuces);
	for (int&i : consumoLuces)
		std::cin >> i;
	int etapa = 0;
	int consumoActual = 0;
	int combinaciones = 0;
	lucesNavidad(consumoMax, consumoLuces, etapa, tamanio,numLuces,consumoActual,solucion,lucesUsadas,combinaciones);
	std::cout  <<" "<<combinaciones<< std::endl;
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
