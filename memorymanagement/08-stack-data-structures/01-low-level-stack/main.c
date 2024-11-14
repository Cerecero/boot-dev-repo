#include "munit.h"
#include "snekstack.h"

// Test for creating a stack with a small capacity
static MunitResult test_create_stack_small(const MunitParameter params[], void *user_data) {
  stack_t *s = stack_new(3);
  
  munit_assert_int(s->capacity, ==, 3); // Checks if the capacity is set to 3
  munit_assert_int(s->count, ==, 0);    // Checks if the stack count is 0 initially
  munit_assert_not_null(s->data);       // Checks if data has been allocated

  free(s->data);
  free(s);

  munit_assert_true(boot_all_freed());  // Verifies all memory was freed
  return MUNIT_OK;
}

// Test for creating a stack with a larger capacity
static MunitResult test_create_stack_large(const MunitParameter params[], void *user_data) {
  stack_t *s = stack_new(100);
  
  munit_assert_int(s->capacity, ==, 100); // Checks if the capacity is set to 100
  munit_assert_int(s->count, ==, 0);      // Checks if the stack count is 0 initially
  munit_assert_not_null(s->data);         // Checks if data has been allocated

  free(s->data);
  free(s);

  munit_assert_true(boot_all_freed());    // Verifies all memory was freed
  return MUNIT_OK;
}

// Main function for running Munit tests
int main(int argc, char* argv[]) {
  MunitTest tests[] = {
    { "/create_stack_small", test_create_stack_small, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/create_stack_large", test_create_stack_large, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL } // Termination entry for tests array
  };

  MunitSuite suite = {
    "/snekstack", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
  };

  return munit_suite_main(&suite, NULL, argc, argv);
}

