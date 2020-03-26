// Nombre del alumno miguel robledo
// Usuario del Juez e61

#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

// función que resuelve el problema

int valla(std::vector<int>const&datos, int metros,bool &encontrado)
{
	int numCerosActual = 0;
	int numCerosMaximo = 1; // para cuando en la secuencia no haya ningun cero
	int comienzo = 0;
	for (int i = 0; i < metros; i++) // iniciar la ventana
	{
		if (datos[i] == 0)
		{
			numCerosActual++;
			encontrado = true;
		}
	}
	numCerosMaximo = (numCerosActual >= numCerosMaximo) ? numCerosActual : numCerosMaximo;
	for (int i = metros; i < datos.size(); i++)
	{
		numCerosActual = (datos[i - metros ] == 0) ? numCerosActual -= 1 : numCerosActual; // eliminamos el ultimo valor
		numCerosActual = (datos[i] == 0) ? numCerosActual += 1 : numCerosActual; // añadimos el nuevo elemento

		if (numCerosActual >= numCerosMaximo)
		{
			comienzo = i - metros + 1;
			encontrado = true;
		}
	}
	return comienzo;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tamanio, metros;
	std::cin >> tamanio;
	if (tamanio == 0)
		return false;
	std::cin >> metros;
	std::vector<int>datos(tamanio);
	for (int i = 0; i < tamanio; i++)
		std::cin >> datos[i];
	bool encontrado = false;
	int posicion = valla(datos, metros,encontrado);
	if (encontrado)
		std::cout << posicion << "\n";
	else
		std::cout << "No hace falta" << "\n";

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
