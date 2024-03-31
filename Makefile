# Directories used
INCLUDE_DIR=include
SRC_DIR=src
TEST_DIR=test
BUILD_DIR=build

# Flags for compilation and linking
CFLAGS = -std=c99 -Wall -Wextra -pedantic
CFLAGS += -I./$(INCLUDE_DIR)/
CFLAGS += -DDEBUG
LDFLAGS = -O3 -ffast-math
LDFLAGS += -lpthread -lm

# Sources
SOURCES = $(BUILD_DIR)/types.o

# Pattern rules
$(SOURCES): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< $(CFLAGS) -o $@

# File targets
# Library
$(BUILD_DIR)/ltwoflower.a: $(SOURCES)
	$(AR) -rcs $@ $(BUILD_DIR)/*.o
# Test
$(BUILD_DIR)/test: $(TEST_DIR)/main.c $(BUILD_DIR)/ltwoflower.a
	$(CC) $(BUILD_DIR)/ltwoflower.a $(TEST_DIR)/*.c $(CFLAGS) $(LDFLAGS) -o $@

# Phony targets
.PHONY: clean test build

clean:
	rm -rf $(BUILD_DIR)/*

test: $(BUILD_DIR)/test
	$(BUILD_DIR)/test

build: $(BUILD_DIR)/ltwoflower.a
