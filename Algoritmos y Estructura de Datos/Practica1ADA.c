#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000

typedef struct {
    int tren[MAX_N];
    int tope;
} Pila;

void inicializarPila(Pila *pila) {
    pila->tope = -1;
}

void push(Pila *pila, int valor) {
    pila->tren[++pila->tope] = valor;
}

int pop(Pila *pila) {
    return pila->tren[pila->tope--];
}

int estaVacia(Pila *pila) {
    return pila->tope == -1;
}

int verTope(Pila *pila) {
    return pila->tren[pila->tope];
}

int puedeMover(int vagones[], int n) {
    Pila estacion;
    inicializarPila(&estacion);

    int vagonEsperado = 1;
    int i = 0;

    while (i < n) {
        while (!estaVacia(&estacion) && verTope(&estacion) == vagonEsperado) {
            pop(&estacion);
            vagonEsperado++;
        }

        if (vagones[i] == vagonEsperado) {
            vagonEsperado++;
        } else {
            push(&estacion, vagones[i]);
        }
        i++;
    }

    while (!estaVacia(&estacion) && verTope(&estacion) == vagonEsperado) {
        pop(&estacion);
        vagonEsperado++;
    }

    return estaVacia(&estacion);
}

int main() {
    char linea[4 * MAX_N];
    int vagones[MAX_N], n, resultado[MAX_N], indiceResultado = 0;
    Pila estacion;

    while (fgets(linea, sizeof(linea), stdin)) {
        if (strcmp(linea, "00\n") == 0) break;

        n = 0;
        char *numero = strtok(linea, " ");
        while (numero) {
            vagones[n++] = atoi(numero);
            numero = strtok(NULL, " ");
        }

        if (n == 1 && vagones[0] == 0) {
            int i = 0;
            while (i < indiceResultado) {
                printf(resultado[i] ? "Si\n" : "No\n");
                i++;
            }
            printf("Fin del bloque de trenes.\n\n");
            indiceResultado = 0;
        } else if (n > 1) {
            resultado[indiceResultado++] = puedeMover(vagones, n);
        }
    }

    return 0;
}