#ifndef TABLERO_H
#define TABLERO_H
#include "Bomba.h"

extern void*** tablero; //tablero po que mas va a ser 
extern int ** arr; //matriz estados
extern int dimension; // 7 en 7x7, 10 en 10x10, 12 en 12x12
extern int cant_tesoros; //cantidad de tesoros en tablero, se actualiza por turno

void IniciarTablero(int n); 
void MostrarTablero();
void BorrarTablero();
void ColocarBomba(Bomba* b, int fila, int columna);
void VerTesoros();
void MostrarBombas();
void PasarTurno();
void ContarTesoros();
int RevisarTesoros();
void fue_descubierto();

#endif