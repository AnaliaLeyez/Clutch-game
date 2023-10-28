//#ifndef FUNCIONES_H_INCLUDED
//#define FUNCIONES_H_INCLUDED
//#endif // FUNCIONES_H_INCLUDED
#pragma once //guards

#include<iostream>
#include "estructuras.h"

//ACA VAN LAS DECLARACIONES

//FUNCIONES DEL MENU
void mostrarMenu(int &opcion, Jugador &j1, Jugador &j2, Jugador vEstadisticas[]);
void manejarOpcion(int opcion, Jugador &j1, Jugador &j2, Jugador vEstadisticas[]);

//FUNCIONES DE INGRESO DE DATOS PRIMARIOS
void nombresJugadores(Jugador &j1, Jugador &j2);

//FUNCIONES RANDOM
int generarNumero(int tamanio);

//FUNCIONES JUGAR
void resetearMazo(Carta vMazo[]);
void repartirCartas(Jugador &j1, Jugador &j2, Carta arr[]);
void mezclarMazo(Carta vArr[]);
void mostrarRonda(Jugador jA, Jugador jB, int &contRonda);
void mostrarMazoEnMesa(Carta vMazo[]);
void mostrarCartasDeJugadores(Jugador &j1, Jugador &j2);

//FUNCIONES UNDER THE GUN
int clutchStarter(Jugador j1, Jugador j2);
bool straightHand (Jugador &j1, Jugador &j2);

//FUNCIONES DADO
int lanzarDado();
void dadoCaraUno(Jugador &j, Carta mazoMano[]);
void dadoCaraDos(Jugador &j, Carta mazo[]);
void dadoCaraTres(Jugador &j1, Jugador &j2);
void dadoCaraCuatro(Jugador &j);
void dadoCaraCinco(Jugador &j);
void dadoCaraSeis(Jugador &j1, Jugador &j2, Carta vMazo[]);

//JUEGO IN SITU
void juegoInsitu(Jugador &j1, Jugador &j2, int returne, Carta vMazo[], Jugador vEstadisticas[]);

//FIN DE JUEGO
bool juegoFinalizado(Jugador &jugador);

//PUNTAJES
void mostrarPuntajes(Jugador &ganador, Jugador &perdedor);
void cargarEstadisticas(Jugador vJugador[], Jugador &ganador);
void mostrarEstadisticas(Jugador vJugador[]);
