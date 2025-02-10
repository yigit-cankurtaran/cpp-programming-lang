#include <iostream>

bool accept() {
    std::cout << "Do you want to proceed (y or n)?\n"; // writing question

    char answer = 0;
    std::cin >> answer; // we read the answer

    if (answer == 'y') {
        std::cout << "You pressed y.";
        return true;
    }

    return false;
}

int main() {
    accept();
}
