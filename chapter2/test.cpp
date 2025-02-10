#include <iostream>

bool accept() {
    std::cout << "Do you want to proceed (y or n)?\n"; // writing question
    // all the std's can be skipped by writing "using namespace std;" on top
    // but it's not best practice

    char answer = 0;
    std::cin >> answer; // we read the answer

    if (answer == 'y') {
        std::cout << "You pressed y.";
        return true;
    }

    return false;
}

bool accept2(){
    std::cout << "Do you want to proceed (y or n)?\n"; // writing question

    char answer = 0;
    std::cin >> answer;

    switch(answer){ // "tests a value against constants"
        // we're testing answer against the following characters
        case 'y':
            std::cout << "You're proceeding";
            return true;
        case 'n':
            return false;
        default: // if answer is not either 'y' or 'n'
            std::cout << "I'll take that for a no.\n";
            return false;
    }
}

bool accept3(){
    int tries = 1;
    while (tries < 4) { // basic loop. gives us 4 tries.
        std::cout << "Do you want to proceed (y or n)?\n"; // writing question
        char answer = 0;
        std::cin >> answer;

        switch(answer){
            case 'y':
                std::cout << "You're proceeding";
                return true;
            case 'n':
                return false;
            default:
                std::cout << "I'll take that for a no.\n";
                tries += 1;
        }
    }
    std::cout << "I'll take that as a no.\n";
    return false;
}

int main() {
    accept();
    accept2();
    accept3();
}
