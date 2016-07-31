#include "test/null-pointer-error.h"

#include <string.h>

#include <check.h>

#include "src/romcalc.h"

static char sum[ROMCALC_MAX_LENGTH];
static char difference[ROMCALC_MAX_LENGTH];

static void setup(void) {
  strcpy(sum, "");
  strcpy(difference, "");
}

START_TEST(sum_cannot_be_NULL) {
  int expected = ROMCALC_NULL_POINTER_ERROR;
  int actual = add(NULL, "I", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(augend_cannot_be_NULL) {
  int expected = ROMCALC_NULL_POINTER_ERROR;
  int actual = add(sum, NULL, "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(addend_cannot_be_NULL) {
  int expected = ROMCALC_NULL_POINTER_ERROR;
  int actual = add(sum, "I", NULL);
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(difference_cannot_be_NULL) {
  int expected = ROMCALC_NULL_POINTER_ERROR;
  int actual = subtract(NULL, "II", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(minuend_cannot_be_NULL) {
  int expected = ROMCALC_NULL_POINTER_ERROR;
  int actual = subtract(difference, NULL, "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(subtrahend_cannot_be_NULL) {
  int expected = ROMCALC_NULL_POINTER_ERROR;
  int actual = subtract(difference, "II", NULL);
  ck_assert_int_eq(expected, actual);
} END_TEST

TCase *null_pointer_error(void) {
  TCase *null_pointer_error = tcase_create("Null Pointer Error");
  tcase_add_checked_fixture(null_pointer_error, setup, NULL);

  tcase_add_test(null_pointer_error, sum_cannot_be_NULL);
  tcase_add_test(null_pointer_error, augend_cannot_be_NULL);
  tcase_add_test(null_pointer_error, addend_cannot_be_NULL);

  tcase_add_test(null_pointer_error, difference_cannot_be_NULL);
  tcase_add_test(null_pointer_error, minuend_cannot_be_NULL);
  tcase_add_test(null_pointer_error, subtrahend_cannot_be_NULL);

  return null_pointer_error;
}
