#include <stdlib.h>
#include "munit.h"
#include "snekobject.h"

static MunitResult test_positive(const MunitParameter params[], void *user_data) {
  snek_object_t *obj = new_snek_float(42.0);
  munit_assert_double(obj->data.v_float, ==, 42.0);
  
  free(obj);
  // munit_assert_true(boot_all_freed());
  
  return MUNIT_OK;
}

static MunitResult test_zero(const MunitParameter params[], void *user_data) {
  snek_object_t *obj = new_snek_float(0.0);

  munit_assert_int(obj->kind, ==, FLOAT);
  munit_assert_double(obj->data.v_float, ==, 0.0);
  
  free(obj);
  // munit_assert_true(boot_all_freed());
  
  return MUNIT_OK;
}

static MunitResult test_negative(const MunitParameter params[], void *user_data) {
  snek_object_t *obj = new_snek_float(-5.0);

  munit_assert_int(obj->kind, ==, FLOAT);
  munit_assert_double(obj->data.v_float, ==, -5.0);
  
  free(obj);
  // munit_assert_true(boot_all_freed());
  
  return MUNIT_OK;
}

static MunitTest tests[] = {
  { "/positive", test_positive, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/zero", test_zero, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/negative", test_negative, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
  "object-float", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char *argv[]) {
  return munit_suite_main(&suite, NULL, argc, argv);
}

