#include <stdio.h>

// Función que implementa el algoritmo de Euclides Extendido
void extended_euclidean(int a, int b, int *gcd, int *s, int *t) {
    int a0 = a, b0 = b;
    int t0 = 0, t1 = 1;
    int s0 = 1, s1 = 0;
    int q, r, temp;

    q = a0 / b0;
    r = a0 - q * b0;

    while (r > 0) {
        temp = t0 - q * t1;
        t0 = t1;
        t1 = temp;

        temp = s0 - q * s1;
        s0 = s1;
        s1 = temp;

        a0 = b0;
        b0 = r;
        q = a0 / b0;
        r = a0 - q * b0;
    }

    *gcd = b0;
    *s = s1;
    *t = t1;
}

// Función principal
int main() {
    int a, b, gcd, s, t;

    // Entrada del usuario
    printf("Ingrese dos numeros enteros: ");
    scanf("%d %d", &a, &b);

    // Llamada al algoritmo extendido de Euclides
    extended_euclidean(a, b, &gcd, &s, &t);

    // Resultados
    printf("MCD(%d, %d) = %d\n", a, b, gcd);
    printf("Coeficientes: s = %d, t = %d\n", s, t);
    printf("Verificacion: %d * %d + %d * %d = %d\n", s, a, t, b, gcd);

    return 0;
}
