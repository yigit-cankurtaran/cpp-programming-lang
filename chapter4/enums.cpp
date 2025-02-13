#include <iostream>

// enums are user defined data types, consists of named integer constants
// makes code more readable and maintainable, adds some type safety, prevents magic numbers

enum DaysOfWeek {
    Monday = 1, // by default it's assigned a 0, we start it at 1
    Tuesday, // this is 2, wed is 3 etc. automatically increments
    Wednesday,
    Friday,
    Saturday,
    Sunday
};

enum ErrorCodes: short { // we can specify different underlying types if we want
    NoError = 0,
    FileNotFound = 101,
    AccessDenied = 102,
    OutOfMemory = 200
};

int main(){
    DaysOfWeek today = DaysOfWeek::Wednesday;
    ErrorCodes errorCode = ErrorCodes::FileNotFound;

    std::cout << "today is " << today << std::endl;
    std::cout << "error code is " << errorCode << std::endl;

    // enums are very commonly used with switch statements
    DaysOfWeek day = DaysOfWeek::Saturday;
    switch(day) {
        case DaysOfWeek::Monday:
        case DaysOfWeek::Tuesday:
        case DaysOfWeek::Wednesday:
        case DaysOfWeek::Thursday:
        case DaysOfWeek::Friday:
            std::cout << "it's a weekday" << std::endl;
            break;
        case DaysOfWeek::Saturday:
        case DaysOfWeek::Sunday:
            std::cout << "it's the weekend" << std::endl;
        default:
            std::cout << "invalid day" << std::endl;
            break;
    }
}
