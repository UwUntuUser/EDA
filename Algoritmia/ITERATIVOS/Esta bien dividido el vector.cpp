// Nombre del alumno miguel robledo 
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

// función que resuelve el problema
bool dividido(std::vector<int>const& sol, int pos)
{
	if (pos == sol.size() - 1) 
		return true;
	else {
		int mayorIzquierda = sol[0], menorDerecha = sol[pos + 1];
		for (int i = 0; i <= pos; i++)
			mayorIzquierda = (mayorIzquierda > sol[i]) ? mayorIzquierda : sol[i];
		for (int i = pos + 1; i < sol.size(); i++)
			menorDerecha = (menorDerecha < sol[i]) ? menorDerecha : sol[i];
		return mayorIzquierda < menorDerecha;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int tamanio, pos;
	std::cin >> tamanio >> pos;
	std::vector<int>datos(tamanio);
	for (int i = 0; i < tamanio; i++)
		std::cin >> datos[i];
	if (dividido(datos, pos))
		std::cout << "SI\n";
	else
		std::cout << "NO\n";

	

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