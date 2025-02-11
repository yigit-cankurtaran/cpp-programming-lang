#include <vector>
#include <string>
#include <iostream>

struct Entry {
    string name;
    int number;
};

vector<Entry> phone_book(1000);

void print_entry(int i) {
    std::cout << phone_book[i].name << ' ' << phone_book[i].number << '\n';
    // works just the way arrays do
}

void add_entries(int n) {
    phone_book.resize(phone_book.size() + n);
    // increase size by n
}


int main(){

}
