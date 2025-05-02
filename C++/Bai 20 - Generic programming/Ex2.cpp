#include <iostream>
using namespace std;



template <typename T>
class Sensor{
    private:
        T value;
    public:
        Sensor(T init): value(init){}
        void readSensor(T newValue){ value = newValue; }
        T getValue() const { return value; }
        void display(){ cout << "Gia tri cam bien: " << value << endl; }
};

int main(int argc, char const *argv[]){
    Sensor<int> tempSensor(36.5);
    tempSensor.display();

    Sensor lightSensor(512);
    lightSensor.display();

    Sensor stateSensor("OFF");/* Muốn không định nghĩa kiểu dữ liệu như này thì ta phải dùng C++17 */
    stateSensor.display();
    
    return 0;
}


