#pragma once;
using namespace std;

const int MAZO_PALO=4, MAZO_VALOR=5, CARTAS_CORRAL=5, MAZO=20;
const int MAZO_MANO=10;
struct Carta
{
    string palo;
    string valor;
    bool enMazo=true;
};

struct Jugador
{
    string nombre;
    Carta corral[CARTAS_CORRAL];
};

