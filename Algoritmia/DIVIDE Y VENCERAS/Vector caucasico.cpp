// Nombre del alumno Miguel robledo blanco
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

/*
			   { C1           si n=1
Recursividad:  {
			   { 2T(n/2) +c1  si n>=2

Coste lineal = O(n)
*/
struct tSol {
	bool ok;
	int contador;
};

tSol caucasico(std::vector<int>const& vector, int inicio, int fin)
{
	//tSol solucion;
	if (inicio +1 == fin)
	{
		int pares;
		if (vector[inicio] % 2 == 0)
			return { true, 1 };
		else
			return { true,0 };
	}
	else
	{
		int mitad = (inicio + fin) / 2;
		tSol izda = caucasico(vector, inicio, mitad);
		tSol drcha = caucasico(vector, mitad, fin);
		return{ izda.ok && drcha.ok && std::abs(izda.contador - drcha.contador) <= 2, izda.contador + drcha.contador };
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tamanio;
	std::cin >> tamanio;
	if (tamanio == 0)
		return false;
	else
	{
		std::vector<int>v(tamanio);
		for (int i = 0; i < tamanio; i++)
			std::cin >> v[i];
		if (caucasico(v, 0, v.size()).ok)
			std::cout << "SI\n";
		else
			std::cout << "NO\n";
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
