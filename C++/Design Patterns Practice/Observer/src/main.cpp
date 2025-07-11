#include "../inc/ecu.hpp"

int main()
{
    // Tạo subject manager
    Engine_Manager_Unit user1;

    // Tạo Observers
    Cooling_System cooling_system;

    user1.addObserver(&cooling_system);

    user1.setEngineState(100, 50.4);

    user1.getState();

}