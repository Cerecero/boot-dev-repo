#include "snekstack.h"
#include "stdlib.h"
#include <string.h>

void stack_push_multiple_types(stack_t *s) {
  float *mem = malloc(sizeof(float));
    if (mem == NULL){
        return;
    }
    *mem = 3.14;
    stack_push(s, mem);
    char *string = malloc(strlen("Sneklang is blazingly slow!") + 1);
    if (string == NULL){
        free(mem);
        return;
    }
    strcpy(string, "Sneklang is blazingly slow!");
    stack_push(s, string);
}
