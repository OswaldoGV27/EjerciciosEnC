/*Curso: Sistemas Operativos 4CV3
(C) Noviembre 2024
Implementó: Papas con chile
ESCOM-IPN

Hacer un cogido en c de métodos de asignación contigua*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_SIZE 100

// Estructura para representar un bloque de memoria
struct BloqueDeMemoria {
    int inicio;
    int tam;
    int libre;
};

struct BloqueDeMemoria memoria[MAX_SIZE];
int TamTotalMemoria;

// Función para inicializar la memoria
void InicializarMemoria(int tam) {
    TamTotalMemoria = tam;
    memoria[0].inicio = 0;
    memoria[0].tam = tam;
    memoria[0].libre = 1;
}

// Función para asignar memoria
int AsignacionMemoria(int tam) {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (memoria[i].libre && memoria[i].tam >= tam) {
            int TamRes = memoria[i].tam - tam;
            memoria[i].tam = tam;
            memoria[i].libre = 0;
            
            if (TamRes > 0) {
                for (int j = MAX_SIZE - 1; j > i; j--) {
                    memoria[j] = memoria[j - 1];
                }
                memoria[i + 1].inicio = memoria[i].inicio + tam;
                memoria[i + 1].tam = TamRes;
                memoria[i + 1].libre = 1;
            }
            return memoria[i].inicio;
        }
    }
    return -1; // No hay suficiente memoria disponible
}

// Función para liberar memoria
void LibMemoria(int inicio) {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (memoria[i].inicio == inicio) {
            memoria[i].libre = 1;
            // Fusionar con bloques libres adyacentes
            if (i > 0 && memoria[i - 1].libre) {
                memoria[i - 1].tam += memoria[i].tam;
                for (int j = i; j < MAX_SIZE - 1; j++) {
                    memoria[j] = memoria[j + 1];
                }
            }
            if (i < MAX_SIZE - 1 && memoria[i + 1].libre) {
                memoria[i].tam += memoria[i + 1].tam;
                for (int j = i + 1; j < MAX_SIZE - 1; j++) {
                    memoria[j] = memoria[j + 1];
                }
            }
            break;
        }
    }
}

// Función para imprimir el estado de la memoria
void ImpEstMem() {
    printf("Estado de la memoria:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (memoria[i].tam == 0) break;
        printf("Bloque %d: Inicio = %d, Tam. = %d, %s\n", 
               i, memoria[i].inicio, memoria[i].tam, 
               memoria[i].libre ? "Libre" : "Ocupado");
    }
}

int main() {
    int TamMem;
    printf("------------------------------------------------------------------\n");
    printf("GRUPO: 4CV3  EQUIPO: Papas con chile VERSION: 1.2 FECHA: 6/11/2024\n");
    printf("------------------------------------------------------------------\n");
    printf("Ingrese el TAM. total de la memoria: ");
    scanf("%d", &TamMem);
    InicializarMemoria(TamMem);

    int op;
    do {
        printf("\n--------------------------------\n");
        printf("1.- Asignar memoria\n");
        printf("2.- Liberar memoria\n");
        printf("3.- Imprimir estado de la memoria\n");
        printf("4.- Salir\n");
        printf("-----------------------------------\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &op);
        if (op == 1) {
            int tam;
            printf("Ingrese el TAM del bloque de memoria a asignar: ");
            scanf("%d", &tam);
            int inicio = AsignacionMemoria(tam);
            if (inicio != -1) {
                printf("Memoria asignada en la posicion %d\n", inicio);
            } else {
                printf("No hay suficiente memoria disponible\n");
            }
        } else if (op == 2) {
            int inicio;
            printf("Ingrese el inicio del bloque de memoria a liberar: ");
            scanf("%d", &inicio);
            LibMemoria(inicio);
            printf("Memoria liberada\n");
        } else if (op == 3) {
            ImpEstMem();
        }
    } while (op != 4);

    return 0;
}