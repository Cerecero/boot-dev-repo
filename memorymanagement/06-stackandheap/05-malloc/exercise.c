#include <stdio.h>
#include <stdlib.h>

#include "exercise.h"
#define MAX_ALLOCATION (1024 * 1024 * 100)
int *allocate_scalar_list(int size, int multiplier) {
    if ((size * sizeof(int)) > MAX_ALLOCATION){
        return NULL;
    }
    int *new_arr = (int*)malloc(size * sizeof(int));
    if (new_arr == NULL){
        return NULL;
    }
    for(int i = 0; i < size; i++){
        new_arr[i] = i * multiplier;
    }

    return new_arr;
}

