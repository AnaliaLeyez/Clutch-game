#include<iostream>
#include<locale>
#include<stdio.h>
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
    // INGRESO NOMBRES
    nombresJugadores(j1, j2);

    //NUEVO, ANA
    cout <<"ENHORABUENA COMENZAMOS EL JUEGO!!!" << endl;
    cout << "ESTAS SON LAS CARTAS INICIALES" << endl;
    //Inicio con el mazo ordenado
    Carta vMazo[MAZO];
    resetearMazo(vMazo, MAZO);
    mostrarMazoEnMesa(vMazo);
    //NUEVO, ANA

    // MEZCLAR EL MAZO
    mezclarMazo(vMazo, MAZO); //esto mezcla el mazo completo

    // SELECCIONAR CARTAS EN JUEGO
    repartirCartas(j1, j2, vMazo); //Crea el corral de cada jugador
    mostrarCartasDeJugadores(j1,j2);

    //Valida que no haya escalera
    while(StraightHand(j1, j2)){
      cin.ignore();
      cout << "OPS SALIO ESCALERA! VOLVEREMOS A REPARTIR...";
      // Limpiar el bï¿½fer de entrada de cualquier carï¿½cter pendiente, incluyendo el carï¿½cter de nueva lï¿½nea
      cout << "Mezclando mazo, presione enter para continuar....";
      getchar(); // Espera a que se presione una tecla

      //resetear mazo inicial y volver a repartir cartas
      resetearMazo(vMazo,MAZO);
      repartirCartas(j1, j2, vMazo);
    }

    cout << "DETERMINEMOS QUIEN COMIENZA EL JUEGO" << endl;
    cout << "Veremos quien tiene mas A, caso de empate seguiremos comparando con los siguientes valores (K, Q, J, 10)" << endl;
    //ELEGIR QUIEN JUEGA PRIMERO
    int starter = clutchStarter(j1, j2);
    while(starter == 0){
      cin.ignore(); // Limpiar el bï¿½fer de entrada de cualquier carï¿½cter pendiente, incluyendo el carï¿½cter de nueva lï¿½nea
      cout << "*****OPS SALIO EMPATE...*****" << endl;
      cout << "Debemos volver a repartir el mazo. Presione enter para continuar....";
      getchar(); // Espera a que se presione una tecla
    //resetear mazo inicial y volver a repartir cartas
      resetearMazo(vMazo,MAZO);
      repartirCartas(j1, j2, vMazo);
      starter = clutchStarter(j1, j2);
    }
    cout << endl << "-> El jugador que inicia es: " << ((starter == 1) ? j1.nombre : j2.nombre) << " <-" << endl << endl;
    juegoInsitu(j1, j2, starter, vMazo);
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

