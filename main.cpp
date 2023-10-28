#include <iostream>
#include <locale>
#include <cstdlib> // Necesario para rand() y srand()
#include <ctime>   // Necesario para time()
#include "rlutil.h"
#include "funciones.h"
#include "estructuras.h"

using namespace std;

int main()
{
    rlutil::setBackgroundColor(rlutil::WHITE);
    rlutil::cls();
    rlutil::setColor(rlutil::BLACK);
    setlocale(LC_ALL, "Spanish");
    srand(time(0));

    // INGRESO AL SWITCH DE OPCIONES
    int opcion;
    Jugador jugador1;
    Jugador jugador2;

    //Array para las estadisticas
    Jugador estadisticas[CARTAS_CORRAL]={};

    //FUNCION MENU()
    mostrarMenu(opcion, jugador1, jugador2, estadisticas); //MUESTRA el menu y maneja la opcion elegida

    //MENU con 3 funciones => 1 - JUGAR(), 2 - ESTADISTICAS(), 3 - CREDITOS;

    return 0;
}
