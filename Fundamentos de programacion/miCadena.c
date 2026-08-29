#include <stdio.h>

int main(){

    char palabra[201];
    int x=0, y=0, posicion=0, i, j, acentos=0;

    //Escritura de la frase.
    printf("--------------------------------------------\n");
    printf("Escribe una  frase no mayor a 200 caracteres\n");
    printf("--------------------------------------------\n");
    scanf("%[^\n]", palabra);
    printf("--------------------------\n");
    printf("la palabra introducida es: \n--------------------------\n%s\n", palabra);
    
    //Conteo de caracteres en la palabra. 
    while (palabra[x] != '\0'){
    x++;
    }
    posicion=x;
    x--;
    i=0;
    while (palabra[y] != '\0'){
        if (palabra[y]==32){
            for (i=y; i<x; i++){
                palabra[i]=palabra[i+1];
            }
        x--;
        }
    y++;
    }
    printf("-----------------------------------------\n");
    printf("El tama%co en caracteres de la cadena es: %d\n", 164, posicion);
    printf("-----------------------------------------\n");

    //Cantidad de vocales por separado encontradas en la cadena: a, e, i, o, u.
   


    //Cantidad de mayúsculas encontradas en la cadena.




    //Cantidad de acentos encontrados en la cadena.





    //Cantidad de palabras encontradas en la cadena.


    return 0;
}