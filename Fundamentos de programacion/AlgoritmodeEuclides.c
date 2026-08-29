//Oswaldo Gil Valentín 1CV6
#include <stdio.h>

// Función que calcula el MCD utilizando el algoritmo de Euclides
int mcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2, opcion;

    // Bucle principal del programa do while
    do {
        // Menú principal con las 2 opciones
        printf("--------------------------------\n");
        printf("Seleccione una opci%cn:\n", 162);
        printf("1. Calcular el MCD de dos n%cmeros.\n", 163);
        printf("2. Salir del programa.\n");
        printf("Opci%cn: ", 162);
        scanf("%d", &opcion);
        printf("--------------------------------\n");

        // Según la opción seleccionada por el usuario, realizamos la acción correspondiente
        switch (opcion) {
            case 1:
                // Solicitamos los dos números a calcular el MCD
                printf("-------------------------------\n");
                printf("\nIntroduce el primer n%cmero: ", 163);
                scanf("%d", &num1);
                printf("Introduce el segundo n%cmero: ", 163);
                scanf("%d", &num2);
                printf("-------------------------------\n");

                // Calculamos y mostramos el MCD
                printf("-----------------------\n");
                printf("El MCD de %d y %d es: %d\n", num1, num2, mcd(num1, num2));
                printf("-----------------------\n");
                break;
            case 2:
                printf("\nSaliendo del programa...\n");
                break;
            default:
                printf("\nOpci%cn no v%clida. Introduce una opci%cn v%clida.\n", 162, 160, 162, 160);
                break;
        }

    } while (opcion != 2);

    return 0;
}