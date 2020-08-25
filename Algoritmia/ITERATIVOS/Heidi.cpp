// Nombre del alumno miguel robledo blanco
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

struct tSol{
	int longuitud;
};

tSol heidi(std::vector<int>const&entrada, std::vector<int>&salida, int longMin)
{
	//se hace con ventana deslizante
	tSol aux;
	aux.longuitud = 0;
	int numeroActual = entrada[entrada.size() - 1];
	int cont = 0; // para llevar un recuento del numero de cachos de terreno iguales en un mismo llano
	
	for (int i = entrada.size() - 1; i >= 0; i--)
	{
		if (entrada[i] == numeroActual)
		{
			cont++;
			if (i == 0)
			{
				if (cont >= longMin)
				{
					if (aux.longuitud < cont)
					{
						aux.longuitud = cont;
					}
					aux.longuitud = cont;
					salida.push_back(i + cont - 1);
				}
			}
		}
		else if (cont >= longMin)
		{
			if (aux.longuitud < cont)
			{
				aux.longuitud = cont;
			}
			salida.push_back(i + cont);
			cont = 1;
		}
		else
		{
			cont = 1;
			if (entrada[i] > numeroActual)
				numeroActual = entrada[i];
		}
	}
	return aux;
}





// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tamanio, longMin;
	std::cin >> tamanio >> longMin;
	if (!std::cin)
		return false;
	std::vector<int>parcelas(tamanio);
	for (int i = 0; i < tamanio; i++)
		std::cin >> parcelas[i];

	std::vector<int>comienzos;

	tSol sol = heidi(parcelas, comienzos,longMin);

	std::cout << sol.longuitud << " " << comienzos.size() << " ";
	for (int i = 0; i < comienzos.size(); i++)
		std::cout << comienzos[i] << " ";
	std::cout << "\n";
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