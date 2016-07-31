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

TCase *subtraction(void) {
  TCase *subtraction = tcase_create("Subtraction");

  tcase_add_test(subtraction, MMMCMXCIX_minus_CXI_is_MMMDCCCLXXXVIII);
  tcase_add_test(subtraction, MMMDCCCLXXXVIII_minus_MDCCCLXXXVIII_is_MM);
  tcase_add_test(subtraction, MM_minus_M_is_M);

  return subtraction;
}
