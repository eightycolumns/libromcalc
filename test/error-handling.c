#include "test/error-handling.h"

#include <check.h>

#include "test/success.h"
#include "test/null-pointer-error.h"
#include "test/invalid-operand-error.h"

Suite *error_handling(void) {
  Suite *error_handling = suite_create("Error Handling");

  suite_add_tcase(error_handling, success());
  suite_add_tcase(error_handling, null_pointer_error());
  suite_add_tcase(error_handling, invalid_operand_error());

  return error_handling;
}
