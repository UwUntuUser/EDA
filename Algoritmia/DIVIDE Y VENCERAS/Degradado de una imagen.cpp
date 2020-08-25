// Nombre del alumno Miguel robledo blanco
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
struct tSol {
	bool ok;
	int suma;
};


// función que resuelve el problema
tSol degradado(std::vector<int> const & v, int inicio, int fin)
{
	if (inicio + 1 == fin)
			return{ true, v[inicio]};
	else
	{
		int mitad = (inicio + fin) / 2;
		//int derecha = 0, izquierda = 0;
		tSol Izquierda = degradado(v, inicio, mitad);
		tSol Derecha = degradado(v, mitad, fin);
		tSol solucion;
		solucion.suma = Derecha.suma + Izquierda.suma;
		solucion.ok = Izquierda.suma < Derecha.suma && Izquierda.ok && Derecha.ok;
		return solucion;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int fila, columna;
	std::cin >> fila >> columna;
	if (!std::cin)
		return false;
	else
	{
		tSol Solucion;
		Solucion.ok = true;
		for (int i = 0; i < fila; i++) //bucle para ir cargando todas las filas de la matriz
		{
			std::vector<int> v(columna);
			Solucion.suma = 0;
			for (int j = 0; j < columna; j++) // cargo una fila de la matriz
				std::cin >> v[j]; 
			if (Solucion.ok) // si una de las filas no cumple ser degradada salimos
			{
				Solucion = degradado(v, 0, v.size());
			}
		}
		if (!Solucion.ok) std::cout << "NO" << std::endl;
		else std::cout << "SI" << std::endl;
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



