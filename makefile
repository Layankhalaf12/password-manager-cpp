# Makefile for Assignment1
# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -Wall -std=c++17

# Target executable
TARGET = Assignment1

# Source files
SRCS = Assignment1.cc 
OBJS = $(SRCS:.cc=.o)
# Default rule  
all: $(TARGET)

# Link object files 
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJS)

# Run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run