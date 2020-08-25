// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
struct tMaximos {
	int presupuestoMax;
	int presupuestoActual;
	int superficieMejor;
	int superficieActual;
};
void DecorarCasa(std::vector<std::pair<int, int>>const& datos, int etapa, tMaximos &maximos, std::vector<bool>&sol, std::vector<int>const& acum)
{
	//resuelto con arbol binario
	// no hace falta comprobar si el objeto esta disponible, solo se usa uno una vez por llamada
	//añado el objeto
	sol[etapa] = true;
	if (maximos.presupuestoActual + datos[etapa].first <= maximos.presupuestoMax) // no nos hemos pasado, es buena
	{
		maximos.presupuestoActual += datos[etapa].first;
		maximos.superficieActual += datos[etapa].second;
		if (etapa == (int)datos.size() - 1) // si hemos llegado al final 
		{
			if (maximos.superficieActual > maximos.superficieMejor)
				maximos.superficieMejor = maximos.superficieActual;
		}
		else
		{
			if (maximos.superficieActual + acum[etapa + 1] > maximos.superficieMejor)
				DecorarCasa(datos, etapa + 1, maximos, sol,acum);
		}
		maximos.presupuestoActual -= datos[etapa].first;
		maximos.superficieActual -= datos[etapa].second;
	}
	//no añado el objeto
	sol[etapa] = false;
	if (etapa == (int)datos.size() - 1) // si hemos llegado al final
	{
		if (maximos.superficieActual > maximos.superficieMejor)
			maximos.superficieMejor = maximos.superficieActual;
	}
	else
	{
		if (maximos.superficieActual + acum[etapa + 1] > maximos.superficieMejor)
			DecorarCasa(datos, etapa + 1, maximos, sol, acum);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numObjetos, presupuesto;
	std::cin >> numObjetos;
	std::cin >> presupuesto;
	if (!std::cin)
		return false;
	std::vector<std::pair<int,int>> datos(numObjetos); // el primer int es coste  y el segundo superficie
	for (int i = 0; i < numObjetos; i++)
	{
		std::cin >> datos[i].first;
		std::cin >> datos[i].second;
	}


	std::vector<int>acum(numObjetos,0);
	for (int i = 0; i <(int) datos.size(); i++)
		acum[i] = datos[i].second;
	for (int i = datos.size() - 1; i > 0; i--)			
		acum[i - 1] += acum[i];


	std::vector<bool>sol(numObjetos);
	tMaximos maximos;
	maximos.presupuestoActual = 0;
	maximos.presupuestoMax = presupuesto;
	maximos.superficieActual = 0;
	maximos.superficieMejor = 0;
	DecorarCasa(datos, 0, maximos, sol,acum);
	std::cout << maximos.superficieMejor << "\n";
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

nFUncionarios == nTareas
nFUncionarios
ntareas
matriz[funcionarios]{tareas] // tiempo que tarda en hacer una tarea
las posiciones del vector sol son los funcionarios, y lo que va dentro del vector las tareas

void funcionarios(int etapa,int numtareas, int numFuncionarios,std::vector<int>&sol,int tiempoActual, std::vector<bool> &marcas,int &tiempoMejor)
{
	for(int i=0; i<numTareas; i++)
	{
		sol[etapa]=i;
		tiempoActual+=d.tiempos[etapa][i];
		if(!marcas[etapa]
			{
				marcas[i]=true;
				if(essolucion)
					...
				else if(tiempoActual + estimacion <solMejor)
			}
	}
}

sumando la diaginal obtienes una primera solucion valida para solMejor


*/