#programa config FOSC = XT
#programa config WDTE = OFF
#programa config PWRTE = OFF
#programa config BOREN = OFF
#programa config LVP = OFF
#programa config CPD = OFF
#programa config WRT = OFF
#programa config CP = OFF

#include <stdlib.h>
#include <pic16f873a.h>

void main ()
{
    TRISB = 0x0F;   // De RB7-4 son salidas de RB3-0 son entradas
    PORTB = 0x00;   // se reinicia el puerto

IVONE:

    PORTBbits.RB7 = 0;              // Se explora en la fila 0
    
    if (PORTBbits.RB3 == 0)         // Si la columna 0 es 0
        tecla = '1';                // Se asigna '1' a la variable tecla
    else if (PORTBbits.RB2 == 0)    // Si la columna 1 es 0
        tecla = '2';                // Se asigna '2' a la variable tecla
    else if (PORTBbits.RB1 == 0)    // Si la columna 2 es cero
        tecla = '3';                // Se asigna '3' a la variable tecla
    else if (PORTBbits.RB0 == 0)    // Si la columna 3 es 0
        tecla = '4';                // Se asigna '4' a la variable tecla
    
    PORTB = 0xF0;                   // Se refresca el puerto
    PORTBbits.RB6 = 0;              // Se explora la fila 1 

    if (PORTBbits.RB3 == 0)         // Si la columna 0 es 0
        tecla = '5';                // Se asigna '5' a la variable tecla
    else if (PORTBbits.RB2 == 0)    // Si la columna 1 es 0
        tecla = '6';                // Se asigna '6' a la variable tecla
    else if (PORTBbits.RB1 == 0)    // Si la columna 2 es cero
        tecla = '7';                // Se asigna '7' a la variable tecla
    else if (PORTBbits.RB0 == 0)    // Si la columna 3 es 0
        tecla = '8';                // Se asigna '8' a la variable tecla
    
    PORTB = 0xF0;                   // Se refresca el puerto
    PORTBbits.RB5 = 0;              // Se explora la fila 2

    if (PORTBbits.RB3 == 0)         // Si la columna 0 es 0
        tecla = '9';                // Se asigna '9' a la variable tecla
    else if (PORTBbits.RB2 == 0)    // Si la columna 1 es 0
        tecla = 'A';                // Se asigna 'A' a la variable tecla
    else if (PORTBbits.RB1 == 0)    // Si la columna 2 es cero
        tecla = 'B';                // Se asigna 'B' a la variable tecla
    else if (PORTBbits.RB0 == 0)    // Si la columna 3 es 0
        tecla = 'C';                // Se asigna 'C' a la variable tecla

    PORTB = 0xF0;                   // Se refresca el puerto
    PORTBbits.RB4 = 0;              // Se explora la fila 3

    if (PORTBbits.RB3 == 0)         // Si la columna 0 es 0
        tecla = 'D';                // Se asigna 'D' a la variable tecla
    else if (PORTBbits.RB2 == 0)    // Si la columna 1 es 0
        tecla = 'E';                // Se asigna 'E' a la variable tecla
    else if (PORTBbits.RB1 == 0)    // Si la columna 2 es cero
        tecla = 'F';                // Se asigna 'F' a la variable tecla
    else if (PORTBbits.RB0 == 0)    // Si la columna 3 es 0
        tecla = '0';                // Se asigna '0' a la variable tecla

    goto IVONE;
}