CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g -I./src -I./src/Controller -I./src/Model -I./src/Utils -I./src/View -I./src/DAO/inMemory -I./src/DAO/interface
TARGET = programa

# Compilação e linkagem em um único passo
$(TARGET): src/*.cpp src/Controller/*.cpp src/Model/*.cpp src/Utils/*.cpp src/View/*.cpp src/DAO/inMemory/*.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

# Limpar arquivos gerados
clean:
	rm -f $(TARGET)
