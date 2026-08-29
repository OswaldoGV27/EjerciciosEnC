#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
        int tam, *arr1, *arr2, Pares=0, cont=0, tam2;
        printf("-----------------------------------------------\n");
        printf("Ingresa la dimension que deseas para el arreglo\n");
        printf("-----------------------------------------------\n");
        scanf("%d", &tam);
        srand(time(NULL));
        arr1=(int *)malloc(tam*sizeof(int));

        for (int a=0;a<tam;a++){
        arr1[a]=-1001+rand()%(1001-(-1001)+1);
        }
        arr2=(int *)malloc(Pares*sizeof(int));

        for(int a=0; a<tam;a++){
            if (arr1[a]%2==0){
            arr2[cont]=arr1[a];
            cont++;
            }
        }
        
        printf("-------------------------------------\n");
        printf("Cantidad de numeros pares encontrados: %d\n", cont);
        printf("-------------------------------------\n");
        
        printf("----------------\n");
        printf("Arreglo Original\n");
        for(int a=0;a<tam;a++){
          printf("%d\n",arr1[a]);
        }
        tam2=tam*sizeof(int);
        printf("El tama%co  en bytes del arreglo original es: %d\n", 164, tam2);
        printf("----------------\n");

        printf("----------------\n");
        printf("Arreglo de Pares\n");
        for(int a=0;a<tam;a++){
            printf("%d\n", arr2[cont]);
        }
        tam2=tam*sizeof(int);
        printf("El tama%co en bytes arreglo de pares es: %d\n", 164, tam2);
        printf("----------------\n");

        

        free(arr1);
        free(arr2);
    return 0;
}