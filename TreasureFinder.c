#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Tierra.h"
#include "Tablero.h"
#include "Bomba.h"

int main(int argc, char const *argv[])
{
    // Inicio tablero
    int juego_terminado = 0;
    int opcion, opcion_inicial;
    int turno = 1;
    int fila, columna, forma; //para colocar bomba            
    srand(time(0));
    printf("Indique el tamaño del tablero a jugar: \n");
    printf("1.7x7 2.10x10 3.12x12 \n");
    printf("Su input : ");
    scanf("%d", &opcion_inicial);
    if(opcion_inicial == 1){
        dimension = 7;
    }
    else if(opcion_inicial == 2){
        dimension = 10;
    }
    else if(opcion_inicial == 3){
        dimension = 12;
    }
    IniciarTablero(dimension);
    ContarTesoros();
    //Comienza Juego
    while (juego_terminado == 0){
        juego_terminado = RevisarTesoros();
        printf("Tablero ( Turno %d )\n\n",turno);
        MostrarTablero();
        printf("Seleccione una accion: \n");
        printf("1.Colocar Bomba 2.Mostrar Bombas 3.Mostrar Tesoros  \n");
        printf("Escoja una opcion: ");
        scanf("%d", &opcion);
        if(opcion == 1){ //Colocar Bomba
            Bomba * bomba = malloc(sizeof(Bomba));
            printf("Indique coordenadas de la bomba:  \n");
            printf("Fila: ");
            scanf("%d",&fila );
            printf("Columna: ");
            scanf("%d",&columna );
            //Casos donde se pasa:
            if (fila>dimension){
                fila -= dimension;
            }
            if (columna>dimension){
                columna -= dimension;
            }
            if (fila<=0){
                fila += dimension;
            }
            if (columna<=0){
                columna += dimension;
            }
            //Adapto fila y columna:
            fila--;
            columna--;
            printf("Indique la forma en que explota la bomba \n");
            printf("1.Punto 2.X \n");
            printf("Su input : ");
            scanf("%d",&forma);
            //Forma de explosion
            if(forma == 1){
                bomba->contador_turnos = 1;
                bomba->explotar = ExplosionPunto;
            }
            else if(forma == 2){
                bomba->contador_turnos = 3;
                bomba->explotar = ExplosionX;
            }
            else{
                printf("Forma invalida, terminando programa... \n");
                BorrarTablero();
                break;
            }
            ColocarBomba(bomba,fila,columna);
            
        }
        else if(opcion == 2){//Mostrar Bomba
            MostrarBombas();   
        }
        else if(opcion == 3){//Ver tesoros
            VerTesoros();
        }
        PasarTurno();
        fue_descubierto();
        juego_terminado = RevisarTesoros();
        turno++;
    }
    for (int x=0 ; x<dimension ; x++){ //Me aseguro de borrar las bombas que queden
        for(int y=0 ; y<dimension ; y++){
            if(arr[x][y]==2){
                BorrarBomba(x,y);
            }
        }
    }
    BorrarTablero(); //Borro finalmente el tablero
    printf("Encontraste Todas los Tesoros!!!\n");
    return 0;
}
