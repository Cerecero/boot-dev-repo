#include <stdlib.h>

#include "snekobject.h"

snek_object_t *new_snek_integer(int value) {
    snek_object_t *new_arr = (snek_object_t *) malloc(sizeof(snek_object_t));
    if (new_arr == NULL){
        return NULL;
    }
    new_arr->kind = INTEGER;

    new_arr->data.v_int =  value;
    return new_arr;
}

