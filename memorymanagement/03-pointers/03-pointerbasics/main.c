#include "munit.h"
#include "exercise.h"

// Define the test function for each case
static MunitResult test_change_filetype_cpp_to_python(const MunitParameter params[], void *data) {
  codefile_t original = { .lines = 100, .filetype = 1 };
  codefile_t result = change_filetype(&original, 2);

  munit_assert_int(result.filetype, ==, 2);
  munit_assert_int(result.lines, ==, 100);

  return MUNIT_OK;
}

static MunitResult test_change_filetype_same_type(const MunitParameter params[], void *data) {
  codefile_t original = { .lines = 50, .filetype = 3 };
  codefile_t result = change_filetype(&original, 3);

  munit_assert_int(result.filetype, ==, 3);
  munit_assert_int(result.lines, ==, 50);

  return MUNIT_OK;
}

static MunitResult test_change_filetype_java_to_rust(const MunitParameter params[], void *data) {
  codefile_t original = { .lines = 200, .filetype = 4 };
  codefile_t result = change_filetype(&original, 5);

  munit_assert_int(result.filetype, ==, 5);
  munit_assert_int(result.lines, ==, 200);

  return MUNIT_OK;
}

static MunitResult test_change_filetype_zero_lines(const MunitParameter params[], void *data) {
  codefile_t original = { .lines = 0, .filetype = 1 };
  codefile_t result = change_filetype(&original, 6);

  munit_assert_int(result.filetype, ==, 6);
  munit_assert_int(result.lines, ==, 0);

  return MUNIT_OK;
}

// Define the tests array
static MunitTest tests[] = {
  { "/test_change_filetype_cpp_to_python", test_change_filetype_cpp_to_python, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/test_change_filetype_same_type", test_change_filetype_same_type, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/test_change_filetype_java_to_rust", test_change_filetype_java_to_rust, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/test_change_filetype_zero_lines", test_change_filetype_zero_lines, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// Define the test suite
static const MunitSuite suite = {
  "/change_filetype_tests",  // Suite name prefix
  tests,                     // Array of test cases
  NULL,                      // No sub-suites
  1,                         // Number of iterations
  MUNIT_SUITE_OPTION_NONE    // Options
};

int main(int argc, char* argv[]) {
  // Run the test suite
  return munit_suite_main(&suite, NULL, argc, argv);
}

