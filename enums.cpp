#include <iostream>

enum keyword
{
    ASM,
    AUTO,
    BREAK
};

enum darkness
{
    dark,
    light
    // has a 0:1 range
};

enum e2
{
    firstNum = 3,
    secondNum = 9
};

void weirdFunction(keyword key)
// key is gonna be from type keyword
{
    switch (key)
    {
    case ASM:
        std::cout << "ASM is " << ASM << std::endl;
        // prints "ASM is 0"
        break;

    case AUTO:
        std::cout << "AUTO is " << AUTO << std::endl;
        // prints "AUTO is 1"
        break;

    case BREAK:
        std::cout << "BREAK is " << BREAK << std::endl;
        // prints "BREAK is 2"
        break;

    default:
        std::cout << "not in keyword";
        break;

        // need to handle every case in a switch statement
    }
}

int main(int argc, char const *argv[])
{

    // we define 3 integer constants with this enum
    // we can call this with the keyword
    // each are called enumerator
    // these are assigned increasing from 0
    // ASM == 0, AUTO == 1, BREAK 2 etc.

    weirdFunction(ASM);
    weirdFunction(AUTO);
    weirdFunction(BREAK);
    // // weirdFunction(5);
    // the compiler doesn't let this compile
    // int isn't in type keyword

    std::cout << "second num in e2 is " << e2::secondNum << std::endl;
    // we can also call them with this syntax

    e2 lol = e2(5);
    std::cout << "lol is " << lol << std::endl;
    // we can do this for some reason because 5 is in the range of them

    e2 mightBeAnError = e2(1000000);
    std::cout << "might be an error is " << mightBeAnError << std::endl;
    // apparently it's not an error. crazy

    std::cout << "size of e2 is " << sizeof(e2) << std::endl;
    // sizeof endl is 4
    // 2 vars and their values

    return 0;
}
