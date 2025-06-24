# Nome do executável
TARGET = programa

# Compilador
CXX = g++

# Flags de compilação (incluindo os diretórios dos headers)
CXXFLAGS = -I src/Controller -I src/Model -I src/Utils -I src/View -I src/DAO/inMemory -I src/DAO/interface

# Diretórios dos arquivos fonte
SRC = src/*.cpp src/Controller/*.cpp src/Model/*.cpp src/Utils/*.cpp src/View/*.cpp src/DAO/inMemory/*.cpp

# Regra padrão
all:
	$(CXX) $(SRC) $(CXXFLAGS) -o $(TARGET)

# Limpar arquivos binários (opcional)
clean:
	del $(TARGET).exe
