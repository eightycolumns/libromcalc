#include "src/romcalc.h"

#include <assert.h>
#include <regex.h>
#include <stdbool.h>
#include <stddef.h>

static bool is_roman_numeral(const char *string);

int add(char *sum, const char *augend, const char *addend) {
  if (sum == NULL || augend == NULL || addend == NULL) {
    return ROMCALC_NULL_POINTER_ERROR;
  }

  if (!is_roman_numeral(augend) || !is_roman_numeral(addend)) {
    return ROMCALC_INVALID_OPERAND_ERROR;
  }

  return ROMCALC_SUCCESS;
}

int subtract(char *difference, const char *minuend, const char *subtrahend) {
  if (difference == NULL || minuend == NULL || subtrahend == NULL) {
    return ROMCALC_NULL_POINTER_ERROR;
  }

  if (!is_roman_numeral(minuend) || !is_roman_numeral(subtrahend)) {
    return ROMCALC_INVALID_OPERAND_ERROR;
  }

  return ROMCALC_SUCCESS;
}

static bool is_roman_numeral(const char *string) {
  assert(string != NULL);

  regex_t regex;

  char pattern[] = "^(C{0,3}|CD)(L?X{0,3}|X[LC])(V?I{0,3}|I[VX])$";

  int flags = REG_EXTENDED|REG_NOSUB;

  if (regcomp(&regex, pattern, flags) != 0) {
    return false;
  }

  bool result = (regexec(&regex, string, 0, NULL, 0) == 0);

  regfree(&regex);

  return result;
}
