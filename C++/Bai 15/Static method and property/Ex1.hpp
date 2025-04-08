#ifndef EX1_HPP
#define EX1_HPP

/*======================[INCLUDE FILES]=======================*/
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

/*======================[TYPES DEFINITIONS]===================*/
class SinhVien
{
public:
    string name; // khai báo như này thì biến sẽ truy cập được vì nó đang public
    int age;
    
    static int x; // static property

    static void show()
    {
        
        cout << "This is static method" << endl;
    }

    void display();

   //  void createObject()
   //  {
   //      SinhVien sv2; // có thể khai báo object chính trong class
   //      sv2.name = "trung";
   //      sv2.age = 24;
   //      cout << "Ten: " << sv2.name << endl << "Tuoi: "<< sv2.age << endl;
   //  }
};
#endif // EX1_HPP