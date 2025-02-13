#include <iostream>

void increment(int& aa) { aa++; } // pass by reference
// aa is an alias for the var we pass into this, it will run side effect

void incrementWithPointer(int* x) { (*x)++; }
// classic pointer stuff i saw in C
// dereference pointer to get value, increment the value
// this updates it in the memory

int main() {
    int myNumber = 10;
    increment(myNumber);
    std::cout << "number after first increment is " << myNumber << std::endl;
    incrementWithPointer(&myNumber);
    std::cout << "number after second increment is " << myNumber << std::endl;

}

