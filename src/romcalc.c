#include "src/romcalc.h"

#include <stddef.h>

int add(char *sum, const char *augend, const char *addend) {
  // Temporarily suppress "unused parameter" warnings
  (void)addend;

  if (sum == NULL || augend == NULL) {
    return ROMCALC_NULL_POINTER_ERROR;
  }

  return ROMCALC_SUCCESS;
}
