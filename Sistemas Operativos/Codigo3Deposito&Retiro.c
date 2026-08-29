#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//Declara un mutex para controlar el acceso concurrente a la variable saldo.
pthread_mutex_t mutex;
int saldo=0;

/*Toma un argumento (el monto a retirar), bloquea el mutex, realiza la 
operación de retiro (resta el monto del saldo), imprime el monto retirado 
y el saldo restante, y luego desbloquea el mutex.*/
void* realizarRetiro(void* arg) {
    int monto = *(int *) arg;
    pthread_mutex_lock(&mutex);
    printf("Realizando retiro de %d\n", monto);
    saldo -= monto;
    printf("Saldo restante:  %d\n", saldo);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

/*Toma un argumento (el monto a depositar), bloquea el mutex, realiza la 
operación de deposito (suma el monto del saldo), imprime el monto depositado
y el saldo restante, y luego desbloquea el mutex.*/
void* realizarDeposito(void* arg) {
    int monto = *(int *)arg;
    pthread_mutex_lock(&mutex);
    printf("Realizando deposito de %d\n", monto);
    saldo += monto;
    printf("Saldo actual: %d\n", saldo);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main() {
//Declara dos hilos (hiloRetiro y hiloDeposito) y define los montos de retiro (100) y depósito (200).
    pthread_t hiloRetiro, hiloDeposito;
    int montoRetiro = 100;
    int montoDeposito = 200;
    //Inicializa el mutex
    pthread_mutex_init(&mutex, NULL); 
    //Crea los hilos para realizar las operaciones de retiro y depósito.
    pthread_create(&hiloRetiro, NULL, realizarRetiro, &montoRetiro);
    pthread_create(&hiloDeposito, NULL, realizarDeposito, &montoDeposito);
    //Espera a que ambos hilos terminen su ejecución.
    pthread_join(hiloRetiro, NULL);
    pthread_join(hiloDeposito, NULL);
    //Destruye el mutex antes de finalizar el programa.
    pthread_mutex_destroy(&mutex);
return 0;
}
/*El programa permite que un hilo retire dinero y otro deposite dinero de forma simultánea, 
pero el uso del mutex asegura que solo un hilo puede modificar el saldo a la vez. Esto previene 
condiciones de carrera donde ambos hilos intentan acceder y modificar el saldo al mismo tiempo, 
lo cual podría llevar a resultados inesperados.*/