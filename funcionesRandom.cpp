#include "funciones.h"
#include "estructuras.h"

using namespace std;

int generarNumero(int tamanio)
{
    int random;
    random = rand()% tamanio;
    return random;
}


int lanzarDado()
{
    int dado = generarNumero(6) + 1;
    return dado;
}
