# MOVE SEMANTICS: Là một cơ chế di chuyển dữ liệu, tài nguyên

## 1. lvalue và rvalue

1. lvalue

- __lvalue__ _(left value)_ là những giá trị có địa chỉ cụ thể trong bộ nhớ và thường được đặt tên bằng một định danh (biến, đối tượng...)

- _Thường_ xuất hiện ở __bên trái__ của phép gán __(=)__

- __lvalue__ có thể là một biến, một tham chiếu... được truy cập thông qua địa chỉ bộ nhớ.

2. rvalue

- Là những giá trị tạm thời, không có địa chỉ cố định mà chương trình có thể truy cập
- _Thường_ xuất hiện bên phải phép gán
- _Thường_ là kết quả của một biểu thức hoặc một hằng số
- __Không thể__ lấy địa chỉ của __rvalue__


```cpp
int x = 10;
/*
x: lvalue
10: rvalue
*/
```

```cpp
int y = x;

* lvalue: x, y
* rvalue: giá trị của x khi gán cho y
```

```cpp
char *ptr = "hello";
/**
 * lvalue: ptr
 * rvalue: "hello" chuỗi hằng, mặc dù có địa chỉ cố định nhưng trường hợp này được coi là "tạm thời" vì nó không thể được thay đổi sau khi được gán cho một biến
 *  
 */
```

## 2. Tham chiếu

### 2.1 lvalue reference

1. Tham chiếu lvalue chỉ có thể liên kết lvalue (đối tượng có sẵn tên và địa chỉ)
2. Thường được dùng để truyền tham số cho hàm bằng tham chiếu, cho phép hàm thao tác trực tiếp trên đối tượng gốc

### 2.2 rvalue reference (C++11 đổ lên)

1. rvalue chỉ là tạm thời và sẽ bị hủy ngay khi kết thúc câu lệnh. Để có thể sử dụng lâu hơn ta có thể liên kết vào một tham chiếu
    - __const T&__ hoặc __T&&__

2. Chủ yếu dùng trong __move semantics và perfect forwarding.__

```cpp
int main()
{
    int &&ref = 10; // ref là rvalue reference
    ref = 20;       // ref thay đổi tham chiếu tới 1 đối tượng tạm thời khác


    const double &ref = 3.14;
    /*
     * ref là 1 lvalue reference tới 1 hằng số
     */


    return 0;
}

```

- Sử dụng rvalue khi

## 3. Move semantics - Di chuyển dữ liệu

- Là một cơ chế trong C++11, giúp __chuyển giao__ tài nguyên từ mọt đối tượng này sang đối tượng khác thay vì __sao chép__ từng phần, làm __phình to bộ nhớ RAM__

- Để hỗ trợ __Move semantics__, C++11 giới thiệu __Move Constructor__ (_constructor di chuyển tài nguyên_) và __Move Assignment Operator__ (_toán tử gán di chuyển tài nguyên_).

### 3.1. Copy constructor

```cpp
ClassName(const ClassName &other){}
```

- Ví dụ

```cpp
#include <iostream>
using namespace std;


class User
{
    private:
        int *id;	// raw pointer


    public:
        // constructor
        User(int i){ id = new int(i); }


        // Copy constructor
        User(const User& other)
        {
            this->id = other.id;
            display();
        }


        void display() const
        {
            cout << "id = " << id << endl;
        }
};
   
int main()
{
    User a(2);
    User b = a;  // Copy constructor được gọi


    return 0;
}

```

### 3.2 Copy assignment operator

- Cú pháp
```cpp
ClassName operator = (const ClassName &other);
```

- Ví dụ
```cpp
// Copy assignment operator
User& operator = (const User& other)
{
    if (this != &other)
    {
        this->id = other.id;
        cout << "this is copy assignment operator\n";
    }
    return *this;
}


User a(2);
User c;
c = a;  // Copy assignment operator được gọi
```

### 3.3 Move constructor

- _Move constructor_ là một hàm đặc biệt trong C++ được gọi khi bạn chuyển __quyền sở hữu tài nguyên__ từ __một đối tượng tạm thời (rvalue) sang đối tượng mới.__

- Cú pháp

```cpp
ClassName(ClassName &&other){}

- Muốn gọi thì 
 User c = move(a); // move constructor được gọi

```

#### Con trỏ this

- Là một con trỏ giữ địa chỉ của chính đối tượng đang gọi tới nó.

```cpp
class Hust
{
    public:
        print_this_pointer()
        {
            std::cout << this << std::endl;
        }
};

int main()
{
    Hust BK;
    BK.print_this_pointer();
    std::cout << &BK << std::endl;
}

===> Output: in ra cùng 1 địa chỉ
```

- Khi nào cần dùng con trỏ __this__




