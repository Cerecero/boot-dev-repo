#include <stdio.h>
#include <stdlib.h>
#include "exercise.h"

// Function to test allocation and size
void test_allocate_scalar_list_size() {
  int size = 5;
  int multiplier = 2;
  int *result = allocate_scalar_list(size, multiplier);
  
  if (result == NULL) {
    printf("Test failed: Function should return a non-null pointer\n");
  } else {
    printf("Test passed: Non-null pointer returned\n");
  }
  free(result);
}

// Function to test correct values in the list
void test_allocate_scalar_list_values() {
  int size = 5;
  int multiplier = 2;
  int *result = allocate_scalar_list(size, multiplier);
  int expected[5] = {0, 2, 4, 6, 8};
  
  int passed = 1;
  for (int i = 0; i < size; i++) {
    if (result[i] != expected[i]) {
      printf("Test failed: Element %d does not match expected value\n", i);
      passed = 0;
    }
  }
  
  if (passed) {
    printf("Test passed: All elements match expected values\n");
  }
  
  free(result);
}

// Function to test with a zero multiplier
void test_allocate_scalar_list_zero_multiplier() {
  int size = 3;
  int multiplier = 0;
  int *result = allocate_scalar_list(size, multiplier);
  
  int passed = 1;
  for (int i = 0; i < size; i++) {
    if (result[i] != 0) {
      printf("Test failed: Element %d should be 0 with multiplier 0\n", i);
      passed = 0;
    }
  }
  
  if (passed) {
    printf("Test passed: All elements are 0 with multiplier 0\n");
  }
  
  free(result);
}

// Function to test very large allocations
void test_allocate_too_much() {
  int size = 1024 * 1024 * 100;  // Large size
  int multiplier = 1;
  int *result = allocate_scalar_list(size, multiplier);
  
  if (result == NULL) {
    printf("Test passed: Giant allocation resulted in NULL\n");
  } else {
    printf("Test failed: Giant allocation should result in NULL\n");
    free(result);
  }
}

int main() {
  // Running all tests
  test_allocate_scalar_list_size();
  test_allocate_scalar_list_values();
  test_allocate_scalar_list_zero_multiplier();
  test_allocate_too_much();

  return 0;
}

