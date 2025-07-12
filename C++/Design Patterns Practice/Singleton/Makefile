#Tên file thực thi
TARGET = main

#Tên các tệp

SRCDIR = src
INCDIR = inc
BINDIR = bin

#Tìm tất cả các file nguồn trong thư mục src
SRCS = $(wildcard $(SRCDIR)/*.cpp)

#Biên dịch thành file.o cho vào thư mục bin
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(BINDIR)/%.o, $(SRCS))

# Trình biên dịch
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I$(INCDIR)

#lệnh all để build chương trình
all: $(TARGET)

#Tạo thư mục bin nếu chưa tồn tại
$(BINDIR):
	@echo "Tạo thư mục bin"
	@mkdir -p $(BINDIR)

# Rule biên dịch từng file .cpp thành .o trong bin
$(BINDIR)/%.o: $(SRCDIR)/%.cpp | $(BINDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

#clean
clean: 
	rm -f $(BINDIR)/*.o $(BINDIR)/$(TARGET)
#run
run: $(TARGET)
	./$(TARGET)




