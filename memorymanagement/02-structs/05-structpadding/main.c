#include "munit.h"
#include "exercise.h"

static MunitResult test_optimal_size(const MunitParameter params[], void* data) {
  munit_assert_int(sizeof(sneklang_var_t), ==, 24);
  return MUNIT_OK;
}

static MunitTest tests[] = {
    { "/test_optimal_size", test_optimal_size, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }  // End of test array
};

static const MunitSuite suite = {
    "/padding",          /* suite name */
    tests,               /* tests */
    NULL,                /* no sub-suites */
    1,                   /* iterations */
    MUNIT_SUITE_OPTION_NONE /* options */
};

int main(int argc, char* argv[]) {
  return munit_suite_main(&suite, NULL, argc, argv);
}

