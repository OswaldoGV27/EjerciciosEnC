#include <stdio.h>

int main(){
    int a, ar[5];
    char r=129, palabra3[50], palabra[10]="Mi texto", palabra2[10]={'H','i','r',54,'\0'};
    //palabra
    ar[0]=564;
    ar[1]=32;
    printf("%d\n", sizeof(r));
    printf("%d\n", sizeof(palabra));
    printf("%c\n", palabra[0]);
    for(int x=0; x<sizeof(palabra); x++){
        printf("%c", palabra[x]);
    }
    
    printf("\n%s\n", palabra);
    
    printf("\n%s\n", palabra2);
    printf("%d\n", r);

    printf("Ingresa una palabra no mayor a 49 caracteres\n");
    scanf("%[^\n]", palabra3);
    printf("%s", palabra3);

    return 0;
}