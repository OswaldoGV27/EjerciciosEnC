#include <stdio.h>
#include <stdlib.h>

void imprimirPolinomio(unsigned int b, int n) {
    if (n < 0 || n > 32) {
        printf("Error: n debe estar entre 0 y 32\n");
        return;
    }

    int primero = 1;
    for (int i = n; i >= 0; i--) {
        if ((b >> i) & 1) {
            if (!primero)
                printf(" + ");
            if (i == 0)
                printf("1");
            else if (i == 1)
                printf("x");
            else
                printf("x^%d", i);
            primero = 0;
        }
    }

    if (primero)
        printf("0");
    
    printf("\n");
}

int main (){
    printf("Tama%co de entero sin signo: %lu bits\n",164,  sizeof(unsigned int)*8);

    unsigned int b; int n;
    printf("Escrbe un numero entero n entre 0 y 32\n");
    scanf("%d", &n);
    printf("Escribe un numero en su representacion Binaria de tama%co n\n", 164);
    scanf("%d", &b);

    imprimirPolinomio(b, n);
    
    return 0;
}