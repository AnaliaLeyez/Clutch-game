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
    case 1:
      nombresJugadores(j1, j2);
     // mezclarDado(dado);
    //cout << "El dado ahora es: " << dado;
      break;
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

