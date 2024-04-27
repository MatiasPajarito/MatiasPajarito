#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Robot.h"
#include "Mundo.h"
#include "Io.h"

void** mundo;
int dimension;

void crear_mundo(int n){
    /* ====================================================================== //
    // Funcion: crear_mundo() //
    // Parametros: Es un entero que indica cantidad de casillas del tablero //
    // Descripcion: En esta funcion lo principal que hace esta es crear //
    // asignando memoria al tablero primeramente, seguido lo recorremos el //
    // mundo para poder asignarle la memoria a cada casilla por separado, //
    // por ultimo inicializamos la primera y ultima casilla con los Io de //
    // entrada y salida respectivamente, asignado la entrada y salida //
    // ====================================================================== */
    mundo = (void**)malloc(n*sizeof(void *));
    if (mundo == NULL){
        printf("ERROR AL CREAR EL MUNDO");
        exit(1);
    }
    for(int i = 0; i < n; i++){
        mundo[i] = (void *)malloc(sizeof(casilla));
        ((casilla*)(mundo[i]))->tipo_estructura = ' ';
        ((casilla*)(mundo[i]))->estructura = NULL;
        dimension++;
    }
    for (int i = 0; i < dimension; i++){
        if(i == 0){
            ((casilla*)(mundo[i]))->tipo_estructura = 'E';
            ((casilla*)(mundo[i]))->estructura = (io*)malloc(sizeof(io));
            io *estructura_io = ((casilla*)(mundo[i]))->estructura;
            estructura_io->entrada_o_salida = 'E';
        }
        if(i = n-1){
            ((casilla*)(mundo[i]))->tipo_estructura = 'S';
            ((casilla*)(mundo[i]))->estructura = (io*)malloc(sizeof(io));
            io *estructura_io = ((casilla*)(mundo[i]))->estructura;
            estructura_io->entrada_o_salida = 'S';
        }
    }
    
}

void mostrar_mundo(){
    /* ====================================================================== //
    // Funcion: mostrar_mundo() //
    // Parametros: No presenta parametros la funcion //
    // Descripcion: En esta funcion lo principal que hace esta es mostrar //
    // el mundo para que el jugador pueda ver lo que pasa en cada momento //
    // de la ejecucion de este programa, este dependiendo la estructura //
    // mostrara un tipo de caracter espececial //
    // ====================================================================== */
    printf("========================\n");
    printf("|");
    for (int i = 0; i < dimension; i++){
        if(((casilla*)(mundo[i]))->tipo_estructura == 'E'){
            printf(" E1 |");
        }
        else if(((casilla*)(mundo[i]))->tipo_estructura == 'S'){
            printf(" S1 |");
        }
        else if(((casilla*)(mundo[i]))->tipo_estructura == 'R'){
            printf(" <R |");
        }
        else if(((casilla*)(mundo[i]))->tipo_estructura == 'r'){
            printf(" R> |");
        }
        else if(((casilla*)(mundo[i]))->tipo_estructura == 'M'){
            printf(" M+ |");
        }
        else if(((casilla*)(mundo[i]))->tipo_estructura == 'm'){
            printf(" M- |");
        }
        else if(((casilla*)(mundo[i]))->tipo_estructura == 'p'){
            printf(" M* |");
        }
        else if(((casilla*)(mundo[i]))->tipo_estructura == 'd'){
            printf(" M/ |");
        }
        else{
            printf(" %c |",((casilla*)(mundo[i]))->tipo_estructura);
        }
    }
    printf("\n========================\n");
}

void borrar_mundo(){
    /* ====================================================================== //
    // Funcion: borrar_mundo() //
    // Parametros: No presenta parametros la funcion //
    // Descripcion: En esta funcion lo principal que hace esta es borrar //
    // el mundo, primero recorremos el mundo para liberar la memoria de las //
    // casillas y los punteros asociaddos a estas, para que finalmente hay //
    // que liberar la memoria que se le asigno al mundo al principio //
    // ====================================================================== */
    for (int i = 0; i < dimension; i++){
        casilla* cas = (casilla*)mundo[i];
        free(cas->estructura);
        free(mundo[i]);
    }
    free(mundo);
}

void simular(int tiks){
    /* ====================================================================== //
    // Funcion: simular() //
    // Parametros: Recibe un entero //
    // Descripcion: En esta funcion por temas de tiempo no pude crearla...  //
    // ====================================================================== */
}