// Nombre del alumno miguel robledo blanco
// Usuario del Juez f47


#include <iostream>
#include <iomanip>
#include <fstream>
#include"hashmap_eda.h"



bool resuelveCaso() {
    // leer los datos de la entrada
    int numEjercicios;
    map<std::string, int>alumnos;
    std::cin >> numEjercicios;
    std::cin.ignore();
    if (numEjercicios == 0)
        return false;
    for (int i = 0; i < numEjercicios; i++)
    {
        std::string alumno;
        std::string nota;

        getline(std::cin, alumno);
        getline(std::cin, nota);

        if (alumnos.count(alumno) == 0)//no existe
            alumnos[alumno] = 0;
        alumnos[alumno] += (nota == "INCORRECTO") ? -1 : 1;
    }

    for (auto it : alumnos)
    {
        if (it.valor != 0)
            std::cout << it.clave << ", " << it.valor << std::endl;
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
