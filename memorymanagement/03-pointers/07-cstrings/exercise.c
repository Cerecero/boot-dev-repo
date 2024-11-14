#include "exercise.h"

void concat_strings(char *str1, const char *str2) {
    while (*str1) { // check each character until null terminator
    str1++;
  }
  
  while (*str2) { // check each character until null terminator
    *str1 = *str2; // from the position of null terminator is equal to the start of str2
    str1++;
    str2++;
  }
  
  *str1 = '\0';
}
