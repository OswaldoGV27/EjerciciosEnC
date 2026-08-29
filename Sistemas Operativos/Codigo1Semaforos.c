#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

//Crea una variable tipo semaforo
sem_t mutex;

//Definicion de la función que ejecutará el hilo
void* thread_func(void* arg) {
//Bloquea el semáforo 
sem_wait(&mutex);
printf("Seccion critica del hilo\n");

//Libera el semáforo 
sem_post(&mutex);
return NULL;
}

int main() {
pthread_t thread;

//Inicializa el semáforo con 1.
sem_init(&mutex, 0, 1);

//Crea un hilo
pthread_create(&thread, NULL, thread_func, NULL);

//Bloquea el semáforo 
sem_wait(&mutex);
printf("Seccion critica del hilo principal\n");

//Libera el semáforo 
sem_post(&mutex);

//Espera que el hilo termine su ejecución 
pthread_join(thread, NULL);

//Destruye el código para liberar los procesos asociados a el.
sem_destroy(&mutex);
return 0;
}