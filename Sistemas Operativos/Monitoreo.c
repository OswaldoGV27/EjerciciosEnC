// Equipo Papas con chile
// 16/09/2024
// Version 1.0
//Codigo que emplea 3 hilos para monitoreo de disco, ram y velocidad de internet, otro hilo para esperar una entrada y terminar el proceso

#include <stdio.h>        // Para funciones de entrada/salida como printf()
#include <pthread.h>      // Para trabajar con hilos
#include <sys/sysinfo.h>  // Para obtener información del sistema (RAM)
#include <sys/statvfs.h>  // Para obtener información del sistema de archivos (disco)
#include <unistd.h>       // Para funciones POSIX como sleep()
#include <stdlib.h>       // Para usar funciones estándar como system() y exit()
#include <termios.h>      // Para controlar la configuración del terminal
#include <string.h>       // Para manipulación de cadenas, como strncmp()

// Variable global que indica si el programa está en ejecución
int ejecutando = 1;

// Variables globales para almacenar los datos del monitoreo
long free_ram_global = 0;          // RAM libre en MB
unsigned long free_disk_global = 0; // Espacio libre en disco (ROM) en MB
unsigned long rx_speed_global = 0;  // Velocidad de descarga de red (Mbps)
unsigned long tx_speed_global = 0;  // Velocidad de subida de red (Mbps)

// Función para limpiar la pantalla
void limpiar_pantalla() {
    system("clear");  // Comando para limpiar la pantalla en sistemas Linux
}

// Función ejecutada por el hilo para monitorear la memoria RAM
void *monitorear_memoria_ram(void *arg) {
    struct sysinfo info;  // Estructura para almacenar la información del sistema
    while (ejecutando) {  // Bucle que se ejecuta mientras el programa está activo
        sysinfo(&info);   // Obtener información del sistema
        free_ram_global = info.freeram / (1024 * 1024);  // Convertir la RAM libre a MB
        sleep(1);  // Pausa de 1 segundo entre cada actualización
    }
    pthread_exit(NULL);  // Finalizar el hilo
}

// Función ejecutada por el hilo para monitorear el espacio en disco (ROM)
void *monitorear_memoria_rom(void *arg) {
    struct statvfs stat;  // Estructura para almacenar la información del sistema de archivos

    while (ejecutando) {
        if (statvfs("/", &stat) == 0) {  // Obtener estadísticas del sistema de archivos para la raíz "/"
            free_disk_global = (stat.f_bfree * stat.f_frsize) / (1024 * 1024);  // Calcular el espacio libre en MB
        }
        sleep(1);  // Pausa de 1 segundo entre cada actualización
    }
    pthread_exit(NULL);  // Finalizar el hilo
}

// Función ejecutada por el hilo para monitorear la velocidad de la red Wi-Fi
void *monitorear_red(void *arg) {
    FILE *file;  // Archivo para leer estadísticas de la red
    char buffer[1024];  // Buffer para almacenar las líneas leídas del archivo
    unsigned long prev_rx_bytes = 0, prev_tx_bytes = 0;  // Bytes recibidos y enviados en la lectura anterior
    unsigned long rx_bytes, tx_bytes;  // Bytes actuales recibidos y enviados

    while (ejecutando) {
        file = fopen("/proc/net/dev", "r");  // Abrir el archivo con estadísticas de la red
        if (file != NULL) {
            // Saltar las dos primeras líneas del archivo, que contienen encabezados
            fgets(buffer, sizeof(buffer), file);
            fgets(buffer, sizeof(buffer), file);

            // Leer las estadísticas de cada interfaz de red
            while (fgets(buffer, sizeof(buffer), file) != NULL) {
                char interfaz[20];  // Almacenar el nombre de la interfaz de red
                // Leer los bytes recibidos y enviados para cada interfaz de red
                sscanf(buffer, "%s %lu %*d %*d %*d %*d %*d %*d %lu", interfaz, &rx_bytes, &tx_bytes);

                // Si la interfaz es "wlp0s20f3" (la interfaz de Wi-Fi)
                if (strncmp(interfaz, "wlp0s20f3:", 10) == 0) {
                    // Calcular la velocidad de descarga y subida en Mbps
                    rx_speed_global = (rx_bytes - prev_rx_bytes) * 8 / 1024 / 1024;  // Descarga en Mbps
                    tx_speed_global = (tx_bytes - prev_tx_bytes) * 8 / 1024 / 1024;  // Subida en Mbps

                    // Actualizar los valores previos para la próxima lectura
                    prev_rx_bytes = rx_bytes;
                    prev_tx_bytes = tx_bytes;
                    break;  // Terminar el bucle cuando se encuentra la interfaz deseada
                }
            }
            fclose(file);  // Cerrar el archivo
        }
        sleep(1);  // Pausa de 1 segundo entre cada actualización
    }
    pthread_exit(NULL);  // Finalizar el hilo
}

// Función ejecutada por el hilo para detectar la entrada del teclado (Enter)
void *detectar_entrada(void *arg) {
    struct termios oldt, newt;  // Estructuras para almacenar la configuración del terminal
    tcgetattr(STDIN_FILENO, &oldt);    // Guardar la configuración actual del terminal
    newt = oldt;
    newt.c_lflag &= ~(ICANON);  // Desactivar el modo canónico (la entrada no se espera hasta presionar Enter)
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);  // Aplicar la nueva configuración
    getchar();  // Esperar a que el usuario presione Enter
    ejecutando = 0;  // Cambiar la variable global para detener la ejecución del programa
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  // Restaurar la configuración original del terminal
    pthread_exit(NULL);  // Finalizar el hilo
}

int main() {
    pthread_t hilos[4];  // Crear un arreglo de hilos para manejar RAM, ROM, red y entrada del teclado

    // Crear y lanzar el hilo para monitorear la RAM
    pthread_create(&hilos[0], NULL, monitorear_memoria_ram, NULL);

    // Crear y lanzar el hilo para monitorear el disco (ROM)
    pthread_create(&hilos[1], NULL, monitorear_memoria_rom, NULL);

    // Crear y lanzar el hilo para monitorear la red Wi-Fi
    pthread_create(&hilos[2], NULL, monitorear_red, NULL);

    // Crear y lanzar el hilo para detectar la entrada del teclado
    pthread_create(&hilos[3], NULL, detectar_entrada, NULL);

    // Bucle principal que actualiza la pantalla mientras el programa está ejecutándose
    while (ejecutando) {
        limpiar_pantalla();  // Limpiar la pantalla antes de mostrar los nuevos datos
        printf("Monitoreo del sistema:\n");
        printf("RAM Libre: %ld MB\n", free_ram_global);  // Mostrar la RAM libre
        printf("Disco Libre: %lu MB\n", free_disk_global);  // Mostrar el espacio en disco libre
        printf("Velocidad Wi-Fi: Descarga: %lu Mbps, Subida: %lu Mbps\n", rx_speed_global, tx_speed_global);  // Mostrar la velocidad de la red
        sleep(1);  // Pausa de 1 segundo entre cada actualización
    }

    // Esperar a que los hilos terminen su ejecución
    for (int i = 0; i < 4; i++) {
        pthread_join(hilos[i], NULL);
    }

    printf("Monitoreo terminado.\n");  // Mostrar mensaje final

    return 0;  // Terminar el programa
}
