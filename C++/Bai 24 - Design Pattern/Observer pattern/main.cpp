#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// interface cho cac đối tượng cần theo dõi và cần nhận được các thông báo
class IObserver
{
    public:
        virtual void update(double data) = 0;
};

// concrete observer: kế thừa và triển khai từ IObserver

class Observer1 : public IObserver
{
    public: 
        void update(double data) override
        {
            cout << "Update date for observer1\n";
        }
};

class Observer2 : public IObserver
{
    public: 
        void update(double data) override
        {
            cout << "Update date for observer2\n";
        }
};

// các observer khác


// interface for subject
class ISubject
{
    protected:
        virtual void notifyObserver() = 0;
    public:
        virtual void registerObserver(IObserver* obserber) = 0;
        virtual void removerObserver(IObserver* obserber) = 0;

};

class SubjectManager : public ISubject
{
    private:
        double value1, value2;
        vector<IObserver *> observers;

    protected:
         void notifyObserver() override
         {
            for(auto ob : observers)
            {
                ob->update(value1);
            }
         }
    public:
        void registerObserver(IObserver* ob) override
        {
            observers.push_back(ob);
        }
        void removerObserver(IObserver* ob) override
        {
            auto o = find(observers.begin(), observers.end(), ob);

            if(o != observers.end())
            {
                observers.erase(o);
            }
        }

        // getter
        void setData()
        {
            
        }
};