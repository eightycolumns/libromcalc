#include "test/success.h"

#include <stdlib.h>

#include <check.h>

#include "src/romcalc.h"

static char sum[ROMCALC_MAX_LENGTH];

START_TEST(I_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "I", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(III_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "III", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

TCase *success(void) {
  TCase *success = tcase_create("Success");

  tcase_add_test(success, I_is_a_valid_operand);
  tcase_add_test(success, III_is_a_valid_operand);

  return success;
}
