#include <iostream>
using namespace std;

/*
* private constrcutor: Để đảm bảo không thể khởi tạo từ bên ngoài class
* con trỏ static: trỏ tới đối tượng duy nhất này
* hàm static: tạo đối tượng
*/

void gpio_inti()
{
    cout << "GPIO Init params\n";
}

class GPIO
{
    private:
        GPIO()
        {
            cout << "This is contructor" << endl;
        }

      static  GPIO *gpio;

      ~ GPIO(){ // Hàm hủy không thể tác động tới biến static
        delete gpio;    
        cout << "Destructor\n";
      }
      
    public:
        static GPIO* createObject() // Để khởi tạo trực tiếp từ class
        {
            // gpio = new GPIO();
            // cout << &gpio << endl;

            if(gpio == nullptr)
            {
                gpio = new GPIO();
                gpio_inti();
            }
            return gpio;
        }
        static void delete_Objects(){
            delete gpio;    
            cout << "Destructor\n";
          }
    
};

GPIO *GPIO::gpio = nullptr;

int main()
{
    // GPIO gp1, gp2, gp3;
    GPIO::createObject(); 
    GPIO::createObject(); 
    GPIO::createObject(); 
    // Chỉ trả 1 lần vì constructor chỉ chạy khi có đối tượng mới được tạo ra

    GPIO::delete_Objects();
   return 0;
}