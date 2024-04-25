#ifndef BOMBA_H
#define BOMBA_H
#include "Tierra.h"

typedef struct Bomba{
    int contador_turnos; //turnos para que la bomba explote
    void (*explotar)(int fila, int columna); //puntero a una funcion
    Tierra* tierra_debajo; //puntero a struct tierra que se ocupa cuando se coloca una bomba donde habia tierra
} Bomba;

void TryExplotar(int fila, int columna);
void BorrarBomba(int fila, int columna); 
void ExplosionPunto(int fila, int columna); 
void ExplosionX(int fila, int columna); 

#endif