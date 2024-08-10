#include <iostream>

bool accept()
{

    std::cout << "first accept\n";
    std::cout << "Do you want to proceed (y or n)?\n"; // write question
    char answer = 0;
    std::cin >> answer; // read answer
    if (answer == 'y')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool accept2()
{
    std::cout << "second accept\n";
    std::cout << "Do you want to proceed (y or n)?\n"; // write question

    char answer = 0;
    std::cin >> answer;

    switch (answer)
    {
    case 'y':
        return true;

    case 'n':
        return false;

    default:
        std::cout << "I'll take that for a no.";
        return false;
    }
}

bool accept3()
{
    int tries = 1;
    while (tries < 4)
    {
        std::cout << "Do you want to proceed (y or n)?\n"; // write question
        char answer = 0;
        std::cin >> answer;

        switch (answer)
        {
        case 'y':
            std::cout << "You accepted.\n";
            return true;

        case 'n':
            std::cout << "You refused.\n";
            return false;

        default:
            std::cout << "I don't know what you're talking about.\n";
            tries += 1;
        }
    }
    // it has to return a bool value all the time.
    std::cout << "I'll take that for a no.\n";
    return false;
}

int main()
{

    accept3();

    return 1;
}
