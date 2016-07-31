BUILD_DIR = ../build

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
