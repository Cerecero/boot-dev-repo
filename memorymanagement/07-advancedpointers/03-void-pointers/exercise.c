#include "exercise.h"

void snek_zero_out(void *ptr, snek_object_kind_t kind){
    if(kind == INTEGER){
        snek_int_t *int_ptr = (snek_int_t *)ptr;
        int_ptr->value = 0;
    }
    else if(kind == FLOAT){
        snek_float_t *float_ptr = (snek_float_t *)ptr;
        float_ptr->value = 0;
    }
    else if(kind == BOOL){
        snek_bool_t *bool_ptr = (snek_bool_t *)ptr;
        bool_ptr->value = 0;
    }
}

