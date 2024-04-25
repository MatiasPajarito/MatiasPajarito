#include "Tierra.h"
#include "Tablero.h"
#include "Bomba.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void*** tablero;
int dimension;
const int chance[5]={1,2,3,4,5}; //arreglo de 5 enteros para revisar el 5% de probabilidad de tierra.es_tesoro
int cant_tesoros; //cantidad inicial de tesoros para el tablero 
int ** arr; //matriz para ver estados (1 tierra, 2 bomba, 0 tesoro encontrado)
const char punto[] = "ExplosionPunto"; //string ExplosionPunto
const char cruz[] = "ExplosionX";//string ExplosionX



void IniciarTablero(int n){
    tablero = malloc(n*sizeof(void**));
    arr = malloc(n*sizeof(int*));
    //Reviso que no haya un error en la memoria
    if((tablero == NULL)||(arr == NULL)){
        printf("%s", "error con la memoria \n");
        exit(1);
    }   
    for( int i=0 ; i<n ; i++){
        tablero[i] = malloc(n*sizeof(void*));
        arr[i] = malloc(n*sizeof(int));
        //Reviso que no haya un error en la memoria
        if ((tablero[i] == NULL)|(arr[i] == NULL)){
            printf("%s", "error con la memoria \n");
            exit(1);
        }
        //Lleno las matrices en cada casilla
        for( int j=0 ; j<n ; j++){
            tablero[i][j] = malloc(sizeof(void*));
            Tierra* tierra = (Tierra*)tablero[i][j];
            tierra->vida = (rand() % 3) + 1; // valor random 1-3
            int probabilidad = (rand() % 100);
            int contenido = 0;
            //reviso el 5% de probabilidad
            for (int c=0 ; c<5 ; c++){
                if(probabilidad==chance[c]){
                    contenido = 1;
                }
            }
            tierra->es_tesoro = contenido; // asigno 1 o 0 dependiendo si se cumplio el 5% de probabilidad
            arr[i][j] = 1; //Asigno a mi matriz de "estados" un 1 en cada posición (1 = tierra)
        }
    }
}

/* Funcion void IniciarTablero
** Parametro: int n corresponde a la dimension que se la asignara a las filas y a las columnas del tablero (nxn)
** La funcion crea inicialmente los espacios de memoria en el heap que se usara para crear el tablero, inicia a todas las casillas con una Tierra,
** y a la vez crea otra matriz de enteros, esta matriz es usada para revisar en que posiciones hay bombas, tierras y tesoros encontrados.
** sin return
*/

void MostrarTablero(){
    for (int i=0 ; i<dimension ; i++){
        for (int j=0 ; j<dimension ; j++){
            // Si en la pos i,j hay una bomba, hace...
            if (arr[i][j]==2){
                printf("o | ");
            }
            //sino yo se que es o una Tierra o un tesoro encontrado, que tambien es un struct tierra
            else{
                Tierra* imprimir = (Tierra*)tablero[i][j];
                //si la tierra fue destruida muestra 0, para evitar numeros negativos
                if(imprimir->vida<0){
                    printf("0 | ");
                }
                else{
                    printf("%d | ",imprimir->vida);
                } 
            }
        }
        printf("\n");
    }
    printf("\n");
}

/* Funcion void MostrarTablero
** sin Parametros
** La funcion recorre el tablero y muestra por pantalla la vida de la tierra, y si es una bomba muestra una "o"
** sin return
*/

void BorrarTablero(){ 
    for (int i=0 ; i<dimension ; i++){
        for(int j=0 ; j<dimension ; j++){
            free(tablero[i][j]);
        }
        free(tablero[i]);
        free(arr[i]);
    }
    free(tablero);
    free(arr);
}

/* Funcion void BorrarTablero
** sin Parametros
** Recorre el tablero y elimina tanto tablero como arr (matriz de estados)
** sin return
*/

void ColocarBomba(Bomba* b, int fila, int columna){
    Tierra* debajo = (Tierra*)tablero[fila][columna];
    b->tierra_debajo = debajo;
    tablero[fila][columna] = b;
    arr[fila][columna] = 2;
}

/* Funcion void ColocarBomba
** Parametros:
** Bomba* b : puntero a bomba que se colocará
** int fila, columna : coordenadas donde se colocará la bomba
** La funcion coloca la bomba b en la pos (fila,columna) almacenando la tierra debajo de la bomba y apuntandosela a b->tierra_debajo
** luego en la matriz de estado en la misma posición cambia a un 2
** sin return
*/

void VerTesoros(){
    printf("\n");
    for (int i=0 ; i<dimension ; i++){
        for (int j=0 ; j<dimension ; j++){
            if(arr[i][j]==2){
                Bomba* imprimir1 = (Bomba*)tablero[i][j];
                if(imprimir1->tierra_debajo->es_tesoro == 1){
                    printf("* | ");
                }
                else{
                    if(imprimir1->tierra_debajo->vida<0){
                        printf("0 | ");
                    }
                    else{
                        printf("%d | ",imprimir1->tierra_debajo->vida);
                    }
                }
            }
            else{
                Tierra* imprimir = (Tierra*)tablero[i][j];
                if(imprimir->es_tesoro == 1){
                    printf("* | ");
                }
                else{
                    if(imprimir->vida<0){
                        printf("0 | ");
                    }
                    else{
                        printf("%d | ",imprimir->vida);
                    }                   
                }
            }   
        }
        printf("\n");
    }
    printf("\n");
}

/* Funcion void VerTesoros
** sin Parametros
** La funcion recorre el tablero y printeando la vida de las Tierras, si encuentra un tesoro, printea un * en su lugar.
** sin return
*/

void MostrarBombas(){
    for (int i=0 ; i<dimension ; i++){
        for (int j=0 ; j<dimension ; j++){
            //si en i,j hay una bomba hace...
            if(arr[i][j]==2){
                Bomba* imprimir = (Bomba*)tablero[i][j];
                printf("\nTurnos para explotar: %d\n",imprimir->contador_turnos);
                printf("Coordenada: %d %d\n",i,j);
                if(imprimir->explotar==ExplosionPunto){
                    printf("Forma Explosión: %s\n", punto);
                }
                else if(imprimir->explotar==ExplosionX){
                    printf("Forma Explosión: %s\n", cruz);
                }
                printf("Vida de Tierra Debajo : %d\n\n",imprimir->tierra_debajo->vida);            
            }
        }
    }
}

/* Funcion void MostrarBombas
** sin Parametros
** La funcion recorre el tablero y si encuentra una bomba, printea la información de esta.
** sin return
*/

void PasarTurno(){
    for (int i=0 ; i<dimension ; i++){
        for (int j=0 ; j<dimension ; j++){
            //si en i,j hay una bomba hace...
            if(arr[i][j]==2){
                TryExplotar(i,j);
            }
        }
    }
}

/* Funcion void PasarTurno
** sin Parametros
** La funcion recorre el tablero y si encuentra una bomba, intenta explotarla
** sin return
*/

void ContarTesoros(){
    printf("\n");
    int tesoros = 0;
    for (int i=0 ; i<dimension ; i++){
        for (int j=0 ; j<dimension ; j++){
            // si en i,j hay una tierra...
            if(arr[i][j]==1){
                Tierra* imprimir = (Tierra*)tablero[i][j];
                //reviso si es tesoro
                if(imprimir->es_tesoro==1){
                    tesoros++;
                }
            }
            //sino es bomba
            else{
                Bomba* bomba = (Bomba*)tablero[i][j];
                //reviso si es tesoro
                if(bomba->tierra_debajo->es_tesoro==1){
                    tesoros++;
                }
            }
        }
    }
    printf("\n");
    cant_tesoros = tesoros;
}

/* Funcion void ContarTesoros
** sin Parametros
** Esta función es usada solo al comienzo del juego, luego de iniciar el tablero, recorre el tablero y si encuentra un tesoro aumenta un contador
** finalmente le asigna a cant_tesoros, la cantidad de tesoros totales que contó.
** sin return
*/

int RevisarTesoros(){
    int tesoros_actuales = 0;
    for (int i=0 ; i<dimension ; i++){
        for (int j=0 ; j<dimension ; j++){
            //si en i,j hay un tesoro descubierto hace...
            if(arr[i][j]==0){
                tesoros_actuales++;
            }
        }
    }
    if(tesoros_actuales==cant_tesoros){
        return 1;
    }
    else{
        return 0;
    }
}

/* Funcion int RevisarTesoros
** sin Parametros
** Esta función se usa cada turno, lo que hace es revisar la matriz de estados, y si la cantidad de estados 0 (tesoros encontrados) es igual
** a cant_tesoros (tesoros totales), devuelve 1 sino devuelve 0
** Retorna 1 o 0
*/

void fue_descubierto(){
    for (int i=0 ; i<dimension ; i++){
        for (int j=0 ; j<dimension ; j++){
            // si en i,j hay una bomba hace...
            if (arr[i][j]==2){
                Bomba* bomba = (Bomba*)tablero[i][j];
                if (bomba->tierra_debajo->vida<=0 && bomba->tierra_debajo->es_tesoro == 1){
                    arr[i][j]=0;
                }
            }
            //sino es tierra
            else{
                Tierra* imprimir = (Tierra*)tablero[i][j];
                if (imprimir->vida<=0 && imprimir->es_tesoro == 1){
                    arr[i][j]=0;
                }
            }
        }
    }
}

/* Funcion void fue_descubierto
** sin Parametros
** Esta función se usa cada turno, lo que hace es recorrer el tablero, y si la tierra fue destruida y esta tenía tesoro debajo, asigna en 
** la matriz de estados en la posicion donde estaba la tierra (habia un 1) un 0 (tesoro descubierto)
** Sin return
*/