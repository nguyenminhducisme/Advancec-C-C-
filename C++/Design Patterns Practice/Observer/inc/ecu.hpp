#ifndef ECU_HPP
#define ECU_HPP

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Observer
{
    public:
        virtual void update(int speed, float temprature) = 0;
};

class Engine
{
    protected:
    virtual void notifyObserver() = 0;
    public:
        virtual void addObserver(Observer* ob) = 0;
        virtual void removeObserver(Observer* ob) = 0;
        
};

class Engine_Manager_Unit : public Engine
{
    private:
        int _speed_set_up;
        float _temprature_set_up;
        vector<Observer *> ob;
    public:
        void notifyObserver() override;    
        void removeObserver(Observer* _observers) override;
        void addObserver(Observer* _observers) override;

        void setEngineState(int speed, float temprature);
        void getState();

};


class Cooling_System : public Observer
{
    public:
        void update(int speed, float temprature) override;
};


#endif