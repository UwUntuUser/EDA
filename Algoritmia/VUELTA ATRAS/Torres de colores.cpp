// Nombre del alumno miguel robledo blanco
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include<string>


void escribirSolucion(std::vector<int>&vector)
{
	for (int i = 0; i < (int)vector.size(); i++)
	{
		if (vector[i] == 0)
			std::cout<<"azul ";
		else if (vector[i] == 1)
			std::cout << "rojo ";
		else
			std::cout << "verde ";
	}
	std::cout << "\n";
}

bool esValida(std::vector<int>&sol, std::vector<int>const& marcas, std::vector<int>const& numFichasUsadas,int actual, int colorUsado)
{
	//debe comprobar que no haya dos verdes seguidas y que no se hayan usado mas fichas de las que hay
	if (colorUsado == 2 && actual>0 && sol[actual] == sol[actual - 1]) // si no se pone la condicion de actual>0 salta excepcion cuando la primera ficha es verde
		return false;
	if (sol[0] != 1) // la primera tiene que ser roja
		return false;
	if (numFichasUsadas[2] > numFichasUsadas[0]) // si verdes > azules
		return false;
	if (numFichasUsadas[colorUsado] > marcas[colorUsado]) // nos hemos quedado sin fichas 
		return false;
	return true;

}

bool esSolucion(std::vector<int>&numFichasUsadas)
{
	if (numFichasUsadas[1] > (numFichasUsadas[0] + numFichasUsadas[2])) // rojo > verde + azul 
		return true;
	return false;
}
void torresColores(int etapas, int actual, std::vector<int>&sol, std::vector<int>&marcas,std::vector<int>&numFichasUsadas, bool &existe)
{
	for (int i = 0; i < 3; ++i) //la i nos marca el color que estamos usando
	{
		sol[actual] = i;
		numFichasUsadas[i]++;
		if (esValida(sol, marcas, numFichasUsadas, actual, i) )
		{
			if (actual == sol.size() - 1)
			{
				if (esSolucion(numFichasUsadas))
				{
					escribirSolucion(sol);
					existe = true;
				}
			}
			else
				torresColores(etapas, actual + 1, sol, marcas, numFichasUsadas, existe);
		}
		numFichasUsadas[i]--;
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int altura, etapas, actual = 0;
	bool exito = false;
	std::cin >> altura;
	etapas = altura;
	if (altura == 0)
		return false;
	else
	{
		std::vector<int>sol(altura); //sobre el que se construye la solucion
		std::vector<int>numFichasUsadas(3); //sobre el que se apunta cuantas fichas llevamos de cada color
		std::vector<int>marcas(3); //para guardar el numero de fichas de cada color

		for (int i = 0; i < 3; i++)
			std::cin >> marcas[i];
		torresColores(etapas, actual, sol, marcas, numFichasUsadas, exito);
		if (!exito) std::cout << "SIN SOLUCION \n";
		std::cout << "\n";
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
