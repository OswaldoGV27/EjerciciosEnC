#include <stdio.h>
#include <stdlib.h>

int compara(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n = 0;
    int numeros[10000]; /*Asumiendo que N es menor que 10000*/

    while (scanf("%d", &numeros[n]) != EOF) {
        n++; /*Incrementar el contador de números*/
        qsort(numeros, n, sizeof(int), compara); /*Ordenar el arreglo*/

        /*Calcular la mediana*/
        int mediana;
        if (n % 2 == 0) {
            mediana = (numeros[n/2 - 1] + numeros[n/2]) / 2;
        } else {
            mediana = numeros[n/2];
        }

        printf("%d\n", mediana); /*Imprimir la mediana*/
    }

    return 0;
}