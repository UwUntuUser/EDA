// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include"queue_eda.h"

template<typename T>
class ListaDuplicada : public queue<T>
{
	using Nodo = typename queue<T>::Nodo;

public:

	void duplica()
	{
		Nodo * primero = this->prim;
		int tam = this->nelems;
		for (int i = 0; i < tam; i++)
		{
			Nodo* siguiente = primero->sig;
			primero->sig = new Nodo(primero->elem, siguiente);
			primero = siguiente;
			this->nelems++;
		}
	}

	void mostrar()
	{
		if (!this->empty())
		{
			Nodo* aux = this->prim;
			for (int i = 0; i < this->nelems; i++)
			{
				std::cout << aux->elem << " ";
				aux = aux->sig;
			}
		}
	}
};



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int elem;
	std::cin >> elem;

	if (!std::cin)
		return false;

	ListaDuplicada<int> lista;
	while (elem != 0)
	{		
		lista.push(elem);
		std::cin >> elem;
	}

	lista.duplica();
	lista.mostrar();
	std::cout << "\n";



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