/********************
 * Developed by Luiz Felipe
 * GitHub: https://github.com/Silva97
 *
 * Distributed under the MIT License.
 ********************/

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "inc/sort.h"

/*****
 * Insertion Sort(English):   https://en.wikipedia.org/wiki/Insertion_sort
 * Insertion Sort(Português): https://pt.wikipedia.org/wiki/Insertion_sort
 *****/

void intarray_sort(int *arr, int size){
    int x, y, value;

    for(x = 1; x < size; x++){
        value = arr[x];

        for(y = x - 1; y >= 0 && arr[y] > value; y--){
            arr[y+1] = arr[y];
        }

        arr[y+1] = value;
    }
}

void strarray_sort(char **arr, int size){
    int x, y;
    char *value;

    for(x = 1; x < size; x++){
        value = arr[x];

        for(y = x - 1; y >= 0 && *arr[y] > *value; y--){
            arr[y+1] = arr[y];
        }

        arr[y+1] = value;
    }
}

char** strarray_alloc(int w, int h){
    int i;
    char **arr = malloc(h * sizeof(char *));

    for(i = 0; i < h; i++){
        arr[i] = malloc(w * sizeof(char));
    }

    return arr;
}

void strarray_set(char **arr, int length, ...){
    int i;
    va_list ap;
    va_start(ap, length);

    for(i = 0; i < length; i++){
        strcpy(arr[i], va_arg(ap, char *));
    }

    va_end(ap);
}