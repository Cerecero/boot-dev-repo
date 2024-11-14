#include "munit.h"
#include <string.h>
#include "exercise.h"

static MunitResult test_new_node_simple(const MunitParameter params[], void* data) {
  snekobject_t node = new_node("root");
  munit_assert_string_equal(node.name, "root");
  munit_assert_null(node.child);
  return MUNIT_OK;
}

static MunitResult test_new_node_empty_name(const MunitParameter params[], void* data) {
  snekobject_t node = new_node("");
  munit_assert_string_equal(node.name, "");
  munit_assert_null(node.child);
  return MUNIT_OK;
}

static MunitResult test_new_node_with_child(const MunitParameter params[], void* data) {
  snekobject_t child = new_node("child");
  snekobject_t parent = new_node("parent");
  parent.child = &child;

  munit_assert_string_equal(parent.name, "parent");
  munit_assert_not_null(parent.child);
  munit_assert_string_equal(parent.child->name, "child");
  munit_assert_null(parent.child->child);
  return MUNIT_OK;
}

static MunitResult test_new_node_nested_children(const MunitParameter params[], void* data) {
  snekobject_t grandchild = new_node("grandchild");
  snekobject_t child = new_node("child");
  snekobject_t parent = new_node("parent");

  child.child = &grandchild;
  parent.child = &child;

  munit_assert_string_equal(parent.name, "parent");
  munit_assert_not_null(parent.child);
  munit_assert_string_equal(parent.child->name, "child");
  munit_assert_not_null(parent.child->child);
  munit_assert_string_equal(parent.child->child->name, "grandchild");
  munit_assert_null(parent.child->child->child);
  return MUNIT_OK;
}

static MunitTest tests[] = {
  { "/test_new_node_simple", test_new_node_simple, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/test_new_node_empty_name", test_new_node_empty_name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/test_new_node_with_child", test_new_node_with_child, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/test_new_node_nested_children", test_new_node_nested_children, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
  "/new_node_tests",
  tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
  return munit_suite_main(&suite, NULL, argc, argv);
}

