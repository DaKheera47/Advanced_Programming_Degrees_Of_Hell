# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Iheaders -Wall -std=c++14 -g

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

# Default make target
all: $(TARGET) copy_static

# Link object files to create the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

# Compile cpp files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Custom target to copy the static folder
copy_static:
	@mkdir -p $(DIST_DIR)/static
	@cp -r ./static/ $(DIST_DIR)/static/
	@echo "Static content copied."

# Clean target for removing compiled files
clean:
	@rm -rf $(OBJ_DIR) $(TARGET) $(DIST_DIR)/static
	@echo "Project cleaned."

.PHONY: all clean copy_static
