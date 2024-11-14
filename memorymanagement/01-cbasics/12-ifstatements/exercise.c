#include "execinfo.h"
#include <stdio.h>

char *get_temperature_status(int temp) {

  if (temp <= 70) {
    printf("too cold\n");
  } else if (temp > 90) {
    printf("too ho\n");
  } else {
    printf("just right");
  }
}
