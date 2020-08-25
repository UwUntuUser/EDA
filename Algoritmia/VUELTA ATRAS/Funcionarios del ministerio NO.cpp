// Nombre del alumno Miguel robledo blanco
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include<algorithm>
#include <utility>
struct tDatos {
	int numFuncionarios;
	int numTareas;
	std::vector<std::vector<int>> tiempos;
};
void funcionarios(int etapa, tDatos const& d, std::vector<int>&sol, int tiempoActual, std::vector<bool> &marcas, int &tiempoMejor)
{
	for (int i = 0; i < d.numTareas; i++)
	{
		sol[etapa] = i;
		tiempoActual += d.tiempos[etapa][i];
		if (!marcas[i])
		{
			marcas[i] = true;
			if (etapa == (int)sol.size() - 1)
			{
				if (tiempoActual < tiempoMejor)
					tiempoMejor = tiempoActual;
			}
			else 
				funcionarios(etapa + 1, d, sol, tiempoActual, marcas, tiempoMejor);
			marcas[i] = false;
		}
		tiempoActual -= d.tiempos[etapa][i];
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	tDatos datos;
	std::cin >> datos.numFuncionarios;
	if (datos.numFuncionarios == 0)
		return false;
	datos.numTareas = datos.numFuncionarios;

	for (int i = 0; i < datos.numFuncionarios; i++)
	{
		std::vector<int>aux(datos.numFuncionarios);
		for (int j = 0; j < datos.numTareas; j++)
			std::cin >> aux[j];
		datos.tiempos.push_back(aux);
	}

	int tiempoMejor = 0;
	std::vector<bool>marcas(datos.numFuncionarios, false); // si esta false, la tarea i no se esta usando
	std::vector<int>sol(datos.numFuncionarios); // lo que va dentro son tareas
	for (int i = 0; i < datos.numFuncionarios; i++)
		tiempoMejor += datos.tiempos[i][i];
	funcionarios(0, datos, sol, 0, marcas, tiempoMejor);
	std::cout << tiempoMejor << "\n";
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}


/*
COMBINACIONES SIN REPETICION

ABC == BCA == CBA

sol(longuitudPalabra) donde guardo letras

void Combinaciones( int numLetras, int tamanioPalabra,int etapa, std::vector<char>&sol,char primeraLetra) // iniciar la primera letra
{
for(char i= primeraLetra; i<primeraLetra + numLetras - etapa;++i) // puedes pasar un parametro que sea la ultima letra
{
sol[etapa]= i;
if(etapa= tamanioPalabra-1)
{
escribirSol(...);
}
else
Combinaciones(numLetras,tamanioPalabra, etapa+1, sol, i+1); // el i+1 existe porque la siguiente letra con la que empiezas es la siguiente a la que estas tratando en la etapa actual
// si quitamos i+1 y ponemos i salen con repeticion, si ponemos +1 salen sin repeticion
}
}

FUNCIONARIOS DEL MINISTERIO (EL ULTIMO EJERCICIO DE ESCUCHAR MUSICA ES ARBOL BINARIO PERO SIN SI/NO)
*/