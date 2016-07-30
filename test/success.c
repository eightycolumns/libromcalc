#include "test/success.h"

#include <stdlib.h>

#include <check.h>

#include "src/romcalc.h"

static char sum[ROMCALC_MAX_LENGTH];
static char difference[ROMCALC_MAX_LENGTH];

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

START_TEST(IV_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "IV", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(V_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "V", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(IX_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "IX", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(X_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "X", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(XXX_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "XXX", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(XL_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "XL", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(L_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "L", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(XC_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "XC", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(C_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "C", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(CCC_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "CCC", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(CD_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "CD", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(D_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "D", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(CM_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "CM", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(M_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "M", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(MMM_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "MMM", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(MMMDCCCLXXXVIII_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "MMMDCCCLXXXVIII", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(mmmdccclxxxviii_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "mmmdccclxxxviii", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(MMMCMXCIX_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = subtract(difference, "MMMCMXCIX", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(mmmcmxcix_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = subtract(difference, "mmmcmxcix", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

TCase *success(void) {
  TCase *success = tcase_create("Success");

  tcase_add_test(success, I_is_a_valid_operand);
  tcase_add_test(success, III_is_a_valid_operand);
  tcase_add_test(success, IV_is_a_valid_operand);
  tcase_add_test(success, V_is_a_valid_operand);
  tcase_add_test(success, IX_is_a_valid_operand);

  tcase_add_test(success, X_is_a_valid_operand);
  tcase_add_test(success, XXX_is_a_valid_operand);
  tcase_add_test(success, XL_is_a_valid_operand);
  tcase_add_test(success, L_is_a_valid_operand);
  tcase_add_test(success, XC_is_a_valid_operand);

  tcase_add_test(success, C_is_a_valid_operand);
  tcase_add_test(success, CCC_is_a_valid_operand);
  tcase_add_test(success, CD_is_a_valid_operand);
  tcase_add_test(success, D_is_a_valid_operand);
  tcase_add_test(success, CM_is_a_valid_operand);

  tcase_add_test(success, M_is_a_valid_operand);
  tcase_add_test(success, MMM_is_a_valid_operand);

  tcase_add_test(success, MMMDCCCLXXXVIII_is_a_valid_operand);
  tcase_add_test(success, mmmdccclxxxviii_is_a_valid_operand);

  tcase_add_test(success, MMMCMXCIX_is_a_valid_operand);
  tcase_add_test(success, mmmcmxcix_is_a_valid_operand);

  return success;
}
