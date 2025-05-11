# Compiler
CC = gcc
CFLAGS = -g -Wall -Wextra -IHeader

# Source files
SRC := $(wildcard Source/*.c)

# Object files
OBJ := $(patsubst Source/%.c, build/%.o, $(SRC))

# Output file
TARGET := bin\main.exe

# Default rule
all: $(TARGET)

# Linking
$(TARGET): $(OBJ)
	@mkdir -p bin
	$(CC) $(OBJ) -o $@
	@echo "✅ Build xong: $@"

# Compiling
build/%.o: Source/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	@echo "🚀 Running..."
	.\$(TARGET)
	@echo "🏁 Done."

# Clean
clean:
	rm -rf build bin
	@echo "🧹 Dọn sạch xong"

debug: $(TARGET)
	gdb ./$(TARGET)
