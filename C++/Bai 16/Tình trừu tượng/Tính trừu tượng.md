# Tính trừu tượng

```cpp
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
      
   public:
         static int x; // static property

         void display() ;// phuowng thức (method) - là những hàm trong class
         int *ptr;
    
         // constructor - có tham số - có giá trị mặc định
         SinhVien(string newName =" ", int newAge = 20);
        // initialize list
        // SinhVien(string newName =" ", int newAge = 20)
        //     : name (newName), age(newAge)
        //     {
        //         display();
        //     }

        
         // destructor
         ~SinhVien();

         static void show()
         {
            // name = 'a; Không được
            x = 50;// cái này lại được
            cout<<"this is static method"<< endl;
         }
};
```

- Giống như static global trong C, để ẩn những phần code mà không muốn user động tới, bằng cách bỏ phần đó vào trong private
### Tính trừu tượng đề cập đến việc ẩn đi các chi tiết cụ thể của một đối tượng và chỉ hiển thị những gì cần thiết để sử dụng đối tượng đó.

