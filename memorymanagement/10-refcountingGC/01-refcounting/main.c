#include <stdio.h>
#include <stdlib.h>

#include "bootlib.h"
#include "munit.h"
#include "snekobject.h"

// Test case for integer refcount
static MunitResult
test_int_has_refcount(const MunitParameter params[], void* data) {
  snek_object_t *obj = new_snek_integer(10);
  munit_assert_int(obj->refcount, ==, 1);
  free(obj);
  return MUNIT_OK;
}

// Test case for float refcount
static MunitResult
test_float_has_refcount(const MunitParameter params[], void* data) {
  snek_object_t *obj = new_snek_float(42.0);
  munit_assert_int(obj->refcount, ==, 1);
  free(obj);
  return MUNIT_OK;
}

// Test cases array
static MunitTest tests[] = {
  {
    (char*) "test_int_has_refcount",
    test_int_has_refcount,
    NULL,
    NULL,
    MUNIT_TEST_OPTION_NONE,
    NULL
  },
  {
    (char*) "test_float_has_refcount",
    test_float_has_refcount,
    NULL,
    NULL,
    MUNIT_TEST_OPTION_NONE,
    NULL
  },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// Test suite
static const MunitSuite suite = {
  (char*) "refcount",
  tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
  return munit_suite_main(&suite, NULL, argc, argv);
}

