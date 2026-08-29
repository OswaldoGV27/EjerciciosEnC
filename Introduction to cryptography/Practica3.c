#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>  

// Función que implementa el algoritmo de Euclides Extendido para calcular el inverso multiplicativo
int inverso_multiplicativo(int a, int n) {
    int a0 = n, b0 = a;
    int t0 = 0, t1 = 1;
    int q, r, temp;

    while (b0 > 0) {
        q = a0 / b0;
        r = a0 % b0;
        temp = t0 - q * t1;
        t0 = t1;
        t1 = temp;
        a0 = b0;
        b0 = r;
    }

    if (a0 != 1) {
        printf("No existe inverso multiplicativo para %d modulo %d.\n", a, n);
        return -1;
    }

    // Asegurar que el inverso sea positivo
    if (t0 < 0) {
        t0 += n;
    }

    return t0;
}

// Función para generar una clave aleatoria válida para el cifrado Hill
void generar_clave_hill(int n, int clave[2][2]) {
    int det, inv_det;

    srand(time(NULL));

    do {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                clave[i][j] = rand() % n;
            }
        }

        det = (clave[0][0] * clave[1][1]) - (clave[0][1] * clave[1][0]);
        det = det % n;
        if (det < 0) det += n;

        // Calcular el inverso multiplicativo del determinante
        inv_det = inverso_multiplicativo(det, n);
    } while (inv_det == -1);

    printf("Clave generada:\n");
    printf("%d %d\n", clave[0][0], clave[0][1]);
    printf("%d %d\n", clave[1][0], clave[1][1]);
    printf("Determinante: %d\n", det);
    printf("Inverso del determinante: %d\n", inv_det);
}

void menu() {
    int opcion;
    do {
        printf("\n------------ Menu -------------------\n");
        printf("1. AEE Modificado\n");
        printf("2. Generar clave aleatoria Hill Cipher\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                int a, n;
                printf("Ingrese el numero a: ");
                scanf("%d", &a);
                printf("Ingrese el modulo n: ");
                scanf("%d", &n);

                int inverso = inverso_multiplicativo(a, n);
                if (inverso != -1) {
                    printf("El inverso multiplicativo de %d modulo %d es: %d\n", a, n, inverso);
                }
                break;
            }

            case 2: {
                int n;
                int clave[2][2];

                printf("Ingrese el tamano del alfabeto (n >= 2): ");
                scanf("%d", &n);

                if (n < 2) {
                    printf("El tamaño del alfabeto debe ser al menos 2.\n");
                    break;
                }

                generar_clave_hill(n, clave);
                break;
            }

            case 3:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opcion no valida. Intentalo de nuevo.\n");
                break;
        }
    } while (opcion != 3);
}

int main() {
    menu();
    return 0;
}
