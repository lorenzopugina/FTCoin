CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g \
  -I./src -I./src/Controller -I./src/Model -I./src/Utils -I./src/View -I./src/DAO/inMemory -I./src/DAO/interface
TARGET = ftcoin

# Compilation and linking in one step
$(TARGET): src/*.cpp src/Controller/*.cpp src/Model/*.cpp src/Utils/*.cpp src/View/*.cpp src/DAO/inMemory/*.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up generated files
clean:
	rm -f $(TARGET)
