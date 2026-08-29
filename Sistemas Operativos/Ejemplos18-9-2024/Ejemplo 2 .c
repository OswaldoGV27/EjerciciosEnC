#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char* argv[]){
    int i; // Variable para recorrer los argumentos

    // Imprime un mensaje indicando que el programa se está ejecutando
    printf("Ejecutando el programa invocador (execprog1). Sus argumentos son:\n");

    // Bucle para recorrer los argumentos pasados al programa desde la línea de comandos
    for(i=0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]); // Imprime cada argumento con su índice
    }

    // Pausa la ejecución durante 10 segundos
    sleep(10);

    /*Cambia el primer argumento argv[0] (nombre del programa) a "execprog2"
    Esto es solo un cambio local en el contenido de argv, no cambia el programa en sí*/
    strcpy(argv[0], "execprog2");

    /*Invoca otro programa llamado "execprog2", utilizando los mismos argumentos
    execv reemplaza el programa actual con "execprog2". Si tiene éxito, no vuelve aquí.*/ 
    if(execv("./execprog2", argv) < 0){
        // Si execv falla (retorna un valor negativo), imprime un mensaje de error
        printf("Error en la invocacion a execprog2\n");
        exit(1); // Finaliza el programa con un código de error
    };

    // Finaliza el programa con éxito (aunque en caso de que execv funcione, nunca se llega aquí)
    exit(0);
}