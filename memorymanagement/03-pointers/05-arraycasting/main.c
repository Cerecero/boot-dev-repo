#include "munit.h"
#include "exercise.h"

// Define the test function for `dump_graphics`
static MunitResult
test_dump_graphics(const MunitParameter params[], void* data) {
  graphics_t graphics_array[10] = {
    {60, 1080, 1920},
    {30, 720, 1280},
    {144, 1440, 2560},
    {75, 900, 1600},
    {120, 1080, 1920},
    {60, 2160, 3840},
    {240, 1080, 1920},
    {60, 768, 1366},
    {165, 1440, 2560},
    {90, 1200, 1920}
  };

  // Call the function to test
  dump_graphics(graphics_array);

  return MUNIT_OK;
}

// Array of test cases
static MunitTest tests[] = {
  { "/test_dump_graphics", test_dump_graphics, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// Define the test suite
static const MunitSuite suite = {
  "/graphics_tests",    // Name of the suite
  tests,                // Array of test cases
  NULL,                 // No sub-suites
  1,                    // Number of iterations
  MUNIT_SUITE_OPTION_NONE
};

// Main function
int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  return munit_suite_main(&suite, NULL, argc, argv);
}

