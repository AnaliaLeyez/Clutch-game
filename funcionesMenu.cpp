#include<iostream>
#include<locale>
#include<stdio.h>
#include "rlutil.h"
#include "funciones.h"
#include "estructuras.h"

using namespace std;

void mostrarMenu(Jugador &j1, Jugador &j2, bool &banderaUltimoGanador)
{
    setlocale(LC_ALL, "Spanish");
    int opcion;
    Jugador ganadorMaximo; //si esto lo declaro en manejarOpcion no funciona

    do
    {
        cout << endl << "CLUTCH " << endl;
        cout << "--------------------" << endl;
        cout << "1 - JUGAR" << endl;
        cout << "2 - ESTADÍSTICAS" << endl;
        cout << "3 - CRÉDITOS" << endl;
        cout << "---------------------" << endl;
        cout << "0 - SALIR" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        if(opcion < 0 || opcion > 3)
        {
            cout << "ERROR: " << opcion << " no es un numero valido. Presione una tecla para continuar...." << endl;
            rlutil::anykey();
            rlutil::cls();//Borra pantalla para ver el fondo verde
        }
        else
        {
            manejarOpcion(opcion, j1, j2, ganadorMaximo, banderaUltimoGanador);
        }

    }
    while(opcion!=0);
}

void manejarOpcion(int opcion, Jugador &j1, Jugador &j2, Jugador &ganadorMaximo, bool &banderaUltimoGanador)
{
    setlocale(LC_ALL, "Spanish");
    Jugador ganador;

    switch (opcion)
    {
    case 1: //Jugar
    {
        rlutil::cls();

        // INGRESO NOMBRES
        nombresJugadores(j1, j2);
        rlutil::cls(); //Borra lo que estaba antes al elegir una opcion

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
            mostrarCartasDeJugadores(j1,j2);
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
            mostrarCartasDeJugadores(j1,j2);
            starter = clutchStarter(j1, j2);
        }
        cout << endl << "-> El jugador que inicia es: " << ((starter == 1) ? j1.nombre : j2.nombre) << " <-" << endl << endl;
        cout << "Presione una tecla cualquiera cuando esté listo para iniciar el juego." << endl << endl;
        rlutil::anykey();
        rlutil::cls();//Borra pantalla para ver el fondo verde

        ganador = juegoInsitu(j1, j2, starter, vMazo);
        if(!banderaUltimoGanador)
        {
            ganadorMaximo = ganador;
            banderaUltimoGanador  = true;
        }
        else if(ganador.puntajeHistorico > ganadorMaximo.puntajeHistorico || ganador.puntajeHistorico == ganadorMaximo.puntajeHistorico )
        {
            ganadorMaximo = ganador;
        }

        break;
    }
    case 2:
        mostrarHito(ganadorMaximo);
        break;
    case 3:
        mostrarCreditos(opcion,j1,j2);
        break;
    case 0:
        cout << "SALIENDO DEL JUEGO. Gracias por jugar CLUTCH" << endl;
        break;
    }
}

