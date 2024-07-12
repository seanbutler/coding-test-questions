#include <iostream>

class BaseClass
{
public:
    BaseClass(int I, int J) : i(I), j(J) {}

    virtual int do_work() const = 0;

    int const i;
    int const j;
};

class DerivedClass : public BaseClass
{
public:
    DerivedClass() : BaseClass(normal, normal) {}

    virtual int do_work() const override
    {
        return i + j;
    }
    static int const normal = 1;
};

// static int do_work( BaseClass & first,  BaseClass & second)

// int do_work( BaseClass & first,  BaseClass & second)
// {
//     return first.do_work() + second.do_work();
// }

class Worker
{
public:
    int do_work(BaseClass &first, BaseClass &second)
    {
        return first.do_work() + second.do_work();
    }
};

int main(int, char **)
{
    Worker worker;
    DerivedClass obj1, obj2;

    // return worker.do_work(obj1, obj2);
    // return obj1.do_work() + obj2.do_work();
    // return do_work(obj1, obj2);
}

// 1. take the above code an put it in godbolt, make sure you use -Ofast
// 2. comment and uncomment the return values (lines 45 & 46) of the main function, each time check the generated code
//       // return worker.do_work(obj1, obj2);
//       // return obj1.do_work() + obj2.do_work();

// 3. now use the non-class do_work function, you will need to uncomment lines 26 - 29, check the generated code
//       // return do_work(obj1, obj2);

// 4. put the static keyword in the functiond eclaration as per line 24, check the generated code
//       // static int do_work( BaseClass & first,  BaseClass & second)

// use of const allows the compiler to optimise in ways that can remove large amounts of cod
// use of classes allows the compiler to know exactly the scope of a given function *method and variable * member so can optimise better
// use of static for c-style functions allows the compiler to assume they arent called outside the current compilation unit and optimise them out if unused