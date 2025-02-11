#include <iostream>

class Base {
    public:
        virtual void foo() { // virtual function, can be redefined later 
            std::cout << "this is the base\n";
        }
};

class Derived : public Base {
    // this means derived implements Base
    // ": public" can be read as "is derived from, implements, is a subtype of" etc.
    public:
        void foo() override { 
            std::cout << "this is derived\n";
        }
};

void call_foo(Base& obj) { // accepts any object derived from Base
    obj.foo(); // calls the correct version due to virtual foo function
}

int main() {
    Derived d;
    Base b;
    call_foo(d);
    call_foo(b);
}
