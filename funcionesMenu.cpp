#include<iostream>
#include<locale>
#include<stdio.h>
#include "rlutil.h"
#include "funciones.h"
#include "estructuras.h"

using namespace std;

void mostrarMenu(int &opcion, Jugador &j1, Jugador &j2, Jugador vEstadisticas[])
{
    setlocale(LC_ALL, "Spanish");
    cout << endl << "CLUTCH " << endl;
    cout << "--------------------" << endl;
    cout << "1 - JUGAR" << endl;
    cout << "2 - ESTADÍSTICAS" << endl;
    cout << "3 - CRÉDITOS" << endl;
    cout << "---------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "Ingrese su opción: ";
    cin >> opcion;
    manejarOpcion(opcion, j1, j2, vEstadisticas);
}

void manejarOpcion(int opcion, Jugador &j1, Jugador &j2,Jugador vEstadisticas[])
{
    setlocale(LC_ALL, "Spanish");
    switch (opcion)
    {
    case 1: //Jugar
    {
        rlutil::cls();

        // INGRESO NOMBRES
        nombresJugadores(j1, j2);

        cout << "ENHORABUENA COMENZAMOS EL JUEGO!!!" << endl;
        cout << "ESTAS SON LAS CARTAS INICIALES" << endl;

        //Inicio con el mazo ordenado
        Carta vMazo[MAZO]; //declaro el vector que contiene todo el mazo
        resetearMazo(vMazo);
        mostrarMazoEnMesa(vMazo);

        // MEZCLAR EL MAZO
        mezclarMazo(vMazo); //esto mezcla el mazo completo

        // SELECCIONAR CARTAS EN JUEGO Y MOSTRARLAS
        cout << "Las cartas de cada jugador son:" << endl;
        repartirCartas(j1, j2, vMazo); //Crea el corral de cada jugador
        mostrarCartasDeJugadores(j1,j2);

        //Valida que no haya escalera
        while(straightHand(j1, j2))
        {
            // Limpiar el buffer de entrada de cualquier caracter pendiente, incluyendo el caracter de nueva linea
            cin.ignore();
            cout << "OPS SALIO ESCALERA! VOLVEREMOS A REPARTIR...";
            cout << "Mezclando mazo, presione enter para continuar....";
            getchar(); // Espera a que se presione una tecla
            resetearMazo(vMazo); //resetear mazo inicial y volver a repartir cartas
            repartirCartas(j1, j2, vMazo);

        }

        rlutil::setColor(rlutil::RED);
        cout << "DETERMINEMOS QUIEN COMIENZA EL JUEGO" << endl;
        cout << "Veremos quien tiene mas A, caso de empate seguiremos comparando con los siguientes valores (K, Q, J, 10)" << endl;
        rlutil::setColor(rlutil::BLACK);
        //ELEGIR QUIEN JUEGA PRIMERO
        int starter = clutchStarter(j1, j2);
        while(starter == 0)
        {
            cin.ignore(); // Limpiar el buffer de entrada de cualquier caracter pendiente, incluyendo el caracter de nueva linea
            cout << "*****OPS SALIO EMPATE...*****" << endl;
            cout << "Debemos volver a repartir el mazo. Presione enter para continuar....";
            getchar(); // Espera a que se presione una tecla
            resetearMazo(vMazo); //resetear mazo inicial y volver a repartir cartas
            mezclarMazo(vMazo);
            repartirCartas(j1, j2, vMazo);
            starter = clutchStarter(j1, j2);
        }
        cout << endl << "-> El jugador que inicia es: " << ((starter == 1) ? j1.nombre : j2.nombre) << " <-" << endl << endl;
        cout << "Presione una tecla cualquiera cuando esté listo para iniciar el juego." << endl << endl;
        rlutil::anykey();
        juegoInsitu(j1, j2, starter, vMazo, vEstadisticas);
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
        mostrarMenu(opcion, j1, j2, vEstadisticas);
        break;
    }
}

