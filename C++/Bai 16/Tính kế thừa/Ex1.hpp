#ifndef EX1_HPP
#define EX1_HPP

/*======================[INCLUDE FILES]=======================*/
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

/*======================[TYPES DEFINITIONS]===================*/
class DoiTuong
{
   protected:
      string name;
      int age;
      int id;

      bool checkname(string str)
      {
          for(int i = 0; i<str.length(); i++)
          {
              if(isdigit(str[i]) || !isalpha(str[i]))
              {
                  return false;
              }
          }
          return true;
      }

      bool checkAge(int newAge)
      {
         if(newAge < 0)
         {
            cout <<"Tuoi khong hop le\n";
            return false;
         }
         return true;
      }
      
   public:
      DoiTuong()
      {
         static int ID = 1;
         id = ID;
         ID++;
      }

     // setter method
     void setName(string str)
     {
      if(checkname(str))
      {
         name = str;
      }
      else
      {
         name = " ";
      }
     }

     void setAge(int newAge)
     {
         if(checkAge(newAge))
         {
            age = newAge;
         }
         else
         age = -1;
     }

     // getter method
     string getName()
     {
      return name;
     }

     int getAge()
     {
      return age;
     }

     int getID()
     {
      return id;
     }

     void display() ;
};
class SinhVien : public DoiTuong
{
   private:
         string chuyenNganh;
   public:
         void setMajor(string newMajor);

         void display();
};

class HocSinh: public DoiTuong// Ta muốn kế thừa class DoiTuong 
{
   private:
        
        string lop;
   public:
        void setLop(string newClass);

        void display();
};

class GiaoVien: public  DoiTuong // Ta muốn kế thừa class DoiTuong
{
   private:
        
        string chuyenMon;
   public:
        void setSubject(string newSubject);
        void display();
};


#endif // EX1_HPP