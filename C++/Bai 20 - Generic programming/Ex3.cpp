#include <iostream>
using namespace std;

// Template tổng quát
template <typename T>
void display(T value){
    cout << "Generic: " << value << endl;
}

// Chuyên biệt hóa cho kiểu `int`
template <>
void display<int>(int value){
    cout << "Specialized for int: " << value << endl;
}

// Chuyên biệt hóa cho kiểu `char*`
template <>
void display<char*>(char* value){
    cout << "Specialized for string: " << value << endl;
}

int main(){
    display(42);        // Sử dụng chuyên biệt hóa cho int
    display(3.14);      // Sử dụng template tổng quát
    display("Hello");   // Sử dụng chuyên biệt hóa cho char*
    return 0;
}

