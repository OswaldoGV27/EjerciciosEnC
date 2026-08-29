#include <stdio.h>

int main(){
    int x=1, y, elDoble, miarr[16];
    float division;
    //Prototipo
    int Aleatorio();

    // Manual
    printf("--------------------\n");
    printf("     FORMA MANUAL\n");
    printf("--------------------\n");
while(x<16){
    printf("Ingresa el valor %d entero del arreglo\n", x);
    scanf("%d",&miarr[x]);
    x++;
}

x=1;
while(x<16){
    printf("El valor %d es: %d\n", x, miarr[x]);
    elDoble=miarr[x]*2;
    printf("El doble del arreglo es: %d\n", elDoble, miarr[x]);
    division=(float)miarr[x]/(float)3;
    printf("El resultado de la division entre 3 del arreglo es: %.2f \n", division);
    x++;
}
printf("\n\n\n");

printf("\n", Aleatorio());


    return 0;
}

//Aleatoria

int Aleatorio(){
    int x, y, rand() , elDoble, miarr[16];
    float division;
    printf("------------------------\n");
    printf("     FORMA ALEATORIA\n");
    printf("------------------------\n");

x=1;
while(x<16){
    y=rand()%101;
    printf("El valor %d es: %d\n", x, miarr[y]);
    elDoble=miarr[y]*2;
    printf("El doble del arreglo es: %d\n", elDoble, miarr[y]);
    division=(float)miarr[y]/(float)3;
    printf("El resultado de la division entre 3 del arreglo es: %.2f \n", division);
    x++;
}
}