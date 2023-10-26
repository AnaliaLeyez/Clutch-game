#pragma once;
using namespace std;

const int MAZO_PALO=4, MAZO_VALOR=5, CARTAS_CORRAL=5, MAZO=20;
const int MAZO_MESA=10;
const string valores[CARTAS_CORRAL] = {"10", "J", "Q", "K", "A"};
const string palos[MAZO_PALO] = {"Diamante", "Corazon", "Pica", "Trebol"};

struct Carta
{
    string palo;
    string valor;
    bool enMazo;
    bool bloqueada; //Para el dado  cara CINCO
};

struct Jugador
{
    string nombre;
    Carta corral[CARTAS_CORRAL];
};

