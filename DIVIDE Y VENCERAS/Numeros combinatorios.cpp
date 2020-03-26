// Nombre del alumno Miguel robledo blanco
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>



void Combinatorio(std::vector<std::vector<int>> &m, int a, int b) {
	if (a == b)
		m[a][b] = 1;
	else if (b == 1)
		m[a][b] = a;
	else
	{
		if (m[a - 1][b] == -1)
			Combinatorio(m, a - 1, b);
		if (m[a - 1][b - 1] == -1)
			Combinatorio(m, a - 1, b - 1);
		m[a][b] = m[a - 1][b] + m[a - 1][b - 1];
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	using tMatriz = std::vector < std::vector <int > >;
	int fila, columna;
	std::cin >> fila >> columna;
	if (!std::cin) return false;
	else {
		tMatriz matriz(fila + 1, std::vector <int >(columna + 1, -1));

		for (int i = 0; i < fila; i++)
			for (int j = 0; j < columna; j++)
				matriz[i][j] = -1;
		Combinatorio(matriz, fila, columna);
		std::cout << matriz[fila][columna]<<"\n";
	}




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