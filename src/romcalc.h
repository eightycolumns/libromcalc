#ifndef ROMCALC_H
#define ROMCALC_H

#define ROMCALC_MAX_LENGTH 16

enum {
  ROMCALC_SUCCESS,
  ROMCALC_NULL_POINTER_ERROR
};

int add(char *sum, const char *augend, const char *addend);

#endif
