MAKEFLAGS += -s

export CC = gcc
export CFLAGS = -std=c99 -pedantic -Wall -Wextra -Werror -I .. -O2 -D NDEBUG

export LIB_NAME = libromcalc.a
export TEST_EXE = romcalc-test

DIRS = src test

MAKE_DIRS = $(DIRS:%=make-%)

.PHONY: all
all: $(MAKE_DIRS)

.PHONY: $(MAKE_DIRS)
$(MAKE_DIRS):
	$(MAKE) -C $(@:make-%=%)

.PHONY: check
check:
	./build/$(TEST_EXE)

CLEAN_DIRS = $(DIRS:%=clean-%)

.PHONY: clean
clean: $(CLEAN_DIRS)

.PHONY: $(CLEAN_DIRS)
$(CLEAN_DIRS):
	$(MAKE) -C $(@:clean-%=%) clean
