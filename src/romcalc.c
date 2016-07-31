#include "src/romcalc.h"

#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#include "src/numeral-validation.h"

typedef struct {
  char *key;
  int value;
} Numeral;

static Numeral numerals[] = {
  {"M", 1000}, {"CM", 900},
  {"D",  500}, {"CD", 400},
  {"C",  100}, {"XC",  90},
  {"L",   50}, {"XL",  40},
  {"X",   10}, {"IX",   9},
  {"V",    5}, {"IV",   4},
  {"I",    1}
};

static size_t numeral_count = sizeof numerals / sizeof numerals[0];

static int roman_to_arabic(const char *roman);
static char *substring(char *dest, const char *src, size_t n);
static char *to_uppercase(char *string);
static bool numerals_array_includes(const char *key);
static char *arabic_to_roman(char *roman, int arabic);

int add(char *sum, const char *augend, const char *addend) {
  if (sum == NULL || augend == NULL || addend == NULL) {
    return ROMCALC_NULL_POINTER_ERROR;
  }

  if (!is_roman_numeral(augend) || !is_roman_numeral(addend)) {
    return ROMCALC_INVALID_OPERAND_ERROR;
  }

  int result = roman_to_arabic(augend) + roman_to_arabic(addend);

  arabic_to_roman(sum, result);

  return ROMCALC_SUCCESS;
}

int subtract(char *difference, const char *minuend, const char *subtrahend) {
  if (difference == NULL || minuend == NULL || subtrahend == NULL) {
    return ROMCALC_NULL_POINTER_ERROR;
  }

  if (!is_roman_numeral(minuend) || !is_roman_numeral(subtrahend)) {
    return ROMCALC_INVALID_OPERAND_ERROR;
  }

  int result = roman_to_arabic(minuend) - roman_to_arabic(subtrahend);

  arabic_to_roman(difference, result);

  return ROMCALC_SUCCESS;
}

static int roman_to_arabic(const char *roman) {
  assert(roman != NULL);
  assert(is_roman_numeral(roman));

  int arabic = 0;

  size_t i = 0;
  size_t roman_length = strlen(roman);

  while (i < roman_length) {
    char two_char_substring[3];
    substring(two_char_substring, &roman[i], 2);
    to_uppercase(two_char_substring);

    char one_char_substring[2];
    substring(one_char_substring, &roman[i], 1);
    to_uppercase(one_char_substring);

    if (numerals_array_includes(two_char_substring)) {
      for (size_t k = 0; k < numeral_count; k += 1) {
        if (strcmp(two_char_substring, numerals[k].key) == 0) {
          arabic += numerals[k].value;
        }
      }

      i += 2;
    } else {
      for (size_t k = 0; k < numeral_count; k += 1) {
        if (strcmp(one_char_substring, numerals[k].key) == 0) {
          arabic += numerals[k].value;
        }
      }

      i += 1;
    }
  }

  return arabic;
}

static char *substring(char *dest, const char *src, size_t n) {
  assert(dest != NULL);
  assert(src != NULL);

  strncpy(dest, src, n);
  dest[n] = '\0';

  return dest;
}

static char *to_uppercase(char *string) {
  assert(string != NULL);

  size_t i = 0;

  while ((string[i] = toupper(string[i])) != '\0') {
    i += 1;
  }

  return string;
}

static bool numerals_array_includes(const char *key) {
  assert(key != NULL);

  for (size_t i = 0; i < numeral_count; i += 1) {
    if (strcmp(key, numerals[i].key) == 0) {
      return true;
    }
  }

  return false;
}

static char *arabic_to_roman(char *roman, int arabic) {
  assert(roman != NULL);

  strcpy(roman, "");

  for (size_t i = 0; i < numeral_count; i += 1) {
    while (arabic >= numerals[i].value) {
      strcat(roman, numerals[i].key);
      arabic -= numerals[i].value;
    }
  }

  return roman;
}
