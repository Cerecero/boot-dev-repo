#include "snekstack.h"
#include "stdlib.h"

void scary_double_push(stack_t *s) {
  stack_push(s, (void *)1337);
    int *new_mem = malloc(sizeof(int));

    *new_mem = 1024;

    stack_push(s, (void*)new_mem);
    
}

