#include "../Constructor/EX1.hpp"

// truy cập các thành viên từ bên ngoài / bên trong
// có thể gọi trực tiếp hoặc thông qua tên class

void SinhVien::display()
{
    cout << "Ten: " << name << endl;
    cout << "Tuoi: " << SinhVien::age << endl;
}

SinhVien::SinhVien(string newName, int newAge) 
{
    name = newName;
    age = newAge;
}


SinhVien::~SinhVien()
{
    name = "";
    age = 0;
    display();
}


int main()
{
    SinhVien sv1("anh", 23);  // đối tượng (object)
    
    sv1.display();

    SinhVien sv2;
    sv2.display();
    return 0;
}
