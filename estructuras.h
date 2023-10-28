#pragma once;
using namespace std;

const int MAZO_VALOR=5, MAZO_PALO=4, CARTAS_CORRAL=5, MAZO=20, MAZO_MESA=10;
const string VALORES[CARTAS_CORRAL] = {"10", "J", "Q", "K", "A"};
const string PALOS[MAZO_PALO] = {"Diamante", "Pica", "Corazon", "Trebol"};

struct Carta
{
    string palo;
    string valor;
    bool enMazo;
    bool bloqueada; //Para el dado cara CINCO
};

struct Jugador
{
    string nombre;
    Carta corral[CARTAS_CORRAL];
    int puntaje = 0;
    bool ganar = false;
    bool roboUltimaCarta = false;
    int malUbicadas = 0;
    bool sinPasarTurno = false;
    bool sinRobo=false;
};
