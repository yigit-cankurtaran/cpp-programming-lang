#include <iostream>

int main()
{
    int num = 0;
    // an outstream
    std::cout << "enter a number: ";
    // an instream
    std::cin >> num;

    // prints whatever number we put into num
    std::cout << num;
}