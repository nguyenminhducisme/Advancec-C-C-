# FACTORY PATTERN

- Thuộc nhóm Creational, cho phép ẩn đi việc khởi tạo đối tượng cụ thể, thay vào đó là một __cơ chế chung__ để khởi tạo.

- Chia làm 3 loại
    - Simple factory
    - Factory method
    - Abstract factory

## 1. Simple factory

- không khởi tạo trực tiếp các đối tượng mà sử dụng một phương thức hoặc 1 lớp trung gian để __quyết định__ loại đối tượng nào sẽ được khởi tạo hoặc một lớp trung gian để quyết định loại đối tượng nào sẽ được khởi tạo __dựa trên tham số đầu vào__ hoặc logic cụ thể

```cpp
class Create
{
    void createObject(Objecttype type)
    {
        if(type == "tpms")
        {
            --> cần phải khởi tạo một đối tượng là TPMS
        }
    }
};
```

- Các thành phần chính
    - Product: interface mà các class con sẽ kế thừa
    - Concrete product: Các lớp con cụ thể được tạo ra từ __Product__
    - Factory: Một __class hoặc hàm__ đảm nhiệm việc tạo ra đối tượng

- Thường chỉ phù hợp cho hệ thống nhỏ (biết trước được số đối tượng user sẽ khởi tạo)

```cpp
#include <iostream>
#include <string>

using namespace std;

// Abstract class
class Sensor{
    public:
        virtual void readData() = 0;
};

// Temperature class
class TemperatureSensor : public Sensor{
    public:
        void readData() override {
            cout<<"reading temp data: "<<endl;
        }
};

// Humidity class
class HumiditySensor : public Sensor{
    public:
        void readData() override {
            cout<<"reading humidity data: "<<endl;
        }
};

// Factory class (Creator)
class SensorFactory{
    public:
        static Sensor* createSensor(const string& sensorType){
            if(sensorType == "temp"){
                return new TemperatureSensor();     // trả về đối tượng TemperatureSensor
            }
            else if (sensorType == "humi"){
                return new HumiditySensor();        // trả về đối tượng PressureSensor
            }
            else{
                return nullptr;                     // trả về con trỏ null
            }
        }
};


int main(int argc, char const *argv[])
{
    Sensor* sensor = SensorFactory::createSensor("humi");
    sensor->readData();

    sensor = SensorFactory::createSensor("temp");
    sensor->readData();

    return 0;
}
```


## 2. Factory method

- Dùng để tạo đối tượng mà khồn chỉ định chính xác lớp cụ thể sẽ được tạo ra, thay vào đó để cho các lớp con quyết định lớp nào sẽ được khởi tạo

- Các thành phần chính
    - Product: interface mà các class con sẽ kế thừa
    - Concrete product: các lớp con cụ thể được tạo ra từ __Product__
    - Creator: Khai báo phương thức khởi tạo đối tượng
    - Concrete creator: triển khai phương thức trên để tạo ra đối tượng cụ thể

