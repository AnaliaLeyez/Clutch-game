#include <iostream>
#include "funciones.h"
#include "estructuras.h"

using namespace std;


/*Elegir una carta de su propio corral (1-5) y robar una carta del mazo.
Se intercambian las dos. La carta robada pasa a formar parte del corral
y la carta seleccionada se incorpora al mazo.

    1 - Elegir carta
    2 - Tomar la primer carta del mazo.
    3 - La carta tomada del mazo, se pone en false.
    4 - La carta tomada del corral, se pone en true en el mazo.
    5 - La carta tomada, sobre-escribe la carta del indice seleccionado.

    Que parametros necesita? Un corral y un amzo
    Retorna algo? No.
    Modifica algo? Si.*/


void dadoCaraUno(Jugador &j, Carta mazo[]) //elige del propio corral y cambia por mazo
{
    int posicion;
    Carta top; // La primera del mazo
    Carta cartaJugador; //La carta del jugador que quiere cambiar.

    cout << "Intercambiar una carta del propio corral con una del mazo" << endl;
    cout << endl << "Ingrese el numero de la carta que quiere seleccionar de su propio corral: ";
    cin >> posicion; ///Selecciono mi carta


    for (int x = 0; x < MAZO; x++)
    {
      if (mazo[x].enMazo /*&& contador==0*/)
      {
        top = mazo[x]; //la primera coincidencia.Osea la primer carta True
        mazo[x].enMazo = false; // ponemos en false;
        x = MAZO; //con esto se termina el for
      }
    }

    cartaJugador = j.corral[posicion - 1]; //esto es para ir al indice del array

    for (int x = 0; x < MAZO; x++)
    {
        if (cartaJugador.palo == mazo[x].palo && cartaJugador.valor == mazo[x].valor) //Este if, hizo preguntarme si seria una buena idea ponerles "ID" a las cartas.
        {///Por ej 10 de picas es true en el jugador y false en el mazo => aqui lo pongo en true en el mazo
          mazo[x].enMazo = true; // en la coincidnecia, ponemos true.
        }
    }

    j.corral[posicion -1] = top;

    cout << "La carta " << top.palo << " " << top.valor << " es la carta tomada del mazo" << endl;
    cout << "La carta " << j.corral[posicion -1].palo << " " << j.corral[posicion -1].valor << " es la carta nueva en la posicion " << posicion << endl;
}

void dadoCaraDos(Jugador &j, Carta mazo[]){///elige del contrario y cambia por mazo
  int posicion;
    Carta top; // La primera del mazo
    Carta cartaJugadorContrario; //La carta del jugador que quiere cambiar.

    cout << "Intercambiar una carta del corral CONTRARIO con una del mazo" << endl;
    cout << endl << "Ingrese el numero de la carta que quiere seleccionar del corral de su oponente: ";
    cin >> posicion; ///Selecciono mi carta

    while(j.corral[posicion-1].bloqueada)
    {
      cout << "No puedes usar una carta bloqueada." << endl;

      cout << "INGRESE OTRA CARTA para Intercambiar una carta del corral CONTRARIO con una del mazo" << endl;
      cout << endl << "Ingrese el numero de la carta que quiere seleccionar del corral de su oponente: ";
      cin >> posicion; ///Selecciono mi carta
    }

    for (int x = 0; x < MAZO; x++)
    {
      if (mazo[x].enMazo)
      {
        top = mazo[x]; //la primera coincidencia.Osea la primer carta True
        mazo[x].enMazo = false; // ponemos en false;
        x=MAZO;
      }
    }

    cartaJugadorContrario = j.corral[posicion - 1]; //esto es para ir al indice del array

    for (int x = 0; x < MAZO; x++)
    {
        if (cartaJugadorContrario.palo == mazo[x].palo && cartaJugadorContrario.valor == mazo[x].valor) //Este if, hizo preguntarme si seria una buena idea ponerles "ID" a las cartas.
        {///Por ej 10 de picas es true en el jugador y false en el mazo => aqui lo pongo en true en el mazo
          mazo[x].enMazo = true; // en la coincidencia, ponemos true.
        }
    }

    j.corral[posicion -1] = top;

    cout << "La carta " << top.palo << " " << top.valor << " es la carta tomada del mazo" << endl;
    cout << "La carta " << j.corral[posicion -1].palo << " " << j.corral[posicion -1].valor << " es la carta nueva en la posicion " << posicion << endl;
}

void dadoCaraTres(Jugador &j1, Jugador &j2){ ///Cambio una mia por una del contrario
  int posicionA, posicionB;

  cout << "Intercambiar una carta del propio corral con una del oponente" << endl;
  cout << "Ingrese la posicion de la carta de su corral: ";
  cin >> posicionA;
  cout << "Ingrese la posicion de la carta del corral contrario: ";
  cin >> posicionB;

  while(j1.corral[posicionA-1].bloqueada || j2.corral[posicionB - 1].bloqueada)
  {
    cout << endl << "No puedes usar una carta bloqueada." << endl;

    cout << "INGRESE OTRA CARTA para Intercambiar una carta del propio corral con una del oponente" << endl;
    cout << "Ingrese la posicion de la carta de su corral: ";
    cin >> posicionA;
    cout << "Ingrese la posicion de la carta del corral contrario: ";
    cin >> posicionB;
  }

  Carta aux;
  aux = j1.corral[posicionA -1];
  j1.corral[posicionA -1] = j2.corral[posicionB -1];
  j2.corral[posicionB -1] = aux;
}

void dadoCaraCuatro(Jugador &j){/// Cambio 1 mia por otra mia

  int posicionA, posicionB;

  cout << "Intercambiar una carta del propio corral con otra de tu propio corral" << endl;
  cout << "Primer Carta: ";
  cin >> posicionA;
  cout << "Segunda Carta: ";
  cin >> posicionB;

  Carta aux;
  aux = j.corral[posicionA -1];
  j.corral[posicionA -1] = j.corral[posicionB -1];
  j.corral[posicionB -1] = aux;
}

void dadoCaraCinco(Jugador &j){///Bloque mi carta para que dado 2 y dado 3 no la modifique.
  int posicion;

  cout << "Bloquear una carta de su corral para que no sea utilizada con la cara 2 y 3 del dado" << endl;
  cout << "Ingrese la posicion de la carta de su corral: ";
  cin >> posicion;

  j.corral[posicion-1].bloqueada = true;

  cout << "FELICITACIONES! Ahora la carta: " << j.corral[posicion-1].palo << " " << j.corral[posicion-1].valor << " ha sido BLOQUEADA!!" << endl;

}

void dadoCaraSeis(Jugador &j1, Jugador &j2, Carta vMazo[]) {
  int opcion;

  cout << "PUEDES ELEGIR CUALQUIERA DE ESTAS OPCIONES: " << endl;
  cout << "1- Elige una carta de tu propio corral y cambiala por una del mazo." << endl;
  cout << "2- Elige una carta del corral CONTRARIO y cambiala por una del mazo." << endl;
  cout << "3- Elige una carta de TU corral y cambiala por una del corral CONTRARIO." << endl;
  cout << "4- Cambiar una carta de TU corral por otra de TU corral (Intercambio)." << endl;
  cout << "5- Bloquear Carta (Inhibe la funcion del dado DOS y dado Tres)." << endl;
  cout << "0- NO HACER NADA y PASAR EL TURNO." << endl;
  cout << "Elige una opcion: ";
  cin >> opcion;
  cout << endl;

  switch (opcion) {
    case 1:
      dadoCaraUno(j1, vMazo);
      break;
    case 2:
      dadoCaraDos(j2, vMazo);
      break;
    case 3:
      dadoCaraTres(j1, j2);
      break;
    case 4:
      dadoCaraCuatro(j1);
      break;
    case 5:
      dadoCaraCinco(j1);
      break;
    default:
      cout << "Pasando el turno sin hacer nada." << endl;
  }
}






