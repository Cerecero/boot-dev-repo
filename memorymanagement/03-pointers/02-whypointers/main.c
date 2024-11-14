#include "munit.h"
#include "coordinate.h"

// Define the test functions
static MunitResult test_unchanged(const MunitParameter params[], void *data) {
  coordinate_t old = new_coordinate(1, 2, 3);
  munit_assert_int(old.x, ==, 1);

  coordinate_update_x(old, 4);  // Pass by value
  munit_assert_int(old.x, ==, 1);  // x should remain unchanged
  return MUNIT_OK;
}

static MunitResult test_changed(const MunitParameter params[], void *data) {
  coordinate_t old = new_coordinate(1, 2, 3);
  munit_assert_int(old.x, ==, 1);

  coordinate_t new = coordinate_update_and_return_x(old, 4);
  munit_assert_int(new.x, ==, 4);  // new.x should be 4
  munit_assert_int(old.x, ==, 1);  // old.x should remain 1

  munit_assert_ptr_not_equal(&old, &new);  // The addresses must be different
  return MUNIT_OK;
}

int main() {
  // Define the test cases
  MunitTest tests[] = {
      {"/test_unchanged", test_unchanged},
      {"/test_changed", test_changed},
      {NULL, NULL}  // End of the test list
  };

  // Define the suite without setup or teardown
  MunitSuite suite = {
      .prefix = "coordinate_tests",
      .tests = tests,
      .iterations = 1
  };

  // Run the tests
  return munit_suite_main(&suite, NULL, 0, NULL);
}

