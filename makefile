# Makefile for Password Manager
# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -Wall -std=c++17

# Target executable
TARGET = password_manager

# Source files
SRCS = password_manager.cpp 
OBJS = $(SRCS:.cpp=.o)
# Default rule  
all: $(TARGET)

# Link object files 
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJS)

# Run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run