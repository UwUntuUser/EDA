// Nombre del alumno Miguel robledo blanco
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

struct tSol {
	int suma;
	int ini;
	int longuitud;
};

tSol cena(std::vector<int>const&datos)
{
	tSol aux;     // para la cadena auxiliar
	tSol maxima;  // para la cadena mejor
	aux.suma = 0;
	aux.longuitud = 0;
	aux.ini = 0;
	maxima.suma = 0;
	for (int i = 0; i < datos.size(); i++)
	{
		aux.suma += datos[i];
		if (aux.suma > 0)
		{
			aux.longuitud++;
			if (aux.suma > maxima.suma)
			{
				maxima.suma = aux.suma;
				maxima.ini = aux.ini;
				maxima.longuitud = aux.longuitud;
			}
		}
		else
		{
			aux.suma = 0;
			aux.longuitud = 0;
			aux.ini = i+1; // la siguiente
		}

	}
	return maxima;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tamanio;
	std::cin >> tamanio;
	if (!std::cin)
		return false;
	std::vector<int>datos(tamanio);
	for (int i = 0; i < tamanio; i++)
		std::cin >> datos[i];
	tSol sol = cena(datos);
	std::cout << sol.suma <<" "<< sol.ini <<" "<< sol.longuitud << "\n";

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