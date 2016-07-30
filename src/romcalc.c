#include "src/romcalc.h"

#include <assert.h>
#include <string.h>

#include "src/numeral-validation.h"

typedef struct {
  char *key;
  int value;
} Numeral;

static Numeral numerals[] = {
  {"IV", 4},
  {"I", 1}
};

static size_t numeral_count = sizeof numerals / sizeof numerals[0];

static int roman_to_arabic(const char *roman);
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

  return ROMCALC_SUCCESS;
}

static int roman_to_arabic(const char *roman) {
  assert(roman != NULL);
  assert(is_roman_numeral(roman));

  int arabic = 0;

  for (size_t i = 0; i < strlen(roman); i += 1) {
    char one_char_substring[2];
    strncpy(one_char_substring, &roman[i], 1);
    one_char_substring[1] = '\0';

    for (size_t j = 0; j < numeral_count; j += 1) {
      if (strcmp(one_char_substring, numerals[j].key) == 0) {
        arabic += numerals[j].value;
      }
    }
  }

  return arabic;
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
