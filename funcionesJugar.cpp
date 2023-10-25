#include <iostream>
#include <locale>
#include <iomanip> // Necesario para setw
#include <cstdio> // Necesario para getchar()
#include "funciones.h"
#include "estructuras.h"

using namespace std;

void nombresJugadores(Jugador &j1, Jugador &j2)
{
    setlocale(LC_ALL, "Spanish");
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


void mezclarMazo(Carta vArr[], int tam)
{
    setlocale(LC_ALL, "Spanish");
    //como mezclamos muchas veces 1 vez sola mostrara el ENHORA BUENA
//    bool mazoNuevo = true;
//
//    if(mazoNuevo)
//    {
//        cout <<"ENHORABUENA COMENZAMOS EL JUEGO!!!" << endl;
//        cout << "ESTAS SON LAS CARTAS INICIALES" << endl;
//
//        mostrarMazoEnMesa(vArr);
//
//        cin.ignore(); // Limpiar el buffer de entrada de cualquier caracter pendiente, incluyendo el caracter de nueva linea
//        cout << "Mezclando mazo, presione enter para continuar...." << endl;
//        getchar(); // Espera a que se presione una tecla
//        mazoNuevo = false;
//    }

    //NUEVO, DE ANA
        cin.ignore(); // Limpiar el buffer de entrada de cualquier caracter pendiente, incluyendo el caracter de nueva linea
        cout << "Mezclando mazo, presione enter para continuar...." << endl;
        getchar(); // Espera a que se presione una tecla
    //NUEVO, DE ANA


    int aleatorio1, aleatorio2;
    Carta aux;
    for(int x=0; x<100; x++)
    {
        aleatorio1= generarNumero(tam);//Me da 1 aleatoreo
        aleatorio2= generarNumero(tam);//Me da 12 aleatoreo
        aux=vArr[aleatorio1];//Indice 1 {"Diamante", "J", true}
        vArr[aleatorio1]=vArr[aleatorio2]; // Indice 12 {"Pica", "Q", true}
        vArr[aleatorio2]=aux;//Donde tenia PICA Q voy a guardar DIAMANTE J
    }
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
}


void mostrarMazoEnMesa(Carta vMazo[])
{
    cout << "+--------------------+" << endl;
    cout << "|                    |" << endl;

    for (int x = 0; x < MAZO; x++)
    {
        if (vMazo[x].enMazo == true)
        {
            cout << "|     " << vMazo[x].valor << " " << vMazo[x].palo;
            cout << setw(15 - vMazo[x].valor.length() - vMazo[x].palo.length()) << "|" << endl;
        }   ///15 es el ancho total deseado.
    }       ///.length devuelve la longitud de la cadena. => estas son restadas al ancho de 15

    cout << "|                    |" << endl;
    cout << "+--------------------+" << endl;
}

void mostrarCartasDeJugadores(Jugador &j1, Jugador &j2)
{
    //mostrar con cout que le queda a cada jugador
    cout << "+--------------------+" << endl;
    cout << "|                    |" << endl;

    cout << "| " << j1.nombre << setw(20 - j1.nombre.length()) << "|" << endl;
    for(int x=0; x<CARTAS_CORRAL; x++)
    {
        cout << "|     ";
        if (j1.corral[x].bloqueada)
        {
            cout << "* ";
            cout << j1.corral[x].palo << " " << j1.corral[x].valor << setw(13 - j1.corral[x].valor.length() - j1.corral[x].palo.length()) << "|";
        }
        else
        {
            cout << j1.corral[x].palo << " " << j1.corral[x].valor << setw(15 - j1.corral[x].valor.length() - j1.corral[x].palo.length()) << "|";
        }
        cout << endl;
    }

    cout << "|                    |" << endl;
    cout << "|                    |" << endl;
    cout << "|                    |" << endl;

    cout  << "| "<< j2.nombre << setw(20 - j2.nombre.length()) << "|" << endl;

    for(int x=0; x<CARTAS_CORRAL; x++)
    {
        cout << "|     ";
        if (j2.corral[x].bloqueada)
        {
            cout << "* ";
            cout << j2.corral[x].palo << " " << j2.corral[x].valor << setw(13 - j2.corral[x].valor.length() - j2.corral[x].palo.length()) << "|";
        }
        else
        {
            cout << j2.corral[x].palo << " " << j2.corral[x].valor << setw(15 - j2.corral[x].valor.length() - j2.corral[x].palo.length()) << "|";
        }
        cout << endl;
    }
    cout << "|                    |" << endl;
    cout << "+--------------------+" << endl;
}

void mostrarRonda(Jugador jA, Jugador jB, int &contRonda)
{

    cout << "CLUTCH" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "RONDA #" << contRonda  << endl;
    cout <<  jA.nombre << " vs " << jB.nombre << endl << endl;
}


bool juegoFinalizado(Jugador &jugador)
{
    for (int i = 0; i < CARTAS_CORRAL; i++)
    {
        if(jugador.corral[i].valor != valores[i])
        {
            return false;
        }
    }
    return true;
}


void juegoInsitu(Jugador &j1, Jugador &j2, int returne, Carta vMazo[])
{
    setlocale(LC_ALL, "Spanish");
    Jugador jugadorA;
    Jugador jugadorB;
    int dado;
    int contRonda=1;
    int turno=1;

    if(returne == 1)
    {
        jugadorA = j1;
        jugadorB = j2;
    }
    else
    {
        jugadorA = j2;
        jugadorB = j1;
    }

    //mostrarCartasDeJugadores(jugadorA,jugadorB,vMazo);
    bool juegoTerminado = false;
    while(!juegoTerminado)
    {
        //cin.ignore(); // Limpiar el buffer de entrada de cualquier caracter pendiente, incluyendo el caracter de nueva linea
        mezclarMazo(vMazo, MAZO);
        mostrarRonda(jugadorA, jugadorB, contRonda);
        if(turno%2!=0)
        {
            cout << "TURNO DE " << jugadorA.nombre << endl;
        }
        else
        {
            cout << "TURNO DE " << jugadorB.nombre << endl;
            contRonda ++;
        }
        cout << "Pulse Enter cuando este listo para lanzar el dado." << endl;
        getchar();
        dado = lanzarDado();
        cout << endl << "LANZAMIENTO DADO #" << dado << endl;
        switch (dado)
        {
        case 1:
            turno%2!=0 ? dadoCaraUno(jugadorA, vMazo) : dadoCaraUno(jugadorB, vMazo);
            break;
        case 2:
            turno%2!=0 ? dadoCaraDos(jugadorB, vMazo) : dadoCaraDos(jugadorA, vMazo);
            break;
        case 3:
            turno%2!=0 ? dadoCaraTres(jugadorA, jugadorB) : dadoCaraTres(jugadorB, jugadorA);
            break;
        case 4:
            turno%2!=0 ? dadoCaraCuatro(jugadorA) : dadoCaraCuatro(jugadorB);
            break;
        case 5:
            turno%2!=0 ? dadoCaraCinco(jugadorA) : dadoCaraCinco(jugadorA);
            break;
        case 6:
            turno%2!=0 ? dadoCaraSeis(jugadorA, jugadorB, vMazo) : dadoCaraSeis(jugadorB, jugadorA, vMazo);
            break;
        }

        cout << endl << "Cartas Actuales" << endl;
        mostrarCartasDeJugadores(jugadorA, jugadorB);
        juegoTerminado = juegoFinalizado(jugadorA) || juegoFinalizado(jugadorB);
        turno++;
    }

    cout << "PARAPAPA PA PA PAPA! HAY UN GANADORRR, ESTE ES: " ;
            if((turno-1) %2!=0){
                cout << jugadorA.nombre << endl;
            }else{
                cout << jugadorB.nombre << endl;
            }

}


void resetearMazo(Carta vMazo[],int MAZO){
    vMazo[0] = {"Diamante", "10", true, false};
    vMazo[1] = {"Diamante", "J", true, false};
    vMazo[2] = {"Diamante", "Q", true, false};
    vMazo[3] = {"Diamante", "K", true, false};
    vMazo[4] = {"Diamante", "A", true, false};
    vMazo[5] = {"Corazon", "10", true, false};
    vMazo[6] = {"Corazon", "J", true, false};
    vMazo[7] = {"Corazon", "Q", true, false};
    vMazo[8] = {"Corazon", "K", true, false};
    vMazo[9] = {"Corazon", "A", true, false};
    vMazo[10] = {"Pica", "10", true, false};
    vMazo[11] = {"Pica", "J", true, false};
    vMazo[12] = {"Pica", "Q", true, false};
    vMazo[13] = {"Pica", "K", true, false};
    vMazo[14] = {"Pica", "A", true, false};
    vMazo[15] = {"Trebol", "10", true, false};
    vMazo[16] = {"Trebol", "J", true, false};
    vMazo[17] = {"Trebol", "Q", true, false};
    vMazo[18] = {"Trebol", "K", true, false};
    vMazo[19] = {"Trebol", "A", true, false};
}


