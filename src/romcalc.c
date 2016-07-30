#include "src/romcalc.h"

#include <stddef.h>

#include "src/numeral-validation.h"

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
