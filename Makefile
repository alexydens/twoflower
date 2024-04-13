# Directories used
INCLUDE_DIR=include
SRC_DIR=src
TEST_DIR=test
BUILD_DIR=build

# Flags for compilation and linking
CFLAGS = -std=c99 -Wall -Wextra -pedantic -Wno-unused-parameter
CFLAGS += -I./$(INCLUDE_DIR)/
CFLAGS += -DDEBUG
LDFLAGS = -O3 -ffast-math
LDFLAGS += -lpthread -lm
LDFLAGS += -lwayland-client

# Sources
SOURCES = $(BUILD_DIR)/base.o
SOURCES += $(BUILD_DIR)/types.o
SOURCES += $(BUILD_DIR)/arena_alloc.o
SOURCES += $(BUILD_DIR)/str.o

# Pattern rules
$(SOURCES): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< $(CFLAGS) -o $@

# File targets
# Library
$(BUILD_DIR)/ltwoflower.a: $(SOURCES)
	$(AR) -rcs $@ $(BUILD_DIR)/*.o 
# Test
$(BUILD_DIR)/test: $(TEST_DIR)/main.c $(BUILD_DIR)/ltwoflower.a
	$(CC) $(TEST_DIR)/*.c $(BUILD_DIR)/ltwoflower.a $(CFLAGS) $(LDFLAGS) -o $@

# Phony targets
.PHONY: clean test build

clean:
	rm -rf $(BUILD_DIR)/*

test: $(BUILD_DIR)/test
	$(BUILD_DIR)/test

build: $(BUILD_DIR)/ltwoflower.a
