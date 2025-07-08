#ifndef ECU_HPP
#define ECU_HPP

#include <iostream>
using namespace std;



namespace ECU_Calib
{
class ECU
{
    private:
        ECU(); // Hàm khởi tạo ECU ban đầu

        static ECU *ecu;

        float _temprature;
        int _speed;
        int Fuel_Injection_Rate;

        // Các hàm lấy dữ liệu ECU
        int getEngineSpeed(){return _speed;}
        float getEngineTemprature(){return _temprature;}
        int isOverHeating()
        {
            if(_temprature > 100)
            {
                cout<< "Engine is overheating!!!\n";
                return 0;
            }
            else return 1;
        }
        
        
    public:
        static ECU* Set_Working_Parameter()
        {
            if(ecu == nullptr)
            {
                ecu = new ECU();
            }
            return ecu; 
        }

        void setEngineSpeed(int speed);
        void setEngineTemprature(float temprature);
        void diagnostic()
        {        
            cout << "Speed of engine: " << getEngineSpeed() << endl;
            if(isOverHeating() == 0)
            {
                cout << "Warning!!! The temprature is getting over 100 degrees" << endl;
                cout << "The current temprature: " << getEngineTemprature() << endl;
            }
            else
            cout << "The current temprature: " << getEngineTemprature() << endl;
        }

       
        
};
}//ECU_Calib
#endif