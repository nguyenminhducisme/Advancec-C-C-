# Tên của chương trình
TARGET = main

# Thư mục chứa header và source files
HEADER_DIR = Header
SOURCE_DIR = Source

# Các tệp nguồn và tệp object tương ứng
SOURCES = $(wildcard $(SOURCE_DIR)/*.c)
OBJECTS = $(SOURCES:$(SOURCE_DIR)/%.c=$(SOURCE_DIR)/%.o)

# Trình biên dịch và các cờ
CC = gcc
CFLAGS = -I$(HEADER_DIR) -Wall -Wextra

# Quy tắc đầu tiên là quy tắc mặc định sẽ được thực thi
all: $(TARGET)

# Quy tắc để tạo ra tệp thực thi
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "Compiling $(TARGET) with objects: $(OBJECTS)"

# Quy tắc để biên dịch các tệp .c thành .o
$(SOURCE_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $^

# Quy tắc để làm sạch thư mục build
clean:
	rm -f $(SOURCE_DIR)/*.o $(TARGET)

# Quy tắc để chạy chương trình
run: $(TARGET)
	./$(TARGET)

# Quy tắc giả (phony target)
.PHONY: all clean run