#include <iostream>
using namespace std;

// Class tổng quát sử dụng Variadic Template
template <typename... Args>
class MyClass;

// Định nghĩa class khi không có đối số
template <>
class MyClass<>
{
    public:
        void display()
        {
            cout << "No arguments" << endl;
        }
};

// Định nghĩa class khi có ít nhất một đối số
template <typename T, typename... Args>
class MyClass<T, Args...> : public MyClass<Args...> // kế thừa từ lớp public của class Myclass với không đối số
{
    private:
        T first_; // Khởi tạo thuộc tính first

    public:
 // T first_ = first, Args1 args1_ = args1, Args2 args2_ = args2,...
        MyClass(T first, Args... args): first_(first),  MyClass<Args...>(args...){} // constructor khởi tạo đối số

        void display()
        {
            cout << first_ << " ";
            MyClass<Args...>::display(); // Gọi hàm display của lớp cơ sở
        }  

};

int main()
{
    MyClass<int, double, char> obj(1, 2.5, 'A'); // Khởi tạo obj với 3 đối số với 3 kiểu dữ liệu khác nhau
    obj.display();  // Kết quả: 1 2.5 A

    MyClass obj1;
    obj1.display();
    return 0;
}

