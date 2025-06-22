# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I./

# Diretórios
SRC_DIR = ./src
BUILD_DIR = ./build
BIN_DIR = ./bin

# Arquivo executável
TARGET = $(BIN_DIR)/app

# Procurar todos os arquivos .cpp no diretório src
SOURCES = $(wildcard $(SRC_DIR)/**/*.cpp) $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

# Regra padrão
all: $(TARGET)

# Regra para o executável
$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra para gerar os objetos
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar objetos e binários
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Executar o programa
run: all
	./$(TARGET)
