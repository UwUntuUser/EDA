// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<sstream>
#include"hashmap_eda.h"

void leerDiccionario(map<std::string, int>& diccionario,std::string linea)
{
    std::stringstream aux(linea);
    std::string clave;
    int valor;
    while (aux >> clave && aux >> valor)
        diccionario[clave] = valor;
}

void resuelveCaso() {
    // leer los datos de la entrada
    std::string viejo;
    std::string nuevo;
    map<std::string, int> dicc_old;
    map<std::string, int>dicc_new;


    getline(std::cin, viejo);
    getline(std::cin, nuevo);
    
    leerDiccionario(dicc_old, viejo);
    leerDiccionario(dicc_new, nuevo);
    
    bool hay_suma = false;
    bool hay_resta = false;
    bool hay_ast = false;
    std::string suma = "+ ";
    std::string resta = "- ";
    std::string asterisco = "* ";

    for (auto it : dicc_new)
    {
        if (dicc_old.count(it.clave) == 0) // si la clave no existe en el diccionario antiguo es una clave nueva
        {
            suma.append(it.clave);
            suma.append(" ");
            hay_suma = true;
        }
        else if (dicc_old.count(it.clave) != 0 && dicc_old[it.clave] != dicc_new[it.clave]) // si los valores son distintos es una clave modificada
        {
            asterisco.append(it.clave);
            asterisco.append(" ");
            hay_ast = true;
        }
    }

    for (auto it : dicc_old) // para las claves eliminadas
    {
        if (dicc_new.count(it.clave) == 0)
        {
            resta.append(it.clave);
            resta.append(" ");
            hay_resta = true;
        }
    }
    if (hay_suma || hay_resta || hay_ast)
    {
        if (hay_suma)
            std::cout << suma << std::endl;
        if (hay_resta)
            std::cout << resta << std::endl;
        if (hay_ast)
            std::cout << asterisco << std::endl;
    }
    else
        std::cout << "SIN CAMBIOS\n";
    std::cout << "---\n";

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::string basura;
    std::cin >> numCasos;
    getline(std::cin, basura);
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}