#include <iostream>
#include <list>
#include <string>

int main() {
    // creating and initializing
    std::list<int> intList; // empty list that will hold integers
    std::list<std::string> stringList = {"apple", "banana", "cherry"}; // init w vals
    std::list<int> anotherList(5); // list of size 5 (all elements default 0 for int)
    std::list<int> yetAnotherList(5, 100); // size 5, each element init 100
    std::list<int> copyList = yetAnotherList; // list that's a copy of another list

    // adding elements
    intList.push_back(10); // add 10 to the END of list
    intList.push_back(20);
    intList.push_front(5); // add 5 to the START of list

    stringList.push_back("date"); // end of stringList
    stringList.push_front("apricot"); // start of stringList

    // inserting at specific positions
    std::list<int> numbers = {1, 2, 3, 4, 5};
    std::list<int>::iterator it = numbers.begin(); // iterator pointing to the beginning
    std::advance(it, 2); // move the iterator 2 positions forward so it points to 3
    numbers.insert(it, 100); // insert 100 before the element pointed to by the iterator
    std::cout << "List after insertions: ";
    for (int num: numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    // prints "List after insertions: 1 2 100 3 4 5"

    // removing elements
    intList.pop_back(); // removes LAST element (20)
    intList.pop_front(); // removes FIRST element (5)

    stringList.pop_back(); // remove last element ("date");
    stringList.pop_front(); // remove first element ("apricot");

    numbers.erase(numbers.begin()); // erase the first element
    std::cout << "List after erase: ";
    for (int num: numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    // prints "List after erase: 2 100 3 4 5"

    numbers.clear(); // deletes every element in numbers

    // accessing elements
    std::list<int> accessList = { 10, 20, 30 };
    if (!accessList.empty()) { // checking if a list is empty before accessing is good practice
        int firstElement = accessList.front();
        int lastElement = accessList.back();
        std::cout << "access list first element: " << firstElement << ", access list last element: " << lastElement << std::endl;
        // accessing other elements is typically done with iterators
    }


    std::list<std::string> fruits = {"apple", "banana", "cherry"};
    std::cout << "fruits in the fruits list: ";
    for (std::list<std::string>::iterator iter = fruits.begin(); iter != fruits.end(); ++iter) {
        std::cout << *iter << " "; // dereference iterator to get current element
    }
    std::cout << std::endl;

    std::cout << "fruits using range based for loop: "; // better and simpler
    for (const std::string& fruit : fruits) { // const and & for efficiency
        // & = references strings instead of making copies, const = can't modify original string
        // pretty much a "for fruit in fruits" syntax
        std::cout << fruit << " ";
    }
    std::cout << std::endl;

    // checking list size
    std::cout << "size of fruits list: " << fruits.size() << std::endl;
    std::cout << "is fruits list empty? " << (fruits.empty() ? "yes" : "no") << std::endl;

    std::list<int> emptyList;
    std::cout << "size of empty list: " << emptyList.size() << std::endl;
    std::cout << "is empty list empty? " << (emptyList.empty() ? "yes" : "no") << std::endl;

    // other useful stuff
    std::list<int> listToSort = {5, 2, 8, 1, 9, 4};
    std::cout << "sorted list: ";
    listToSort.sort(); // sorts in ascending order and in place
    for (int num : listToSort) { // for element in list
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::list<int> listToReverse = {1, 2, 3, 4, 5};
    listToReverse.reverse(); // reverse the order of elements in place
    std::cout << "reversed list: ";
    for (int num : listToReverse) { // for element in list
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::list<int> list1 = {1, 2, 3};
    std::list<int> list2 = {4, 5, 6};
    list1.splice(list1.end(), list2); // move all elements from list2 to list1's end
    std::cout << "list1 after splice: ";
    for (int num : list1) { // for element in list
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "list2 after splice (should be empty): " << list2.size() << std::endl;

    return 0;
}
