#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    while (scanf("%d", &n) == 1) {
        /* Almacena las diferencias absolutas en un arreglo*/
        int *diferencia = (int *)malloc((n - 1) * sizeof(int));

        int i;
        for (i = 0; i < n; i++) {
            scanf("%d", &diferencia[i]);
        }

        /*Crea un arreglo de banderas para verificar las diferencias*/ 
        int *flags = (int *)calloc(n, sizeof(int));

        /* Verifica las diferencias absolutas*/
        for (i = 1; i < n; i++) {
            int diff = abs(diferencia[i] - diferencia[i - 1]);

            /* Si la diferencia no está en el rango o ya se encontró antes, no es jolly*/
            if (diff < 1 || diff >= n || flags[diff] == 1) {
                printf("Not jolly\n");
                break;
            }

            flags[diff] = 1; /* Marca la diferencia como encontrada*/
        }

        /* Si se corrió todo el bucle sin imprimir "Not jolly", entonces es jolly*/
        if (i == n) {
            printf("Jolly\n");
        }

        free(diferencia);
        free(flags);
    }

    return 0;
}