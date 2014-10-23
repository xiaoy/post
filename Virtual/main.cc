#include <iostream>

class Base{
public:
    virtual ~Base(){ std::cout << "Base Dis Constructor called\n";}
};

class SubClass : public Base{
public:
    ~SubClass() { std::cout <<"SubClass Dis Constructor called\n";}
};

int main(){
    SubClass sub;

    std::cout << "base pointer begin:\n";
    Base* base = new SubClass();
    delete base;
    std::cout << "base pointer end:\n";
    return 0;
}
