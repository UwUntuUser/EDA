// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include"hashmap_eda.h"
#include<vector>

void resolver(std::vector<int> vec, unordered_map<int, int>& mapa, std::vector<int>& solucion)
{
    for (int a : vec)
    {
        mapa[a]++;
        if (mapa[a] == 1)
            solucion.push_back(a);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamanio;
    std::cin >> tamanio;
    if (!std::cin)
        return false;
    std::vector<int> aux;
    std::vector<int>solucion;
    int a;

    for (int i = 0; i < tamanio; i++)
    {
        std::cin >> a;
        aux.push_back(a);
    }

    unordered_map<int, int>mapa;
    resolver(aux, mapa, solucion);

    for (auto it = solucion.begin(); it != solucion.end(); ++it)
    {
        auto valor = mapa.find(*it);
        std::cout << valor->clave << " ";
        std::cout << valor->valor << std::endl;

    }
    std::cout << "---" << std::endl;
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


    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}