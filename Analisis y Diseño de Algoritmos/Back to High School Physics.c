#include <stdio.h>

int main() {
    int v, t;

    /* Lectura de la entrada hasta el final del archivo */
    while (scanf("%d %d", &v, &t) != EOF) {
        /* Cálculo del desplazamiento al doble de ese tiempo */
        int displacement = v * (2 * t);

        /* Imprimir el resultado */
        printf("%d\n", displacement);
    }

    return 0;
}