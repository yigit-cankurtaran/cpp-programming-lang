#include <iostream>
#include <string>
#include <vector>
using namespace std;
// namespace is so that we don't have to preface everything with std::

struct Entry
{
    string name;
    int number;
};

vector<Entry> phone_book(1000);
// a vector that takes in type of Entry that has 1000 elements.
// vector<Entry> books[1000];
// watch out for the syntax, the above creates 1000 empty vectors

void print_entry(int i)
{
    cout << phone_book[i].name << ' ' << phone_book[i].number << '\n';
    // use is exactly the same as for array
}

void add_entries(int n)
{
    phone_book.resize(phone_book.size() + n);
    // increase size by n
}

// copying large vectors and such is undesirable because of memory and compute
// pointers and references is useful because of this