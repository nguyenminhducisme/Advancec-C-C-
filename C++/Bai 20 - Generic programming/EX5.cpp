#include<iostream>
#include<string>
using namespace std;


class Sensor
{
    public:
        virtual double getvalue() const = 0;
        virtual string getUnit() const = 0;
};

class TempSensor : public Sensor
{
    private:
        double temp;
    public:
        double getvalue() const override
        {
            return 40.5;
        }
        string getUnit() const override{
            return "Celcius";
        }
};

class TPMS : public Sensor
{
    private:
        double pressure;
    public:
        double getvalue() const override
        {
        return 40.5;
        }
        string getUnit() const override{
        return "Pascal";
        }
};

template <typename Sensor1, typename Sensor2>
class SensorMonitor 
{
    private:
        Sensor1 sensor1;
        Sensor2 sensor2;
    public:
        SensorMonitor(Sensor1 s1, Sensor2 s2) : sensor1(s1), sensor2(s2){}
        void display() const{
            cout <<"Sensor 1 value: " << sensor1.getvalue() << " " << sensor1.getUnit() << endl;
            cout <<"Sensor 2 value: " << sensor2.getvalue() << " " << sensor2.getUnit() << endl;
        }

};

int main(void)
{
    TempSensor tempSensor;
    TPMS tPMS;

    SensorMonitor monitor(tempSensor, tPMS); // Cách này chỉ dùng được đối với C++17
    // Trong C++11 ta phải dùng như sau
    /* SensorMonitor<TempSensor, TPMS> monitor(tempSensor, tPMS);*/
    monitor.display();
    return 0;
}