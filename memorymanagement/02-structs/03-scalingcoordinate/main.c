#include "munit.h"
#include "coord.h"

/* Test function for creating a new coordinate */
static MunitResult test_new_coordinate(const MunitParameter params[], void* data) {
  struct Coordinate c;
  c.x = 1;
  c.y = 2;
  c.z = 3;

  munit_assert_int(c.x, ==, 1);  // Check x value
  munit_assert_int(c.y, ==, 2);  // Check y value
  munit_assert_int(c.z, ==, 3);  // Check z value

  return MUNIT_OK;
}

/* Test function for scaling a coordinate by a factor of 2 */
static MunitResult test_scale_coordinate1(const MunitParameter params[], void* data) {
  struct Coordinate c = new_coord(1, 2, 3);
  struct Coordinate scaled = scale_coordinate(c, 2);

  munit_assert_int(scaled.x, ==, 2);  // Check x scaling
  munit_assert_int(scaled.y, ==, 4);  // Check y scaling
  munit_assert_int(scaled.z, ==, 6);  // Check z scaling

  return MUNIT_OK;
}

/* Another test function for scaling a different coordinate */
static MunitResult test_scale_coordinate2(const MunitParameter params[], void* data) {
  struct Coordinate c = new_coord(4, 2, 0);
  struct Coordinate scaled = scale_coordinate(c, 2);

  munit_assert_int(scaled.x, ==, 8);  // Check x scaling
  munit_assert_int(scaled.y, ==, 4);  // Check y scaling
  munit_assert_int(scaled.z, ==, 0);  // Check z scaling

  return MUNIT_OK;
}

/* Array of test cases */
static MunitTest test_suite_tests[] = {
  { "/create_coordinate", test_new_coordinate, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/test_scale_coordinate1", test_scale_coordinate1, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/test_scale_coordinate2", test_scale_coordinate2, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }  // Null-terminated array
};

/* Define the test suite */
static const MunitSuite test_suite = {
  "/coordinates",           /* Suite name */
  test_suite_tests,         /* Tests in the suite */
  NULL,                     /* No sub-suites */
  1,                        /* Number of iterations */
  MUNIT_SUITE_OPTION_NONE   /* Options */
};

/* Main function to run the test suite */
int main(int argc, char* argv[]) {
  return munit_suite_main(&test_suite, NULL, argc, argv);
}

