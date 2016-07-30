#include "src/romcalc.h"

#include <stddef.h>

int add(char *sum, const char *augend, const char *addend) {
  if (sum == NULL || augend == NULL || addend == NULL) {
    return ROMCALC_NULL_POINTER_ERROR;
  }

  return ROMCALC_SUCCESS;
}

int subtract(char *difference, const char *minuend, const char *subtrahend) {
  // Temporarily suppress "unused parameter" warnings
  (void)subtrahend;

  if (difference == NULL || minuend == NULL) {
    return ROMCALC_NULL_POINTER_ERROR;
  }

  return ROMCALC_SUCCESS;
}
