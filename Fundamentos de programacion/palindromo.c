//Oswaldo Gil Valentín 1CV8
#include <stdio.h>

int main(){
    char Arr[101];
    unsigned char Arr2[101];
    int posicion=0, x=0, y=0, i, acentos=0;

    printf("-------------------------------------------------\n");
    printf(" Escribe un texto no mayor a 100 caracteres\n");
    printf("Para saber si una palabra es palindromo o no\n");
    printf("   cuantos caracteres fueron integrados\n"); 
    printf("                 y acentos\n");
    printf("-------------------------------------------------\n");
    scanf("%[^\n]", Arr);

    while (Arr[x] != '\0'){
    x++;
    }
    posicion=x;
    x--;
    i=0;
    while (Arr[y] != '\0'){
        if (Arr[y]==32){
            for (i=y; i<x; i++){
                Arr[i]=Arr[i+1];
            }
        x--;
        }
    y++;
    }
    printf("El numeros de caracteres utilizados es: %d\n", posicion);

    for(i=0; i<sizeof(Arr); i++) {
        Arr2[i]=Arr[i];
    }

    y=0;
   while (Arr2[y]==Arr2[x] &x!= 0){
    x--;
    y++;
   }

    if (x<=0){
        printf("La palabra escrita si es un palindromo\n");
    }
    else{
        printf("La palabra escrita no es un palindromo\n");
    }

    printf("El numero de asentos de la palabra o frase son: %d\n", acentos);

    return 0;
}