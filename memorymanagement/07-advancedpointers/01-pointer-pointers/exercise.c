#include "stdlib.h"

#include "exercise.h"

void allocate_int(int **pointer_pointer, int value) {
    int *new_pointer = (int*)malloc(sizeof(int));
    if (new_pointer == NULL){
        *pointer_pointer = NULL;
        return;
    }
    *new_pointer = value;
    *pointer_pointer = new_pointer;
}
