#include "snekstack.h"
#include <stdlib.h>

stack_t *stack_new(size_t capacity) {
    stack_t *stack = (stack_t*)malloc(sizeof(stack_t));
    if (stack == NULL){
        return NULL;
    }
    stack->count = 0;
    stack->capacity = capacity;

    stack->data = (void **)malloc(capacity * sizeof(void **));
    if(stack->data == NULL){
        free(stack);
        return NULL;
    }

    return stack;
}

