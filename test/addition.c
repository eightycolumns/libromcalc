#include "test/addition.h"

#include <stdlib.h>

#include <check.h>

#include "src/romcalc.h"

static char actual[ROMCALC_MAX_LENGTH];

START_TEST(I_plus_I_is_II) {
  char expected[] = "II";
  add(actual, "I", "I");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(II_plus_II_is_IV) {
  char expected[] = "IV";
  add(actual, "II", "II");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(IV_plus_I_is_V) {
  char expected[] = "V";
  add(actual, "IV", "I");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(V_plus_IV_is_IX) {
  char expected[] = "IX";
  add(actual, "V", "IV");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(IX_plus_I_is_X) {
  char expected[] = "X";
  add(actual, "IX", "I");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(X_plus_X_is_XX) {
  char expected[] = "XX";
  add(actual, "X", "X");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(XX_plus_XX_is_XL) {
  char expected[] = "XL";
  add(actual, "XX", "XX");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(XL_plus_X_is_L) {
  char expected[] = "L";
  add(actual, "XL", "X");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(L_plus_XL_is_XC) {
  char expected[] = "XC";
  add(actual, "L", "XL");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(XC_plus_X_is_C) {
  char expected[] = "C";
  add(actual, "XC", "X");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(C_plus_C_is_CC) {
  char expected[] = "CC";
  add(actual, "C", "C");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(CC_plus_CC_is_CD) {
  char expected[] = "CD";
  add(actual, "CC", "CC");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(CD_plus_C_is_D) {
  char expected[] = "D";
  add(actual, "CD", "C");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(D_plus_CD_is_CM) {
  char expected[] = "CM";
  add(actual, "D", "CD");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(CM_plus_C_is_M) {
  char expected[] = "M";
  add(actual, "CM", "C");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(M_plus_M_is_MM) {
  char expected[] = "MM";
  add(actual, "M", "M");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(MM_plus_MDCCCLXXXVIII_is_MMMDCCCLXXXVIII) {
  char expected[] = "MMMDCCCLXXXVIII";
  add(actual, "MM", "MDCCCLXXXVIII");
  ck_assert_str_eq(expected, actual);
} END_TEST

TCase *addition(void) {
  TCase *addition = tcase_create("Addition");

  tcase_add_test(addition, I_plus_I_is_II);
  tcase_add_test(addition, II_plus_II_is_IV);
  tcase_add_test(addition, IV_plus_I_is_V);
  tcase_add_test(addition, V_plus_IV_is_IX);
  tcase_add_test(addition, IX_plus_I_is_X);

  tcase_add_test(addition, X_plus_X_is_XX);
  tcase_add_test(addition, XX_plus_XX_is_XL);
  tcase_add_test(addition, XL_plus_X_is_L);
  tcase_add_test(addition, L_plus_XL_is_XC);
  tcase_add_test(addition, XC_plus_X_is_C);

  tcase_add_test(addition, C_plus_C_is_CC);
  tcase_add_test(addition, CC_plus_CC_is_CD);
  tcase_add_test(addition, CD_plus_C_is_D);
  tcase_add_test(addition, D_plus_CD_is_CM);
  tcase_add_test(addition, CM_plus_C_is_M);

  tcase_add_test(addition, M_plus_M_is_MM);
  tcase_add_test(addition, MM_plus_MDCCCLXXXVIII_is_MMMDCCCLXXXVIII);

  return addition;
}
