#include<iostream>
#include<locale>
#include "funciones.h"
#include "estructuras.h"

using namespace std;


void mostrarMenu(int &opcion, Jugador &j1, Jugador &j2)
{
    setlocale(LC_ALL, "Spanish");
        cout << endl << "CLUTCH " << endl; //Usamos el UNICODE
        cout << "--------------------" << endl;
        cout << "1 - JUGAR" << endl;
        cout << "2 - ESTADÍSTICAS" << endl;
        cout << "3 - CRÉDITOS" << endl;
        cout << "---------------------" << endl;
        cout << "0 - SALIR" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;
    manejarOpcion(opcion, j1, j2);
}

void manejarOpcion(int opcion, Jugador &j1, Jugador &j2)
{
    setlocale(LC_ALL, "Spanish");
    switch (opcion)
  {
    case 1: //Jugar
    {
        //Inicio con el mazo ordenado
        Carta vMazo[MAZO] =
    {
        {"Diamante", "10", true}, {"Diamante", "J", true}, {"Diamante", "Q", true}, {"Diamante", "K", true}, {"Diamante", "A", true},
        {"Corazon", "10", true}, {"Corazon", "J", true}, {"Corazon", "Q", true}, {"Corazon", "K", true}, {"Corazon", "A", true},
        {"Pica", "10", true}, {"Pica", "J", true}, {"Pica", "Q", true}, {"Pica", "K", true}, {"Pica", "A", true},
        {"Trebol", "10", true}, {"Trebol", "J", true}, {"Trebol", "Q", true}, {"Trebol", "K", true}, {"Trebol", "A", true}
    };
    Carta vMazoMano[MAZO_MANO]={};
    // INGRESO NOMBRES
      nombresJugadores(j1, j2);

    // MEZCLAR EL MAZO
    mezclarMazo(vMazo, MAZO); //esto mezcla el mazo completo

    // SELECCIONAR CARTAS EN JUEGO
    repartirCartas(j1, j2, vMazo, vMazoMano);
    mezclarMazo(vMazo, MAZO_MANO); //esto mezcla las cartas que quedan a un costado
    //repartirCartas(vMazoMano, j1, j2); //Crea el corral de cada jugador


    //    ->10-J-Q-K-A de manera ordenada, se mezcla y reparte nuevamente.
    //    ->OPCIÓN NIVEL  DIOS: EMPATE EN TODO! POR EJ 2 ASES + 2 Ks + Js
    //    ->QUIEN COMIENZA? MAS ASES - MAS Ks - MAS Qs - MAS Js - MAS 10s
    //  B - INFORMACION de RONDA - JUGADORES - EL TURNO DEL JUGADOR - CARTAS QUE LE CORRESPONDE
    //  C- ACCION: LANZAMIENTO DADO


     // mezclarDado(dado);
    //cout << "El dado ahora es: " << dado;
      break;
    }
    case 2:
      //estadisticas();
      break;
    case 3:
      //creditos();
      break;
    case 0:
      cout << "Gracias por jugar CLUTCH" << endl;
      break;
    default:
      cout << "El numero ingresado no es valido. Por favor ingrese una opcion valida." << endl;
      mostrarMenu(opcion, j1, j2);
      break;
  }
}

