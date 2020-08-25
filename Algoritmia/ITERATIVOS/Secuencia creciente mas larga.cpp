// Nombre del alumno e61
// Usuario del Juez miguel robledo


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

/*
consecutivos(vector, ini,fin) = Pt k : ini<= k <=fin : vector[k]+1== vector[k+1]
secuenciaMax(secuencia, long) = 

Invariante = {1<=cont<i ^ 0<=aux.longuitud<=i ^ 0<=aux.inicio<=i}


*/
// función que resuelve el problema
struct tSol {
	int inicio;
	int longuitud;
};

tSol secuencia(std::vector<int>const& datos)
{
	tSol aux = { 0 , 1 };
	int cont = 1;
	int anterior = datos[0];
	for (int i = 1; i < datos.size(); i++)
	{
		if (datos[i] != anterior + 1) // si el numero no es consecutivo
		{
			cont = 1;
		}
		else
		{
			cont++;
			if (cont > aux.longuitud)
			{
				aux.longuitud = cont;
				aux.inicio = i - cont + 1;
			}
		}
		anterior = datos[i];
	}
	return aux;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tamanio;
	std::cin >> tamanio;
	if (tamanio == 0)
		return false;
	std::vector<int>datos(tamanio);
	for (int i = 0; i < tamanio; i++)
		std::cin >> datos[i];
	tSol sol = secuencia(datos);
	std::cout << sol.inicio << " " << sol.longuitud << "\n";
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
