#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <utility>
#include <cstdlib>

// Datos de entrada
struct tDatos {
	int numJuguetes, numNinos;
	std::vector<std::vector<int> > satis;
};

// Soluci�n que se va construyendo
struct tSol {
	std::vector<int> sol;
	int sumaSatis;
};
// Par�metros:
// datos de entrada
// k - etapa
// s - Soluci�n que se va construyendo
// asignados - Vector de dimensi�n el n�mero de juguetes marca los juguetes ya asignados
// acum - vector con la satisfacci�n acumulada desde cada ni�o hasta el �ltimo
// satisMejor - la satisfaci�n m�xima
void resolver(tDatos const& datos, int k, tSol & s, std::vector<bool>& asignados, int& satisMejor,
	std::vector<int> const& acum) {
	for (int i = 0; i < datos.numJuguetes; ++i) {
		s.sol[k] = i;
		if (!asignados[i]) { // es Valida
			s.sumaSatis += datos.satis[k][i];
			asignados[i] = true; // marca
			if (k == s.sol.size() - 1) { // es solucion
				if (s.sumaSatis > satisMejor) satisMejor = s.sumaSatis; // soluci�n mejor
			}
			else { // No es soluci�n
				if (s.sumaSatis + acum[k + 1] > satisMejor) // Estimaci�n
					resolver(datos, k + 1, s, asignados, satisMejor, acum);
			}
			asignados[i] = false; // desmarca
			s.sumaSatis -= datos.satis[k][i];
		}
	}
}

bool resuelveCaso() {
	// Lectura de los datos de entrada
	tDatos datos;
	std::cin >> datos.numJuguetes;

	if (!std::cin) return false;
	std::cin >> datos.numNinos;


	// Lee la satisfaccion que les proporcionan los juguetes a los ni�os
	for (int i = 0; i < datos.numNinos; ++i) {
		std::vector<int> aux(datos.numJuguetes);
		for (int j = 0; j < datos.numJuguetes; ++j) 
			std::cin >> aux[j];
		datos.satis.push_back(aux);
	}


	// Calcula el vector de m�ximos
	std::vector<int> acum(datos.numNinos);
	for (int i = 0; i < datos.numNinos; ++i) 
	{
		int auxMax = datos.satis[i][0];
		for (int j = 1; j < datos.numJuguetes; ++j)
			if (auxMax < datos.satis[i][j]) auxMax = datos.satis[i][j];
		acum[i] = auxMax;
	}

	// Vector acumulados
	for (int i = (int)acum.size() - 1; i > 0; --i) {
		acum[i - 1] += acum[i];
	}

	// Obtiene una inicializaci�n posible para la soluci�n mejor
	int satisMejor = 0;
	for (int i = 0; i < datos.numNinos; ++i) {
		satisMejor += datos.satis[i][i];
	}

	// Prepara los datos de la funci�n
	tSol s;
	s.sol.assign(datos.numNinos, 0);
	s.sumaSatis = 0;
	std::vector<bool> asignados(datos.numJuguetes, false);
	resolver(datos, 0, s, asignados, satisMejor, acum);
	std::cout << satisMejor << '\n';
	return true;
}


int main() {
	#ifndef DOMJUDGE
	std::ifstream in("/Users/isabel/Dropbox/XcodePrograms/Prueba/datos1.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
	#endif
	

	while (resuelveCaso())
		;


	#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif
	return 0;
}
