MAKEFLAGS += -s

DIRS = src test

MAKE_DIRS = $(DIRS:%=make-%)

.PHONY: all
all: $(MAKE_DIRS)

.PHONY: $(MAKE_DIRS)
$(MAKE_DIRS):
	$(MAKE) -C $(@:make-%=%)

BUILD_DIR = build
TEST_EXE = romcalc-test

.PHONY: check
check:
	./$(BUILD_DIR)/$(TEST_EXE)

CLEAN_DIRS = $(DIRS:%=clean-%)

.PHONY: clean
clean: $(CLEAN_DIRS)

.PHONY: $(CLEAN_DIRS)
$(CLEAN_DIRS):
	$(MAKE) -C $(@:clean-%=%) clean
