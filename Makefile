# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# Source files
SRC = main.cpp Game.cpp GameState.cpp Caretaker.cpp Memento.cpp

# Header files
HEADERS = Game.h GameState.h Caretaker.h Memento.h

# Output executable
OUT = game

# Targets
all: $(OUT)

# Rule to compile the program
$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

# Clean rule to remove compiled files
clean:
	rm -f $(OUT)

# Rebuild the project (clean and build)
rebuild: clean all
