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

    Jugador jugador1;
    Jugador jugador2;

    bool banderaUltimoGanador = false;

    //FUNCION MENU()
    mostrarMenu(jugador1, jugador2, banderaUltimoGanador); //MUESTRA el menu y maneja la opcion elegida

    return 0;
}
