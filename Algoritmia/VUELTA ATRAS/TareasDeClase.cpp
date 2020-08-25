// Nombre del alumno miguel robledo blanco
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

// función que resuelve el problema
struct tSatisfaccion
{
	int actual;
	int maxima;
};
bool esValida(int etapa,std::vector<int>const&limitacion,int n,int i)
{
	if (etapa == 0)
		return true;
	else
	{
		if (limitacion[i] <= n)
			return true;
		else
			return false;
		
	}
}

void tareasClase(std::vector<std::vector<int>>const& satisfaccion, std::vector<int>&limitacion, tSatisfaccion& s, int etapa,
					int tareasXNiño, int numAlumnos, int numTareas,std::vector<int>&solucion)
{
	// el for recorrera los niños y la etapa las tareas
	for (int i = 0; i < numAlumnos; i++)
	{
		solucion[etapa] = i; // a la tarea 'etapa' le asigno el niño i
		if (esValida(etapa,limitacion,tareasXNiño,i))//limitacion[i] <= tareasXNiño)
		// es valida cuando  no hay un niño con mas de x tareas
		{
			limitacion[i]++;
			s.actual += satisfaccion[i][etapa];
			if (etapa == numTareas - 1)
				s.maxima = (s.actual > s.maxima) ? s.actual : s.maxima;
			else
				tareasClase(satisfaccion, limitacion, s, etapa + 1, tareasXNiño, numAlumnos, numTareas, solucion);
			s.actual -= satisfaccion[i][etapa];
			limitacion[i]--;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numTareas, numAlumnos, numTareasXNiño;
	std::cin >> numTareas >> numAlumnos >> numTareasXNiño;
	if (numTareas == 0)
		return false;
	std::vector<std::vector<int>>satisfaccion(numAlumnos, std::vector<int>(numTareas));
	for (int i = 0; i < numAlumnos; i++)
		for (int j = 0; j < numTareas; j++)
			std::cin>>satisfaccion[i][j]; // horizontal son tareas, vertical son niños

	tSatisfaccion s;
	s.actual = 0;
	s.maxima = 0;
	int etapa = 0;
	std::vector<int>limitacion(numAlumnos); // sirve para almacenar cuantas atreas estan asigandasa  cada niño
	std::vector<int>solucion(numTareas * 2);
	std::vector<bool>marcas(numTareas);
	tareasClase(satisfaccion, limitacion, s, etapa, numTareasXNiño, numAlumnos, numTareas,solucion);

	std::cout << s.maxima << std::endl;

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
