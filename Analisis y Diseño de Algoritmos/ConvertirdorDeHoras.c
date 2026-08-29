#include <stdio.h>
#include <stdlib.h>

int main (){
    int t;
    scanf("%d", &t);
    if(t>1440)return 0;

    while (t != 0){
        int hh, mm, hora, minuto;
        scanf("%d %d", &hh, &mm);

        if(hh > 0 && hh < 12){
            if(mm > 59){
                minuto=mm-60;
                hora=hh+1;
                if(hora < 10 && minuto > 10){
                    printf("0%d:%d AM\n", hora, minuto);
                }
                if(hora > 10 && minuto < 10){
                    printf("%d:0%d AM\n", hora, minuto);
                }
                if(hora < 10 && minuto < 10){
                    printf("0%d:0%d AM\n", hora, minuto);
                }
                if(hora > 10 && minuto > 10){
                    printf("%d:%d AM\n", hora, minuto);
                }
            }

            if(mm < 60){
                if(hh < 10 && mm > 10){
                    printf("0%d:%d AM\n", hh, mm);
                }
                if(hh > 10 &&mm < 10){
                    printf("%d:0%d AM\n", hh, mm);
                    }
                if(hh < 10 && mm < 10){
                    printf("0%d:0%d AM\n", hh, mm);
                }
                if(hh > 10 && mm > 10){
                    printf("%d:%d AM\n", hh, mm);
                }
            }

        }
        

        if (hh > 12){
            hora= hh-12;
            hora= abs(hora);
            if (mm > 59){
                minuto=mm-60;
                hora=hora+1;
                if(hora < 10 && minuto > 10){
                    printf("0%d:%d PM\n", hora, minuto);
                }
                if(hora > 10 && minuto < 10){
                    printf("%d:0%d PM\n", hora, minuto);
                }
                if(hora < 10 && minuto < 10){
                    printf("0%d:0%d PM\n", hora, minuto);
                }
                if(hora > 10 && minuto > 10){
                    printf("%d:%d PM\n", hora, minuto);
                }
            }


            if(mm < 60){
                if(hora < 10 && mm > 10){
                    printf("0%d:%d PM\n", hora, mm);
                }
                if(hora > 10 &&mm < 10){
                    printf("%d:0%d PM\n", hora, mm);
                }
                if(hora < 10 && mm < 10){
                    printf("0%d:0%d PM\n", hora, mm);
                }
                if(hora > 10 && mm > 10){
                    printf("0%d:0%d PM\n", hora, mm);
                }
            }
        }

        if(hh==12){
            if (mm > 59){
                minuto=mm-60;
                hora=1;

                if(hora < 10 && minuto > 10){
                    printf("0%d:%d PM\n", hora, minuto);
                }
                if(hora > 10 && minuto < 10){
                    printf("%d:0%d PM\n", hora, minuto);
                }
                if(hora < 10 && minuto < 10){
                    printf("0%d:0%d PM\n", hora, minuto);
                }
                if(hora > 10 && minuto > 10){
                    printf("%d:%d PM\n", hora, minuto);
                }
            }


            if(mm < 60){
                if(hh < 10 && mm > 10){
                    printf("0%d:%d PM\n", hh, mm);
                }
                if(hh > 10 &&mm < 10){
                    printf("%d:0%d PM\n", hh, mm);
                }
                if(hh < 10 && mm < 10){
                    printf("0%d:0%d PM\n", hh, mm);
                }
                if(hh > 10 && mm > 10){
                    printf("%d:%d PM\n", hh, mm);
                }
            }
        }

        if(hh==0){
            if (mm > 59){
                minuto=mm-60;
                hh=1;

                if(hora < 10 && minuto > 10){
                    printf("0%d:%d AM\n", hora, minuto);
                }
                if(hora > 10 && minuto < 10){
                    printf("%d:0%d AM\n", hora, minuto);
                }
                if(hora < 10 && minuto < 10){
                    printf("0%d:0%d AM\n", hora, minuto);
                }
                if(hora > 10 && minuto > 10){
                    printf("%d:%d AM\n", hora, minuto);
                }
            }


            if(mm < 60){
                hh=12;
                if(hh < 10 && mm > 10){
                    printf("0%d:%d AM\n", hh, mm);
                }
                if(hh > 10 &&mm < 10){
                    printf("%d:0%d AM\n", hh, mm);
                }
                if(hh < 10 && mm < 10){
                    printf("0%d:0%d AM\n", hh, mm);
                }
                if(hh > 10 && mm > 10){
                    printf("%d:%d AM\n", hh, mm);
                }
            }
        }
        t--;
    }
    return 0;
}