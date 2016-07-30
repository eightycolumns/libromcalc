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

TCase *addition(void) {
  TCase *addition = tcase_create("Addition");

  tcase_add_test(addition, I_plus_I_is_II);
  tcase_add_test(addition, II_plus_II_is_IV);

  return addition;
}
