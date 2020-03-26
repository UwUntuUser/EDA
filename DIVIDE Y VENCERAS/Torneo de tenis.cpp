// Nombre del alumno miguel robledo blanco
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include<vector>

struct tDatos {
	int ronda;
	int partidos;
};
tDatos PartidoTenis(std::vector<std::string>const &jugadores, int ronda, int ini, int fin, int &partidos)
{
	tDatos izda, drcha;
	tDatos sol;
	if (ini + 1 == fin) // caso base de dos elementos
	{
		if (jugadores[ini] != "NP" && jugadores[ini + 1] != "NP")
			return { 1,1 };
		return { 1,0 };
	}
	else
	{
		int mitad = (ini + fin) / 2;
		izda = PartidoTenis(jugadores, ronda, ini, mitad-1, partidos);
		drcha = PartidoTenis(jugadores, ronda, mitad , fin-1,partidos);
		if (izda.ronda <= ronda && drcha.ronda <= ronda)
			return{ izda.ronda+1 ,izda.partidos + drcha.partidos+1 };
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tamanio, ronda;
	std::cin >> tamanio;
	if (!std::cin) return false;
	std::cin >> ronda;
	std::vector<std::string>jugadores(tamanio);
	for (int i = 0; i < tamanio; i++)
		std::cin >> jugadores[i];

	int partidos = 0;
	tDatos d;
	d.partidos = 0;
	d.ronda = 0;
	d = PartidoTenis(jugadores, ronda, 0, tamanio,partidos);
	std::cout << d.partidos << "\n";
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