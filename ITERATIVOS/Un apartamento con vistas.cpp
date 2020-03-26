// Nombre del alumno Miguel robledo blanco
// Usuario del Juez e61

#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include<string>
// función que resuelve el problema
struct tDatos {
	std::string id;
	int piso;
	int altura;
};

void vistas(std::vector<tDatos>const& datos, std::vector<tDatos>&sol, bool &encontrado,int &cont)
{
	tDatos mayor;
	mayor.altura = -1;
	mayor.piso = -1;
	int aux = 0;
	for (int i = datos.size() - 1; i >= 0; i--)
	{
		if (mayor.altura < datos[i].piso && datos[i].piso<=datos[i].altura)
		{
			sol.push_back(datos[i]);
			aux++;
			encontrado = true;
			mayor = (mayor.altura < datos[i].altura) ? datos[i] : mayor;
		}
		else
			mayor = (mayor.altura < datos[i].altura) ? datos[i] : mayor;

	}
	cont = aux;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numCiudades;
	bool encontrado = false;
	int cont = 0;
	std::cin >> numCiudades;
	if (numCiudades == 0) return false;
	std::vector<tDatos>datos(numCiudades);
	std::vector<tDatos>sol;
	for (int i = 0; i < numCiudades; i++)
		std::cin >> datos[i].id >> datos[i].altura >> datos[i].piso;
	vistas(datos, sol,encontrado,cont);
	if (!encontrado)
		std::cout << "Ninguno\n";
	else
	{
		std::cout << cont << "\n";
		for (int i = 0; i < sol.size(); i++)
			std::cout << sol[i].id << " ";
		std::cout << "\n";
	}
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
