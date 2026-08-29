#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a,b,c,d,e,f, *ptr, arr[4],arr2[3][2];
    ptr=&a;

    printf("--------------------------------------------------\n");
    printf("Direcciones de memoria de las variables primitivas\n");
    printf("--------------------------------------------------\n");
    printf("La direccion de la variable a es: %p\n",&a);
    printf("La direccion de la variable b es: %p\n",&b);
    printf("La direccion de la variable c es: %p\n",&c);
    printf("La direccion de la variable d es: %p\n",&d);
    printf("La direccion de la variable e es: %p\n",&e);
    printf("La direccion de la variable f es: %p\n\n",&f);

    printf("---------------------------------------------------\n");
    printf("Direcciones de memoria de un arreglo Unidimensional\n");
    printf("---------------------------------------------------\n");
    printf("La direccion del arrego 0 es: %p\n",&arr[0]);
    printf("La direccion del arrego 1 es: %p\n",&arr[1]);
    printf("La direccion del arrego 2 es: %p\n",&arr[2]);
    printf("La direccion del arrego 3 es: %p\n\n",&arr[3]);

    printf("---------------------------------------------------\n");
    printf("Direcciones de memodria de un arreglo Bidimensional\n");
    printf("---------------------------------------------------\n");
    printf("La direccion del arreglo fila 1 columna 1 es: %p\n",&arr2[0][0]);
    printf("La direccion del arreglo fila 1 columna 2 es: %p\n",&arr2[0][1]);
    printf("La direccion del arreglo fila 2 columna 1 es: %p\n",&arr2[1][0]);
    printf("La direccion del arreglo fila 2 columna 2 es: %p\n",&arr2[1][1]);
    printf("La direccion del arreglo fila 3 columna 1 es: %p\n",&arr2[2][0]);
    printf("La direccion del arreglo fila 3 columna 2 es: %p\n\n",&arr2[2][1]);

    printf("----------------------------------------------------------------------\n");
    printf("Asignamos e imprimimos el contenido de las variables y de los arreglos \n");
    printf("----------------------------------------------------------------------\n");
    
    for(int x=1 ;x<7;x++){
    *ptr=x;
    ptr--;
    }
    printf("          ----------\n");
    printf("          Variables\n");
    printf("          ----------\n");
    printf("El Valor de la variable a es: %d\n",a);
    printf("El Valor de la variable b es:%d\n",b);
    printf("El Valor de la variable c es:%d\n",c);
    printf("El Valor de la variable d es:%d\n",d);
    printf("El Valor de la variable e es:%d\n",e);
    printf("El Valor de la variable f es:%d\n\n",f);

    printf("  -------------------------\n");
    printf("  Arreglos Unidimensionales\n");
    printf("  -------------------------\n");
    srand(time(NULL));
    for(int doble, y=1; y<5;y++){
        *ptr=y;
        arr[y]=1+rand()%(15-1+1);
        doble=arr[y]*2;
        printf("El Valor del arreglo %d es: %d\n", y, arr[y]);
        printf("El doble del arreglo %d es: %d\n", y, doble);
    }
 
        printf("\n------------------------\n");
        printf("Arreglos Bidimensionales\n");
        printf("------------------------\n");
        int x=0, y=0, doble2;
        for(x=0;x<3;x++)
             for(y=0;y<2;y++)
                  arr2[x][y]=x;
        for(x=0;x<3;x++)
        {
            for(y=0;y<2;y++)
            printf(" %d ", arr2[x][y]);
            printf("\n");
        }

    printf("El doble del arreglo Bidimensional\n");
    for(x=0;x<3;x++)
             for(y=0;y<2;y++)
                  arr2[x][y]=x*2;
        for(x=0;x<3;x++)
        {
            for(y=0;y<2;y++)
            printf(" %d ", arr2[x][y]);
            printf("\n");
        }
    return 0;
}