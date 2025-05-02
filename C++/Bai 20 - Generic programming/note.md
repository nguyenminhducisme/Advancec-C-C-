# Generic programming
- Là phương pháp lập trình sử dụng các **tham số kiểu dữ liệu** để viết mã có thể **tái sử dụng và hoạt động với nhiều kiểu dữ liệu khác nhau**. Giúp loại bỏ sự trùng lặp code và tăng tính linh hoạt trong thiết kế phần mềm.

## C++ sử dụng Templates để triển khai Generics. Chia thành 2 loại:
    - Function Templates
    - Class Templates
- _Và dùng để thiết kế thư viện_
## 1. Function templates

Trong C++, Templates giúp viết hàm có thể làm việc với **nhiều kiểu dữ liệu mà không cần overload nhiều lân**

Chỉ áp dụng cho một định nghĩa cụ thể của hàm, không áp dụng cho tất cả các hàm

```cpp
template < typename T >
T func(T a, T b){} // bắt buộc phải cùng kiểu

template < typename T1, typename T2, typename T3 >
T1 func(T1 a, T2 b, T3 c){} // có thể cùng hoặc khác kiểu
-------------------------------------------------------------
-------------------------------------------------------------

template <typename T1, typename T2>
T1 sum(T1 a, T2 b)
{
    return a+b;
}

template <typename T>
T sum(T a, T b)
{
    return a+b;
}

int main()
{
    cout << "Sum: " << sum(1,2)<< endl; // T: int
    cout << "Sum: " << sum(1.4, 2.7) << endl; // T: double
    cout << "Sum: " << sum(1, 2.7) << endl; // Tham số T1: int quyết định kiểu trả về của hàm
    return 0;
}

```
### Từ khóa auto

``` cpp
auto x = 2;
auto y = 3.5;
auto z = 'a';
auto t = "hello";
auto m; // Khong thể khai báo biến rác với auto được
```

- Từ khóa auto tự định nghĩa kiểu dữ liệu dựa vào giá trị ta gán cho biến. Nhưng chỉ sử dụng từ phiên bản **C++11**
```cpp
template <typename T1, typename T2>
auto sum(T1 a, T2 b)
{
    return a+b;
}
cout << "Sum: " << sum(1, 2.7) << endl; ==> Output: 3.7
```
### Template với kiểu mặc định
```cpp
// tham số mặc định
template <typename T = int>
T square(T x)
{
    return x * x;
}

cout << square(4) << endl;
cout << square<double>(4.5) << endl; // ép kiểu int -> double

==> Output:
16
20.25
```
- Nhưng giả sử ở tên ta truyền square(4.5) vào thì compiler vẫn tự suy luận kiểu là double, và cho ra kết quả 20.25
## 2. Class Template

Class templates trong C++ là một khái niệm tương tự như function templates, nhưng được áp dụng cho **class thay vì function**. Class templates cho phép tạo các class có thể làm việc với nhiều kiểu dữ liệu mà không cần viết lại code.

Template chỉ áp dụng cho một định nghĩa cụ thể của class, không áp dụng cho tất cả các class.

Cú pháp:
```cpp
template <typename T>
class <name_of_class>
{
    private:
        T var;
}
```
* Example
```cpp
#include <iostream>
using namespace std;



template <typename T>
class Sensor{
    private:
        T value;
    public:
        Sensor(T init): value(init){}
        void readSensor(T newValue){ value = newValue; }
        T getValue() const { return value; }
        void display(){ cout << "Gia tri cam bien: " << value << endl; }
};

int main(int argc, char const *argv[]){
    Sensor tempSensor(36.5);
    tempSensor.display();

    Sensor lightSensor(512);
    lightSensor.display();

    Sensor stateSensor("OFF");
    stateSensor.display();
    /* Muốn không định nghĩa kiểu dữ liệu thì ta phải dùng C++17 */
    return 0;
}
```
### Template Specialization

**Template chuyên biệt hóa** cho phép tùy chỉnh hành vi của template cho **một kiểu dữ liệu cụ thể**.

Cú pháp:
```cpp
template <>
class name_of_class<data_type>
{
    private:
        data_type var;
}
```

## 3. Variadic Template

- Variadic Template cho phép bạn tạo các hàm template hoặc lớp template có thể nhận một số lượng tham số không xác định. 

- Điều này giúp bạn viết mã linh hoạt hơn khi làm việc với danh sách tham số có kích thước động.