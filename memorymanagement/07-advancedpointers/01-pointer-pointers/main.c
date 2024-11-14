#include <stdlib.h>
#include "exercise.h"
#include "munit.h"

// Test case for allocate_int that verifies pointer allocation and value assignment
static MunitResult test_allocate(const MunitParameter params[], void* data) {
  int *pointer = NULL;
  allocate_int(&pointer, 10);

  munit_assert_not_null(pointer);  // Verify pointer is not NULL
  munit_assert_int(*pointer, ==, 10);  // Check if the value assigned is correct

  free(pointer);
  return MUNIT_OK;
}

// Test case to ensure the original value is not overwritten
static MunitResult test_does_not_overwrite(const MunitParameter params[], void* data) {
  int value = 5;
  int *pointer = &value;

  allocate_int(&pointer, 20);

  munit_assert_int(value, ==, 5);  // Verify original value remains the same
  munit_assert_not_null(pointer);  // Check pointer is not NULL
  munit_assert_int(*pointer, ==, 20);  // Check assigned value

  free(pointer);
  return MUNIT_OK;
}

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  // Define the test cases
  MunitTest tests[] = {
    { "/create", test_allocate, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/overwrite", test_does_not_overwrite, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }  // Null-terminated array
  };

  // Define the test suite
  MunitSuite suite = {
    "/allocate_list", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
  };

  // Run the test suite
  return munit_suite_main(&suite, NULL, argc, argv);
}

