# Tên file thực thi
TARGET = main

# Thư mục chứa file header, file nguồn và file thực thi
INCDIR = inc
SRCDIR = src
BINDIR = bin

# Tìm tất cả các file nguồn .cpp trong thư mục SRCDIR
SRCS = $(wildcard $(SRCDIR)/*.cpp)

# Tạo danh sách các file object .o tương ứng trong thư mục BINDIR
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(BINDIR)/%.o)

# Compiler và các flags cho compiler
CXX = g++
CXXFLAGS = -Wall -std=c++11 -I$(INCDIR)

# cở debug
# CXXFLAGS = -std=c++11 -g -Wall -Wextra

# cờ mã hóa sang ký tự có dấu
# CXXFLAGS = -std=c++11 -Wall -Wextra -finput-charset=UTF-8 -fexec-charset=UTF-8

# Rule mặc định để biên dịch chương trình
all: $(BINDIR)/$(TARGET)

# Tạo thư mục bin nếu chưa tồn tại
$(BINDIR):
	mkdir -p $(BINDIR)

# Rule để tạo file thực thi trong thư mục bin
$(BINDIR)/$(TARGET): $(OBJS) | $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$(TARGET) $(OBJS)

# Rule để tạo các file object (.o) trong thư mục bin từ file source (.cpp)
$(BINDIR)/%.o: $(SRCDIR)/%.cpp | $(BINDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule để dọn dẹp các file biên dịch
clean:
	rm -f $(BINDIR)/*.o $(BINDIR)/$(TARGET)

# Rule để chạy chương trình từ thư mục bin
run: all
	./$(BINDIR)/$(TARGET)