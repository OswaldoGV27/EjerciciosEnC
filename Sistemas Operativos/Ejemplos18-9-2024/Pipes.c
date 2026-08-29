#include <stdio.h>   // Para funciones de entrada y salida como printf y scanf
#include <errno.h>   // Para manejar errores y acceder al valor de errno
#include <unistd.h>  // Para usar funciones como fork(), pipe(), read(), write(), close()
#include <string.h>  // Para manejar cadenas y funciones como strlen()
#include <stdlib.h>  // Para usar exit() y funciones de gestión de memoria
#include <sys/wait.h> // Para usar wait() y esperar la terminación del proceso hijo

// Prototipos de funciones
void imprimeDePipe (int leePipe); // Función que ejecuta el proceso hijo, leyendo del pipe
void enviaAPipe (int escribePipe); // Función que ejecuta el proceso padre, escribiendo en el pipe

int main(){
    pid_t procHijo;  // Variable para almacenar el PID del proceso hijo
    int pipeFileDescriptors[2]; // Arreglo que almacenará los descriptores de archivo del pipe (lectura y escritura)
    
    // Crea el pipe y verifica si ocurrió algún error
    if (pipe(pipeFileDescriptors) == -1) { 
        printf ("Error al crear pipe\n");
        exit(1);  // Finaliza el programa en caso de error
    }
    
    procHijo = fork(); // Crea un nuevo proceso (hijo)
    
    if (procHijo < 0){
        int interrnum = errno; // Almacena el código de error en caso de falla en fork()
        printf("Error al generar proceso hijo con fork: %d\n", interrnum);  
        exit(1);  // Finaliza el programa en caso de error
    }

    if (procHijo == 0){  // Código ejecutado por el proceso hijo
        close(pipeFileDescriptors[1]);  // Cierra el extremo de escritura del pipe, solo necesita leer
        imprimeDePipe(pipeFileDescriptors[0]);  // Llama a la función que leerá del pipe
    }
    
    if(procHijo > 0){  // Código ejecutado por el proceso padre
        close(pipeFileDescriptors[0]);  // Cierra el extremo de lectura del pipe, solo necesita escribir
        enviaAPipe(pipeFileDescriptors[1]);  // Llama a la función que escribirá en el pipe
    }
    
    return 0;  // El programa termina correctamente
}

/** Función ejecutada por el proceso hijo
 *  Lee datos del pipe y los imprime en la consola (STDOUT)
 *  Luego cierra el pipe y termina el proceso hijo
 **/
void imprimeDePipe(int leePipe){
    char buf;  // Buffer para almacenar un carácter leído del pipe
    printf("Proceso hijo, esperando cadena...\n");  
    
    // Lee del pipe un byte (carácter) a la vez y lo escribe en la salida estándar (STDOUT)
    while (read(leePipe, &buf, 1) > 0)
        write(STDOUT_FILENO, &buf, 1);
    
    write(STDOUT_FILENO, "\n", 1);  // Imprime un salto de línea después de leer toda la cadena
    close(leePipe);  // Cierra el extremo de lectura del pipe
    printf("Proceso hijo, finalizando\n");
    exit(0);  // Termina el proceso hijo
}

/** Función ejecutada por el proceso padre
 *  Lee una cadena de hasta 10 caracteres del usuario
 *  La escribe en el pipe, luego cierra el pipe y espera a que el proceso hijo termine
 **/
void enviaAPipe(int escribePipe){
    char buf[10];  // Buffer para almacenar hasta 10 caracteres ingresados por el usuario
    printf("Proceso padre, ingresa una cadena de 10 caracteres y presiona enter:\n");
    
    // Lee una cadena de hasta 10 caracteres del usuario
    scanf("%10s", buf);  
    printf("\n");  // Imprime un salto de línea para separar la entrada del usuario de futuras salidas
    
    // Escribe la cadena ingresada en el pipe
    write(escribePipe, buf, strlen(buf));  
    
    close(escribePipe);  // Cierra el extremo de escritura del pipe (esto envía una señal de EOF al proceso hijo)
    wait(NULL);  // Espera a que el proceso hijo termine
    
    printf("Hijo terminado, terminando proceso padre\n");
    exit(0);  // Termina el proceso padre
}
