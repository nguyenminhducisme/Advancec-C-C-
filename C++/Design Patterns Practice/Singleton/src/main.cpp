#include "../inc/ecu.hpp"
using namespace ECU_Calib;

ECU *ECU::ecu = nullptr;

int main()
{
    ECU *user = ECU::Set_Working_Parameter();
    user->setEngineSpeed(2000);
    user->setEngineTemprature(110);
    user->diagnostic();

    return 0;
    
    
}