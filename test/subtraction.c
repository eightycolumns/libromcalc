#include "test/subtraction.h"

#include <stdlib.h>

#include <check.h>

#include "src/romcalc.h"

static char actual[ROMCALC_MAX_LENGTH];

START_TEST(MMMCMXCIX_minus_CXI_is_MMMDCCCLXXXVIII) {
  char expected[] = "MMMDCCCLXXXVIII";
  subtract(actual, "MMMCMXCIX", "CXI");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(MMMDCCCLXXXVIII_minus_MDCCCLXXXVIII_is_MM) {
  char expected[] = "MM";
  subtract(actual, "MMMDCCCLXXXVIII", "MDCCCLXXXVIII");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(MM_minus_M_is_M) {
  char expected[] = "M";
  subtract(actual, "MM", "M");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(M_minus_C_is_CM) {
  char expected[] = "CM";
  subtract(actual, "M", "C");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(CM_minus_CD_is_D) {
  char expected[] = "D";
  subtract(actual, "CM", "CD");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(D_minus_C_is_CD) {
  char expected[] = "CD";
  subtract(actual, "D", "C");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(CD_minus_CC_is_CC) {
  char expected[] = "CC";
  subtract(actual, "CD", "CC");
  ck_assert_str_eq(expected, actual);
} END_TEST

TCase *subtraction(void) {
  TCase *subtraction = tcase_create("Subtraction");

  tcase_add_test(subtraction, MMMCMXCIX_minus_CXI_is_MMMDCCCLXXXVIII);
  tcase_add_test(subtraction, MMMDCCCLXXXVIII_minus_MDCCCLXXXVIII_is_MM);
  tcase_add_test(subtraction, MM_minus_M_is_M);

  tcase_add_test(subtraction, M_minus_C_is_CM);
  tcase_add_test(subtraction, CM_minus_CD_is_D);
  tcase_add_test(subtraction, D_minus_C_is_CD);
  tcase_add_test(subtraction, CD_minus_CC_is_CC);

  return subtraction;
}
