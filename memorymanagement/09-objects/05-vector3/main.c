#include <stdlib.h>
#include "munit.h"
#include "snekobject.h"

static MunitResult
test_returns_null(const MunitParameter params[], void* user_data) {
  snek_object_t *vec = new_snek_vector3(NULL, NULL, NULL);

  munit_assert_null(vec);


  return MUNIT_OK;
}

static MunitResult
test_vec_multiple_objects(const MunitParameter params[], void* user_data) {
  snek_object_t *x = new_snek_integer(1);
  snek_object_t *y = new_snek_integer(2);
  snek_object_t *z = new_snek_integer(3);
  snek_object_t *vec = new_snek_vector3(x, y, z);

  munit_assert_not_null(vec);

  // Ensure vector references the original objects.
  munit_assert_ptr_equal(x, vec->data.v_vector3.x);
  munit_assert_ptr_equal(y, vec->data.v_vector3.y);
  munit_assert_ptr_equal(z, vec->data.v_vector3.z);

  // Verify integer values in vector.
  munit_assert_int(vec->data.v_vector3.x->data.v_int, ==, 1);
  munit_assert_int(vec->data.v_vector3.y->data.v_int, ==, 2);
  munit_assert_int(vec->data.v_vector3.z->data.v_int, ==, 3);

  // Free allocated memory.
  free(x);
  free(y);
  free(z);
  free(vec);
  

  return MUNIT_OK;
}

static MunitResult
test_vec_same_object(const MunitParameter params[], void* user_data) {
  snek_object_t *i = new_snek_integer(1);
  snek_object_t *vec = new_snek_vector3(i, i, i);

  munit_assert_not_null(vec);

  // Ensure vector references the same object for all coordinates.
  munit_assert_ptr_equal(i, vec->data.v_vector3.x);
  munit_assert_ptr_equal(i, vec->data.v_vector3.y);
  munit_assert_ptr_equal(i, vec->data.v_vector3.z);

  // Check initial integer value.
  munit_assert_int(vec->data.v_vector3.x->data.v_int, ==, 1);
  munit_assert_int(vec->data.v_vector3.y->data.v_int, ==, 1);
  munit_assert_int(vec->data.v_vector3.z->data.v_int, ==, 1);

  // Update the value and confirm all references update accordingly.
  i->data.v_int = 2;
  munit_assert_int(vec->data.v_vector3.x->data.v_int, ==, 2);
  munit_assert_int(vec->data.v_vector3.y->data.v_int, ==, 2);
  munit_assert_int(vec->data.v_vector3.z->data.v_int, ==, 2);

  // Free allocated memory.
  free(i);
  free(vec);


  return MUNIT_OK;
}

static MunitTest tests[] = {
  { "/returns_null", test_returns_null, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/multiple_objects", test_vec_multiple_objects, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/same_object", test_vec_same_object, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
  "object-vector",   // Test suite name
  tests,             // Array of tests
  NULL,              // Sub-suites
  1,                 // Number of iterations per test
  MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
  return munit_suite_main(&suite, NULL, argc, argv);
}

