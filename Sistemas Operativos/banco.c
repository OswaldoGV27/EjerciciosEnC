/*Curso: Sistemas Operativos
(C) Octubre 2024
Implementó: Equipo Papas con Chile; 

ESCOM-IPN
Programa que simula el funcionamiento de un banco.
Las funciones retiro y deposito son atomicas.
¿Que significa que sean atomicas?
Que un proceso sea atomico significa que o se ejecuta COMPLETAMENTE
o no lo hace en absoluto, lo que permite que el proceso no sea interrumpido
o que se accedan a los datos que usa mientras esta en ejecucion.

El programa consta de 2 hilos, uno para depositar y otro para retirar, que
se ejecutan paralelamente.
Existe una varible global llamada saldo.

Con ayuda de un candado (mutsaldo) hacemos que los procesos sean atomicos.
si mutsaldo de encuentra bloqueado, el proceso tendra que esperar a que se
desocupe, caso contrarario tiene acceso a los recursos (modificar el saldo)
*********************************************************/


#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int saldo = 0;

//Nos ayudara a darle acceso a la variable saldo a solo un hilo a la vez
pthread_mutex_t mutsaldo;

//prototipos de funciones para los hilos
void *depositar(void *monto);
void *retirar(void *monto);

int main() {

  pthread_t hdepositar, hretirar;
  
  //Variables para los montos a depositar y retirar
  int mdeposito;
  int mretiro;
  
  printf("\nCuanto deseas depositar?: ");
  scanf("%d", &mdeposito);

  printf("\nCuanto deseas retirar?: ");
  scanf("%d", &mretiro);

  //Creacion de hilos
  pthread_create(&hdepositar, NULL, depositar, &mdeposito);
  pthread_create(&hretirar, NULL, retirar, &mretiro);
  
  //Ejecucion de hilos
  pthread_join(&hdepositar, NULL);
  pthread_join(&hretirar, NULL);

  pthread_mutex_destroy(&mutsaldo);

return 0;
}

void *depositar(void *monto) {
    int montod = *(int *)monto;

    pthread_mutex_lock(&mutsaldo);
    printf("\nSe depositan: $%d pesos", montod);
    saldo += montod;
    printf("\nSaldo de la cuenta: $%d pesos", saldo);
    pthread_mutex_unlock(&mutsaldo);
  return NULL;
}
void *retirar(void *monto) {
     int montor = *(int *)monto;

     pthread_mutex_lock(&mutsaldo);
     printf("\n Se retiran : $%d pesos", montor);

     if(saldo < montor) {
        printf("\nERROR: No puedes retirar mas dinero del que dispones\n");
     } else {
         saldo -= montor;
     }

     printf("\nSaldo de la cuenta: $%d pesos", saldo);
     
     pthread_mutex_unlock(&mutsaldo);
     return NULL;

}

