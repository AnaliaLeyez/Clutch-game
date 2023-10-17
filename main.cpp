#include <iostream>
#include <locale>
#include <cstdlib> // Necesario para rand() y srand()
#include <ctime>   // Necesario para time()
#include "funciones.h"
#include "estructuras.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Spanish");
    srand(time(0));
    int opcion; // INGRESO AL SWITCH DE OPCIONES
    Jugador jugador1 = {"Jugador 1", {}};// FUNCION INGRESO DE NOMBRES
    Jugador jugador2 = {"Jugador 2", {}};// FUNCION INGRESO DE NOMBRES
    //FUNCION MENU()
    mostrarMenu(opcion, jugador1, jugador2); //MUESTRA el menu y maneja la opcion elegida

    //MENU con 3 funciones => 1 - JUGAR(), 2 - ESTADISTICAS(), 3 - CREDITOS;

    return 0;
}
