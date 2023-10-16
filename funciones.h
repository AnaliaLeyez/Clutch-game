//#ifndef FUNCIONES_H_INCLUDED
//#define FUNCIONES_H_INCLUDED
//#endif // FUNCIONES_H_INCLUDED
#pragma once //guards

#include<iostream>
#include "estructuras.h"

//ACA VAN LAS DECLARACIONES

void mostrarMenu(int &opcion, Jugador &j1, Jugador &j2);
void manejarOpcion(int opcion, Jugador &j1, Jugador &j2);
void nombresJugadores(Jugador &j1, Jugador &j2);
int generarNumero(int tamanio);
void mezclarMazo(Jugador j1, Jugador j2, Carta arr[], Carta vMazoMano[]);
void repartirCartas(Carta nMazo[], Jugador &jugador1, Jugador &jugador2);
void mezclarMazoMano(Carta vArr[]);
