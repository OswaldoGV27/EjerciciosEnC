#include <stdio.h>

/* Función para calcular el Máximo Común Divisor (MCD) de dos números.*/
int mcd(int a, int b) {
    while(b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int N, i, j;
    long G;

    /* Leer los valores de N y calcular G hasta que se introduzca un cero.*/
    while(scanf("%d", &N) && N) {
        /* Verificar si N es mayor a 500*/
        if(N > 500) {
            printf("N debe ser menor a 501\n");
            continue; /* Saltar al siguiente ciclo del bucle.*/
        }

        G = 0;
        for(i = 1; i < N; i++) {
            for(j = i + 1; j <= N; j++) {
                G += mcd(i, j);
            }
        }
        printf("%ld\n", G);
    }

    return 0;
}
