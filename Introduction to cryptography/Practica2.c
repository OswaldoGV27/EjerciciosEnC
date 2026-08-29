#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_ALFABETO 100
#define TAM_MAX_MENSAJE 1000

// Función para asociar cada símbolo del alfabeto con un elemento de Z_n
void asociar_alfabeto(char alfabeto[], int n, int asociacion[], int inverso[]) {
    for (int i = 0; i < n; i++) {
        asociacion[(int)alfabeto[i]] = i;
        inverso[i] = alfabeto[i];
    }
}

// Función para cifrar un mensaje usando el cifrado de Vigenère
void vigenere_cifrar(char *mensaje, char *clave, int asociacion[], int n, char *mensaje_cifrado, char alfabeto[]) {
    int tam_mensaje = strlen(mensaje);
    int tam_clave = strlen(clave);

    for (int i = 0; i < tam_mensaje; i++) {
        int indice_mensaje = asociacion[(int)mensaje[i]];
        int indice_clave = asociacion[(int)clave[i % tam_clave]];
        int indice_cifrado = (indice_mensaje + indice_clave) % n;
        mensaje_cifrado[i] = alfabeto[indice_cifrado];
    }
    mensaje_cifrado[tam_mensaje] = '\0';
}

// Función para descifrar un mensaje cifrado con el cifrado de Vigenère
void vigenere_descifrar(char *mensaje_cifrado, char *clave, int asociacion[], int n, char *mensaje_descifrado, char alfabeto[]) {
    int tam_mensaje = strlen(mensaje_cifrado);
    int tam_clave = strlen(clave);

    for (int i = 0; i < tam_mensaje; i++) {
        int indice_cifrado = asociacion[(int)mensaje_cifrado[i]];
        int indice_clave = asociacion[(int)clave[i % tam_clave]];
        int indice_descifrado = (indice_cifrado - indice_clave + n) % n;
        mensaje_descifrado[i] = alfabeto[indice_descifrado];
    }
    mensaje_descifrado[tam_mensaje] = '\0';
}

// Función para guardar el alfabeto en un archivo
void guardar_alfabeto_en_archivo(char alfabeto[]) {
    FILE *archivo = fopen("alfabeto.txt", "w");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return;
    }
    fprintf(archivo, "%s", alfabeto);
    fclose(archivo);
    printf("Alfabeto guardado en 'alfabeto.txt'.\n");
}

// Función para cargar el alfabeto desde un archivo
void cargar_alfabeto_desde_archivo(char alfabeto[], int *n) {
    FILE *archivo = fopen("alfabeto.txt", "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return;
    }
    fscanf(archivo, "%s", alfabeto);
    fclose(archivo);
    *n = strlen(alfabeto);
    printf("Alfabeto cargado desde 'alfabeto.txt': %s\n", alfabeto);
}

// Menú principal
void menu() {
    char alfabeto[TAM_MAX_ALFABETO];
    int n = 0;
    int asociacion[256] = {0};
    int inverso[TAM_MAX_ALFABETO];
    char clave[TAM_MAX_MENSAJE];
    char mensaje[TAM_MAX_MENSAJE];
    char mensaje_cifrado[TAM_MAX_MENSAJE];
    char mensaje_descifrado[TAM_MAX_MENSAJE];

    int opcion;
    do {
        printf("\n------------ Menu ------------\n");
        printf("1. Crear y guardar alfabeto\n");
        printf("2. Cifrar un mensaje\n");
        printf("3. Descifrar un mensaje\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        printf("\n------------------------------\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("----- ::Introduce el alfabeto:: ------\n (debe tener al menos 2 simbolos y solo letras minusculas): ");
                scanf("%s", alfabeto);
                n = strlen(alfabeto);
                if (n < 2) {
                    printf("El alfabeto debe tener al menos 2 simbolos.\n");
                    break;
                }
                guardar_alfabeto_en_archivo(alfabeto);
                asociar_alfabeto(alfabeto, n, asociacion, inverso);
                break;

            case 2:
                cargar_alfabeto_desde_archivo(alfabeto, &n);
                if (n < 2) {
                    printf("Primero debes crear un alfabeto valido.\n");
                    break;
                }
                printf("------ ::Introduce la clave:: ------\n (debe tener al menos 5 caracteres): ");
                scanf("%s", clave);
                if (strlen(clave) < 5) {
                    printf("La clave debe tener al menos 5 caracteres.\n");
                    break;
                }
                printf("------ ::Introduce el mensaje:: ------\n (debe tener al menos 30 caracteres): ");
                scanf("%s", mensaje);
                if (strlen(mensaje) < 30) {
                    printf("El mensaje debe tener al menos 30 caracteres.\n");
                    break;
                }
                vigenere_cifrar(mensaje, clave, asociacion, n, mensaje_cifrado, alfabeto);
                printf("------::Mensaje cifrado:: ------\n %s\n", mensaje_cifrado);
                break;

            case 3:
                cargar_alfabeto_desde_archivo(alfabeto, &n);
                if (n < 2) {
                    printf("Primero debes crear un alfabeto valido.\n");
                    break;
                }
                printf("------ ::Introduce la clave:: ------\n (debe tener al menos 5 caracteres): ");
                scanf("%s", clave);
                if (strlen(clave) < 5) {
                    printf("La clave debe tener al menos 5 caracteres.\n");
                    break;
                }
                printf("------ ::Introduce el mensaje cifrado:: ------\n ");
                scanf("%s", mensaje_cifrado);
                vigenere_descifrar(mensaje_cifrado, clave, asociacion, n, mensaje_descifrado, alfabeto);
                printf("------ ::Mensaje descifrado:: ------\n %s\n", mensaje_descifrado);
                break;

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