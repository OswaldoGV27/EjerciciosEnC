#include <stdio.h>

/*Prototipos de las funciones de Ordenamiento*/
void merge(int arr[], int izq, int med, int der);
void mergeSort(int arr[], int izq, int der);

int main() {
    int t;
    scanf("%d", &t);

    int arr[t];
    int i;
    for (i = 0; i < t; i++)
        scanf("%d", &arr[i]);

    /*Ordenar el array usando Merge Sort*/
    mergeSort(arr, 0, t - 1);

    /* Mostrar los números ordenados*/
    for (i = 0; i < t; i++)
        printf("%d\n", arr[i]);

    return 0;
}

/*Función para combinar dos subarrays ordenados*/ 
void merge(int arr[], int izq, int med, int der) {
    int n1 = med - izq + 1;
    int n2 = der - med;

    /*Crear subarrays temporales*/ 
    int I[n1], D[n2];

    /* Copiar datos a los subarrays temporales I[] y D[]*/
    int i;
    for (i = 0; i < n1; i++)
        I[i] = arr[izq + i];
    int j;
    for (j = 0; j < n2; j++)
        D[j] = arr[med + 1 + j];

    /* Combinar los subarrays en uno solo*/
    int a = 0, b = 0, c = izq;
    while (a < n1 && b < n2) {
        if (I[a] <= D[b]) {
            arr[c] = I[a];
            a++;
        } else {
            arr[c] = D[b];
            b++;
        }
        c++;
    }

    /* Copiar los elementos restantes de I[], si los hay*/
    while (a < n1) {
        arr[c] = I[a];
        a++;
        c++;
    }

    /* Copiar los elementos restantes de D[], si los hay*/
    while (b < n2) {
        arr[c] = D[b];
        b++;
        c++;
    }
}

/*Función principal de ordenamiento por mezcla*/ 
void mergeSort(int arr[], int izq, int der) {
    if (izq < der) {
        int med = izq + (der - izq) / 2;

        /* Ordenar la primera mitad y la segunda mitad*/
        mergeSort(arr, izq, med);
        mergeSort(arr, med + 1, der);

        /* Combinar las mitades ordenadas*/
        merge(arr, izq, med, der);
    }
}