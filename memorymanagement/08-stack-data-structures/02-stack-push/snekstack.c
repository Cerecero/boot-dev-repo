#include "snekstack.h"
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

void stack_push(stack_t *stack, void *obj) {
    if(stack->count == stack->capacity){
        // stack->capacity = stack->capacity * 2; //This would modify the capacity before a succesful reallocation
        // Double the capacity
        size_t new_capacity = stack->capacity * 2; 
        void **new_ptr = realloc(stack->data, new_capacity * sizeof(void *));
        // If realloc fails
        if(new_ptr == NULL){
            free(stack->data);
            return;
        }
        // Update stack data and capacity
        stack->data = new_ptr;
        stack->capacity = new_capacity;
    }
    //add the new object to the top of the stack
    stack->data[stack->count] = obj;
    stack->count++; // increments
}

// don't touch below this line

stack_t *stack_new(size_t capacity) {
  stack_t *stack = malloc(sizeof(stack_t));
  if (stack == NULL) {
    return NULL;
  }

  stack->count = 0;
  stack->capacity = capacity;
  stack->data = malloc(stack->capacity * sizeof(void *));
  if (stack->data == NULL) {
    free(stack);
    return NULL;
  }

  return stack;
}
