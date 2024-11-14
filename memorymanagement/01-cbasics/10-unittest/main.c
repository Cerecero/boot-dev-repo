#include "munit.h"
#include "excercise.h"

static MunitResult test_get_average(const MunitParameter params[], void* data) {
    float result = get_average(3, 4, 5);
    munit_assert_double_equal((double)result, 4.0, 1);
    return MUNIT_OK;
}

static MunitResult test_non_integer(const MunitParameter params[], void* data) {
    float result = get_average(3, 3, 5);
    munit_assert_double_equal((double)result, 11.0 / 3.0, 1);
    return MUNIT_OK;
}

static MunitResult test_average_of_same(const MunitParameter params[], void* data) {
    float result = get_average(10, 10, 10);
    munit_assert_double_equal((double)result, 10.0, 1);
    return MUNIT_OK;
}

static MunitResult test_average_of_big_numbers(const MunitParameter params[], void* data) {
    float result = get_average(1050, 2050, 2075);
    munit_assert_double_equal((double)result, 1725.0, 1);
    return MUNIT_OK;
}

/* Array of tests for the suite. */
static MunitTest test_suite_tests[] = {
    { "/get_average", test_get_average, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/get_average_float", test_non_integer, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/get_average_same", test_average_of_same, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/get_average_big", test_average_of_big_numbers, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }  // End of test array
};

/* Define the test suite. */
static const MunitSuite test_suite = {
    "/get_average_suite",         /* Suite name */
    test_suite_tests,             /* Tests in the suite */
    NULL,                         /* No sub-suites */
    1,                            /* Number of iterations */
    MUNIT_SUITE_OPTION_NONE       /* Options */
};

/* Main function to run the test suite. */
int main(int argc, char* argv[]) {
    return munit_suite_main(&test_suite, NULL, argc, argv);
}
