# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++23 -Wall -Wextra

# Directories
SRC_DIR := src
BUILD_DIR := build
TARGET := game

# Find all source files recursively
SRC_FILES := $(shell dir /s /b $(SRC_DIR)\*.cpp)

# Find all include directories recursively
INC_DIRS := $(shell dir /s /b /ad $(SRC_DIR))
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# Object files
OBJ_FILES := $(patsubst $(SRC_DIR)\%.cpp,$(BUILD_DIR)\%.o,$(SRC_FILES))

# Target executable
$(BUILD_DIR)\$(TARGET): $(OBJ_FILES)
	@mkdir $(BUILD_DIR) 2>nul || goto :eof
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) $^ -o $@

# Pattern rule for object files
$(BUILD_DIR)\%.o: $(SRC_DIR)\%.cpp
	@mkdir $(@D) 2>nul || goto :eof
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) -c $< -o $@

# Clean target
.PHONY: clean
clean:
	rmdir /S /Q $(BUILD_DIR) 2>nul || goto :eof

# Default target
all: $(BUILD_DIR)\$(TARGET)