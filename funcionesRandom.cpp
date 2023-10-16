#include "funciones.h"
#include "estructuras.h"

using namespace std;

int generarNumero(int tamanio)
{
    int random;
    random = rand()% tamanio;
    return random;
}
