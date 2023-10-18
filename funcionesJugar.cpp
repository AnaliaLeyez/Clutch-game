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

void repartirCartas(Jugador j1, Jugador j2, Carta arr[], Carta vMazoMano[])
{
    int aleatorio;
    for (int i = 0; i < MAZO_MANO; i ++)
    {
        aleatorio = generarNumero(MAZO);
        if(arr[aleatorio].enMazo == true)
        {

            //INICIO OPCION 2. directamente se las voy repartiendo a cada jugador. esta función estaría repartiendo directamente
            if(i%2== 0) //Indice par se asocia al jugador 1 e impar al jugador 2
        {
            j1.corral[i/2]=arr[aleatorio];
        }
        else
        {
            j2.corral[i/2]=arr[aleatorio];
        }
            //FIN OPCION 2

            arr[aleatorio].enMazo = false;
        }
        else
        {
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

//void repartirCartas(Carta vMazoMano[], Jugador jugador1, Jugador jugador2)
//{
//    for(int x=0; x<MAZO_MANO; x++)
//    {
//        if(x%2== 0) //Indice par se asocia al jugador 1 e impar al jugador 2
//        {
//            jugador1.corral[x/2]=vMazoMano[x];
//        }
//        else
//        {
//            jugador2.corral[x/2]=vMazoMano[x];
//        }
//    }
//
//    //mostrar con cout que le queda a cada jugador
//    cout << "----CARTAS DE " << jugador1.nombre<< "----" << endl;
//    for(int x=0; x<5; x++)
//    {
//    cout  << jugador1.corral[x].palo << " " << jugador1.corral[x].valor << endl;
//    }
//    cout  << "----CARTAS DE " << jugador2.nombre << "----"  << endl;
//    for(int x=0; x<5; x++)
//    {
//    cout << jugador2.corral[x].palo << " " << jugador2.corral[x].valor << endl;
//    }
//}


