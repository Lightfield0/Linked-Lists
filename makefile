# Temel değişkenler
CXX = g++
CXXFLAGS = -Wall -g -Iinclude
BIN_DIR = bin
OBJ_DIR = lib
SRC_DIR = src
INCLUDE_DIR = include

# Kaynak ve obje dosyaları
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Hedef dosya
TARGET = $(BIN_DIR)/program

# Hedefi oluştur
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Objeleri oluştur
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 'make clean' komutu
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

# 'make run' komutu
run: $(TARGET)
	cd $(BIN_DIR) && program
