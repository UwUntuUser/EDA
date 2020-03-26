// Nombre del alumno Miguel robledo blanco
// Usuario del Juez  e61


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

// función que resuelve el problema
// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<algorithm>

struct tSol {
	bool oK;
	int maximo;
	int minimo;
};

/*
				    { Co		si n=1
Recurrencia  T(n)=	{
				    {2T(n/2)    si n>1

*/

    
//función devuele el minimo  valor para una parte del vector y ademas comprueba
//si esa parte esta parcialmente ordenada
tSol parcialmenteOrdenado(std::vector<int>const & vector, int inicio, int fin)
{

	if (inicio + 1 == fin) //vector de un elemenetos
		return{ true,vector[inicio],vector[inicio] };
	else
	{
		tSol vDerecha, vIzquierda;
		int mitad = (inicio+fin) / 2;
		vIzquierda= parcialmenteOrdenado(vector, inicio, mitad); //parte izquierda ordenada
		vDerecha= parcialmenteOrdenado(vector, mitad, fin); //parte derecha ordenada
		if ((vIzquierda.oK && vDerecha.oK) && (vIzquierda.minimo <= vDerecha.minimo) && (vDerecha.maximo >= vIzquierda.maximo)) // condiciones para parcialmente ordenado
			return { true, vDerecha.maximo, vIzquierda.minimo };
		else
			return { false,vDerecha.maximo, vIzquierda.minimo };
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int num;
	std::cin >> num;
	std::vector<int> v;
	if (num == 0)
		return false;
	while (num != 0)
	{
		v.push_back(num);
		std::cin >> num;
	}
	tSol solucion = parcialmenteOrdenado(v, 0, v.size());
	if(solucion.oK)
		std::cout << "SI"<<std::endl;
	else
		std::cout << "NO"<<std::endl;

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




