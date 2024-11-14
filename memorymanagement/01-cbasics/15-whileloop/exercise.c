#include <stdio.h>

void print_numbers_reverse(int start, int end){
    while (start >= end){
        printf("%d\n", start);
        start--;
    }
}
