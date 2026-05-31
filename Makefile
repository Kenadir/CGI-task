# compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

# folders
SRC = src
OBJ = obj
BIN = bin

# target
TARGET = $(BIN)/bank_app

# sources
SOURCES = $(wildcard $(SRC)/*.cpp)
OBJECTS = $(SOURCES:$(SRC)/%.cpp=$(OBJ)/%.o)

# build all
all: $(TARGET)

# link
$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN)
	$(CXX) $(OBJECTS) -o $(TARGET)

# compile
$(OBJ)/%.o: $(SRC)/%.cpp
	@mkdir -p $(OBJ)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# run
run: all
	./$(TARGET)

# clean
clean:
	rm -rf $(OBJ) $(BIN)
