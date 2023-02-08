#include <iostream>
#include <memory>
#include <string>

class Car // Abstract now because of =0
{
public:
    Car() = default;
    virtual ~Car() {} // Good Practice for inhereting classes

    virtual void driving() = 0;

};

class Bmw : public Car
{
public:
    Bmw() : Car() {}
    void driving() override // no driving() = error
    {
        std::cout << "Driving a BMW car ..." << std::endl;
    }
};

class Ford : public Car
{
public:
    Ford() : Car() {}
    void driving() override
    {
        std::cout << "Driving a Ford car ..." << std::endl;
    }
};

class Mustang : public Ford {

public:
    Mustang() : Ford() {}
    void driving() override
    {
        std::cout << "Driving Mustang..\n";
    }
};

class PolyCheck {
    /*   std::shared_ptr<Car> p = nullptr;

       char type = 0;

       do
       {
           std::cout << "enter car type: ";
           std::cin >> type;

           switch (type)
           {
           case 'b':
               p = std::make_shared<Bmw>();
               break;
           case 'f':
               p = std::make_shared<Ford>();
               break;
           default:
               p = std::make_shared<Car>();
               break;
           }

           p->driving();
       } while (type != 0);*/
    Car* CarPtr = nullptr;
    Bmw cbmw = Bmw();

public:
    void Do(){   

        Mustang mustang = Mustang();

        CarPtr = &cbmw;
        CarPtr->driving();
        CarPtr = &mustang;
        CarPtr->driving();
    }
};