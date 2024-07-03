//
//  main.cpp
//  Constructors and Destructors
//

#include <iostream>
static int core_ctr = 0;
class Core
{
public:
    Core(std::string & name) { std::cout << "Core constructor " << name << " " << core_ctr++ << std::endl; }
    virtual ~Core() { std::cout << "Core destructor " << --core_ctr << std::endl; };
};

class Base : public Core
{
public:
    Base(std::string & name) : Core(name) { std::cout << "Base constructor " << name << std::endl; }
    virtual ~Base() { std::cout << "Base destructor" << std::endl; }
};

class Other : public Core
{
public:
    Other(std::string & name) : Core(name) { std::cout << "Other constructor " << name << std::endl; }
    virtual ~Other() { std::cout << "Other destructor" << std::endl; }
};

class Derived : public Base, Other
{
public:
    Derived(std::string L) : Base(L), Other(L), label(L) { std::cout << "Derived constructor - " << label << std::endl; }
    virtual ~Derived() { std::cout << "Derived destructor - " << label << std::endl; }

    std::string label;
};

void function()
{

    std::cout << "--- function is called" << std::endl;

    Derived d2("function stack");

    Derived *d3 = new Derived("function heap");
    delete(d3);

    std::cout << "--- function returns" << std::endl;
}

const Derived d1("d1 outside stack");

int main(int argc, const char *argv[])
{
    // std::cout << "--- main is called" << std::endl;

    Derived d2("d2 main stack");

    function();

    std::string message = "d3 main heap";
    Derived *d3 = new Derived(message);
    delete(d3);

    std::cout << "--- main returns" << std::endl;
}