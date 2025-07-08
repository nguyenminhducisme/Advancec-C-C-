#include "../inc/ecu.hpp"
using namespace ECU_Calib;



ECU::ECU()
{
    _speed = 0;
    _temprature = 0;
    Fuel_Injection_Rate = 0;
}




void ECU::setEngineSpeed(int speed)
{
    _speed = speed;
    if((speed < 0) || (speed > 6000))
    {
        cout << "Warning!!! The installed speed is getting over the safe boundary\n";
    }
}


void ECU::setEngineTemprature(float temprature)
{
    if((temprature < -20) || (temprature > 100))
    {
        cout << "Not approriate temprature!!! Please reinstall\n";
    }
    else
    _temprature = temprature;
}


