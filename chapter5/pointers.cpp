#include <iostream>

void incrementByValue(int value) {
    value++; // modifies local copy 'value'
}

void incrementByPointer(int* ptrValue) {
    (*ptrValue)++; // dereference pointer and increment value at that address
    // pointers can be used to change values outside of their scope (side effects)
    // this happens because pointers access memory and change values directly
        // instead of having to copy values and changing them
}

int main() {
    // pointers are declared with asterisks before var name
    int* ptrToInt; // ptrToInt stores the address of an integer
    double* ptrToDouble; // ptrToDouble stores the address of a double
    char* ptrToChar; // ptrToChar stores the address of a char
    // syntax is data_type* ptr_name

    int number = 25; // declare an integer var
    ptrToInt = &number; // address of number to ptrToInt
    // & for address, * for dereferencing.

    std::cout << "value of number is " << number << std::endl;
    std::cout << "address of number is " << &number << std::endl; // & for address
    std::cout << "value of ptrToInt is " << ptrToInt << std::endl;
    std::cout << "value pointed by ptrToInt is " << *ptrToInt << std::endl; // dereference pointer
 
    *ptrToInt = 50;
    std::cout << "value pointed after modification is is " << number << std::endl;
    // number is now 50 bc we directly manipulate it in the memory
    std::cout << std::endl;

    int numbers[5] = {1, 2, 3, 4, 5};
    int* ptrToArray;

    ptrToArray = numbers; // arrays decay to a pointer to the first element (&numbers[0])
    std::cout << "first element of array using name: " << numbers[0] << std::endl;
    std::cout << "first element of array using pointer: " << *ptrToArray << std::endl;

    std::cout << "second element of array using name: " << numbers[1] << std::endl;
    std::cout << "second element of array using pointer: " << *(ptrToArray + 1) << std::endl;
    // we need the parentheses bc execution order
    // points to the next element of the array. + 1 moves it forward by 1 * size of datatype
    // pointer arithmetic, very easy to get wrong so should be avoided

    std::cout << "array name as pointer: " << numbers << std::endl;
    std::cout << "pointer ptrToArray: " << ptrToArray << std::endl;
    std::cout << std::endl;

    int funcNum = 10;
    std::cout << "before incrementByValue: " << funcNum << std::endl;
    incrementByValue(funcNum);
    std::cout << "after incrementByValue: " << funcNum << std::endl;

    std::cout << "before incrementByPointer: " << funcNum << std::endl;
    incrementByPointer(&funcNum);
    std::cout << "after incrementByPointer: " << funcNum << std::endl;

    return 0;
}
