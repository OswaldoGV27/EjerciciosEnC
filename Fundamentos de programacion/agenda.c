#include <stdio.h>

   typedef struct {
    char ID[20];
    char Nombre[25];
    char ApellidoPaterno[20];
    char Apellidomaterno[20];
    char Domicilio[30];
    char RFC[14];
    char NumMovil[12];
    char NumFijo[12];
    char Email[25];
    char Facebook[15];
    char Twitter[15];
   }agenda;

int main(){
    int x, nombre, op=0;
    agenda contactos[100];
 
 do {
    printf("------------------------------\n");
    printf("            AGENDA\n");
    printf("------------------------------\n");

    printf("Seleccione que desea hacer:\n");
    printf("1.- Nuevo Contacto\n");
    printf("2.- Buscar contacto por nombre\n");
    printf("3.- Modificar contacto\n");
    printf("4.- Imprimir contactos\n");
    printf("5.- Eliminar contacto\n");
    printf("6.- Salir \n");
    scanf("%d", &op);

    switch(op){
        case 1:
        printf("Nuevo contacto\n");

        for (x=0; x<1; x++){
            fflush(stdin);
            printf("Ingrese el ID: \n");
            fgets(contactos->ID, 20, stdin);
            fflush(stdin);
            printf("Ingrese el Nombre: \n");
            fgets(contactos->Nombre, 25, stdin);
            fflush(stdin);
            printf("Ingrese el Apellido Paterno: \n");
            fgets(contactos->ApellidoPaterno, 20, stdin);
            fflush(stdin);
            printf("Ingrese el Apellido Materno: \n");
            fgets(contactos->Apellidomaterno, 20, stdin);
            fflush(stdin);
            printf("Ingrese el Domicilio: \n");
            fgets(contactos->Domicilio, 30, stdin);
            fflush(stdin);
            printf("Ingrese el RFC: \n");
            fgets(contactos->RFC, 14, stdin);
            fflush(stdin);
            printf("Ingrese el Num. Movil: \n");
            fgets(contactos->NumMovil, 12, stdin);
            fflush(stdin);
            printf("Ingrese el Num. Fijo: \n");
            fgets(contactos->NumFijo, 12, stdin);
            fflush(stdin);
            printf("Ingrese el Email: \n");
            fgets(contactos->Email, 25, stdin);
            fflush(stdin);
            printf("Ingrese el Facebook: \n");
            fgets(contactos->Facebook, 15, stdin);
            fflush(stdin);
            printf("Ingrese el Twitter: \n");
            fgets(contactos->Twitter, 15, stdin);
            fflush(stdin);
    }
        break;

        case 2:
        printf("Buscar contacto por nombre \n");
        
        printf("Introduce el nombre del contacto que se desee buscar: \n");
        
        if(nombre==contactos->Nombre){
            printf("El contacto que solicito es:", contactos[x]);
        }
        break;

        case 3:
        printf("Modificar Contacto\n");
        break;

        case 4:
        printf("Imprimir Contacto\n");

        printf("ID: \n", contactos->ID);
        printf("Nombre del contacto: \n", contactos->Nombre);
        printf("Apellido paterno: \n", contactos->ApellidoPaterno);
        printf("Apellido materno: \n", contactos->Apellidomaterno);
        printf("Domicilio: \n", contactos->Domicilio);
        printf("El RFC es: \n", contactos->RFC);
        printf("El Num Movil es: \n", contactos->NumMovil);
        printf("El Num Fijo es: \n", contactos->NumFijo);
        printf("El Email es: \n", contactos->Email);
        printf("El Facebook es: \n", contactos->Facebook);
        printf("El Twitter es: \n", contactos->Twitter);
        break;

        case 5:
        printf("Eliminar contacto\n");
        break;

        case 6:
        break;

        default:
        printf("Opci%cn Incorrecta\n", 162);
        break;
  }
}while(op !=6);
    return 0;
}