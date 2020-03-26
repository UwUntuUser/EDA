// Nombre del alumno Miguel robledo blanco
// Usuario del Juez ...... E61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

struct tSol
{
	bool ok;
	int maximo;
	int minimo;
};

// función que resuelve el problema
tSol disperso(std::vector<int> const & vector, int ini, int fin, int dispersion)
{
	tSol derecha, izquierda;
	//if (ini + 1 == fin) //vector de un elemento
		//return true;
	if (ini + 2 == fin) //vector de dos elementos
		if (vector[ini] < vector[ini + 1])
			return { true, vector[ini],vector[ini + 1] };
	else //vector de mas de dos elementos
	{
		int mitad = (ini + fin) / 2;
		derecha = disperso(vector, mitad, fin, dispersion); //mitad derecha dispersa
		izquierda= disperso(vector, ini, mitad, dispersion); //mitad izquierda dispersa
		if (izquierda.minimo<derecha.minimo && derecha.maximo>izquierda.maximo)
			return { true,derecha.maximo, izquierda.minimo };
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numElem, disp;

	std::cin >> numElem;
	std::cin >> disp;

	int inicio = 0, max = numElem;

	if (!std::cin)
		return false;
	else
	{
		tSol solucion;
		std::vector<int> v(numElem);
		for (int i = 0; i < numElem; i++)
		{
			std::cin >> v[i];
		}
		solucion = disperso(v, inicio, max, disp);
		if (solucion.ok)
			std::cout << "SI" << std::endl;
		else
			std::cout << "NO" <<std::endl;
		return true;

	
	}
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