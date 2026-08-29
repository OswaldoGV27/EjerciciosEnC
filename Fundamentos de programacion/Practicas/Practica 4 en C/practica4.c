#include <stdio.h>
#include <math.h>

float Distancia(float a1, float b1, float c1, float d1, float d );
float PendienteAB(float a1, float b1, float c1, float d1, float m );
float ModuloA(float a1, float b1, float dA);
float ModuloB(float c1, float d1, float dB);
float AnguloA(float a1, float b1, float AA);
float AnguloB(float c1, float d1, float AB);

float EDLR(float a1, float b1, float c1, float d1, float e );

int main (){
    float X1, Y1, X2, Y2, d, m, s1, s2, dA, dB, G1, G2, GA, GB;

    printf("Ingrese el valor de X1: \n");
    scanf("%f",&X1);
    printf("Ingrese el valor de Y1: \n");
    scanf("%f",&Y1);
    printf("Ingrese el valor de X2: \n");
    scanf("%f",&X2);
    printf("Ingrese el valor de Y2: \n");
    scanf("%f",&Y2);

    printf("---------------------------------------------\n");
    printf("Las coordenadas del Punto A son: (%.2f, %.2f)\n", X1, Y1);
    printf("Las coordenadas del punto B son: (%.2f, %.2f)\n", X2, Y2);

    printf("El modulo del punto A es: %.2f\n", ModuloA(X1, Y1, dA));
    printf("El modulo del punto B es: %.2f\n", ModuloB(X2, Y2, dB));

    
    G1=atan(Y1/X1);
    if(X1>0, Y1>0){
        GA=(G1*180)/3.1416;
    }
    else if(X1<0, Y1>0){
        GA=180-((G1*180)/3.1416);
    }
    else if(X1<0, Y1<0){
        GA=270-((G1*180)/3.1416);
    }
    else if(X1>0, Y1<0){
        GA=360-((G1*180)/3.1416);
    }
    if(GA<0){
        GA=GA*-1;
    }
    printf("El angulo del punto A es: %.2f%c\n", GA, 167);

    G2=atan(Y2/X2);
    if(X2>0, Y2>0){
        GB=(G2*180)/3.1416;
    }
    else if(X2<0, Y2>0){
        GB=180-((G2*180)/3.1416);
    }
    else if(X2<0, Y2<0){
        GB=270-((G2*180)/3.1416);
    }
    else if(X2>0, Y2<0){
        GB=360-((G2*180)/3.1416);
    }
    if(GB<0){
        GB=GB*-1;
    }
    printf("El angulo del punto B es: %.2f%c\n", GB, 167);
    printf("---------------------------------------------\n");

    printf("--------------------------------------------\n");
    printf("La distancia entre los puntos A y B es: %0.2f\n", Distancia(X1, Y1, X2, Y2, d));
    printf("--------------------------------------------\n");

    printf("La ecuaci%cn de la recta es: (Y-%.2f)=%.2f(X-%.2f)\n", 162, Y1, PendienteAB(X1, Y1, X2, Y2, m), X1);

    printf("---------------------------------\n");
    printf("La pendiente de la recta es %.2f\n", PendienteAB(X1, Y1, X2, Y2, m));
    printf("---------------------------------\n");

    s1=X1+X2;
    s2=Y1+Y2;
    printf("--------------------------------------------\n");
    printf("La suma de los puntos A+B es: (%.2f, %.2f) \n", s1, s2 );
    printf("--------------------------------------------\n");

    s1=X1-X2;
    s2=Y1-Y2;
    printf("--------------------------------------------\n");
    printf("La resta de los puntos A-B es: (%.2f, %.2f) \n", s1, s2 );
    printf("--------------------------------------------\n");

    s1=X1*X2;
    s2=Y1*Y2;
    G1=GA+GB;
if(G1<0){
        G1=G1*-1;
    }
    printf("--------------------------------------------\n");
    printf("El producto de los puntos A*B es: (%.2f, %.2f) %.2f%c\n", s1, s2, G1, 167);
    printf("--------------------------------------------\n");

    s1=X1/X2;
    s2=Y1/Y2;
    G2=GA-GB;
    if(G2<0){
        G2=G2*-1;
    }
    printf("--------------------------------------------\n");
    printf("La division de los puntos A/B es: (%.2f, %.2f) %.2f%c\n", s1, s2, G2, 167);
    printf("--------------------------------------------\n");
 
    return 0;
}

    float Distancia(float a1, float b1, float c1, float d1, float d ){
        d=sqrt(pow((c1-a1), 2)+pow((d1-b1),2));
    return d;        
    }

    float PendienteAB(float a1, float b1, float c1, float d1, float m ){
        m=((d1-b1)/(c1-a1));
    return m;
    }

    float ModuloA(float a1, float b1, float dA){
        dA=sqrt(pow(a1, 2)+pow(b1, 2));
        if(dA<0){
            dA=dA*-1;
        }
    return dA;  
    }

    float ModuloB(float c1, float d1, float dB){
        dB=sqrt(pow(c1, 2)+pow(d1, 2));
        if(dB<0){
            dB=dB*-1;
        }
    return dB;  
    }