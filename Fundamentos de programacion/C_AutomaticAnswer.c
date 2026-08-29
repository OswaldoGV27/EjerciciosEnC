#include <stdio.h>

int main() {
    int t, n;
    scanf("%d", &t); /* Lee el número de casos de prueba*/

    while (t--) {
        scanf("%d", &n); /* Lee el valor n para cada caso de prueba*/

        /* Realiza las operaciones dadas en la pregunta de habilidad*/
        int resultado = ((n * 567 / 9 + 7492) * 235 / 47 - 498) / 10 % 10;

        /*Imprime el dígito en la columna de las decenas*/ 
        printf("%d\n", (resultado < 0) ? -resultado : resultado);
    }

    return 0;
}