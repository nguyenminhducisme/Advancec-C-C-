#include "../Tinh dong goi/Ex1.hpp"
using namespace std;



/* Nếu muốn định nghĩa 1 hàm thuộc class ở bên ngoài phải khai báo như sau */
void SinhVien::display()
{
    cout <<"Ten: "<< name << endl;
    cout << "Tuoi: " << age <<endl;
}
/* Sử dụng cách này khi ta thiết kế thư viện */

int SinhVien::x; // đang cấp phát 1 vùng nhớ cho biến  x này


int main(){
    SinhVien sv1;
    sv1.setName("Anhminh");
    sv1.setAge(-12);
    // sv1.age = 23; 
    // sv1.name = "Anh12";
    sv1.display();

    sv1.x = 103;
    cout << sv1.x << endl;

    SinhVien::show();
  
    return 0;
}