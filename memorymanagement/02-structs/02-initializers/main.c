#include "munit.h"
#include "coord.h"

/* Define each test case as a function. */
static MunitResult test_new_coordinate1(const MunitParameter params[], void* data) {
    struct Coordinate c;
    c.x = 1;
    c.y = 2;
    c.z = 3;

    munit_assert_int(c.x, ==, 1);
    munit_assert_int(c.y, ==, 2);
    munit_assert_int(c.z, ==, 3);

    return MUNIT_OK;
}

static MunitResult test_new_coordinate2(const MunitParameter params[], void* data) {
    struct Coordinate c = new_coord(4, 2, 0);

    munit_assert_int(c.x, ==, 4);
    munit_assert_int(c.y, ==, 2);
    munit_assert_int(c.z, ==, 0);

    return MUNIT_OK;
}

/* Array of tests for the suite. */
static MunitTest test_suite_tests[] = {
    { "/create_coordinate1", test_new_coordinate1, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/create_coordinate2", test_new_coordinate2, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }  // End of test array
};

/* Define the test suite. */
static const MunitSuite test_suite = {
    "/coordinates_suite",         /* Suite name */
    test_suite_tests,             /* Tests in the suite */
    NULL,                         /* No sub-suites */
    1,                            /* Number of iterations */
    MUNIT_SUITE_OPTION_NONE       /* Options */
};

/* Main function to run the test suite. */
int main(int argc, char* argv[]) {
    return munit_suite_main(&test_suite, NULL, argc, argv);
}
