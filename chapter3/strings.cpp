#include <iostream>
#include <string>

int main() {
    std::string s1 = "hello";
    std::string s2 = "world";

    std::string s3 = s1 + ", " + s2 + "!\n";
    std::cout << s3;

    std::string nick = "sleepyhead";
    std::string noun = nick.substr(6, 4); // starts from index 6, 4 chars long
    // we start where the thing we want starts, not when the thing we don't want ends
    nick.replace(6, 4, ""); // remove the "head" portion
    std::cout << "noun is " << noun << ".\n";
    std::cout << "nick after the changes is " << nick << ".\n";

    /*
    std::string name;
    std::cout << "please enter your name:\n";
    std::cin >> name;
    std::cout << "hello, " << name << "!\n";
    */

    std::string full_name;
    std::cout << "please enter your full name:\n";
    getline(std::cin, full_name); // std::cin ends when a whitespace char starts
    // if we want the full line, we use getline with cin
    std::cout << "hello, " << full_name << "!\n";
}
