// Nombre del alumno miguel robledo blanco
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include<string>

bool esValido(std::vector<int>&sol, std::vector<std::string>&juguetes, int etapa)
{

	if (etapa == 0)
		return true;
	else
	{
		if (etapa % 2 == 0) //si no hemos acabado con el niño
			return true;
		else
		{
			// esta condicion sirve para evitar darle dos veces el regalo 0 o el regalo 1 y para que solo salga (0 1) y no (1 0)
			if (sol[etapa] == sol[etapa - 1] || sol[etapa] < sol[etapa - 1]) 
				return false;
			else
			{
				//esta condicio sirve para no darle el mismo tipo de regalo
				if (juguetes[sol[etapa]] == juguetes[sol[etapa - 1]])
					return false;
				else
					return true;
			}
		}
	}
}

void escribirSol(std::vector<int>const&sol)
{
	for (int i : sol)
		std::cout << i << " ";
	std::cout << "\n";
}

void repartirRegalos(std::vector<int>&sol, std::vector<std::string>&juguetes, int numNinios,int numJuguetes,int etapa,bool &exito)
{
	//max etapas = numNinios * 2
	//cada niño son 2 etapas
	//etapa%2!=0 -> etapa impar -> fin del niño
	for (int i = 0; i < numJuguetes; i++)
	{
		sol[etapa] = i;
		if (esValido(sol,juguetes, etapa)) //so hemos acabado de repartir con el niño y
		{
			if (etapa == (numNinios * 2) - 1)
			{
				escribirSol(sol);
				exito = true;
			}
			else
				repartirRegalos(sol,juguetes, numNinios, numJuguetes, etapa + 1, exito);
		}

	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numJuguetes, numNinios;
	bool exito = false;
	std::cin >> numJuguetes >> numNinios;
	if (!std::cin)
		return false;
	else
	{
		std::vector<std::string>juguetes(numJuguetes);
		std::vector<int>sol(numNinios * 2); // a cada niño le tenemos que dar solamente 2 regalos. Si hay 2 niños hay que repartir 4 regalos
		for (int i = 0; i < numJuguetes; i++)
			std::cin >> juguetes[i];
		repartirRegalos(sol,juguetes,numNinios, numJuguetes, 0,exito);
		if (!exito) std::cout << "SIN SOLUCION \n";
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