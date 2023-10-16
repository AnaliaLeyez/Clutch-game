#include <iostream>
//#include <locale>
#include "funciones.h"
#include "estructuras.h"

using namespace std;

void nombresJugadores(Jugador &j1, Jugador &j2)
{
    char confirmacion;
    do
    {
        cout << endl << "CLUTCH" << endl;
        cout << "---------------------" << endl;
        cout << "Antes de comenzar deben registrar sus nombres:" << endl;
        cout << endl;
        cout << "Participante 1: ";
        cin.ignore(); // Limpiar el buffer del teclado antes de leer la cadena
        getline(cin, j1.nombre); //es para poner espacios entre nombres
        cout << "Participante 2: ";
        getline(cin, j2.nombre);

        cout << ("Confirmar nombres (S/N): ");
        cin >> confirmacion;
        while (!(confirmacion == 'S' || confirmacion == 's' || confirmacion == 'N' || confirmacion == 'n'))
        {
            cout << "Por favor ingrese solo 'S' o 'N'." << endl;
            cout << ("Confirmar nombres(S/N): "); //no sale el '¿'
            cin >> confirmacion;
        }

        confirmacion = (confirmacion == 's') ? 'S': confirmacion; //para no usar funcion std::toUppers
        confirmacion = (confirmacion == 'n') ? 'N': confirmacion; //para no usar funcion std::toUppers
        cout << ((confirmacion == 'N') ? "Ingrese los nombres nuevamente: " : "") << endl; // si es 'n' vuelve a empezar el while
    }
    while(confirmacion != 'S');

    cout << "Nombres confirmados: " << j1.nombre << " VS " << j2.nombre << endl;
}

void mezclarMazo(Jugador j1, Jugador j2, Carta arr[], Carta vMazoMano[])
{
    int aleatorio;
    for (int i = 0; i < 10; i ++)
    {
        aleatorio = generarNumero(20);
        if(arr[aleatorio].enMazo == true)
        {
            vMazoMano[i]=arr[aleatorio];
            arr[aleatorio].enMazo = false;
        }
        else
        {
            i--;
        }
    }

    for(int i = 0; i < 20; i ++){
        cout << "CARTA ACTUAL: " << arr[i].palo << " " << arr[i].valor << " " << arr[i].enMazo << endl;
    }
}


void repartirCartas(Carta vMazoMano[], Jugador &jugador1, Jugador &jugador2)
{
    int indice;
    for(int x=0; x<10; x++)
    {
        if(x%2== 0)
        {
            jugador1.corral[indice]=vMazoMano[x];
        }else{
            jugador2.corral[indice]=vMazoMano[x];
        }
    }
}


