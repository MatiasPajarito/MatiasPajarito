#include "Tierra.h"
#include "Tablero.h"
#include "Bomba.h"
#include <stdio.h>
#include <stdlib.h>

void TryExplotar(int fila, int columna){
    Bomba* bomba = (Bomba*)tablero[fila][columna];
    bomba->contador_turnos-=1;
    if(bomba->contador_turnos<=0){
        bomba->explotar(fila,columna);
    }
}

/* Funcion void TryExplotar
** Parametros:
** int fila, columna : son la coordenada donde se intentará explotar la bomba
** La función le disminuye el contador de turnos a la bomba de la pos (fila, columna) en 1 
** y si el contador es <= 0, llama a la funcion
** sin return
*/

void BorrarBomba(int fila, int columna){
    Bomba* bomba = (Bomba*)tablero[fila][columna];
    Tierra* tierra = bomba->tierra_debajo;
    tablero[fila][columna] = tierra;
    free(bomba);
    arr[fila][columna]=1;
    
}

/* Funcion void BorrarBomba
** Parametros:
** int fila, columna : son la coordenada donde se borrará la bomba
** La funcion almacena la tierra que la bomba en la pos (fila, columna) tenía debajo, elimina la bomba 
** y vuelve a apuntar esa tierra al tablero
** sin return
*/

void ExplosionPunto(int fila, int columna){
    Bomba* bomba = (Bomba*)tablero[fila][columna];
    bomba->tierra_debajo->vida -=3;
    BorrarBomba(fila, columna);
}

/* Funcion void ExplosionPunto
** Parametros:
** int fila, columna : son la coordenada donde explotará la bomba
** La funcion reduce la vida de la tierra que hay debajo de la bomba en la pos (fila, columna) por 3
** , luego llama a BorrarBomba en esa misma pos
** sin return
*/

void ExplosionX(int fila, int columna){
    Bomba* bomb = (Bomba*)tablero[fila][columna];
    bomb->tierra_debajo->vida-=1;
    Tierra* tierra1;
    Tierra* tierra2;
    Tierra* tierra3;
    Tierra* tierra4;
    //1
    if(arr[fila+1][columna+1]==2){
        Bomba * sobre1 = (Bomba*)tablero[fila+1][columna+1];
        tierra1 = sobre1->tierra_debajo;
    }
    else if(arr[fila+1][columna+1]==1){
         tierra1 = (Tierra*)tablero[fila+1][columna+1];
    }
    //2
    if(arr[fila+1][columna-1]==2){
        Bomba * sobre2 = (Bomba*)tablero[fila+1][columna-1];
        tierra2 = sobre2->tierra_debajo;
    }
    else if(arr[fila+1][columna-1]==1){
         tierra2 = (Tierra*)tablero[fila+1][columna-1];
    }
    //3
    if(arr[fila-1][columna+1]==2){
        Bomba * sobre3 = (Bomba*)tablero[fila-1][columna+1];
        tierra3 = sobre3->tierra_debajo;
    }
    else if(arr[fila-1][columna+1]==1){
         tierra3 = (Tierra*)tablero[fila-1][columna+1];
    }
    //4
    if(arr[fila-1][columna-1]==2){
        Bomba * sobre4 = (Bomba*)tablero[fila-1][columna-1];
        tierra4 = sobre4->tierra_debajo;
    }
    else if(arr[fila-1][columna-1]==1){
         tierra4 = (Tierra*)tablero[fila-1][columna-1];
    }
    tierra1->vida-=1;
    tierra2->vida-=1;
    tierra3->vida-=1;
    tierra4->vida-=1;
    BorrarBomba(fila, columna);
}

/* Funcion void ExplosionPunto
** Parametros:
** int fila, columna : son la coordenada donde explotará la bomba
** La funcion reduce la vida de la tierra que hay debajo de la bomba en la pos (fila, columna) y a 
** las tierras en sus esquinas por 1, luego llama a BorrarBomba en esa misma pos
** sin return
*/