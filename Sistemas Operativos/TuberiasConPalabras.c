#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void tarea1(const char* filename, int pipe1[], int pipe2[]);
void tarea2(int pipe1[], const char* word, int pipe3[]);
void tarea3(int pipe2[], const char* word, int pipe3[]);
void tarea4(int pipe3[]);

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Uso: %s <fichero> <palabra1> <palabra2>\n", argv[0]);
        exit(1);
    }

    const char *filename = argv[1];
    const char *pal1 = argv[2];
    const char *pald2 = argv[3];

    int pipe1[2], pipe2[2], pipe3[2];
    
    // Crear las tuberías
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1 || pipe(pipe3) == -1) {
        perror("Error al crear las tuberías");
        exit(1);
    }

    // Crear el proceso para la tarea 1
    pid_t pid1 = fork();
    if (pid1 == 0) {
        // Hijo: realiza la tarea 1
        tarea1(filename, pipe1, pipe2);
        exit(0);
    }

    // Crear el proceso para la tarea 2
    pid_t pid2 = fork();
    if (pid2 == 0) {
        // Hijo: realiza la tarea 2
        tarea2(pipe1, word1, pipe3);
        exit(0);
    }

    // Crear el proceso para la tarea 3
    pid_t pid3 = fork();
    if (pid3 == 0) {
        // Hijo: realiza la tarea 3
        tarea3(pipe2, word2, pipe3);
        exit(0);
    }

    // Crear el proceso para la tarea 4
    pid_t pid4 = fork();
    if (pid4 == 0) {
        // Hijo: realiza la tarea 4
        tarea4(pipe3);
        exit(0);
    }

    // Esperar a los hijos
    close(pipe1[0]); close(pipe1[1]);
    close(pipe2[0]); close(pipe2[1]);
    close(pipe3[0]); close(pipe3[1]);
    
    wait(NULL);
    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}

void tarea1(const char* filename, int pipe1[], int pipe2[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error al abrir el fichero");
        exit(1);
    }

    close(pipe1[0]);  // Cerrar la lectura de la tubería 1
    close(pipe2[0]);  // Cerrar la lectura de la tubería 2

    char buffer[BUFFER_SIZE];
    int line_num = 0;

    while (fgets(buffer, BUFFER_SIZE, file)) {
        if (line_num % 2 == 0) {
            write(pipe1[1], buffer, strlen(buffer));  // Líneas pares a pipe1
        } else {
            write(pipe2[1], buffer, strlen(buffer));  // Líneas impares a pipe2
        }
        line_num++;
    }

    close(pipe1[1]);  // Cerrar la escritura de la tubería 1
    close(pipe2[1]);  // Cerrar la escritura de la tubería 2

    fclose(file);
}

void tarea2(int pipe1[], const char* word, int pipe3[]) {
    close(pipe1[1]);  // Cerrar la escritura de la tubería 1
    close(pipe3[0]);  // Cerrar la lectura de la tubería 3

    dup2(pipe1[0], STDIN_FILENO);  // Redirigir entrada estándar desde pipe1
    dup2(pipe3[1], STDOUT_FILENO); // Redirigir salida estándar hacia pipe3

    execlp("grep", "grep", word, NULL);  // Ejecutar grep con la palabra dada

    perror("Error al ejecutar grep");
    exit(1);
}

void tarea3(int pipe2[], const char* word, int pipe3[]) {
    close(pipe2[1]);  // Cerrar la escritura de la tubería 2
    close(pipe3[0]);  // Cerrar la lectura de la tubería 3

    dup2(pipe2[0], STDIN_FILENO);  // Redirigir entrada estándar desde pipe2
    dup2(pipe3[1], STDOUT_FILENO); // Redirigir salida estándar hacia pipe3

    execlp("grep", "grep", word, NULL);  // Ejecutar grep con la palabra dada

    perror("Error al ejecutar grep");
    exit(1);
}

void tarea4(int pipe3[]) {
    close(pipe3[1]);  // Cerrar la escritura de la tubería 3

    dup2(pipe3[0], STDIN_FILENO);  // Redirigir entrada estándar desde pipe3

    execlp("sort", "sort", NULL);  // Ejecutar sort

    perror("Error al ejecutar sort");
    exit(1);
}
