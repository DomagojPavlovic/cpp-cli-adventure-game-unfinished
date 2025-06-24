# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++23 -Wall -Wextra

# Directories
SRC_DIR := src
BUILD_DIR := build
TARGET := game

# Find all source files recursively using find
SRC_FILES := $(shell find $(SRC_DIR) -name "*.cpp")

# Print source files for debugging
$(info Source files: $(SRC_FILES))

# Find all include directories recursively using find
INC_DIRS := $(shell find $(SRC_DIR) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# Print include directories for debugging
$(info Include directories: $(INC_DIRS))

# Object files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Print object files for debugging
$(info Object files: $(OBJ_FILES))

# Target executable
$(BUILD_DIR)/$(TARGET): $(OBJ_FILES)
	@echo Building target $@
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) $^ -o $@

# Pattern rule for object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo Compiling $<
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) -c $< -o $@

# Clean target
.PHONY: clean
clean:
	@echo Cleaning build directory
	rm -rf $(BUILD_DIR)

# Default target
all: $(BUILD_DIR)/$(TARGET)