// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<sstream>
#include<set>
#include"treemap_eda.h"

using palabra = std::string;
using apariciones = std::set<int>;

std::string to_lower(std::string w)
{
    std::string final;
    for (char c : w)
        final += tolower(c);
    return final;
}
void mostrar_conjunto(std::set<int>conj)
{
    for (int a : conj)
        std::cout << a << " ";
    std::cout << std::endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamanio;
    std::cin >> tamanio;
    if (tamanio == 0)
        return false;
    std::cin.ignore();

    std::string linea;
    std::string actual;
    map<palabra, apariciones>referencias;

    for (int i = 1; i <= tamanio; i++)
    {
        getline(std::cin, linea);
        std::stringstream aux(linea);
        while (aux >> actual)
        {
            std::string minusculas = to_lower(actual);
            if (referencias.count(minusculas) == 0)// si a palabra es nueva
            {
                std::set<int> fila;
                fila.insert(i);
                referencias[minusculas] = fila;
            }
            else
                referencias[minusculas].insert(i);
        }

    }

    for (auto it : referencias)
    {
        if (it.clave.size() > 2)
        {
            std::cout << it.clave << " ";
            mostrar_conjunto(it.valor);
        }
    }

    std::cout << "---\n";
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
