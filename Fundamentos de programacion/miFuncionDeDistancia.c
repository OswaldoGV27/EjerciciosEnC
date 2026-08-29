//Oswaldo Gil Valentin 1CV8
#include <stdio.h>
#include <math.h>

//Prototipo
float Distancia();

//Funcion Principal
int main(){
    float X1, Y1, X2, Y2, d;

    printf("------------------------------------------------------------------------------------\n");
    printf("Este programa sirve para calcular la distancia entre 2 puntos de un plano cartesiano\n");
    printf("------------------------------------------------------------------------------------\n");

    printf("La distancia entre los dos puntos es: %0.2f\n", Distancia());

    return 0;
}

//Definiendo la funcion
float Distancia(){
    float X1, Y1, X2, Y2, d;
    printf("Ingrese el valor de X1: \n");
    scanf("%f",&X1);
    printf("Ingrese el valor de Y1: \n");
    scanf("%f",&Y1);
    printf("Ingrese el valor de X2: \n");
    scanf("%f",&X2);
    printf("Ingrese el valor de Y2: \n");
    scanf("%f",&Y2);

    d=sqrt(pow((X2-X1), 2)+pow((Y2-Y1),2));

    return d;
    } 