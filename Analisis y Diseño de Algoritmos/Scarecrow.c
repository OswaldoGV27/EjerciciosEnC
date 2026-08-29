#include <stdio.h>
#include <string.h>

int main() {
    int T, N, i, j, caso = 1;
    char campo[101];

    scanf("%d", &T); /*Número de casos de prueba*/

    while(T--) {
        scanf("%d", &N); /*Longitud del campo*/
        scanf("%s", campo); /*Descripción del campo*/

        int espantapajaros = 0;

        for(i = 0; i < N; ) {
            if(campo[i] == '.') { /*Si hay un lugar para cultivar Colocar un espantapájaros y cubrir tres celdas*/
                espantapajaros++;
                i += 3;
            } else {
                i++; /*Si es una región infértil, simplemente avanzar*/
            }
        }

        printf("Case %d: %d\n", caso++, espantapajaros);
    }

    return 0;
}