#include "test/operations.h"

#include <check.h>

#include "test/addition.h"
#include "test/subtraction.h"

Suite *operations(void) {
  Suite *operations = suite_create("Operations");

  suite_add_tcase(operations, addition());
  suite_add_tcase(operations, subtraction());

  return operations;
}
