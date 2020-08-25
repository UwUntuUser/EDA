// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>


/*

					{c0  si n=2
Recursividad: T(n)= {
					{T(n/2)+c0 si n>2

O(Log n)

*/
char fugado(std::vector<char>const& lleno,int inicio, int fin)
{
	char fuga;
	if (inicio + 2 == fin) //caso bas vector de dos elementos
		fuga = lleno[inicio] + 1;
	else
	{
		int mitad = (inicio + fin) / 2;
		if ((lleno[mitad] - lleno[0]) == mitad) // el faltante esta hacia la derecha
			fuga = fugado(lleno, mitad, fin);
		else
			fuga = fugado(lleno, inicio, mitad+1);
	}
	return fuga;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	char inicio, fin;
	std::cin >> inicio;
	std::cin>>fin;
	std::vector<char>faltante;
	char aux;
	for (int i = 0; i < (fin - inicio); i++) //cargo el vector con los elementos
	{
		std::cin >> aux;
		faltante.push_back(aux);
	}
	if (faltante[0] != inicio) //si el faltante es el primer elemento
		std::cout << inicio << std::endl;
	else if (faltante[faltante.size() - 1] != fin)// si el faltante es el ultimo elemento
		std::cout << fin << std::endl;
	else
	{
		char fuga = fugado(faltante, 0, faltante.size());
		std::cout << fuga << std::endl;
	}
	//char perdido = fugado(vector, 0, tamaño - 1);
	//std::cout << perdido;
	//std::cout <<(char)((e+c)/2) << std::endl;
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