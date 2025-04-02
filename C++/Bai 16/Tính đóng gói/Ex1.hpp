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
   private:
         string name;   // thuộc tính (property) - là các thông số trong class
         int age;
   public:
         static int x; // static property

         void display() ;// phuowng thức (method) - là những hàm trong class
         int *ptr;
        //  void createObject()
        //  {
        //     SinhVien sv2;
        //     sv2.name = "Minh Duc";
        //     sv2.age  = 23;
        //  }
         // constructor - không có tham số
        //  SinhVien();

         // constructor - có tham số - không có giá trị mặc định
         // SinhVien(string newName, int newAge);

         // constructor - có tham số - có giá trị mặc định
         SinhVien(string newName =" ", int newAge = 20);
        // initialize list
        // SinhVien(string newName =" ", int newAge = 20)
        //     : name (newName), age(newAge)
        //     {
        //         display();
        //     }

        void setName(string newName)
        {
            for(int i = 0; i< newName.length(); i++)
            {
               char c = newName[i];
               if(!((c >= 'A' && c<='Z') || (c>='a' && c<='z') || c == ' '))
               {
                  cout << "chuoi khong hop le\n"; 
                  return;              
               }
               
            }
            name = newName;
        }
      
         // destructor
         ~SinhVien();

         static void show()
         {
            // name = 'a; Không được
            x = 50;// cái này lại được
            cout<<"this is static method"<< endl;
         }
};
#endif // EX1_HPP