// Equipo Papas con chile
// 16/09/2024
// Version 1.0
//Codigo que sirve para buscar una palabra en 3 archivos diferentes, usando un hilo para cada archivo

#include <stdio.h>      // Para funciones de entrada y salida como printf()
#include <pthread.h>    // Para trabajar con hilos
#include <stdlib.h>     // Para funciones estándar como malloc() y exit()
#include <string.h>     // Para manipular cadenas, como strstr()

#define MAX_LINE_LENGTH 256  // Definir un tamaño máximo para las líneas leídas de los archivos

// Estructura para pasar datos a los hilos
typedef struct {
    char *filename;      // Nombre del archivo donde se realizará la búsqueda
    char *search_term;   // Término que se buscará dentro del archivo
} hilo_data;

// Función que será ejecutada por cada hilo para buscar una palabra en un archivo
void *buscar_palabra(void *arg) {
    // Convertir el argumento al tipo de dato esperado (estructura hilo_data)
    hilo_data *data = (hilo_data *) arg;

    // Abrir el archivo en modo lectura
    FILE *file = fopen(data->filename, "r");
    if (file == NULL) {
        perror("Error al abrir el archivo");  // Mostrar un mensaje de error si el archivo no se puede abrir
        pthread_exit(NULL);  // Finalizar el hilo
    }

    // Informar qué archivo y término se están buscando
    printf("Buscando '%s' en %s\n", data->search_term, data->filename);
    
    char line[MAX_LINE_LENGTH];  // Buffer para almacenar cada línea leída del archivo
    int line_number = 1;         // Contador de líneas (opcional, pero útil para debug o mejoras futuras)
    int found = 0;               // Bandera para indicar si se encontró la palabra

    // Leer el archivo línea por línea
    while (fgets(line, sizeof(line), file)) {
        // Verificar si la palabra buscada está en la línea actual
        if (strstr(line, data->search_term) != NULL) {
            // Si se encuentra la palabra, imprimir un mensaje
            printf("Se encontró en %s, la palabra %s\n", data->filename, data->search_term);
            found = 1;  // Cambiar la bandera indicando que se encontró la palabra
        }
        line_number++;  // Aumentar el número de línea (no se utiliza pero podría servir en el futuro)
    }

    // Si no se encontró la palabra en todo el archivo, imprimir un mensaje
    if (!found) {
        printf("No se encontró en %s\n", data->filename);
    }

    // Cerrar el archivo y finalizar el hilo
    fclose(file);
    pthread_exit(NULL);
}

int main() {
    pthread_t hilos[3];     // Arreglo de tres hilos para las tres búsquedas en los archivos
    hilo_data datos[3];     // Arreglo de estructuras hilo_data para pasar a cada hilo
    char search_term[100];  // Variable para almacenar el término de búsqueda ingresado por el usuario

    // Solicitar al usuario la palabra que quiere buscar
    printf("Ingrese la palabra a buscar: ");
    scanf("%s", search_term);  // Leer la palabra del usuario
    
    printf("\n\n");  // Imprimir un par de saltos de línea para separar la entrada de los resultados

    // Asignar los nombres de los archivos y la palabra a buscar a cada estructura hilo_data
    datos[0].filename = "frutas.txt";
    datos[0].search_term = search_term;

    datos[1].filename = "nombres.txt";
    datos[1].search_term = search_term;

    datos[2].filename = "ciudades.txt";
    datos[2].search_term = search_term;

    // Crear hilos para buscar la palabra en cada archivo
    for (int i = 0; i < 3; i++) {
        pthread_create(&hilos[i], NULL, buscar_palabra, (void *) &datos[i]);
    }

    // Esperar a que los hilos terminen su ejecución
    for (int i = 0; i < 3; i++) {
        pthread_join(hilos[i], NULL);
    }

    return 0;  // Finalizar el programa
}

