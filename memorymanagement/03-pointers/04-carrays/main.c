#include "munit.h"
#include "exercise.h"

// Test case for basic file update
static MunitResult test_update_file_basic(const MunitParameter params[], void* user_data) {
  int filedata[200] = {0};
  update_file(filedata, 1, 100);
  
  munit_assert_int(filedata[1], ==, 100);  // Check if lines are updated to 100
  munit_assert_int(filedata[2], ==, 1);    // Check if file type is updated to 1
  munit_assert_int(filedata[199], ==, 0);  // Check if last element is 0

  return MUNIT_OK;
}

// Test case for file update with different values
static MunitResult test_update_file_different_values(const MunitParameter params[], void* user_data) {
  int filedata[200] = {0};
  
  for (int i = 0; i < 200; i++) {
    filedata[i] = 69;  // Initialize with a default value
  }
  
  update_file(filedata, 3, 250);
  
  munit_assert_int(filedata[1], ==, 250);  // Check if lines are updated to 250
  munit_assert_int(filedata[2], ==, 3);    // Check if file type is updated to 3
  munit_assert_int(filedata[199], ==, 0);  // Check if last element is 0

  return MUNIT_OK;
}

// Array of test cases
static MunitTest tests[] = {
  { "/test_update_file_basic", test_update_file_basic, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/test_update_file_different_values", test_update_file_different_values, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// Test suite for the update_file function
static const MunitSuite suite = {
  "update_file",  // Suite name
  tests,          // Array of test cases
  NULL,           // No child suites
  1,              // Iterations
  MUNIT_SUITE_OPTION_NONE
};

// Main function to run the test suite
int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  return munit_suite_main(&suite, NULL, argc, argv);
}
