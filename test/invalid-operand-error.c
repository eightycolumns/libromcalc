#include "test/invalid-operand-error.h"

#include <stdlib.h>

#include <check.h>

#include "src/romcalc.h"

static char sum[ROMCALC_MAX_LENGTH];

START_TEST(the_empty_string_is_an_invalid_operand) {
  int expected = ROMCALC_INVALID_OPERAND_ERROR;
  int actual = add(sum, "", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

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

START_TEST(IIV_is_an_invalid_operand) {
  int expected = ROMCALC_INVALID_OPERAND_ERROR;
  int actual = add(sum, "IIV", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(VX_is_an_invalid_operand) {
  int expected = ROMCALC_INVALID_OPERAND_ERROR;
  int actual = add(sum, "VX", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(XXXX_is_an_invalid_operand) {
  int expected = ROMCALC_INVALID_OPERAND_ERROR;
  int actual = add(sum, "XXXX", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(LL_is_an_invalid_operand) {
  int expected = ROMCALC_INVALID_OPERAND_ERROR;
  int actual = add(sum, "LL", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(XXL_is_an_invalid_operand) {
  int expected = ROMCALC_INVALID_OPERAND_ERROR;
  int actual = add(sum, "XXL", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(LC_is_an_invalid_operand) {
  int expected = ROMCALC_INVALID_OPERAND_ERROR;
  int actual = add(sum, "LC", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(CCCC_is_an_invalid_operand) {
  int expected = ROMCALC_INVALID_OPERAND_ERROR;
  int actual = add(sum, "CCCC", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(DD_is_an_invalid_operand) {
  int expected = ROMCALC_INVALID_OPERAND_ERROR;
  int actual = add(sum, "DD", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(CCD_is_an_invalid_operand) {
  int expected = ROMCALC_INVALID_OPERAND_ERROR;
  int actual = add(sum, "CCD", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(DM_is_an_invalid_operand) {
  int expected = ROMCALC_INVALID_OPERAND_ERROR;
  int actual = add(sum, "DM", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(MMMM_is_an_invalid_operand) {
  int expected = ROMCALC_INVALID_OPERAND_ERROR;
  int actual = add(sum, "MMMM", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(MmCcXxIi_is_an_invalid_operand) {
  int expected = ROMCALC_INVALID_OPERAND_ERROR;
  int actual = add(sum, "MmCcXxIi", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

TCase *invalid_operand_error(void) {
  TCase *invalid_operand_error = tcase_create("Invalid Operand Error");

  tcase_add_test(invalid_operand_error, the_empty_string_is_an_invalid_operand);

  tcase_add_test(invalid_operand_error, IIII_is_an_invalid_operand);
  tcase_add_test(invalid_operand_error, VV_is_an_invalid_operand);
  tcase_add_test(invalid_operand_error, IIV_is_an_invalid_operand);
  tcase_add_test(invalid_operand_error, VX_is_an_invalid_operand);

  tcase_add_test(invalid_operand_error, XXXX_is_an_invalid_operand);
  tcase_add_test(invalid_operand_error, LL_is_an_invalid_operand);
  tcase_add_test(invalid_operand_error, XXL_is_an_invalid_operand);
  tcase_add_test(invalid_operand_error, LC_is_an_invalid_operand);

  tcase_add_test(invalid_operand_error, CCCC_is_an_invalid_operand);
  tcase_add_test(invalid_operand_error, DD_is_an_invalid_operand);
  tcase_add_test(invalid_operand_error, CCD_is_an_invalid_operand);
  tcase_add_test(invalid_operand_error, DM_is_an_invalid_operand);

  tcase_add_test(invalid_operand_error, MMMM_is_an_invalid_operand);

  tcase_add_test(invalid_operand_error, MmCcXxIi_is_an_invalid_operand);

  return invalid_operand_error;
}
