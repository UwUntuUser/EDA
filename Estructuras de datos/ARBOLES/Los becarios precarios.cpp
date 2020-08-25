// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>

// función que resuelve el problema
void altura(int r, int n, int &numJefes, int &numBecarios)
{
	int raiz;

	for (int i = 0; i < r; i++)
	{
		std::cin >> raiz;

		if (raiz != 0) // si no es becario
		{
			numJefes++;
			altura(raiz, n, numJefes, numBecarios);
			numJefes--;
		}
		else // si es becario
		{
			numBecarios += (numJefes >= n) ? 1 : 0;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int raiz, n, numJefes = 1, numBecarios = 0;
	std::cin >> n;
	std::cin >> raiz;
	
	if (!std::cin)
		return false;
	if (raiz != 0)
		altura(raiz, n, numJefes, numBecarios);

	std::cout << numBecarios << std::endl;

	return true;


}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 



		while(resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}