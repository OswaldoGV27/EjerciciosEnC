#include <stdio.h>
#include <string.h>

int main() {
    int L, i;
    while (scanf("%d", &L) == 1 && L != 0) {
        char decision[4];
        char alambre[4] = "+x"; /*Inicializamos el alambre con dirección +x*/

        for (i = 1; i < L; ++i) {
            scanf("%s", decision);

            if (strcmp(decision, "No") == 0) {
                continue;
            } else if (strcmp(decision, "+y") == 0) {
                if (strcmp(alambre, "+x") == 0) {
                    strcpy(alambre, "+y");
                } else if (strcmp(alambre, "-x") == 0) {
                    strcpy(alambre, "-y");
                } else if (strcmp(alambre, "+y") == 0) {
                    strcpy(alambre, "-x");
                } else if (strcmp(alambre, "-y") == 0) {
                    strcpy(alambre, "+x");
                }
            } else if (strcmp(decision, "-y") == 0) {
                if (strcmp(alambre, "+x") == 0) {
                    strcpy(alambre, "-y");
                } else if (strcmp(alambre, "-x") == 0) {
                    strcpy(alambre, "+y");
                } else if (strcmp(alambre, "+y") == 0) {
                    strcpy(alambre, "+x");
                } else if (strcmp(alambre, "-y") == 0) {
                    strcpy(alambre, "-x");
                }
            } else if (strcmp(decision, "+z") == 0) {
                if (strcmp(alambre, "+x") == 0) {
                    strcpy(alambre, "+z");
                } else if (strcmp(alambre, "-x") == 0) {
                    strcpy(alambre, "-z");
                } else if (strcmp(alambre, "+z") == 0) {
                    strcpy(alambre, "-x");
                } else if (strcmp(alambre, "-z") == 0) {
                    strcpy(alambre, "+x");
                }
            } else if (strcmp(decision, "-z") == 0) {
                if (strcmp(alambre, "+x") == 0) {
                    strcpy(alambre, "-z");
                } else if (strcmp(alambre, "-x") == 0) {
                    strcpy(alambre, "+z");
                } else if (strcmp(alambre, "+z") == 0) {
                    strcpy(alambre, "+x");
                } else if (strcmp(alambre, "-z") == 0) {
                    strcpy(alambre, "-x");
                }
            }
        }

        printf("%s\n", alambre); /*Imprimimos la dirección del último segmento del alambre*/
    }

    return 0;
}