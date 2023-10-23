//#ifndef FUNCIONES_H_INCLUDED
//#define FUNCIONES_H_INCLUDED
//#endif // FUNCIONES_H_INCLUDED
#pragma once //guards

#include<iostream>
#include "estructuras.h"

//ACA VAN LAS DECLARACIONES

//FUNCIONES DEL MENU
void mostrarMenu(int &opcion, Jugador &j1, Jugador &j2);
void manejarOpcion(int opcion, Jugador &j1, Jugador &j2);

//FUNCIONES DE INGRESO DE DATOS PRIMARIOS
void nombresJugadores(Jugador &j1, Jugador &j2);

//FUNCIONES RANDOM
int generarNumero(int tamanio);

//FUNCIONES JUGAR
void repartirCartas(Jugador &j1, Jugador &j2, Carta arr[]);
void mezclarMazo(Carta vArr[], int tam);
int elegirOrden(Jugador j1, Jugador j2);


//int contadorRonda(Jugador j1, Jugador j2);
