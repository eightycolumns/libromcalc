#ifndef ROMCALC_H
#define ROMCALC_H

/**
 * The number of bytes needed to store the longest possible Roman numeral,
 * including the terminating null byte.
 */
#define ROMCALC_MAX_LENGTH 16

enum {
  /**
   * Successful completion, no errors.
   */
  ROMCALC_SUCCESS,

  /**
   * One or more arguments were null pointers.
   */
  ROMCALC_NULL_POINTER_ERROR,

  /**
   * One or more operands were invalid Roman numerals.
   */
  ROMCALC_INVALID_OPERAND_ERROR,

  /**
   * Both operands were valid Roman numerals, but the result of the operation
   * could not be converted to a valid Roman numeral.
   */
  ROMCALC_INVALID_RESULT_ERROR
};

/**
 * Adds the Roman numeral addend to the Roman numeral augend and writes the
 * resulting Roman numeral to the buffer pointed to by sum. Returns 0 on
 * success, or an error code indicating the cause of failure.
 */
int add(char *sum, const char *augend, const char *addend);

/**
 * Subtracts the Roman numeral subtrahend from the Roman numeral minuend and
 * writes the resulting Roman numeral to the buffer pointed to by difference.
 * Returns 0 on success, or an error code indicating the cause of failure.
 */
int subtract(char *difference, const char *minuend, const char *subtrahend);

#endif
