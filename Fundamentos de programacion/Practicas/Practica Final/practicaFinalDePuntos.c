#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1416

struct puntos {
    int sumaX; 
    int restaX;
    int sumaY; 
    int restaY;       
    int productoX;   
    int productoY; 
    float distancia;
    float angulo;
    float modulo; 
    float SAngulo; 
    float restang;
    float divgenx;
    float divgeny;
};

    //Suma y resta de puntos
struct puntos SumaResta(struct puntos operaciones1, int a, int b, int aX, int aY, int I){

    if (I==1){
        operaciones1.sumaX=(a+aX);
        operaciones1.sumaY=(b+aY);
        printf("------------------------------------------------------------\n");
        printf("La suma de los puntos (%d, %d) y el punto (%d,%d) es: (%d, %d)\n", a, b, aX, aY ,operaciones1.sumaX, operaciones1.sumaY);
        printf("------------------------------------------------------------\n");
    }
    if (I==0){
        operaciones1.restaX=(a-aX);
        operaciones1.restaY=(b-aY);
        printf("------------------------------------------------------------\n");
        printf("La resta de los puntos (%d, %d) y el punto (%d,%d) es: (%d, %d)\n", a, b, aX, aY ,operaciones1.restaX, operaciones1.restaY);
        printf("------------------------------------------------------------\n");
    }
    return operaciones1;
}

    //Producto y division de puntos con angulos
struct puntos ProductoDiv(struct puntos operaciones2, int a, int b, float aX2, float aY2, double angulo, double angulo2, int I2){

    if (I2==1){
        operaciones2.productoX=(a*aX2);
        operaciones2.productoY=(b*aY2);
        operaciones2.SAngulo=(angulo+angulo2);
        printf("--------------------------------------------------------------------------------------------------------------\n");
        printf("La multiplicacion del punto (%d, %d) con angulo %.2f %c y  el punto (%.2f,%.2f) con angulo %.2f %c es: (%d, %d) con angulo %.2f %c\n", a, b, angulo, 167, aX2, aY2, angulo2, 167, operaciones2.productoX, operaciones2.productoY, operaciones2.SAngulo, 167);
        printf("--------------------------------------------------------------------------------------------------------------\n");
    }
    if (I2==0){
        operaciones2.divgenx=(a/aX2);
        operaciones2.divgeny=(b/aY2);
        operaciones2.restang=(angulo-angulo2);
        printf("----------------------------------------------------------------------------------------------------------\n");
        printf("La division del punto (%d, %d) con angulo %.2f %c y el punto (%.2f,%.2f) con angulo %.2f %c es: (%.2f, %.2f) con angulo %.2f %c\n", a, b, angulo, 167, aX2, aY2, angulo2, 167, operaciones2.divgenx, operaciones2.divgeny, operaciones2.restang, 167);
        printf("----------------------------------------------------------------------------------------------------------\n");
    }
    return operaciones2;
}

    //Distancia entre puntos 
struct puntos distancias(struct puntos operaciones3, int a, int b, int aX3, int aY3, int tam){
    if(sqrt(pow((aX3-a), 2)+pow((aY3-b), 2))>0){
        operaciones3.distancia=sqrt(pow((aX3-a), 2)+pow((aY3-b), 2));
        printf("-----------------------------------------------------------------\n");
        printf("La distancia entre el punto (%d,%d) y el punto (%d,%d) es: %.2f unidades\n", a, b, aX3, aY3, operaciones3.distancia);
        printf("-----------------------------------------------------------------\n");
    }else{
    }
    return operaciones3;
}

    //Calculo de los Angulos
struct puntos Angulos(struct puntos operaciones, int a, int b){

    operaciones.modulo=sqrt((a*a)+(b*b));
    if (a==0 & b==0){
        operaciones.angulo=0;
    }
    else if (a!=0 || b!=0){
        operaciones.angulo=(atan2(b, a))*(180/PI);
    if (a>=0 & b>=0){
        operaciones.angulo=(atan2(b, a))*(180/PI);
    }
    else if (a<0 & b>=0){
        operaciones.angulo=(atan2(b, a))*(180/PI)+180;
    }
    else if (a<0 & b<0){
        operaciones.angulo=(atan2(b, a))*(180/PI)+270;
    }
    else if (a>=0 & b<0){
        operaciones.angulo=(atan2(b, a))*(180/PI)+360;
    }
    }
    return operaciones;
}


double DistanciaF(int pt, int pt2, int xp2, int yp2, int tam, double DF){
if(sqrt(pow((xp2-pt), 2)+pow((yp2-pt2), 2))>0){
        DF=sqrt(pow((xp2-pt), 2)+pow((yp2-pt2), 2));
    }else{
    }
    return DF;
}

struct puntos Imprimir (struct puntos operacionesF, int a, int b){
    printf("--------------------------------------\n");
    printf("La informacion del punto (%d,%d) es: \n", a, b);
    printf("Modulo del punto es: %.2f \n", operacionesF.modulo);
    printf("Angulo del punto es: %.2f \n", operacionesF.angulo);
    printf("--------------------------------------\n");
    return operacionesF;
}
int main(){
   
    int op, op2, tam, *ptr, *ptr2, posicion, posicion2, i, a, b=0, cont, Z;
    float A, A2 , X2, Y2;
    double*DF;
    FILE *ap;
    FILE *adf;

    printf("------------------------------------------------\n");
    printf("%cDe que manera quieres generar los puntos?\n", 168);
    printf("1.- Aleatoria\n");
    printf("2.- Manual\n");
    printf("3.- Salir\n");
    printf("------------------------------------------------\n");
    scanf("%d", &op);
    if (op!=3 || op>0){
        printf("------------------------------------\n");
        printf("%cCuantos puntos quieres para operar?\n", 168);
        scanf("%d", &tam);
        printf("------------------------------------\n");
        fflush(stdin);
    }
    
    struct puntos operaciones[tam];
    fflush(stdin);
        switch (op){
        case 1:
            ptr=(int *)malloc(tam * sizeof(int));
            ptr2=(int *)malloc(tam * sizeof(int));
            DF=(double *)malloc(tam * sizeof(double));
//Operaciones con puntoa aleatorios
            
            for (int i=0; i<tam; i++){
                ptr[i]=-200+rand()%(200-(-200));
                ptr2[i]=-200+rand()%(200-(-200));
            }a=1;

            for (int i=0; i<tam; i++){
                printf("--------------\n");
                printf("El punto %d es: (%d, %d) \n",a, ptr[i], ptr2[i]);
                a++; 
            }printf("--------------\n");

            for (int i = 0; i < tam; i++){
                operaciones[i] =Angulos(operaciones[i], ptr[i], ptr2[i]);
                Imprimir(operaciones[i], ptr[i], ptr2[i]);
                printf("\n");
            }printf("\n");
            for (int a = 0; a < tam -1; a++){
                for(int i = 1; i < tam; i ++){
                if( b >= tam){
                    cont = b + 1;
                      DF= (double *) realloc (DF, cont * sizeof(double));
                    fflush(stdin);
                    }
                    X2= ptr[i];
                    Y2 = ptr2[i];
                    DF[b] = DistanciaF(ptr[a], ptr2[a], X2, Y2, tam, DF[b]);
                    b++;
                }
            }
            do
            {
                printf("----------------------------------------------\n");
                printf("%cQue operaciones quieres hacer con los puntos?\n", 168);
                printf("1.- Sumar los puntos\n");
                printf("2.- Restar los puntos\n");
                printf("3.- Multiplicar los puntos\n");
                printf("4.- Dividir los puntos\n");
                printf("5.- Determinar la distancia entre dos puntos\n");
                printf("6.- Salir\n");
                printf("----------------------------------------------\n");
                fflush(stdin);
                scanf("%d", &op2);
            switch (op2){   

            case 1:
                Z=1;
                printf("-----------------------------------\n");
                printf("%cQue puntos quieres sumar?\n", 168);
                printf("Ingresa el numero del primer punto:\n");
                scanf("%d", &posicion);
                posicion=posicion-1;
                printf("Ingresa el numero del segundo punto:\n");
                scanf("%d", &posicion2);
                printf("-----------------------------------\n");
                posicion2=posicion2-1;
                X2=ptr[posicion2];
                Y2=ptr2[posicion2];
                for(int i=0; i<1; i++){
                    operaciones[i]=SumaResta(operaciones[i], ptr[posicion], ptr2[posicion], X2, Y2, Z);
                }
                break;

            case 2:
                Z=0;
                printf("-----------------------------------\n");
                printf("%cQue puntos quieres restar?\n", 168);
                printf("Ingresa el numero del primer punto:\n");
                scanf("%d", &posicion);
                posicion=posicion-1;
                printf("Ingresa el numero del segundo punto:\n");
                scanf("%d", &posicion2);
                printf("-----------------------------------\n");
                posicion2=posicion2-1;
                X2=ptr[posicion2];
                Y2=ptr2[posicion2];
                for(int i=0; i<1; i++){
                    operaciones[i]=SumaResta(operaciones[i], ptr[posicion], ptr2[posicion], X2, Y2, Z);
                };
                break;

            case 3:
                printf("-----------------------------------\n");
                printf("%cQue puntos quieres multiplicar?\n", 168);
                printf("Ingresa el numero del primer punto:\n");
                scanf("%d", &posicion);
                posicion = posicion - 1;
                printf("Ingresa el numero del segundo punto:\n");
                scanf("%d", &posicion2);
                printf("-----------------------------------\n");
                posicion2=posicion2-1;
                fflush(stdin);
                X2=ptr[posicion2];
                Y2=ptr2[posicion2];
                A=operaciones[posicion].angulo;
                A2=operaciones[posicion2].angulo;
                Z=1;
                for(int i=0; i<1; i++){
                    operaciones[i]=ProductoDiv(operaciones[i], ptr[posicion], ptr2[posicion], X2, Y2, A, A2, Z);
                }
                break;

            case 4:
                printf("-----------------------------------\n");
                printf("%cQue puntos quieres dividir?\n", 168);
                printf("Ingresa el numero del primer punto:\n");
                scanf("%d", &posicion);
                posicion=posicion-1;
                printf("Ingresa el numero del segundo punto:\n");
                scanf("%d", &posicion2);
                printf("-----------------------------------\n");
                posicion2=posicion2-1;
                fflush(stdin);
                X2=ptr[posicion2];
                Y2=ptr2[posicion2];
                A=operaciones[posicion].angulo;
                A2=operaciones[posicion2].angulo;
                Z=0;
                for(int i=0; i<1; i++){
                    operaciones[i]=ProductoDiv(operaciones[i], ptr[posicion], ptr2[posicion], X2, Y2, A, A2, Z);
                }
                break;

            case 5:
                printf("------------------------------------------------------------\n");
                printf("%cCuales son los puntos de los cuales quieres saber la distancia?\n", 168);
                printf("Ingresa el numero del primer punto:\n");
                scanf("%d", &posicion);
                posicion=posicion-1;
                printf("Ingresa el numero del segundo punto:\n");
                scanf("%d", &posicion2);
                printf("------------------------------------------------------------\n");
                posicion2=posicion2-1;
                fflush(stdin);
                X2=ptr[posicion2];
                Y2=ptr2[posicion2];
                for(int i=0; i<1; i++){
                    operaciones[i]=distancias(operaciones[i], ptr[posicion], ptr2[posicion], X2, Y2, tam);
                }
                break;

            case 6:
                break;
            default:
                break;
            }
            }while (op2 != 6);
            break;

        case 2:
            ptr=(int *)malloc(tam * sizeof(int));
            ptr2=(int *)malloc(tam * sizeof(int));
            DF=(double *)malloc(tam * sizeof(double));
            fflush(stdin);

//Operaciones con puntos de forma manual
            printf("---------------------------------\n");
            printf("Ingresa los valores para el punto \n");
            printf("---------------------------------\n");
            a=1;

            for (int i=0; i<tam; i++){
                printf("Ingresa el valor de X para el punto: %d \n", a);
                scanf("%d", &ptr[i]);
                fflush(stdin);
                printf("Ingresa el valor de Y para el punto: %d \n", a);
                scanf("%d", &ptr2[i]);
                fflush(stdin);
                a++;
            }a=1;

            for (int i=0; i<tam; i++){
                printf("-------------\n");
                printf("El punto %d es: (%d, %d) \n",a, ptr[i], ptr2[i]);
                a++;
            }printf("-------------\n");;

            for (int i=0; i<tam; i++){
                operaciones[i]=Angulos(operaciones[i], ptr[i], ptr2[i]);
                Imprimir(operaciones[i], ptr[i], ptr2[i]);
                printf("\n");
            };

//Calculo de la distancia de todos los puntos
            for (int a=0; a<tam-1; a++){
                for(int i=1; i<tam; i++){
                if( b>=tam){
                    cont=b+1;
                    DF=(double *)realloc(DF, cont * sizeof(double));
                    fflush(stdin);
                    }
                    X2 = ptr[i];
                    Y2= ptr2[i];
                    DF[b] = DistanciaF(ptr[a], ptr2[a], X2, Y2, tam, DF[b]);
                    b++;
                }
            }
            do{
                printf("----------------------------------------------\n");
                printf("%cQue operaciones quieres hacer con los puntos?\n", 168);
                printf("1.- Sumar los puntos\n");
                printf("2.- Restar los puntos\n");
                printf("3.- Multiplicar los puntos\n");
                printf("4.- Dividir los puntos\n");
                printf("5.- Determinar la distancia entre dos puntos\n");
                printf("6.- Salir\n");
                printf("----------------------------------------------\n");
                fflush(stdin);
                scanf("%d", &op2);
            switch (op2){   
            case 1:
                Z=1;
                printf("-----------------------------------\n");
                printf("%cQue puntos deseas sumar?\n", 168);
                printf("Ingresa el numero del primer punto:\n");
                scanf("%d", &posicion);
                posicion=posicion-1;
                printf("Ingresa el numero del segundo punto:\n");
                scanf("%d", &posicion2);
                printf("-----------------------------------\n");
                posicion2=posicion2-1;
                X2=ptr[posicion2];
                Y2=ptr2[posicion2];
                for(int i=0; i<tam-1; i++){
                    operaciones[i]=SumaResta(operaciones[i], ptr[posicion], ptr2[posicion], X2, Y2, Z);
                }
                break;

            case 2:
                Z=0;
                printf("-----------------------------------\n");
                printf("%cQue puntos quieres restar?\n", 168);
                printf("Ingresa el numero del primer punto:\n");
                scanf("%d", &posicion);
                posicion=posicion-1;
                printf("Ingresa el numero del segundo punto:\n");
                scanf("%d", &posicion2);
                printf("-----------------------------------\n");
                posicion2=posicion2-1;
                X2=ptr[posicion2];
                Y2=ptr2[posicion2];
                for(int i=0; i<tam-1; i++){
                    operaciones[i]=SumaResta(operaciones[i], ptr[posicion], ptr2[posicion], X2, Y2, Z);
                };
                break;

            case 3:
                printf("-----------------------------------\n");
                printf("%cQue puntos quieres multiplicar?\n", 168);
                printf("Ingresa el numero del primer punto:\n");
                scanf("%d", &posicion);
                posicion=posicion-1;
                printf("Ingresa el numero del segundo punto:\n");
                scanf("%d", &posicion2);
                printf("-----------------------------------\n");
                posicion2=posicion2-1;
                fflush(stdin);
                X2=ptr[posicion2];
                Y2=ptr2[posicion2];
                A=operaciones[posicion].angulo;
                A2=operaciones[posicion2].angulo;
                Z= 1;
                for(int i=0; i<tam-1; i++){
                    operaciones[i]=ProductoDiv(operaciones[i], ptr[posicion], ptr2[posicion], X2, Y2, A, A2, Z);
                }
                break;

            case 4:
                printf("-----------------------------------\n");
                printf("%cQue puntos quieres dividir?\n", 168);
                printf("Ingresa el numero del primer punto:\n");
                scanf("%d", &posicion);
                posicion=posicion-1;
                printf("Ingresa el numero del segundo punto:\n");
                scanf("%d", &posicion2);
                printf("-----------------------------------\n");
                posicion2=posicion2-1;
                fflush(stdin);
                X2=ptr[posicion2];
                Y2=ptr2[posicion2];
                A=operaciones[posicion].angulo;
                A2=operaciones[posicion2].angulo;
                Z=0;
                for(int i=0; i<tam-1; i++){
                    operaciones[i]=ProductoDiv(operaciones[i], ptr[posicion], ptr2[posicion], X2, Y2, A, A2, Z);
                }
                break;

            case 5:
                printf("------------------------------------------------------------\n");
                printf("%cCuales son los puntos de los cuales quieres saber la distancia?\n", 168);
                printf("Ingresa el numero del primer punto:\n");
                scanf("%d", &posicion);
                posicion=posicion-1;
                printf("Ingresa el numero del segundo punto:\n");
                scanf("%d", &posicion2);
                printf("------------------------------------------------------------\n");
                posicion2=posicion2-1;
                fflush(stdin);
                X2=ptr[posicion2];
                Y2=ptr2[posicion2];
                A=operaciones[posicion].angulo;
                A2=operaciones[posicion2].angulo;
                for(int i=0; i<tam-1; i++){
                    operaciones[i]=distancias(operaciones[i], ptr[a], ptr2[a], X2, Y2, tam);
                }
                break;

            default:
                break;
            }
            } while (op2!=6);
            break;

        case 3:
            break;
        default:
            break;
        }
//Apretura de archivos...
    adf=fopen("Datos.txt", "w");
        if (adf= NULL){
        printf("Error en la apertura del archivo\n");
        }
        else{
            fprintf(adf, "Distancias\n");
            b=0;
            for (int a=0; a<tam-1; a++){
                for(int i=1; i<tam; i++){
                    X2=ptr[i];
                    Y2=ptr2[i];
                    fprintf(adf, "La distancia entre (%d,%d) y (%.0f,%.0f) es %f\n",ptr[a], ptr2[a], X2, Y2, DF[b]);
                    b++;
                }
            }
        }
    fclose(adf);
//Creacion de archivo de con la informacion de los puntos...
    int id=1;
        ap=fopen("Datos2.txt", "w");
            if (ap==NULL){
                printf("Error en la apertura del archivo\n");
            }else{
                fprintf(ap, "Puntos       Modulo       Angulo       Detalles\n");
                for (int i=0; i<tam; i++){
                    fprintf(ap, "%d       (%d,%d)       %.3f       %.3f \n", id, ptr[i], ptr2[i], operaciones[i].modulo, operaciones[i].angulo);
                    id ++;
                }
            }
    fclose(ap);
    free(ptr);
    free(ptr2);
    free(DF);
    return 0;
}