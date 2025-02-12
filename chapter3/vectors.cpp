#include <vector>
#include <string>
#include <iostream>

struct Entry {
    std::string name;
    int number;
};

std::vector<Entry> phone_book(1000);

void print_entry(int i) {
    std::cout << phone_book[i].name << ' ' << phone_book[i].number << '\n';
    // works just the way arrays do
}

void add_entries(int n) {
    phone_book.resize(phone_book.size() + n);
    // increase size by n
}


int main(){
    phone_book[50].name = "hi";
    phone_book[50].number = 50;
    // most fundamental way to access and modify struct members

    Entry entry1 = {.name = "hello", .number = 123};
    // we can also create stuff like this
    phone_book[51] = entry1;

    Entry entry2 = {.name = "world", .number = 456};
    phone_book.push_back(entry2); // push_back adds to the end of the vector
    print_entry(50);
    print_entry(51);
    print_entry(1000);
}
