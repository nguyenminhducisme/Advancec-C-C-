#include "../inc/ecu.hpp"

void Engine_Manager_Unit::notifyObserver() 
{
    for (auto _observers : ob)
    {
         _observers->update(_speed_set_up, _temprature_set_up);
    }
    cout << "Update ....\n";
}

void Engine_Manager_Unit::removeObserver(Observer* _observers)
{
    auto information = find(ob.begin(), ob.end(), _observers);

    if(information != ob.end())
    {
        ob.erase(information);
    }
}

void Engine_Manager_Unit::addObserver(Observer* _observers)
{
    ob.push_back(_observers);
}

void Engine_Manager_Unit::setEngineState(int speed, float temprature)
{
    this->_speed_set_up = speed;
    this->_temprature_set_up = temprature;

    notifyObserver();

}

void Engine_Manager_Unit::getState()
{
    cout << "Speed: " << this->_speed_set_up << endl;
    cout << "Temprature: " << this->_temprature_set_up << endl;
}

void Cooling_System::update(int speed, float temprature)
{
    cout << "Update Cooling System......\n";
    if(temprature > 90)
    {
        cout << "The temprature is getting over 90 degress!!!!\n";
    }
}

