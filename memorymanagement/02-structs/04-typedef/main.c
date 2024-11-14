#include "munit.h"
#include "coord.h"

/* Test for new_coord function */
static MunitResult
test_new_coordinate(const MunitParameter params[], void* data) {
  coordinate_t c = new_coord(1, 2, 3);

  munit_assert_int(c.x, ==, 1);
  munit_assert_int(c.y, ==, 2);
  munit_assert_int(c.z, ==, 3);

  return MUNIT_OK;
}

/* Test for scale_coordinate function */
static MunitResult
test_scale_coordinate(const MunitParameter params[], void* data) {
  coordinate_t c = new_coord(1, 2, 3);
  coordinate_t scaled = scale_coordinate(c, 2);

  munit_assert_int(scaled.x, ==, 2);
  munit_assert_int(scaled.y, ==, 4);
  munit_assert_int(scaled.z, ==, 6);

  return MUNIT_OK;
}

/* Array of tests */
static MunitTest tests[] = {
    { "/test_new_coordinate", test_new_coordinate, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_scale_coordinate", test_scale_coordinate, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

/* Define the test suite */
static const MunitSuite suite = {
    "/coordinate_tests",   /* Suite name */
    tests,                 /* Array of test cases */
    NULL,                  /* No sub-suites */
    1,                     /* Number of iterations */
    MUNIT_SUITE_OPTION_NONE
};

/* Main function to run the suite */
int main(int argc, char* argv[]) {
  return munit_suite_main(&suite, NULL, argc, argv);
}
