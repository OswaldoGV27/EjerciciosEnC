#include <stdio.h>
#include <stdlib.h>

/*Prototipos de las funciones*/
int compare(const void *a, const void *b);
int buscar(int arr[], int n, int x);

int main() {
    int N, Q, caso = 0;
    int canicas[10000];

    while (1) {
        scanf("%d %d", &N, &Q);
        if (N == 0 && Q == 0) break; /*Terminar si N y Q son 0.*/

        caso++;
        printf("CASE# %d:\n", caso);

        int i;
        for (i = 0; i < N; i++) {
            scanf("%d", &canicas[i]);
        }

        /*Ordenar las canicas.*/
        qsort(canicas, N, sizeof(int), compare);

        int j;
        for (j = 0; j < Q; j++) {
            int consulta;
            scanf("%d", &consulta);

            /*Buscar la canica.*/
            int posicion = buscar(canicas, N, consulta);
            if (posicion != -1) {
                printf("%d found at %d\n", consulta, posicion);
            } else {
                printf("%d not found\n", consulta);
            }
        }
    }

    return 0;
}

/*Función para comparar dos elementos (necesaria para qsort).*/
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

/*Función para buscar la posición de un valor en el arreglo.*/
int buscar(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i + 1; /*Las posiciones comienzan en 1.*/
        }
    }
    return -1; /*Si no se encuentra el valor.*/
}