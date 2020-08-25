// Nombre del alumno Miguel Robledo
// Usuario del Juez f47


#include <iostream>
#include <iomanip>
#include <fstream>
#include<set>
#include<sstream>
#include"treemap_eda.h"

using carton = std::set<int>;
using jugador = std::string;

void cargar_entrada(map<jugador, carton>& mapa, std::string linea)
{
    std::stringstream aux(linea);
    jugador j;
    carton c;
    int numero;

    aux >> j;
    while (aux >> numero)
    {
        if (numero != 0)
            c.insert(numero);
    }
    mapa[j] = c;
}
void mostrar_conjunto(std::set<int>conj)
{
    for (int a : conj)
        std::cout << a << " ";
    std::cout << std::endl;
}

void eliminar(map<jugador, carton>& mapa, int num)
{
    //por cada jugador eliminar de su carton el numero num
    for (auto it : mapa)
    {
        if (mapa[it.clave].count(num) != 0)
            mapa[it.clave].erase(num);
    }
}
bool nadie_acaba(map<jugador, carton>& mapa, std::set<std::string>&ganadores)
{
    bool ok = false;
    for (auto it : mapa)
    {
        if (mapa[it.clave].empty())
        {
            ganadores.insert(it.clave);
            ok = true;
        }
    }
    return ok;
}

bool resuelveCaso() {

    int numJugadores;
    std::cin >> numJugadores;
    if (numJugadores == 0)
        return false;

    std::cin.ignore();
    map<jugador, carton> jugadores;
    std::set<std::string>ganadores;
    std::string linea;


    for (int i = 0; i < numJugadores; i++)
    {
        getline(std::cin, linea);
        cargar_entrada(jugadores, linea);
    }

    getline(std::cin, linea);// leemos los numeros 
    std::stringstream numeros(linea);
    int numero;
    while (numeros >> numero && !nadie_acaba(jugadores,ganadores))
         eliminar(jugadores, numero);
 
    nadie_acaba(jugadores, ganadores);//si ganan en el ultimo numero no se consigue guardar los ganadores

    for (auto it : ganadores)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;

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
