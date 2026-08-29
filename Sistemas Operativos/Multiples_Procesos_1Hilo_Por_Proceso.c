/*Curso: Sistemas operativos
(C) Septiembre 2024
Implementò: Equipo papas con chile
--------
ESCOM-IPN
Programa que dado un arreglo de valores de monedas y el cambio a dar, imprime el cambio a dar
con la menor cantidad de monedas (En algunos casos el enfoque greedy no lo hara)
Usa 2 hilos de procesos, en un hilo se ejecuta un enfoque greedy y en otro programacion dinamica
*/


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>

// Estructura para pasar los parámetros a los hilos
typedef struct {
    int* monedas;
    int numMonedas;
    int cambio;
} ThreadArgs;

//Funciones greddy y dp
void* greedy_Monedas(void* arg);
void* dp_Monedas(void* arg) ;

int main() {
    
    //Definicion de los valores de las monedas y cambio a dar
    int monedas[] = {1, 5, 10, 25};
    int numMonedas = sizeof(monedas) / sizeof(monedas[0]);
    int cambio = 30;

    //Pasar los parámetros a los hilos
    ThreadArgs args;
    args.monedas = monedas;
    args.numMonedas = numMonedas;
    args.cambio = cambio;

    //Creacion de hilos
    pthread_t thread_greedy, thread_dp;

    //Hilo greedy
    pthread_create(&thread_greedy, NULL, greedy_Monedas, (void*)&args);

    //Hilo DP
    (pthread_create(&thread_dp, NULL, dp_Monedas, (void*)&args));

    //Esperar a que los hilos terminen
    pthread_join(thread_greedy, NULL);
    pthread_join(thread_dp, NULL);

    printf("Ambos hilos han terminado.\n");
    
    return 0;
}

// Función que implementa el algoritmo Greedy
void* greedy_Monedas(void* arg) {
    ThreadArgs* args = (ThreadArgs*)arg;
    int* monedas = args->monedas;
    int numMonedas = args->numMonedas;
    int cambio = args->cambio;
    
    int count = 0;
    int restantes = cambio;

    printf("Greedy (Hilo 1): Para cambiar %d usando las monedas: ", cambio);
    for (int i = numMonedas - 1; i >= 0; i--) {
        while (restantes >= monedas[i]) {
            restantes -= monedas[i];
            count++;
            printf("%d ", monedas[i]);
        }
    }
    //Si no quedan mas monedas y no hemos dado el cambio completo;
    if (restantes > 0) {
        printf("\nGreedy (Hilo 1): No se puede dar el cambio exacto usando Greedy.\n");
    } else {
        printf("\nGreedy (Hilo 1): Número mínimo de monedas: %d\n", count);
    }
    
    pthread_exit(NULL);
}

// Función que implementa el algoritmo de Programación Dinámica
void* dp_Monedas(void* arg) {
    ThreadArgs* args = (ThreadArgs*)arg;
    int* monedas = args->monedas;
    int numMonedas = args->numMonedas;
    int cambio = args->cambio;
    
    int dp[cambio + 1];
    int coin_used[cambio + 1];  // Para almacenar las monedas utilizadas

    // Inicialización de la tabla DP
    dp[0] = 0;
    for (int i = 1; i <= cambio; i++) {
        dp[i] = INT_MAX;
        coin_used[i] = -1;
    }

    // Calcular el número mínimo de monedas para cada valor
    for (int i = 1; i <= cambio; i++) {
        for (int j = 0; j < numMonedas; j++) {
            if (monedas[j] <= i) {
                int sub_res = dp[i - monedas[j]];
                if (sub_res != INT_MAX && sub_res + 1 < dp[i]) {
                    dp[i] = sub_res + 1;
                    coin_used[i] = monedas[j];  // Guardar la moneda usada
                }
            }
        }
    }

    if (dp[cambio] == INT_MAX) {
        printf("DP (Hilo 2): No es posible dar el cambio exacto.\n");
    } else {
        printf("DP (Hilo 2): El número mínimo de monedas para dar el cambio de %d es: %d\n", cambio, dp[cambio]);
        printf("DP (Hilo 2): Monedas utilizadas: ");
        
        // Imprimir las monedas utilizadas
        int aux = cambio;
        while (aux > 0) {
            int coin = coin_used[aux];
            printf("%d ", coin);
            aux -= coin;
        }
        printf("\n");
    }

    pthread_exit(NULL);
}