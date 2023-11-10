#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <windows.h>//Para reproducir musica
#include <mmsystem.h>//Para reproducir musica
#include <thread> // Incluye la biblioteca de hilos para reproducir la musica separadamente
#include "funciones.h"
#include "rlutil.h"


using namespace std;

void reproducirSonidoCred() {
    PlaySound(TEXT("Level-Complete.wav"), NULL, SND_ASYNC);//ASYNC es para que se corte la musica con enter
}

void mostrarCreditos(int &opcion, Jugador &j1, Jugador &j2)
{
  setlocale(LC_ALL, "Spanish");
  rlutil::hidecursor(); // Escondemos el cursor en la consola

  // Inicia un hilo para reproducir el sonido
  thread sonido(reproducirSonidoCred);

  int pantallaAltura = rlutil::trows(); //La docu dice que te da el numero de filas de la terminal.
  int pantallaAncho = rlutil::tcols();  // Lo mismo, pero las columnas.
  int x = pantallaAncho / 2;            // Hacemos uso de las clases de matematica lo dividimos a la mitad para ubicar el centro
  int y = pantallaAltura;

  string creditos = "CR�DITOS";
  string alumnos = "Alumnos: ";
  string miguel = "Lardo Miguel �ngel - LEGAJO: 29812";
  string adriel = "V�zquez Adriel Alejandro - LEGAJO: 29930";
  string analia = "Leyez Anal�a Bel�n - LEGAJO: 29817";
  string equipo = "Equipo n 33 - Maestros de la luz y de las sombras.";

  while (y >= pantallaAltura / 2) // Aca lo mismo, dividimos por dos para ubicar el centro.
  {

    // En la "x" y en la "y", tenemos como el eje, entonces, le vamos restando o sumando para ir ubicando cada dos espacios.
    rlutil::cls();
    rlutil::locate(x, y-6 );
    cout << creditos << endl;
    rlutil::locate(x, y -4);
    cout << alumnos << endl;
    rlutil::locate(x - 12, y -2);
    cout << miguel << endl;
    rlutil::locate(x - 16, y );
    cout << adriel;
    rlutil::locate(x - 24, y + 2);
    cout << analia;
    rlutil::locate(x - 24, y + 2);
    cout << equipo;

    rlutil::msleep(50); // Esta funcion, espera en milisegundos para ejecutar. A mayor numero mas tarda.
    y -= 2;

    rlutil::cls(); // Esto es lo que da el efecto de "subida" en ralidad, borra y escribe.
  }

  rlutil::cls(); //Esto es para limpiar

  // Todo este bloque lo volvemos a escribir, para generar el efecto posterior.
  rlutil::locate(x, y -4);
  cout << alumnos << endl;
  rlutil::locate(x - 12, y -2);
  cout << miguel << endl;
  rlutil::locate(x - 16, y );
  cout << adriel;
  rlutil::locate(x - 16, y );
  cout << analia;
  rlutil::locate(x - 24, y + 2);
  rlutil::setColor(rlutil::RED);
  cout << equipo;
  rlutil::setColor(rlutil::BLACK);



  int colores[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

  //https://www.lawebdelprogramador.com/foros/Dev-C/1664435-Kbhit-y-getch.html
  //https://tapiov.net/rlutil/docs/HTML/files/rlutil-h.html

  while (!kbhit()) // Esta funcion esta incluida en rlutil, detecta si presionas una tecla. Por alguna razon si uso rlutil:: antes, no funciona.
  {
    for (int i = 0; i < 8 ; i++)
    {
      rlutil::locate(x, y - 6);  // Ubica la letra actual
      rlutil::setColor(colores[i]); // Cambia el color
      cout << creditos; // Imprime la letra
      rlutil::msleep(50); // Espera un tiempo antes de continuar
    }
  }
  getch(); // Esta funcion, es companiera de kbhit, si no la agrego, lo que sigue  no se muestra.

  rlutil::setColor(rlutil::BLACK);
  rlutil::locate(x - 20, y +6);
  cout << "Presiona una tecla para volver al menu principal";
  rlutil::getkey();
  rlutil::cls();
  PlaySound(NULL, 0, 0);
  sonido.join();//esta es para que el programa no se rompa al salir de CREDITOS
}