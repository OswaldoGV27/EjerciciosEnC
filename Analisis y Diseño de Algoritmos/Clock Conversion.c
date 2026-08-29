#include <stdio.h>
#include <string.h>

int main() {
    int t; 
    scanf("%d", &t);

    while (t--) {
        char s[6]; 
        scanf("%s", s);

        int hh, mm;
        sscanf(s, "%d:%d", &hh, &mm);

        if (hh >= 0 && hh <= 23 && mm >= 0 && mm <= 59) {
            if (hh == 0) {
                printf("12:%02d AM\n", mm);
            } else if (hh < 12) {
                printf("%02d:%02d AM\n", hh, mm);
            } else if (hh == 12) {
                printf("12:%02d PM\n", mm);
            } else {
                printf("%02d:%02d PM\n", hh - 12, mm);
            }
        }
    }

    return 0;
}