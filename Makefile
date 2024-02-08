# Compiler
CXX = g++

# Base Compiler flags
BASE_CXXFLAGS = -Iheaders -Wall

# Source directory
SRC_DIR = source

# Object files directory
OBJ_DIR = dist/obj

# Output directory
DIST_DIR = dist

# Target executable name
TARGET = $(DIST_DIR)/DegreesOfHell

# Find all cpp files in the source directory
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Replace source directory with object directory and change file extension to .o
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Default compiler flags
CXXFLAGS = $(BASE_CXXFLAGS)

# Default make target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

# Compile cpp files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Target for compiling with AddressSanitizer
asan: CXXFLAGS += -fsanitize=address -fno-omit-frame-pointer -g
asan: clean $(TARGET)

# Clean target for removing compiled files
clean:
	@rm -rf $(OBJ_DIR) $(TARGET)
	@echo "Project cleaned."

.PHONY: all clean asan
