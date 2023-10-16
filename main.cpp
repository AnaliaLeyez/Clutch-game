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
    Carta vMazo[MAZO] =
    {
        {"Diamante", "10", true}, {"Diamante", "J", true}, {"Diamante", "Q", true}, {"Diamante", "K", true}, {"Diamante", "A", true},
        {"Corazon", "10", true}, {"Corazon", "J", true}, {"Corazon", "Q", true}, {"Corazon", "K", true}, {"Corazon", "A", true},
        {"Pica", "10", true}, {"Pica", "J", true}, {"Pica", "Q", true}, {"Pica", "K", true}, {"Pica", "A", true},
        {"Trebol", "10", true}, {"Trebol", "J", true}, {"Trebol", "Q", true}, {"Trebol", "K", true}, {"Trebol", "A", true}
    };
    Carta vMazoMano[MAZO_MANO]={};


    //mostrarMenu(opcion, jugador1, jugador2);
    mezclarMazo(jugador1, jugador2, vMazo, vMazoMano);

    //FUNCION MENU()

    //MENU con 3 funciones => 1 - JUGAR(), 2 - ESTADISTICAS(), 3 - CREDITOS;


    //1-JUGAR()
    //  A - INGRESO NOMBRES
    //  ->MEZCLAR EL MAZO
    //  ->ASGINAR CARTAS
    //    ->10-J-Q-K-A de manera ordenada, se mezcla y repartenuevamente.
    //    ->OPCIÓN NIVEL  DIOS: EMPATE EN TODO! POR EJ 2 ASES + 2 Ks + Js
    //    ->QUIEN COMIENZA? MAS ASES - MAS Ks - MAS Qs - MAS Js - MAS 10s
    //  B - INFORMACION de RONDA - JUGADORES - EL TURNO DEL JUGADOR - CARTAS QUE LE CORRESPONDE
    //  C- ACCION: LANZAMIENTO DADO


    return 0;
}
