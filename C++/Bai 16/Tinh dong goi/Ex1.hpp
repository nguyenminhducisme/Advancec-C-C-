#ifndef EX1_HPP
#define EX1_HPP

/*======================[INCLUDE FILES]=======================*/
#include <iostream>
#include <string>
#include <stdlib.h>
#include<cctype>
using namespace std;

/*======================[TYPES DEFINITIONS]===================*/
class SinhVien
{
private:
    string name; // khai báo như này thì biến sẽ truy cập được vì nó đang public
    int age;
public:
    static int x; // static property

    void setName(string newName)
    {
         char c;
         for(int i =0; i<newName.length(); i++)
         {
            char c = newName[i];
            if(!isalpha(c))
            {
               cout << "Ten khong hop le\n" ;
               return;
            }
         }
        name = newName;
    }

    bool checkAge(int newAge)
    {
      if(newAge < 0)
      {
         cout << "Tuoi khong hop le\n" ;
         return 0;
      }
      return true;
    }
    void setAge(int newAge)
    {
      if(checkAge(newAge))
      age = newAge;

      else age = -1;
    }

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
//    SinhVien(string newName, int newAge)
//       : name(newName), age(newAge)
//    {
//       display();
//   }
   ~SinhVien()
   {
      name = " ";
      age = 0;
      display();
   }
};
#endif // EX1_HPP