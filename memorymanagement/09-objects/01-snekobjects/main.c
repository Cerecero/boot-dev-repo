#include <stdlib.h>
#include "munit.h"
#include "snekobject.h"

// Define the test function for INTEGER constant
static MunitResult test_integer_constant(const MunitParameter params[], void* user_data) {
  munit_assert_int(INTEGER, ==, 0);
  return MUNIT_OK;
}

// Define the test function for integer object creation
static MunitResult test_integer_obj(const MunitParameter params[], void* user_data) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  obj->kind = INTEGER;
  obj->data.v_int = 0;
  munit_assert_int(obj->kind, ==, INTEGER);
  munit_assert_int(obj->data.v_int, ==, 0);

  free(obj);
  return MUNIT_OK;
}

// Create the test cases array
static MunitTest tests[] = {
  { "/integer_constant", test_integer_constant, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/integer_obj", test_integer_obj, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// Define the test suite
static const MunitSuite suite = {
  "object-integer-def", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

// Main function to run the tests
int main(int argc, char* argv[]) {
  return munit_suite_main(&suite, NULL, argc, argv);
}

