#ifndef ROMCALC_H
#define ROMCALC_H

#define ROMCALC_MAX_LENGTH 16

enum {
  ROMCALC_SUCCESS,
  ROMCALC_NULL_POINTER_ERROR,
  ROMCALC_INVALID_OPERAND_ERROR,
  ROMCALC_INVALID_RESULT_ERROR
};

int add(char *sum, const char *augend, const char *addend);
int subtract(char *difference, const char *minuend, const char *subtrahend);

#endif
