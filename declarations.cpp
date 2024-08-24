#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string kings[] = {"Antigonus", "Seleucus", "Ptolemy"};

    std::string *firstKingAddress = &kings[0];
    std::string *secondKingAddress = &kings[1];
    // we have to use the star here
    // gets a no viable conversion error
    // because we're getting the address

    std::cout << "first member of kings is " << kings[0] << std::endl;
    std::cout << "first king's address is " << firstKingAddress << std::endl;
    std::cout << "first member of kings is, again, " << *firstKingAddress << std::endl;
    std::cout << "second member of kings is " << kings[1] << std::endl;
    std::cout << "second king's address is " << secondKingAddress << std::endl;
    std::cout << "second member of kings is, again, " << *secondKingAddress << std::endl;
    return 0;
}
