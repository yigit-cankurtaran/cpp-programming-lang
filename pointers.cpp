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

int pointer_arithmetic()
{
    std::cout << std::endl;

    int arr[] = {10,
                 20,
                 30,
                 40,
                 50};
    int *ptr = arr;
    // created a pointer that points to my array

    std::cout << "Array elements using pointer arithmetics" << std::endl;

    for (int i = 0; i < 5; i++)
    {
        std::cout << *ptr << " ";
        // output the value the pointer points at
        ptr++;
        // move to the next memory address
    }

    std::cout << std::endl;

    return 0;
}

int dynamic_allocation()
{
    std::cout << std::endl;

    // dynamically allocating memory
    int *ptr = new int;
    // we're assigning a value with dereferencing
    *ptr = 25;

    std::cout << "value at ptr is " << *ptr << std::endl;
    std::cout << "address of ptr is " << ptr << std::endl;

    delete ptr;
    // we free the allocated memory with delete

    std::cout << "new value of ptr is " << *ptr << std::endl;
    std::cout << "new address of ptr is " << ptr << std::endl;
    // the address is still there but the value is 0

    return 0;
}

int null_pointers()
{
    std::cout << std::endl;

    int *ptr = nullptr;

    if (ptr)
    {
        std::cout << "pointer is not null, value: " << *ptr << std::endl;
    }
    else
    {
        std::cout << "pointer is null, cannot dereference" << std::endl;
        // this triggers
    }

    int var = 5;
    ptr = &var;
    // we point the pointer to the address of var now

    if (ptr)
    {
        std::cout << "pointer is not null, value: " << *ptr << std::endl;
        // this triggers
        // null pointers don't have to stay null forever
    }
    else
    {
        std::cout << "pointer is null, cannot dereference" << std::endl;
    }

    return 0;
}

int main()
{
    my_pointers();
    pointer_arithmetic();
    dynamic_allocation();
    null_pointers();
    return 0;
}
