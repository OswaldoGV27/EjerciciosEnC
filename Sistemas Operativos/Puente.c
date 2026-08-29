//Equipo papas con chile
//13/10/2024
//Versión 1.0
//Codigo que administra el paso de 100 vehículos por un puente de un carril con semáforos e hilos, 50 de un puente y 50 del otro

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// Definición de semáforos y variables globales
sem_t mutex;         // Para el acceso mutuo al puente
sem_t bridge;        // Para controlar el acceso al puente

int cruzando_norte = 0;  // Cantidad de vehículos cruzando hacia el norte
int cruzando_sur = 0;    // Cantidad de vehículos cruzando hacia el sur
int esperando_norte = 0; // Vehículos esperando para cruzar al norte
int esperando_sur = 0;   // Vehículos esperando para cruzar al sur

// Función para simular el cruce del puente en dirección norte
void* cruzar_norte(void* arg) {
    int id = *(int*)arg;
    free(arg);
    sleep(rand() % 20);  // Espera aleatoria antes de intentar cruzar

    sem_wait(&mutex);     // Acceso a las variables globales
    esperando_norte++;
    while (cruzando_sur > 0) { // Espera si hay vehículos cruzando al sur
        sem_post(&mutex);
        sem_wait(&bridge); // Espera a que el puente esté libre
        sem_wait(&mutex);
    }
    esperando_norte--;
    cruzando_norte++;
    printf("Vehículo %d cruzando hacia el norte.\n", id);
    sem_post(&mutex);

    sleep(1);  // Simula el cruce del puente

    sem_wait(&mutex);
    cruzando_norte--;
    printf("Vehículo %d ha salido del puente (norte).\n", id);
    if (cruzando_norte == 0 && esperando_sur > 0) {
        // Si ya no hay vehículos cruzando al norte, deja pasar a los del sur
        for (int i = 0; i < esperando_sur; i++) {
            sem_post(&bridge);
        }
    }
    sem_post(&mutex);
    return NULL;
}

// Función para simular el cruce del puente en dirección sur
void* cruzar_sur(void* arg) {
    int id = *(int*)arg;
    free(arg);
    sleep(rand() % 20);  // Espera aleatoria antes de intentar cruzar

    sem_wait(&mutex);     // Acceso a las variables globales
    esperando_sur++;
    while (cruzando_norte > 0) { // Espera si hay vehículos cruzando al norte
        sem_post(&mutex);
        sem_wait(&bridge); // Espera a que el puente esté libre
        sem_wait(&mutex);
    }
    esperando_sur--;
    cruzando_sur++;
    printf("Vehículo %d cruzando hacia el sur.\n", id);
    sem_post(&mutex);

    sleep(1);  // Simula el cruce del puente

    sem_wait(&mutex);
    cruzando_sur--;
    printf("Vehículo %d ha salido del puente (sur).\n", id);
    if (cruzando_sur == 0 && esperando_norte > 0) {
        // Si ya no hay vehículos cruzando al sur, deja pasar a los del norte
        for (int i = 0; i < esperando_norte; i++) {
            sem_post(&bridge);
        }
    }
    sem_post(&mutex);
    return NULL;
}

int main() {
    pthread_t vehiculos[100];  // 100 vehículos en total
    int i;

    // Inicialización de semáforos
    sem_init(&mutex, 0, 1);
    sem_init(&bridge, 0, 0);

    // Creación de los hilos para los vehículos
    for (i = 0; i < 100; i++) {
        int* id = malloc(sizeof(int));
        *id = i + 1;

        if (i % 2 == 0) {
            // Vehículos en dirección norte (pares)
            pthread_create(&vehiculos[i], NULL, cruzar_norte, id);
        } else {
            // Vehículos en dirección sur (impares)
            pthread_create(&vehiculos[i], NULL, cruzar_sur, id);
        }
        usleep(100000);  // Pequeña pausa entre la creación de vehículos
    }

    // Espera a que todos los hilos terminen
    for (i = 0; i < 100; i++) {
        pthread_join(vehiculos[i], NULL);
    }

    // Destrucción de semáforos
    sem_destroy(&mutex);
    sem_destroy(&bridge);

    return 0;
}