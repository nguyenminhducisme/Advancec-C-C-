#include <iostream>

using namespace std;


class IComponent
{
    public:
        virtual void function() = 0;
};

class Component1 : public IComponent
{
    public:
        void function() override
        {
            cout<< "Component 1\n";
        }

};

class Component2 : public IComponent
{
    public:
        void function() override
        {
            cout<< "Component 2\n";
        }
};

class Decorator : public IComponent
{
    private:
        IComponent *wrapComponent;
    public: 
        Decorator(IComponent *cp) : wrapComponent(cp){}

        void function() override
        {
            wrapComponent->function();
        }
};

class Decorator1 : public Decorator
{


    public: 
        Decorator1(IComponent *cp)
            : Decorator(cp){}

        void function() override
        {
            Decorator ::function();
            addtion1();
        }

        void addtion1()
        {
            cout << "add function 1\n";
        }
};

int main()
{
    IComponent *cp = new Component1();
    
    cp = new Decorator1(cp);

    cp->function();

    return 0;
}