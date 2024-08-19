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

void add_over_range()
{
    // // int i = phone_book[1001].number;
    // 1001 is out of range here
    // this will add a random number apparently? let's see
    // // cout << i;
    // just made it 0

    // throws an out_of_range apparently

    try
    {
        int a = 0;
        for (int i = 0; i < 1000; i++)
        {
            // using a here sets it to 0 all the time.
            // // int a = 0;
            print_entry(i);
            a++;
            cout << "the count is " << a;
        }
    }
    catch (out_of_range)
    {
        cout << "range error\n";
    }
    // usual try-catch block
    // using a main with a block like this is good practice
}

// copying large vectors and such is undesirable because of memory and compute
// pointers and references is useful because of this

int main(int argc, char const *argv[])
{
    try
    {
        add_over_range();
    }
    catch (...)
    {
        cerr << "unknown exception thrown\n";
    }
    // the ... handles any exception not caught before this
    return 1;
}
