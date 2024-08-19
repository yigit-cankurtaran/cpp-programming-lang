#include <iostream>
#include <string>
#include <list>

struct Entry
{
    std::string name;
    // have to use std here because i'm not using namespace std
    int number;
};

std::ostream &operator<<(std::ostream &os, const Entry &e)
{
    os << e.name << ": " << e.number;
    // os is the outstream
    // we pass in the name of the Entry we send
    // then a colon and space and then the number
    // pretty much the constructor for this?
    return os;
}

std::list<Entry> phone_book;
// using list instead of a vector for hpone book this time
// accessing elements with given value
// adding elements to a list is generally easy

void add_entry(Entry &e, std::list<Entry>::iterator i)
{
    phone_book.push_front(e); // add to beginning
    phone_book.push_back(e);  // add to end
    phone_book.insert(i, e);  // add before the element 'i' is
}
// Entry &e is a reference to an Entry object
// not copied, referenced directly
// the 2nd is an iterator to an element in the phone_book list
// front adds an Entry object e to the list
// back adds an Entry object e to the list
// insert puts the Entry object E at the position in the
// phone_book list indicated by the iterator i

int main(int argc, char const *argv[])
{
    // // Entry new_entry{"John Doe", 123456};
    // created new entry
    // that throws an error for me for some reason?? but its valid
    // the following is the old school way to do it

    Entry new_entry;
    new_entry.name = "John Doe";
    new_entry.number = 123456;

    std::list<Entry>::iterator beginning = phone_book.begin(); // iterator to the first element

    add_entry(new_entry, beginning);
    // // std::cout << "phone book is " << phone_book;
    // this doesn't work right now
    // because it doesn't know how to print the Entry
    // we can create an operator for it

    std::cout << phone_book.size() << " phone book entries: " << std::endl;
    // size gets how many elements are there in the phone book

    for (const auto &entry : phone_book)
    // for each entry in phone_book
    // this is a range based for loop in C++
    // iterates over elements in the phone_book list
    // auto gets the type of entry based on the type of elements in phone_book
    // we use a reference to entry instead of entry itself (& address of operator)
    // because using entry would copy it which is expensive
    // const means that we can't manipulate data here
    // if we want to manipulate just remove that
    {
        std::cout << entry << std::endl;
        // print entry
    }
    return 0;
}
