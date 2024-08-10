#include <iostream>

int my_pointers()
{
    int var = 42;
    int *ptr = &var;
    // we take the address of var and pass it to the pointer

    std::cout << "value of var is " << var << std::endl;
    std::cout << "address of var is " << &var << std::endl;
    std::cout << "value stored in ptr is " << ptr << std::endl;
    // ptr's value is the address of var
    std::cout << "what ptr points to is " << *ptr << std::endl;
    // what ptr points to is the value of var
    // this is called dereferencing

    return 0;
}

int main()
{
    my_pointers();
    return 0;
}
