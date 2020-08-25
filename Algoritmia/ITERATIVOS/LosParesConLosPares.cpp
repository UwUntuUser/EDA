// Nombre del alumno miguel robledo
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

bool par(int n)
{
	return n % 2 == 0;
}
void ParesImpares(std::vector<int>&datos)
{
	int k = 0;
	for (int i = 0; i < datos.size(); i++)
	{
		if (par(k) && par(datos[i]) || !par(k) && !par(datos[i]))
		{
			std::swap(datos[k], datos[i]);
			k++;
			if (k <= i) k++;
		}
	}
	if (!par(k))
		k--;
	datos.resize(k);
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
	ParesImpares(datos);
	for (int i = 0; i < datos.size(); i++)
		std::cout << datos[i] << " ";
	std::cout << "\n";

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