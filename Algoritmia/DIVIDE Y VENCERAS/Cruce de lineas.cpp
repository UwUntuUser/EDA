// Nombre del alumno miguel robledo
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

struct tSol {
	int inicio;
	int acaba;
};


tSol cruceCurvas(std::vector<int>const&asciende, std::vector<int>const&desciende, int inicio, int final, bool& encontrado)
{
	//si la asciende[mitad]>desciende[mitad] el corte esta en la izda
	//si la asciende[mitad]<desciende[mitad] el corte esta en la drcha

	tSol sol;

	if (inicio + 1== final) // caso base de un elemento
	{
		if (asciende[inicio] == desciende[inicio])
		{
			encontrado = true;
			return{ inicio,inicio };
		}
		else // si son distintas, compruebo en que parte del vector estoy
		{
			if (inicio == 0 && asciende[inicio] > desciende[inicio]) // necesaria la segunda parte de la condicion
				return{ -1,0 };
			else if (inicio == asciende.size() - 1)
				return{ inicio,inicio+1 };
			else
				return{ inicio,inicio + 1 };
		}
	}
	else
	{
		int mitad = (inicio + final) / 2;
		if (asciende[mitad] > desciende[mitad]) // hacia la izda
			sol = cruceCurvas(asciende, desciende, inicio, mitad, encontrado);
		else
			sol = cruceCurvas(asciende, desciende, mitad, final, encontrado);
	}
	return sol;
}

bool resuelveCaso() {
	// leer los datos de la entrada
	int tamanio;
	tSol sol;
	bool encontrado = false;
	std::cin >> tamanio;
	if (tamanio==0)
		return false;
	std::vector<int>asciende(tamanio);
	std::vector<int>desciende(tamanio);

	for (int &i : asciende)
		std::cin >> i;
	for (int &i : desciende)
		std::cin >> i;

	sol = cruceCurvas(asciende, desciende,0,tamanio,encontrado);

	if (encontrado)
		std::cout << "SI " << sol.inicio << std::endl;
	else
		std::cout << "NO " << sol.inicio<<" "<<sol.acaba << std::endl;

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
