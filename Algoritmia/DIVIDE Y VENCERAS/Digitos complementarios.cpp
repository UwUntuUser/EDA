// Nombre del alumno miguel robledo blanco
// Usuario del Juez e61


#include <iostream>
#include <iomanip>
#include <fstream>

//EXPLICACION DE LOS NUMEROS EN LA FUNCION RECURSIVA

//	int ultimo = num % 10;
//	int comple = 9 - ultimo;
//	comple = comple*m + hecho; 
//		sustutucion
//	comple = (9 - ultimo)*m + hecho     comple = (9 - num % 10) * m + hecho

int InComp(int num, int m)
{
	int inverso = 0;
	if (num == 0)
		inverso = m;
	else
		inverso = InComp(num / 10, m * 10 + num % 10);
	return inverso;
}
int comp(int num, int m, int hecho) // m contador de vueltas
{
	int complementario;
	if (num <10)
	{
		complementario = ((9 - num)*m + hecho);
	}
	else
	{    
		complementario = comp(num / 10, m*10, (9 - num % 10) * m + hecho);
		//inverso = InComp(complementario, m * 10 + num % 10);
	}
	return complementario;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int num;
	std::cin >> num;
	int complementario, InversoCom;
	complementario = comp(num, 1,0);
	InversoCom = InComp(complementario, 0);
	std::cout << complementario << " " <<InversoCom<< std::endl;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
	{
		resuelveCaso();
	}


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}