MAKEFLAGS += -s

CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Werror -I .. -O2 -D NDEBUG

BUILD_DIR = ../build
LIB_NAME = libromcalc.a

.PHONY: all
all: $(BUILD_DIR)/$(LIB_NAME)

OBJECTS = $(patsubst %.c,%.o,$(wildcard *.c))

$(BUILD_DIR)/$(LIB_NAME): $(OBJECTS) | $(BUILD_DIR)
	ar rcs $@ $^

HEADERS = $(wildcard *.h)

$(OBJECTS): $(HEADERS)

$(BUILD_DIR):
	mkdir -p $@

.PHONY: clean
clean:
	rm -rf $(OBJECTS) $(BUILD_DIR)
