#include <stdio.h>

/*Prototipo de la función*/
int EsLetra(char L);

int main() {
    char Renglon[1000]; /*Tamaño máximo de una línea*/
    int i = 0;
    while (fgets(Renglon, sizeof(Renglon), stdin)) {
        int PalCont = 0;
        int Palabra = 0; /*Variable para indicar si estamos dentro de una palabra*/
        while (Renglon[i] != '\0') 
        {
            if (EsLetra(Renglon[i])) {
                if (!Palabra) {
                    Palabra = 1;
                    ++PalCont;
                }
            } else {
                Palabra = 0;
            }
            ++i; 
        }
        printf("%d\n", PalCont);
        i = 0; /*Reiniciamos el índice para la siguiente línea*/
    }
    return 0;
}

/*Definición de la función*/
int EsLetra(char L) {
    return (L >= 'a' && L <= 'z') || (L >= 'A' && L <= 'Z');
}