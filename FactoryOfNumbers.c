#include <stdio.h>
#include <stdlib.h>
#include "Io.h"
#include "Manufactura.h"
#include "Robot.h"
#include "Mundo.h"

void** mundo;

int opcion;
int tamanio;
int op;

void construir(){
    /* ====================================================================== //
    // Funcion: construir() //
    // Parametros: No presenta parametros la funcion //
    // Descripcion: En esta funcion lo principal que hace esta es crear //
    // una estructura en cualquier casilla libre en todo el tablero, esta //
    // estructura puede ser un Robot o Manufactura, en la ejecucion se //
    // pregunta en que casilla quiere ingresar la estructura para asi //
    // terminar con la funcionalidad //
    // ====================================================================== */
    printf("Buena eleccion, decidiste crear una estructura...\n\n");
    printf("1. Robot\n");
    printf("2. Manufactura\n");
    printf("3. Back\n\n");
    printf("Ingresa una de las siguientes opciones: ");
    scanf("%d", &opcion);
    if(opcion == 1){
        printf("\nEscogiste un Robot...\n");
        printf("En que coordenada deseas ingresar el Robot: ");
        scanf("%d", &op);
        printf("Perfecto sera ingresado en la posicion: %d\n\n", op);
        printf("Debemos escoger la direccion para donde apuntara el Robot...\n");
        printf("0. Izquierda\n");
        printf("1. Derecha\n\n");
        printf("Ahora en que direccion apuntara el Robot: ");
        scanf("%d", &opcion);
        if(opcion == 0){
            printf("\nEl Robot ira hacia la izquierda...\n");
            printf("<------------\n\n");
            ((casilla*)(mundo[op]))->tipo_estructura = 'R';
            ((casilla*)(mundo[op]))->estructura = (robot*)malloc(sizeof(robot));
            robot *estructura_robot = ((casilla*)(mundo[op]))->estructura;
        }
        else{
            printf("El Robot ira hacia la derecha...\n");
            printf("------------>\n\n");
            ((casilla*)(mundo[op]))->tipo_estructura = 'r';
            ((casilla*)(mundo[op]))->estructura = (robot*)malloc(sizeof(robot));
            robot *estructura_robot = ((casilla*)(mundo[op]))->estructura;
            estructura_robot->direccion = op;
        }
    }
    else if(opcion == 2){
        printf("\nEscogiste una Manufactura...\n");
        printf("En que coordenada deseas ingresar la Manufactura: ");
        scanf("%d", &op);
        printf("Perfecto sera ingresado en la posicion: %d\n\n", op);
        printf("Debemos escoger la  operacion que tendra Manufactura...\n");
        printf("1. Suma\n");
        printf("2. Resta\n");
        printf("3. Multiplicacion\n");
        printf("4. Division\n\n");
        scanf("%d", &opcion);
        if(opcion == 1){
            printf("La Manufactura estara sumando...\n");
            ((casilla*)(mundo[op]))->tipo_estructura = 'M';
            ((casilla*)(mundo[op]))->estructura = (manufactura*)malloc(sizeof(manufactura));
            manufactura *estructura_manu = ((casilla*)(mundo[op]))->estructura;
        }
        if(opcion == 2){
            printf("La Manufactura estara sumando...\n");
            ((casilla*)(mundo[op]))->tipo_estructura = 'm';
            ((casilla*)(mundo[op]))->estructura = (manufactura*)malloc(sizeof(manufactura));
            manufactura *estructura_manu = ((casilla*)(mundo[op]))->estructura;
        }
        if(opcion == 3){
            printf("La Manufactura estara sumando...\n");
            ((casilla*)(mundo[op]))->tipo_estructura = 'p';
            ((casilla*)(mundo[op]))->estructura = (manufactura*)malloc(sizeof(manufactura));
            manufactura *estructura_manu = ((casilla*)(mundo[op]))->estructura;
        }
        if(opcion == 4){
            printf("La Manufactura estara sumando...\n");
            ((casilla*)(mundo[op]))->tipo_estructura = 'd';
            ((casilla*)(mundo[op]))->estructura = (manufactura*)malloc(sizeof(manufactura));
            manufactura *estructura_manu = ((casilla*)(mundo[op]))->estructura;
        }
    }
}

void destruir(){
    /* ====================================================================== //
    // Funcion: destruir() //
    // Parametros: No presenta parametros la funcion //
    // Descripcion: En esta funcion lo principal que hace esta es destruir //
    // una estructura en cualquier casilla de todo el tablero, esta //
    // estructura puede ser un Robot o Manufactura, en la ejecucion se //
    // pregunta en que casilla quiere borrar la estructura para asi //
    // terminar con la funcionalidad //
    // ====================================================================== */
    printf("Escogiste eliminar la estructura...\n");
    printf("De cual casilla quieres eliminar su estructura: ");
    scanf("%d", &op);
    printf("Perfecto vamos a eliminar la estructura en la posicion: %d\n\n", op);
    if(((casilla*)(mundo[op]))->tipo_estructura == 'R'){
        free(((casilla*)(mundo[op]))->estructura);
        ((casilla*)(mundo[op]))->tipo_estructura = ' ';
        ((casilla*)(mundo[op]))->estructura = NULL;
    }
    else if(((casilla*)(mundo[op]))->tipo_estructura == 'r'){
        free(((casilla*)(mundo[op]))->estructura);
        ((casilla*)(mundo[op]))->tipo_estructura = ' ';
        ((casilla*)(mundo[op]))->estructura = NULL;
    }
    else if(((casilla*)(mundo[op]))->tipo_estructura == 'M'){
        free(((casilla*)(mundo[op]))->estructura);
        ((casilla*)(mundo[op]))->tipo_estructura = ' ';
        ((casilla*)(mundo[op]))->estructura = NULL;
    }
    else if(((casilla*)(mundo[op]))->tipo_estructura == 'm'){
        free(((casilla*)(mundo[op]))->estructura);
        ((casilla*)(mundo[op]))->tipo_estructura = ' ';
        ((casilla*)(mundo[op]))->estructura = NULL;
    }
    else if(((casilla*)(mundo[op]))->tipo_estructura == 'p'){
        free(((casilla*)(mundo[op]))->estructura);
        ((casilla*)(mundo[op]))->tipo_estructura = ' ';
        ((casilla*)(mundo[op]))->estructura = NULL;
    }
    else if(((casilla*)(mundo[op]))->tipo_estructura == 'd'){
        free(((casilla*)(mundo[op]))->estructura);
        ((casilla*)(mundo[op]))->tipo_estructura = ' ';
        ((casilla*)(mundo[op]))->estructura = NULL;
    }
}

void informacion(){
    /* ====================================================================== //
    // Funcion: construir() //
    // Parametros: No presenta parametros la funcion //
    // Descripcion: En esta funcion lo principal que hace esta es ver la  //
    // informacion de una estructura en cualquier casilla de todo el tablero, //
    // esta estructura puede ser un Robot o Manufactura, en la ejecucion se //
    // pregunta en que casilla quiere ver la informacion sobre la estructura //
    // para asi terminar con la funcionalidad //
    // ====================================================================== */
    printf("Escogiste revisar la informacion...\n");
    printf("De que casilla quieres revisar su informacion: ");
    scanf("%d", &op);
    printf("Perfecto vamos a revisar la casilla: %d\n\n", op);
    if(((casilla*)(mundo[op]))->tipo_estructura == 'E'){
        printf("Descubrimos que es una IO\n");
        io *estructura_io = ((casilla*)(mundo[op]))->estructura;
        if(estructura_io->entrada_o_salida == 'E'){
            printf("La IO es de tipo Entrada\n\n");
        }
    }
    else if(((casilla*)(mundo[op]))->tipo_estructura == 'S'){
        printf("Descubrimos que es una IO\n");
        io *estructura_io = ((casilla*)(mundo[op]))->estructura;
        if(estructura_io->entrada_o_salida == 'S'){
            printf("La IO es de tipo Salida\n\n");
        }
    }
    else if(((casilla*)(mundo[op]))->tipo_estructura == 'R'){
        printf("Descubrimos que es un Robot\n");
        robot *estructura_robot = ((casilla*)(mundo[op]))->estructura;
        printf("La direccion del Robot es:%d",estructura_robot->direccion);
        printf("\n\n");
    }
    else if(((casilla*)(mundo[op]))->tipo_estructura == 'r'){
        printf("Descubrimos que es un Robot\n");
        robot *estructura_robot = ((casilla*)(mundo[op]))->estructura;
        printf("La direccion del Robot es: %d",estructura_robot->direccion);
        printf("\n\n");
    }
    else{
        printf("Encontramos una casilla vacia...\n\n");
    }
}

void salir(){
    /* ====================================================================== //
    // Funcion: salir() //
    // Parametros: No presenta parametros la funcion //
    // Descripcion: En esta funcion lo principal que hace esta es terminar  //
    // con el juego en si, borrando la memoria que pedimos anteriormente //
    // para asi terminar con la funcionalidad //
    // ====================================================================== */
    printf("Saliendo...\n\n");
    borrar_mundo();
    exit(0);
}

int main(int argc, char const *argv[]){
    printf("\n!Bienvenido a FactoryOfNumbers!\n");
    printf("Indique el tamanio del tablero:\n\n");
    printf("El tamanio de nuestro tablero es: ");
    scanf("%d",&tamanio);
    printf("\n");
    crear_mundo(tamanio);
    while (1){
        mostrar_mundo();
        printf("\nMENU PRINCIPAL\n\n");
        printf("1. Construir\n");
        printf("2. Destruir\n");
        printf("3. Simular\n");
        printf("4. Información extra\n");
        printf("5. Salir\n\n");
        printf("Ingresa una opción: ");
        scanf("%d", &opcion);
        printf("\n");
        if (opcion == 1){
            construir();
        }
        else if (opcion == 2){
            destruir();
        }
        else if (opcion == 3){
            // simular();
        }
        else if (opcion == 4){
            informacion();
        }
        else if (opcion == 5){
            salir();
        }
        else{
            printf("Opcion invalida. Por favor, ingrese una opcion valida.\n\n");
        }
    }
    return 0;
}