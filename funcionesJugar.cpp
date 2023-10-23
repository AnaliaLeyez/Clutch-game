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

void repartirCartas(Jugador &j1, Jugador &j2, Carta arr[])
{
    int aleatorio;
    for (int i = 0; i < MAZO_MESA; i ++)
    {
        aleatorio = generarNumero(MAZO);
        if(arr[aleatorio].enMazo == true)
        {
            //Reparto a cada jugador una carta de forma alternada:
            if(i%2== 0) //Indice par se asocia al jugador 1 e impar al jugador 2
            {
                j1.corral[i/2]=arr[aleatorio];
            }
            else
            {
                j2.corral[i/2]=arr[aleatorio];
            }
            //En el mazo, dejo en false la carta que saco del mazo:
            arr[aleatorio].enMazo = false;
        }
        else
        {
            //si salio una carta que ya estaba en false, esa vuelta la "anulo" y la hago nuevamente.
            i--;
        }
    }

    for(int i = 0; i < MAZO; i ++)
    {
        cout << "CARTAS DEL MAZO: " << arr[i].palo << " " << arr[i].valor << " " << arr[i].enMazo << endl;
    }
    //mostrar con cout que le queda a cada jugador
    cout << "----CARTAS DE " << j1.nombre<< "----" << endl;
    for(int x=0; x<5; x++)
    {
        cout  << j1.corral[x].palo << " " << j1.corral[x].valor << endl;
    }
    cout  << "----CARTAS DE " << j2.nombre << "----"  << endl;
    for(int x=0; x<5; x++)
    {
        cout << j2.corral[x].palo << " " << j2.corral[x].valor << endl;
    }

}

void mezclarMazo(Carta vArr[], int tam)
{
    int aleatorio1, aleatorio2;
    Carta aux;
    for(int x=0; x<100; x++)
    {
        aleatorio1= generarNumero(tam);
        aleatorio2= generarNumero(tam);
        aux=vArr[aleatorio1];
        vArr[aleatorio1]=vArr[aleatorio2];
        vArr[aleatorio2]=aux;
    }
}



int elegirOrden(Jugador j1, Jugador j2)
{
    string valores[CARTAS_CORRAL] = {"A", "K", "Q", "J", "10"};
    int contadores1[CARTAS_CORRAL] = {}; // indice [0] = A, [1] = K, [2] = Q, etc...
    int contadores2[CARTAS_CORRAL] = {};


    for (int x = 0; x < CARTAS_CORRAL; x++)
    {
        for (int y = 0; y < CARTAS_CORRAL; y++)
        {
            // contar cada carta jugador 1
            if (j1.corral[y].valor == valores[x])
            {
                contadores1[x]++;
            }
            // contar cada carta jugador 2
            if (j2.corral[y].valor == valores[x])
            {
                contadores2[x]++;
            }
        }
    }

    // comparar
    for (int x = 0; x < CARTAS_CORRAL; x++)
    {
        if (contadores1[x] > contadores2[x])
        {
            return 1;
        }
        else if (contadores1[x] < contadores2[x])
        {
            return 2;
        }

    }
    //si empataron todos los casos, retorno 0, tendre que volver a repartir
    return 0;
}

