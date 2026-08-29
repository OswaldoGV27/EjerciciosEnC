#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

// Tabla de codificación Base64
const char caracteres_base64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// Permutación P10
uint16_t permutacion_p10(uint16_t clave) {
    uint16_t resultado = 0;
    int p10[10] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
    for (int i = 0; i < 10; i++) {
        resultado |= ((clave >> (10 - p10[i])) & 1) << (9 - i);
    }
    return resultado;
}

// Permutación P8
uint8_t permutacion_p8(uint16_t clave) {
    uint8_t resultado = 0;
    int p8[8] = {6, 3, 7, 4, 8, 5, 10, 9};
    for (int i = 0; i < 8; i++) {
        resultado |= ((clave >> (10 - p8[i])) & 1) << (7 - i);
    }
    return resultado;
}

// Desplazamiento a la izquierda
uint16_t desplazamiento_izq(uint16_t clave, int bits) {
    return ((clave << bits) | (clave >> (5 - bits))) & 0x1F;
}

// Generación de subclaves K1 y K2
void generar_subclaves(uint16_t clave, uint8_t *k1, uint8_t *k2) {
    clave = permutacion_p10(clave);
    uint16_t izquierda = (clave >> 5) & 0x1F;
    uint16_t derecha = clave & 0x1F;

    izquierda = desplazamiento_izq(izquierda, 1);
    derecha = desplazamiento_izq(derecha, 1);
    *k1 = permutacion_p8((izquierda << 5) | derecha);

    izquierda = desplazamiento_izq(izquierda, 2);
    derecha = desplazamiento_izq(derecha, 2);
    *k2 = permutacion_p8((izquierda << 5) | derecha);
}

// Función para codificar una cadena binaria en Base64
char *binario_a_base64(const char *binario, int *longitud_original) {
    int longitud_binario = strlen(binario);
    *longitud_original = longitud_binario; // Guardar la longitud original
    int relleno = (6 - (longitud_binario % 6)) % 6;
    int nueva_longitud = longitud_binario + relleno;
    char *binario_relleno = (char *)calloc(nueva_longitud + 1, sizeof(char));
    strcpy(binario_relleno, binario);
    memset(binario_relleno + longitud_binario, '0', relleno);

    int longitud_salida = nueva_longitud / 6;
    char *codificado = (char *)malloc(longitud_salida + 1);
    codificado[longitud_salida] = '\0';

    for (int i = 0; i < nueva_longitud; i += 6) {
        int indice = 0;
        for (int j = 0; j < 6; j++) {
            indice = (indice << 1) | (binario_relleno[i + j] - '0');
        }
        codificado[i / 6] = caracteres_base64[indice];
    }

    free(binario_relleno);
    return codificado;
}

// Función para decodificar una cadena Base64 a binario
char *base64_a_binario(const char *base64, int longitud_original) {
    int longitud_base64 = strlen(base64);
    char *binario = (char *)malloc(longitud_base64 * 6 + 1);
    binario[0] = '\0';

    for (int i = 0; i < longitud_base64; i++) {
        char *ptr = strchr(caracteres_base64, base64[i]);
        if (ptr) {
            int indice = ptr - caracteres_base64;
            char temporal[7];
            for (int j = 5; j >= 0; j--) {
                temporal[j] = (indice & 1) + '0';
                indice >>= 1;
            }
            temporal[6] = '\0';
            strcat(binario, temporal);
        }
    }

    binario[longitud_original] = '\0'; // Recortar a la longitud original
    return binario;
}

void menu() {
    int opcion;
    do {
        printf("\n------------ Menu -------------------\n");
        printf("1. Generar claves S-DES\n");
        printf("2. Codificar binario a Base64\n");
        printf("3. Decodificar Base64 a binario\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                uint16_t clave;
                printf("Ingrese una clave binaria de 10 bits (como número entero): ");
                scanf("%hu", &clave);
                
                uint8_t k1, k2;
                generar_subclaves(clave, &k1, &k2);
                
                printf("K1: %02X\n", k1);
                printf("K2: %02X\n", k2);
                break;
            }
            case 2: {
                char binario[256];
                printf("Ingrese una cadena binaria: ");
                scanf("%255s", binario);
            
                int longitud_original;
                char *codificado = binario_a_base64(binario, &longitud_original);
                printf("Base64: %s\n", codificado);
                free(codificado);
                break;
            }

            case 3: {
                char base64[256];
                int longitud_original;
                printf("Ingrese una cadena Base64: ");
                scanf("%255s", base64);
                printf("Ingrese la longitud original de la cadena binaria: ");
                scanf("%d", &longitud_original);
            
                char *decodificado = base64_a_binario(base64, longitud_original);
                printf("Binario: %s\n", decodificado);
                free(decodificado);
                break;
            }

            case 4:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opcion no valida. Intentalo de nuevo.\n");
                break;
        }
    } while (opcion != 4);
}

int main() {
    menu();
    return 0;
}