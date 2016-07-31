#include "test/invalid-result-error.h"

#include <check.h>

#include "src/romcalc.h"

static char sum[ROMCALC_MAX_LENGTH];
static char difference[ROMCALC_MAX_LENGTH];

START_TEST(MMMCMXCIX_plus_I_is_an_invalid_result) {
  int expected = ROMCALC_INVALID_RESULT_ERROR;
  int actual = add(sum, "MMMCMXCIX", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(I_minus_I_is_an_invalid_result) {
  int expected = ROMCALC_INVALID_RESULT_ERROR;
  int actual = subtract(difference, "I", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

TCase *invalid_result_error(void) {
  TCase *invalid_result_error = tcase_create("Invalid Result Error");

  tcase_add_test(invalid_result_error, MMMCMXCIX_plus_I_is_an_invalid_result);
  tcase_add_test(invalid_result_error, I_minus_I_is_an_invalid_result);

  return invalid_result_error;
}
