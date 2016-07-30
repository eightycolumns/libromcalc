#include "test/invalid-operand-error.h"

#include <stdlib.h>

#include <check.h>

#include "src/romcalc.h"

static char sum[ROMCALC_MAX_LENGTH];

START_TEST(IIII_is_an_invalid_operand) {
  int expected = ROMCALC_INVALID_OPERAND_ERROR;
  int actual = add(sum, "IIII", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(VV_is_an_invalid_operand) {
  int expected = ROMCALC_INVALID_OPERAND_ERROR;
  int actual = add(sum, "VV", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

TCase *invalid_operand_error(void) {
  TCase *invalid_operand_error = tcase_create("Invalid Operand Error");

  tcase_add_test(invalid_operand_error, IIII_is_an_invalid_operand);
  tcase_add_test(invalid_operand_error, VV_is_an_invalid_operand);

  return invalid_operand_error;
}
