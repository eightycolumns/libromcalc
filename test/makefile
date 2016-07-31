BUILD_DIR = ../build

.PHONY: all
all: $(BUILD_DIR)/$(TEST_EXE)

OBJECTS = $(patsubst %.c,%.o,$(wildcard *.c))

vpath lib%.a $(BUILD_DIR)

LDFLAGS = -L$(BUILD_DIR)
LDLIBS = -l$(TEST_EXE:%-test=%) -lcheck

$(BUILD_DIR)/$(TEST_EXE): $(OBJECTS) -lromcalc | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS) $(LDLIBS)

HEADERS = $(wildcard *.h) ../src/$(TEST_EXE:%-test=%.h)

$(OBJECTS): $(HEADERS)

$(BUILD_DIR):
	mkdir -p $@

.PHONY: clean
clean:
	rm -rf $(OBJECTS) $(BUILD_DIR)
