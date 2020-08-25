// Nombre del alumno Miguel robledo
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include<algorithm>

/*
					{c0         si n =2
Recursividad: T(n)= {
					{ T(n/2)+c0 si n>2

O(n)=log(n)
*/

int curva(std::vector<int>const& v, int ini, int fin)
{
	int menor;
	if (ini == fin) //vector de un elemento
			menor = v[ini];
	else if (ini + 1 == fin) //vector de dos elementos
	{
		if (v[ini] > v[ini + 1])
			menor = v[ini + 1];
		else
			menor = v[ini];
	}
	else
	{
		int mitad = (ini + fin) / 2;
		menor = v[mitad];
		if (menor > v[mitad + 1])//el menor se encuentra por la derecha
			menor = curva(v, mitad+1, fin);
		else // (v[mitad] > v[mitad - 1]) //el menor se encuentra por la izquierda
			menor = curva(v, ini, mitad);
	}
	return menor;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tamanio;
	std::cin >> tamanio;
	if (!std::cin)
		return false;
	else
	{
		std::vector<int>vector(tamanio);
		for (int i = 0; i < tamanio; i++)
			std::cin >> vector[i];
		int menor = curva(vector, 0, tamanio-1);
		std::cout << menor << std::endl;
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