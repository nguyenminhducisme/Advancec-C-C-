# CLASS
- Để định nghĩa 1 lớp trong C++
- Là nền tảng của OOP trong C++

### Cũng có thể giống như struct or union, nhưng có thể lưu được các kiểu định nghĩa phức tạp.

```cpp
class Classname
{
    Access specifier; /* can be private, public and protected */
    Data members;    /* variables to be used */
    Member functions(){}; /* methods to acccess data members */
}
```

## Phạm vi truy cập
- Là cách quy định mức độ truy cập của các thành viên trong class
- Có 3 phạm vi truy cập chính
1. public
2. private
3. protected

## PUBLIC:

1. Có thể truy cập các members từ bên ngoài

```cpp
class SinhVien
{
    public:
    string name;
    int age;

};
```

2. Khi muốn truy xuất 1 tham số, có thể gọi trực tiếp hoặc thông qua tên class, có thể truy cập từ bên trong lẫn bên ngoài.

```cpp
class SinhVien
{
    public:
         string name;   // thuộc tính (property) - là các thông số trong class
         int age;
         void display() // phuowng thức (method) - là những hàm trong class
         {
            cout << "Ten: " << name << endl;
            cout << "Tuoi: "<< SinhVien::age << endl;
         }
         void createObject()
         {
            SinhVien sv2;
            sv2.name = "Minh Duc";
            sv2.age  = 23;
         }

SinhVien sv1; // đối tượng (object) - là những biến được gọi từ class

};
```

## CONSTRUCTOR:
1. Là 1 hàm được khai báo trong class
2. Có tên trùng với tên class
3. Không có kiểu trả về
4. Được tự động gọi khi khởi tạo những đối tượng, không quan trọng khởi tạo bên trong hay bên ngoài
5. Sử dụng để khởi tạo những giá trị ban đầu của biến


```cpp
class HinhChuNhat
{
    public:
        double chieuDai;
        double chieuRong;
   
        HinhChuNhat(): chieuDai(100), chieuRong(100)
        {
            chieuDai  = 10;
            chieuRong = 9;
        }

        // Hàm tính diện tích
        double tinhDienTich()
        {
            return chieuDai * chieuRong;
        }
};

int main()
{
    HinhChuNhat hinh1;
    cout << "Chieu dai: " << hinh1.chieuDai << '\n';
    return 0;
}
```

### Có 3 dạng:
1. không có tham số
2. có tham số, không có giá trị mặc định
3. có tham số, có giá trị mặc định
4. 

```cpp
int main()
{
   SinhVien sv1 ("mei2e", 23); // đối tượng (object) - là những biến được gọi từ class
    // sv1.age = 34; // khong the truy cap (inaccessible), tức sẽ mặc định private. Nenen ở trên sẽ đổi thành public
    // cout << sv1.age << endl;
    // sv1.name = "Duc";
    sv1.display();

    SinhVien sv2; // nếu không truyền vào thì lấy giá trị mặc định, còn nếu truyền vào thì lấy giá trị mới truyền vào
    sv2.display();
    return 0;
}
```

## DESTRUCTOR
1. Có thêm kí tự ~ ở trước tên.
2. Không có điểm trả về và được tự động gọi ra như constructor.
3. Được tự động gọi ra trước khi object được giải phóng.
4. Được dùng để hủy dữ liệu.

```cpp

void SinhVien::display() 
{
    cout << "Ten: " << name << endl;
    cout << "Tuoi: "<< SinhVien::age << endl;
}

SinhVien::SinhVien(string newName, int newAge)
{
    name = newName;
    age = newAge;
    display();
}

SinhVien::~SinhVien()
{
    name = " ";
    age = 0;
    display();
}

int main()
{
    SinhVien sv1 ("mei2e", 23); // đối tượng (object) - là những biến được gọi từ class
    // sv1.age = 34; // khong the truy cap (inaccessible), tức sẽ mặc định private. Nenen ở trên sẽ đổi thành public
    // cout << sv1.age << endl;
    // sv1.name = "Duc";
    //sv1.display();

    SinhVien sv2("Duc", 28); // nếu không truyền vào thì lấy giá trị mặc định, còn nếu truyền vào thì lấy giá trị mới truyền vào
    //sv2.display();
    return 0;
}
/* Output */
Ten: mei2e
Tuoi: 23
Ten: Duc
Tuoi: 28
Ten:     
Tuoi: 0
Ten:
Tuoi: 0
```

## Static property
```cpp
static int x; // static prooperty  // 0xb4 - 0xb8
- Không phải là vùng địa chỉ liền kề với các biến trước
```
1. Tất cả những object sử dụng chung vùng nhớ của biến x này
2. Phải khởi tạo những đối tượng này mới có thể sử dụng x
```cpp
int SinhVien::x; /* cấp phát vùng nhớ cho biến x này */
```
- Có thể nằm ở data hoặc bss do mình quyết định (khởi tạo có data hoặc không). Nếu đưa vào trong hàm main sẽ lỗi vì nó không nằm ở stack

## Static method

1. ### Khi một method trong class được khai báo với từ khóa static:
2. ### Method này độc lập với bất kỳ đối tượng nào của lớp.
3. ### Method này có thể được gọi ngay cả khi không có đối tượng nào của class tồn tại.
4. ### Method này có thể được truy cập bằng cách sử dụng tên class thông qua toán tử :: .
5. ### Method này có thể truy cập các static property và các static method bên trong hoặc bên ngoài class.


