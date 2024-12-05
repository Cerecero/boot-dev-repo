#include "bootlib.h"
#include "munit.h"
#include "exercise.h"
#include <stdint.h>

typedef struct CoffeeShop {
  uint64_t quality;
  uint64_t taste;
  uint64_t branding;
} coffee_shop_t;

static MunitResult test_generic_ints(const MunitParameter params[], void *data) {
  int i1 = 1234;
  int i2 = 5678;

  swap(&i1, &i2, sizeof(int));

  munit_assert_int(i1, ==, 5678);
  munit_assert_int(i2, ==, 1234);
  munit_assert_true(boot_all_freed());

  return MUNIT_OK;
}

static MunitResult test_generic_strings(const MunitParameter params[], void *data) {
  char *s1 = "dax";
  char *s2 = "adam";

  swap(&s1, &s2, sizeof(char *));
  munit_assert_string_equal(s1, "adam");
  munit_assert_string_equal(s2, "dax");
  munit_assert_true(boot_all_freed());

  return MUNIT_OK;
}

static MunitResult test_generic_structs(const MunitParameter params[], void *data) {
  coffee_shop_t sbucks = {2, 3, 4};
  coffee_shop_t terminalshop = {10, 10, 10};

  swap(&sbucks, &terminalshop, sizeof(coffee_shop_t));

  munit_assert_uint64(sbucks.quality, ==, 10);
  munit_assert_uint64(sbucks.taste, ==, 10);
  munit_assert_uint64(sbucks.branding, ==, 10);

  munit_assert_uint64(terminalshop.quality, ==, 2);
  munit_assert_uint64(terminalshop.taste, ==, 3);
  munit_assert_uint64(terminalshop.branding, ==, 4);

  return MUNIT_OK;
}

int main(int argc, char* argv[]) {
  MunitTest tests[] = {
    { "/generic_ints", test_generic_ints, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/generic_strings", test_generic_strings, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/generic_structs", test_generic_structs, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
  };

  MunitSuite suite = {
    "/swap", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
  };

  return munit_suite_main(&suite, NULL, argc, argv);
}
