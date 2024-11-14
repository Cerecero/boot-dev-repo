#include <stdlib.h>
#include "munit.h"
#include "snekobject.h"

static MunitResult
test_create_empty_array(const MunitParameter params[], void* user_data) {
  snek_object_t *obj = new_snek_array(2);

  munit_assert_int(obj->kind, ==, ARRAY);
  munit_assert_int(obj->data.v_array.size, ==, 2);

  free(obj->data.v_array.elements);
  free(obj);

  return MUNIT_OK;
}

static MunitResult
test_used_calloc(const MunitParameter params[], void* user_data) {
  snek_object_t *obj = new_snek_array(2);

  munit_assert_null(obj->data.v_array.elements[0]);
  munit_assert_null(obj->data.v_array.elements[1]);

  free(obj->data.v_array.elements);
  free(obj);

  return MUNIT_OK;
}

static MunitTest tests[] = {
  { "/empty", test_create_empty_array, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/calloc", test_used_calloc, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
  "object-array",  // Test suite name
  tests,           // Array of tests
  NULL,            // Sub-suites
  1,               // Number of iterations per test
  MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
  return munit_suite_main(&suite, NULL, argc, argv);
}

