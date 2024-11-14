#include "munit.h"
#include "snekobject.h"

// Define the test for positive integer creation
static MunitResult test_positive(const MunitParameter params[], void* user_data) {
  snek_object_t *int_object = new_snek_integer(42);
  munit_assert_int(int_object->data.v_int, ==, 42);
  free(int_object);
  return MUNIT_OK;
}

// Define the test for zero integer creation
static MunitResult test_zero(const MunitParameter params[], void* user_data) {
  snek_object_t *int_object = new_snek_integer(0);
  munit_assert_int(int_object->kind, ==, INTEGER);
  munit_assert_int(int_object->data.v_int, ==, 0);
  free(int_object);
  return MUNIT_OK;
}

// Define the test for negative integer creation
static MunitResult test_negative(const MunitParameter params[], void* user_data) {
  snek_object_t *int_object = new_snek_integer(-5);
  munit_assert_int(int_object->kind, ==, INTEGER);
  munit_assert_int(int_object->data.v_int, ==, -5);
  free(int_object);
  return MUNIT_OK;
}

// Define the array of test cases
static MunitTest tests[] = {
  { "/positive", test_positive, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/zero", test_zero, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/negative", test_negative, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// Define the test suite
static const MunitSuite suite = {
  "object-integer", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

// Main function to run the tests
int main(int argc, char* argv[]) {
  return munit_suite_main(&suite, NULL, argc, argv);
}

