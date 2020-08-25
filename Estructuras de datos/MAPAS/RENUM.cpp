// Nombre del alumno miguel robledo blanco
// Usuario del Juez f47

#include <iostream>
#include <iomanip>
#include <fstream>
#include"hashmap_eda.h"
#include"treemap_eda.h"

struct intruccion
{
    std::string comando;
    int valor;
};


void resuelveCaso() {
    // leer los datos de la entrada
    int c = 10;
    int linea;
    intruccion aux;

    map<int, intruccion> programa;
    unordered_map<int, int> correlacion;
    
    std::cin >> linea;
    while (linea != 0)
    {
        std::cin >> aux.comando;
        if (aux.comando == "GOTO" || aux.comando == "GOSUB")
            std::cin >> aux.valor;
        programa[linea] = aux;
        correlacion[linea] = c;
        c += 10;
        std::cin >> linea;
    }

    for (auto it : programa)
    {
        std::cout << correlacion[it.clave] <<" "<< it.valor.comando<<" ";
        if (it.valor.comando == "GOTO" || it.valor.comando == "GOSUB")
            std::cout << correlacion[it.valor.valor] << std::endl;
    }
    std::cout << std::endl;
    std::cout << "---" << std::endl;
    // escribir sol


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
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}