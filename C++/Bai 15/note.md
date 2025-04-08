# CLASS
- Để định nghĩa 1 lớp trong C++
- Là nền tảng của OOP trong C++

### Cũng giống như struct or union, nhưng có thể lưu được các kiểu định nghĩa phức tạp.
![alt text](image.png)
```cpp
class Classname
{
    Access specifier:  /* can be private, public and protected */
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
1. Có thể truy cập các biến từ bên ngoài
```cpp
// class SinhVien
// {
//     string name; // khai báo như này thì biến mặc định private
//     int age;
// };
class SinhVien
{
public:
    string name; // khai báo như này thì biến sẽ truy cập được vì nó đang public
    int age;
    
    void display()
    {
        // cout <<"Ten: "<< SinhVien::name << endl;
        // cout << "Tuoi: " << SinhVien::age <<endl;
        /* Một cách khác ngắn gọn hơn, có thể gọi trực tiếp biến đó ra hoặc gọi thông qua class đều được */
        cout <<"Ten: "<< name << endl;
        cout << "Tuoi: " << age <<endl;
    }
};
int main(){
    SinhVien sv1;
    /* Khai báo như này sẽ dẫn đến lỗi 
    Ex1.cpp:13:9: error: 'int SinhVien::age' is private within this context
     sv1.age = 23;
         ^~~
Ex1.cpp:8:9: note: declared private here
     int age;
         ^~~
    
    Vì các biến trong class đang trong phạm vi private 
    */
    sv1.age = 23; 
    sv1.name = "Anh";
    sv1.display();
    return 0;
}
```
- Trong class thì biến gọi là property (thuộc tính), hàm thì được gọi là phương thức (method), còn những biến được khai báo từ class như SinhVien sv1 thì được gọi là object (đối tượng)

```cpp
- Cũng có thể khai báo từ bên trong  void createObject()
    {
        SinhVien sv2; // có thể khai báo object chính trong class
        sv2.name = "trung";
        sv2.age = 24;
        cout << "Ten: " << sv2.name << endl << "Tuoi: "<< sv2.age << endl;
    }
```

## CONSTRUCTOR:
1. Là 1 hàm được khai báo trong class
2. Có tên trùng với tên class
3. Không có kiểu trả về
4. Được tự động gọi khi khởi tạo những đối tượng (object), không quan trọng khởi tạo bên trong hay bên ngoài
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

### Có 4 dạng:
1. không có tham số: 
```cpp
SinhVien(); 
```
2. có tham số, không có giá trị mặc định:
```cpp
SinhVien(string newName, int newAge);
```
3. có tham số, có giá trị mặc định:
```cpp
SinhVien(string newName = " ", int newAge = 18);
```
4. gán dữ liệu cho constructor ở bên ngoài, cách này thường sử dụng nhất vì nó linh hoạt và đơn giản.
```cpp
/* Khai baos trong file header */
SinhVien(string newName = " ", int newAge = 18)
        : name(newName), age(newAge)
    {

    }
```


* Linh hoạt hơn khi sử dụng

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
1. Có thêm kí tự ~ ở trước tên và có tên trùng với tên của class.
2. Không có kiểu trả về và được tự động gọi ra như constructor.
3. Được tự động gọi ra trước khi object được giải phóng.
 
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
1. Tất cả những object ta khai báo ra đều sử dụng chung địa chỉ của biến x này
2. Phải khởi tạo những đối tượng này mới có thể sử dụng x
```cpp
int SinhVien::x; /* phải cấp phát vùng nhớ cho biến x này */
```
- Có thể nằm ở data hoặc bss do mình quyết định (khởi tạo có data hoặc không). Nếu đưa vào trong hàm main sẽ lỗi vì nó không nằm ở stack

## Static method

1. ### Khi một method trong class được khai báo với từ khóa static:
2. ### Method này độc lập với bất kỳ đối tượng nào của lớp.
3. ### Method này có thể được gọi ngay cả khi không có đối tượng nào của class tồn tại.
4. ### Method này có thể được truy cập bằng cách sử dụng tên class thông qua toán tử :: .
5. ### Method này có thể truy cập các static property và các static method bên trong hoặc bên ngoài class.
```cpp
static void show()
    {
        // Nếu khai báo biến có sẵn trong class
        name = "anh"; // Như này thì lại lỗi
        // Nhưng nếu ta khai báo 1 biến static
        x = 200; // thì lại không sao vì có đặc điểm giống nhau có thể gọi trực tiếp từ class nên có thể tương tác với nhau
        
        cout << "This is static method" << endl;
    }
```


