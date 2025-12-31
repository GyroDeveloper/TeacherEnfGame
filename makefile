#Project config
CXX      := g++
CXXFLAGS := -O2 -Wall
LDFLAGS  := -lsfml-graphics -lsfml-window -lsfml-system

#Dir structure
SRC_DIR  := src
OBJ_DIR  := obj
BIN_DIR  := bin

#Files
# Gets all .cpp files inside src/
SOURCES  := $(wildcard $(SRC_DIR)/*.cpp)
# Create the list of objects by replacing .cpp with .o and changing the folder.
OBJECTS  := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
# Name of the final executable
TARGET   := $(BIN_DIR)/game.bin

# Rules of compilation && execution

# Standard rule
all: $(TARGET)

# 1. Linking: Unite all .o files into the executable
$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	@echo "Linking..."
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)
	@echo "Build complete: $@"

# 2. Compilation Transform each .cpp file in .o file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Running Rules
run: all
	@echo "Running Game..."
	@./$(TARGET)

rund: all
	@echo "Running Game with Debug..."
	@./$(TARGET) -d

# Cleaning Rules
clean:
	@echo "Cleaning..."
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "Cleaned!"

.PHONY: all run clean