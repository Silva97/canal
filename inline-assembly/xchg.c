/********************
 * Exemplo de Inline Assembly por Luiz Felipe.
 * - https://github.com/Silva97
 *
 * Vídeo: https://youtu.be/mRDiybGBOSE
 ********************/

#include <stdio.h>

#define xchg(x, y) \
    __asm__("xchg %1, %0" : "+m" (x), "+r" (y))
     // Uso um registrador para Y porque xchg não
    //  pode trabalhar com dois valores na memória.

int main(){
    int x = 25;
    int y = 333;

    xchg(x, y);
    /**** Mesma troca acima feita em C:
    x ^= y;
    y ^= x;
    x ^= y;
    *****/

    printf("x  = %d\n", x);
    printf("y  = %d\n", y);
    return 0;
}
