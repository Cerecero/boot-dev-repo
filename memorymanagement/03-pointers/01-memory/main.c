#include "munit.h"
#include "snek.h"

/* Test function for size_of_addr with input 16 */
static MunitResult test_size_of_addr_16(const MunitParameter params[], void* data) {
  unsigned long size = size_of_addr(16);
  munit_assert_ulong(size, ==, 8);
  return MUNIT_OK;
}

/* Test function for size_of_addr with input 32 */
static MunitResult test_size_of_addr_32(const MunitParameter params[], void* data) {
  unsigned long size = size_of_addr(32);
  munit_assert_ulong(size, ==, 8);
  return MUNIT_OK;
}

/* Test function for size_of_addr with input 64 */
static MunitResult test_size_of_addr_64(const MunitParameter params[], void* data) {
  unsigned long size = size_of_addr(64);
  munit_assert_ulong(size, ==, 8);
  return MUNIT_OK;
}

/* Test function for size_of_addr with input 128 */
static MunitResult test_size_of_addr_128(const MunitParameter params[], void* data) {
  unsigned long size = size_of_addr(128);
  munit_assert_ulong(size, ==, 8);
  return MUNIT_OK;
}

/* Array of tests */
static MunitTest tests[] = {
  { "/size_of_addr_16", test_size_of_addr_16, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/size_of_addr_32", test_size_of_addr_32, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/size_of_addr_64", test_size_of_addr_64, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/size_of_addr_128", test_size_of_addr_128, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }  // end of tests array
};

/* Suite */
static const MunitSuite suite = {
  "/snek_suite",   /* suite name */
  tests,           /* test array */
  NULL,            /* no sub-suites */
  1,               /* number of iterations */
  MUNIT_SUITE_OPTION_NONE
};

/* Main function to run the test suite */
int main(int argc, char* argv[]) {
  return munit_suite_main(&suite, NULL, argc, argv);
}

