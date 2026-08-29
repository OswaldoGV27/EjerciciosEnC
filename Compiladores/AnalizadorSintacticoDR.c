#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Definición de constantes
#define MAX_SIZE 1000

// Funciones de la gramática
int E();
int E_prime();
int T();
int T_prime();
int F();

// Variables globales
char *cadena;
int longitud;
int posicion;

// Función para avanzar al siguiente carácter no espacio
void Avanzar() {
    while (cadena[posicion] == ' ' && posicion < longitud) {
        posicion++;
    }
}

// Función Analizador (existente, la modificaremos)
void Analizador(char *cadena, int longitud);

// Función principal
int main() {
    // Configurar la localización para admitir caracteres especiales
    setlocale(LC_ALL, "");

    // Reservar memoria dinámica para la cadena
    cadena = (char*)malloc(sizeof(char) * MAX_SIZE);
    if (cadena == NULL) {
        printf("No se reservó memoria dinámica correctamente\n");
        exit(0);
    }

    // Leer la cadena
    printf("Ingrese la expresión a evaluar: ");
    fgets(cadena, MAX_SIZE, stdin);
    longitud = strlen(cadena);
    if (cadena[longitud - 1] == '\n') {
        cadena[longitud - 1] = '\0';
        longitud--;
    }

    // Inicializar variables globales
    posicion = 0;

    // Realizar análisis sintáctico
    if (E() && posicion == longitud) {
        printf("Expresión reconocida\n");
    } else {
        printf("Expresión no reconocida\n");
    }

    // Liberar memoria dinámica
    free(cadena);

    return 0;
}

// Funciones de la gramática
int E() {
    if (T()) {
        return E_prime();
    }
    return 0;
}

int E_prime() {
    Avanzar(); // Ignorar espacios en blanco
    if (cadena[posicion] == '+') {
        posicion++;
        if (T()) {
            return E_prime();
        }
        return 0;
    } else if (cadena[posicion] == '-') {
        posicion++;
        if (T()) {
            return E_prime();
        }
        return 0;
    }
    return 1;  // ε
}

int T() {
    if (F()) {
        return T_prime();
    }
    return 0;
}

int T_prime() {
    Avanzar(); // Ignorar espacios en blanco
    if (cadena[posicion] == '*') {
        posicion++;
        if (F()) {
            return T_prime();
        }
        return 0;
    } else if (cadena[posicion] == '/') {
        posicion++;
        if (F()) {
            return T_prime();
        }
        return 0;
    }
    return 1;  // ε
}

int F() {
    Avanzar(); // Ignorar espacios en blanco
    if (cadena[posicion] == '(') {
        posicion++;
        if (E()) {
            if (cadena[posicion] == ')') {
                posicion++;
                return 1;
            }
        }
        return 0;
    } else if (isalpha(cadena[posicion])) {  // ID válido
        while (isalnum(cadena[posicion])) { // Procesar letras y números
            posicion++;
        }
        return 1;
    } else if (isdigit(cadena[posicion])) {  // número
        while (isdigit(cadena[posicion])) {
            posicion++;
        }
        return 1;
    }
    return 0;
}

// Función Analizador (modificada)
void Analizador(char *cadena, int longitud) {
    int i, j;
    char aux[100];

    for (i = 0; i < longitud; ++i) {
        aux[0] = '\0';

        if (cadena[i] >= '0' && cadena[i] <= '9') {
            printf("<NUM, ");
            printf("%c", cadena[i]);
            for (j = i + 1; j < longitud; ++j) {
                if (cadena[j] >= '0' && cadena[j] <= '9') {
                    printf("%c", cadena[j]);
                    i++;
                } else {
                    break;
                }
            }
            printf(">\n");
        } else if (cadena[i] == '+' || cadena[i] == '-') {
            if (cadena[i + 1] == '+' || cadena[i + 1] == '-') {
                printf("<OpNoValido, %c%c>\n", cadena[i], cadena[i + 1]);
                i++;
            } else {
                printf("<OP, %c>\n", cadena[i]);
            }
        } else if (isalpha(cadena[i])) { // ID comienza con letra
            for (j = i; j < longitud; ++j) {
                if (isalnum(cadena[j])) { // Permitir letras y números
                    aux[j - i] = cadena[j];
                } else {
                    break;
                }
            }
            aux[j - i] = '\0'; // Agregar fin de cadena a aux
            printf("<ID, %s>\n", aux);
            i = j - 1; // Ajustar posición
        } else if (cadena[i] == ' ') {
            continue; // Omitir espacios
        } else {
            printf("<NoValido, %c >\n", cadena[i]);
        }
    }
}