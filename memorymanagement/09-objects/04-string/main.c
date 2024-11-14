#include <stdlib.h>
#include <string.h>
#include "munit.h"
#include "snekobject.h"

static MunitResult
test_str_copied(const MunitParameter params[], void* user_data) {
  char *input = "Hello, World!";
  snek_object_t *obj = new_snek_string(input);

  munit_assert_int(obj->kind, ==, STRING);

  // Ensure the string is copied by checking that pointers differ.
  munit_assert_ptr_not_equal(obj->data.v_string, input);

  // Verify the copied string matches the input.
  munit_assert_string_equal(obj->data.v_string, input);

  // Ensure correct memory allocation for the string including null terminator.

  // Free allocated memory and the object.
  free(obj->data.v_string);
  free(obj);
  
  // Check if all memory was freed.

  return MUNIT_OK;
}

static MunitTest tests[] = {
  { "/copies_value", test_str_copied, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL } // Null-terminated array
};

static const MunitSuite suite = {
  "object-string",       // Name of the test suite
  tests,                 // Array of test cases
  NULL,                  // Nested suites (none)
  1,                     // Number of iterations to run each test
  MUNIT_SUITE_OPTION_NONE // Suite options
};

int main(int argc, char* argv[]) {
  return munit_suite_main(&suite, NULL, argc, argv);
}

