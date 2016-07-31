#include "src/numeral-validation.h"

#include <assert.h>
#include <ctype.h>
#include <regex.h>
#include <stdbool.h>
#include <string.h>

static bool is_empty_string(const char *string);
static bool is_mixed_case(const char *string);
static bool includes_lowercase(const char *string);
static bool includes_uppercase(const char *string);

bool is_roman_numeral(const char *string) {
  assert(string != NULL);

  if (is_empty_string(string)) {
    return false;
  }

  if (is_mixed_case(string)) {
    return false;
  }

  regex_t regex;

  char pattern[] =
    "^M{0,3}"           // Thousands
    "(D?C{0,3}|C[DM])"  // Hundreds
    "(L?X{0,3}|X[LC])"  // Tens
    "(V?I{0,3}|I[VX])$" // Ones
  ;

  int flags = REG_EXTENDED|REG_ICASE|REG_NOSUB;

  if (regcomp(&regex, pattern, flags) != 0) {
    return false;
  }

  bool result = (regexec(&regex, string, 0, NULL, 0) == 0);

  regfree(&regex);

  return result;
}

bool is_in_range(int arabic_numeral) {
  return arabic_numeral > 0 && arabic_numeral < 4000;
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

  size_t string_length = strlen(string);

  for (size_t i = 0; i < string_length; i += 1) {
    if (islower(string[i])) {
      return true;
    }
  }

  return false;
}

static bool includes_uppercase(const char *string) {
  assert(string != NULL);

  size_t string_length = strlen(string);

  for (size_t i = 0; i < string_length; i += 1) {
    if (isupper(string[i])) {
      return true;
    }
  }

  return false;
}
