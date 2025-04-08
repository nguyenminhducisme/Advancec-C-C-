#include "Ex1.hpp"
using namespace std;

// class SinhVien
// {
//     string name; // khai báo như này thì biến mặc định private
//     int age;
// };


/* Nếu muốn định nghĩa 1 hàm thuộc class ở bên ngoài phải khai báo như sau */
void SinhVien::display()
{
    cout <<"Ten: "<< name << endl;
    cout << "Tuoi: " << age <<endl;
}
/* Sử dụng cách này khi ta thiết kế thư viện */


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