//Equipo Papas con chile
//Grupo 4CV3 Versión 1.0
//Codigo LRU Modificado

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_FRAMES 4   // Número de frames (páginas físicas en memoria)
#define NUM_PAGES 10   // Número total de páginas virtuales

// Estructura para un frame de página en memoria física
typedef struct Frame {
    int page;           // Número de página almacenada en el frame (valor -1 si está vacío)
    bool valid;         // Indica si el frame está ocupado (true) o vacío (false)
    int referenceBit;   // Bit de referencia para el algoritmo CLOCK
} Frame;

// Estructura para la lista de frames en memoria física
typedef struct FrameList {
    int numFrames;      // Número de frames actualmente ocupados
    Frame frames[NUM_FRAMES];  // Array de frames
    int clockHand;      // Puntero para el algoritmo CLOCK
} FrameList;

// Función para inicializar la lista de frames en memoria física
FrameList* createFrameList() {
    FrameList *frameList = (FrameList *)malloc(sizeof(FrameList));
    if (frameList != NULL) {
        frameList->numFrames = 0;
        frameList->clockHand = 0;
        for (int i = 0; i < NUM_FRAMES; i++) {
            frameList->frames[i].page = -1;   // Inicialmente no hay página asignada
            frameList->frames[i].valid = false;
            frameList->frames[i].referenceBit = 0;
        }
    }
    return frameList;
}

// Función para buscar un frame específico por número de página
int findFrame(FrameList *frameList, int page) {
    for (int i = 0; i < NUM_FRAMES; i++) {
        if (frameList->frames[i].page == page) {
            return i;
        }
    }
    return -1;
}

// Función para simular la carga de una página a memoria física usando CLOCK
void loadPage(FrameList *frameList, int page) {
    int frameIndex = findFrame(frameList, page);

    if (frameIndex != -1) {
        // La página ya está en memoria, se actualiza el bit de referencia
        frameList->frames[frameIndex].referenceBit = 1;
    } else {
        // Página no está en memoria, encontrar un frame para reemplazar usando CLOCK
        while (true) {
            if (frameList->frames[frameList->clockHand].referenceBit == 0) {
                // Reemplazar página
                frameList->frames[frameList->clockHand].page = page;
                frameList->frames[frameList->clockHand].valid = true;
                frameList->frames[frameList->clockHand].referenceBit = 1;
                frameList->clockHand = (frameList->clockHand + 1) % NUM_FRAMES;
                break;
            } else {
                // Si el bit de referencia es 1, ponerlo a 0 y mover el puntero
                frameList->frames[frameList->clockHand].referenceBit = 0;
                frameList->clockHand = (frameList->clockHand + 1) % NUM_FRAMES;
            }
        }
    }
}

// Función para imprimir el estado actual de los frames (solo para depuración)
void printFrameList(FrameList *frameList) {
    printf("Estado actual de los frames:\n");
    for (int i = 0; i < NUM_FRAMES; i++) {
        printf("Frame %d: Página %d, Referencia %d\n", i, frameList->frames[i].page, frameList->frames[i].referenceBit);
    }
    printf("\n");
}

int main() {
    FrameList *frameList = createFrameList();

    // Simular la carga de varias páginas a memoria física
    int pagesToLoad[] = {4, 1, 2, 6, 5, 2, 7, 6, 4};
    int numPages = sizeof(pagesToLoad) / sizeof(pagesToLoad[0]);

    for (int i = 0; i < numPages; i++) {
        loadPage(frameList, pagesToLoad[i]);
        printFrameList(frameList);  // Imprimir estado después de cada carga
    }

    // Liberar la memoria utilizada por la lista de frames
    free(frameList);

    return 0;
}