MAKEFLAGS += -s

CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Werror -I .. -O2 -D NDEBUG

BUILD_DIR = ../build
TEST_EXE = romcalc-test

.PHONY: all
all: $(BUILD_DIR)/$(TEST_EXE)

OBJECTS = $(patsubst %.c,%.o,$(wildcard *.c))

vpath lib%.a $(BUILD_DIR)

LDFLAGS = -L$(BUILD_DIR)
LDLIBS = -l$(TEST_EXE:%-test=%) -lcheck

$(BUILD_DIR)/$(TEST_EXE): $(OBJECTS) -lromcalc | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

HEADERS = $(wildcard *.h)

SRC_DIR = ../src
LIB_HEADER = $(TEST_EXE:%-test=%.h)

$(OBJECTS): $(HEADERS) $(SRC_DIR)/$(LIB_HEADER)

$(BUILD_DIR):
	mkdir -p $@

.PHONY: clean
clean:
	rm -rf $(OBJECTS) $(BUILD_DIR)
