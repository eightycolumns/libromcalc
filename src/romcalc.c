#include "src/romcalc.h"

#include <assert.h>
#include <ctype.h>
#include <regex.h>
#include <stdbool.h>
#include <string.h>

static bool is_roman_numeral(const char *string);
static bool is_empty_string(const char *string);
static bool is_mixed_case(const char *string);
static bool includes_lowercase(const char *string);
static bool includes_uppercase(const char *string);

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

  if (is_empty_string(string)) {
    return false;
  }

  if (is_mixed_case(string)) {
    return false;
  }

  regex_t regex;

  char pattern[] = "^M{0,3}(D?C{0,3}|C[DM])(L?X{0,3}|X[LC])(V?I{0,3}|I[VX])$";

  int flags = REG_EXTENDED|REG_ICASE|REG_NOSUB;

  if (regcomp(&regex, pattern, flags) != 0) {
    return false;
  }

  bool result = (regexec(&regex, string, 0, NULL, 0) == 0);

  regfree(&regex);

  return result;
}

static bool is_empty_string(const char *string) {
  assert(string != NULL);
  return strcmp("", string) == 0;
}

static bool is_mixed_case(const char *string) {
  assert(string != NULL);
  return includes_lowercase(string) && includes_uppercase(string);
}

static bool includes_lowercase(const char *string) {
  assert(string != NULL);

  for (size_t i = 0; i < strlen(string); i += 1) {
    if (islower(string[i])) {
      return true;
    }
  }

  return false;
}

static bool includes_uppercase(const char *string) {
  assert(string != NULL);

  for (size_t i = 0; i < strlen(string); i += 1) {
    if (isupper(string[i])) {
      return true;
    }
  }

  return false;
}
