#include <stdlib.h>
#include <string.h>
#include "munit.h"
#include "exercise.h"

// Test case for single token
static MunitResult test_create_token_pointer_array_single(const MunitParameter params[], void* data) {
  token_t token = {"hello", 1, 1};
  token_t** result = create_token_pointer_array(&token, 1);

  munit_assert_not_null(result);
  munit_assert_not_null(result[0]);
  munit_assert_string_equal(result[0]->literal, "hello");
  munit_assert_int(result[0]->line, ==, 1);
  munit_assert_int(result[0]->column, ==, 1);
  munit_assert_ptr_not_equal(result[0], &token);

  free(result[0]);
  free(result);
  return MUNIT_OK;
}

// Test case for multiple tokens
static MunitResult test_create_token_pointer_array_multiple(const MunitParameter params[], void* data) {
  token_t tokens[3] = {
    {"foo", 1, 1},
    {"bar", 2, 5},
    {"baz", 3, 10}
  };
  token_t** result = create_token_pointer_array(tokens, 3);

  munit_assert_not_null(result);
  for (int i = 0; i < 3; i++) {
    munit_assert_not_null(result[i]);
    munit_assert_string_equal(result[i]->literal, tokens[i].literal);
    munit_assert_int(result[i]->line, ==, tokens[i].line);
    munit_assert_int(result[i]->column, ==, tokens[i].column);
    munit_assert_ptr_not_equal(result[i], &tokens[i]);
  }

  for (int i = 0; i < 3; i++) {
    free(result[i]);
  }
  free(result);
  return MUNIT_OK;
}

// Test case for memory allocation
static MunitResult test_create_token_pointer_array_memory_allocation(const MunitParameter params[], void* data) {
  token_t tokens[2] = {
    {"test1", 1, 1},
    {"test2", 2, 2}
  };
  token_t** result = create_token_pointer_array(tokens, 2);

  munit_assert_not_null(result);
  munit_assert_not_null(result[0]);
  munit_assert_not_null(result[1]);
  munit_assert_ptr_not_equal(result[0], result[1]);
  munit_assert_ptr_not_equal(result[0], &tokens[0]);
  munit_assert_ptr_not_equal(result[1], &tokens[1]);

  free(result[0]);
  free(result[1]);
  free(result);
  return MUNIT_OK;
}

// Registering test cases
static MunitTest tests[] = {
  { "/test_create_token_pointer_array_single", test_create_token_pointer_array_single, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/test_create_token_pointer_array_multiple", test_create_token_pointer_array_multiple, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/test_create_token_pointer_array_memory_allocation", test_create_token_pointer_array_memory_allocation, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// Defining the test suite
static const MunitSuite suite = {
  "/create_token_pointer_array", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

// Main function to run the test suite
int main(int argc, char* argv[]) {
  return munit_suite_main(&suite, NULL, argc, argv);
}
