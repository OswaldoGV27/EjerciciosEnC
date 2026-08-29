#include <stdio.h>
#include <stdlib.h> // Para rand() y srand()
#include <time.h>   // Para time()

// Sub-Funcion para calcular mcd (Algoritmo de Euclides)
int mcd(int a, int b) {
    // Algoritmo de Euclides
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Funcion que imprime la lista de enteros Z*n y devuelve el último elemento
int LZn(int n, int *elementos, int *tamano) {
    printf("La lista de Z*%d es:\n", n);
    int contador = 0;

    // Se usa el for para comprobar que los numeros sean coprimos de a hasta n
    for (int a = 1; a <= n; a++) {
        // Si se cumple el if se imprimen y se guardan en el arreglo
        if (mcd(a, n) == 1) {
            printf("%d\n", a);
            elementos[contador] = a;
            contador++;
        }
    }
    printf("\n");

    *tamano = contador; // Guardamos el tamaño del arreglo
    return elementos[contador - 1]; // Devolvemos el último elemento
}

// Función para encontrar el inverso multiplicativo de a módulo n
int encontrar_inverso(int a, int n) {
    // Verificar que a y n son coprimos
    if (mcd(a, n) != 1) {
        printf("El inverso multiplicativo no existe porque a y n no son coprimos.\n");
        return -1; // No existe el inverso multiplicativo
    }

    // Iterar sobre todos los elementos b en Z_n*
    for (int b = 1; b < n; b++) {
        if ((a * b) % n == 1) {
            return b; // b es el inverso multiplicativo de a módulo n
        }
    }

    // Si no se encuentra ningún inverso (aunque debería encontrarse si a y n son coprimos)
    return -1;
}

int main() {
    int a, n, M;

    printf("------------------- Ejercicio 1 -------------------\n");
    printf("Ingrese un numero MAYOR O IGUAL A 2: ");
    scanf("%d", &n);

    // Verificamos que el numero ingresado sea mayor o igual a 2
    if (n < 2) {
        printf("El numero debe ser mayor o igual que 2\n");
        return 1;
    }

    // Arreglo para almacenar los elementos de Z*n
    int elementos[100]; // Asumimos que n no es mayor que 100
    int tamano;

    // Llamamos a la funcion que imprime la lista Z*n y guarda el último elemento
    int ultimo_elemento = LZn(n, elementos, &tamano);

    // Solicitar al usuario que ingrese los valores de a y n
    printf("------------------- Ejercicio 2 -------------------\n");
    printf("Ingrese el valor de a: ");
    scanf("%d", &a);
    printf("Ingrese el valor de n (n >= 2): ");
    scanf("%d", &n);

    // Verificar que n >= 2
    if (n < 2) {
        printf("n debe ser mayor o igual a 2.\n");
        return 1;
    }

    // Encontrar el inverso multiplicativo de a módulo n
    int inverso = encontrar_inverso(a, n);

    // Mostrar el resultado
    if (inverso != -1) {
        printf("El inverso multiplicativo de %d modulo %d es: %d\n", a, n, inverso);
    } else {
        printf("No se pudo encontrar el inverso multiplicativo de %d modulo %d.\n", a, n);
    }

    printf("------------------- Ejercicio 3 -------------------\n");
    printf("Ingrese el tama%co del Alfabeto: ", 164);
    scanf("%d", &M);
    // Generar un número aleatorio b en el intervalo [0, ultimo_elemento]
    srand(time(NULL)); // Inicializar la semilla para rand()
    int p = rand() % (ultimo_elemento + 1); // Número aleatorio entre 0 y ultimo_elemento
    int b = p + M; 

    // Imprimir "Key: a, b"
    printf("Key: %d, %d\n", ultimo_elemento, b);

    return 0;
}