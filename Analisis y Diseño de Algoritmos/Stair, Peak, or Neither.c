#include <stdio.h>

int main() {
    int t, a, b, c;
    scanf("%d", &t); 
    while(t--) {
        scanf("%d %d %d", &a, &b, &c);

        if(a < b && b < c) {
            printf("STAIR\n");
        } else if(a < b && b > c) {
            printf("PEAK\n");
        } else {
            printf("NONE\n");
        }
    }

    return 0;
}