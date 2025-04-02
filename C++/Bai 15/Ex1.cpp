#include "Ex1.hpp"



// typedef struct Ex1
// {
//     int x;
//     int y;

//     void display()
//     {
//         cout << x << "" << y << endl;
//     }
// }Ex1; trong C++ co the dinh nghia ham trong struct



void SinhVien::display() 
{
    cout << "Ten: " << name << endl;
    cout << "Tuoi: "<< SinhVien::age << endl;
}

SinhVien::SinhVien(string newName, int newAge)
{
    ptr = (int *)malloc(sizeof(int));
    name = newName;
    age = newAge;
    display();
}

SinhVien::~SinhVien()
{
    name = " ";
    age = 0;
    free(ptr);
    display();
}

int SinhVien::x; /* cấp phát vùng nhớ cho biến x này */

int main()
{
    // cout << "hello\n";
    // cout << 2 <<endl;
    // cout << 3.5 << endl;

    // int x;
    // cin >> x;
    // cout << x;

    SinhVien sv1 ("mei2e", 23); // đối tượng (object) - là những biến được gọi từ class
    // sv1.age = 34; // khong the truy cap (inaccessible), tức sẽ mặc định private. Nên ở trên sẽ đổi thành public
    // cout << sv1.age << endl;
    // sv1.name = "Duc";
    //sv1.display();



    SinhVien sv2("Duc", 28); // nếu không truyền vào thì lấy giá trị mặc định, còn nếu truyền vào thì lấy giá trị mới truyền vào
    //sv2.display();

    sv2.x = 100;
    cout << sv2.x << endl; /*undefined reference to `SinhVien::x' ===> không tìm thấy được vùng địa chỉ của biến x do chưa cấp phát địa chỉ cho nó*/

    SinhVien::show();

    return 0;
}