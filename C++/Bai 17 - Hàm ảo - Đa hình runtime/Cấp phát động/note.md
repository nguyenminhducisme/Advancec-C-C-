# Cấp phát động
__new operator__

- Toán tử new được sử dụng để cấp phát bộ nhớ động cho một biến, một mảng hoặc một đối tượng. 
- Khi sử dụng new, bộ nhớ sẽ được cấp phát trên phân vùng Heap (khu vực nhớ dành cho cấp phát động) thay vì trên stack (khu vực nhớ dành cho cấp phát tĩnh).
- new tương đương với hàm malloc(), calloc() trong C. 
__delete operator__

- Toán tử delete dùng để giải phóng bộ nhớ đã được cấp phát bằng new. Điều này giúp tránh lãng phí bộ nhớ và hiện tượng rò rỉ bộ nhớ (memory leak).
- delete tương đương với hàm free() trong C.
## 1. Cấp phát động 1 biến đơn
```cpp
 int *ptr = new int(10);
    /****************************************************
     * new int(10)
     *      + Khởi tạo một biến int
     *      + Cấp phát động cho biến int (0x01 0x02 0x03 0x04 - Heap)
     *      + Gán giá trị tại địa chỉ vừa cấp phát là 10
     *      + Trả về địa chỉ của vùng nhớ mới được cấp phát
     * 
     * con trỏ ptr sẽ trỏ đến địa chỉ trên
     ***************************************************/


    cout << "Địa chỉ đối tượng: " << ptr << endl;
    cout << "Giá trị đối tượng: " << *ptr << endl;


    delete ptr;
```
### Vì sao bên C++ lại phát triển new, delete thay vì malloc, calloc, realloc như C
``` cpp
int main()
{
    int *ptr = new double(10);
    
}
==> Không thể ép kiểu như này giống trong C được, bắt buộc phải đồng bộ kiểu dữ liệu
``` 

## 2. Cấp phát động 1 mảng
```cpp
#include <iostream>


using namespace std;


int main(int argc, char const *argv[])
{   
    int size;
    cout << "Nhập kích thước của mảng: ";
    cin >> size;


    int *arr = new int[size]; 


    for (int i = 0; i < size; i++){
        arr[i] = i * 2;
    }


    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;


    delete[] arr;  // Giải phóng bộ nhớ   


    return 0;
}
```

## 3. Cấp phát động với 1 đối tượng của Class
```cpp
#include <iostream>


using namespace std;


class SinhVien{
    private:
        string name;
        int id;
        int age;
    
    public:
        SinhVien(string _name, int _age): name(_name), age(_age){
            static int _id = 1;
            id = _id;
            _id++;
        }


        void display(){
            cout << "Name: " << name << ", ID: " << id << ", Age: " << age << endl;
        }
};


int main(int argc, char const *argv[])
{   
    SinhVien *p1 = new SinhVien("Trung", 25);
    p1->display();


    SinhVien *p2 = new SinhVien("Tuan", 22);
    p2->display();


    return 0;
}
```