#include <stdio.h>
#include "inc/sort.h"

#define ASIZE 5

int main(){
    int i;
    int iarr[]   = {13, 22, 9, 11, 14, 25, 7, 1, 0, 12};
    char **names = strarray_alloc(64, ASIZE);

    strarray_set(names, ASIZE, "Pedro", "Carlos", "Anderson", "Roberto", "Bruna");

    strarray_sort(names, ASIZE);
    intarray_sort(iarr, sizeof iarr / sizeof(int));

    for(i = 0; i < ASIZE; i++){
        puts(names[i]);
    }

    printf("%d", iarr[0]);
    for(i = 1; i < sizeof iarr / sizeof(int); i++){
        printf(", %d", iarr[i]);
    }

    putchar('\n');

    return 0;
}