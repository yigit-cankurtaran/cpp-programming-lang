#include <iostream>
#include <map>
#include <string>

// used when we need key-value associations
// p much dictionaries in python

int main() {
    std::map<std::string, int> ageMap; // create empty map with string keys and int vals

    std::map<int, std::string> productMap = { // int keys str vals
        // initializing with initializer list, needs -std=c+11 flag when compiling
        {101, "Laptop"},
        {105, "Mouse"},
        {102, "Keyboard"},
        // keys will be ordered no matter what position we put them in
    };

    std::map<std::string, double> priceMap( // this is technically a copy of the dict we have inside
            {{"apple", 1.50}, {"banana", 0.75}}
    );

    // inserting
    ageMap["Alice"] = 30;
    ageMap["Bob"] = 25;
    ageMap["Charlie"] = 35;

    // inserting with insert() method
    ageMap.insert(std::pair<std::string, int>("David", 40)); // using pair
    ageMap.insert(std::make_pair("Eve", 28)); // using make_pair
    ageMap.insert({"Frank", 45}); // using initializer list, c++11 onwards

    // if we use operator to insert on an existing key, it will overwrite
    ageMap["Alice"] = 20; // prints alice as 20
    // if we use insert method to insert on an existing key, it will be ignored

    std::cout << "map after insertions and update :" << std::endl;
    for (const auto& pair : ageMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
        // pair.first = key pair.second = value
    }
    std::cout << std::endl;

    if (ageMap.count("Bob")) { // count returns 1 if key exists and 0 if it doesn't
        int bobsAge = ageMap["Bob"]; // if key isn't found it inserts one (0 for int)
        std::cout << "bob's age is " << bobsAge << std::endl;
    }

    // safer lookup, doesn't insert if key doesn't exist
    std::map<std::string, int>::iterator it = ageMap.find("Charlie");
    // returns iterator to element if found, map::end() if not found
    if (it != ageMap.end()) { // check if iterator is not at the end (key was found)
        int charliesAge = it->second; // it = pointer to a pair, it->second gets the value
        std::cout << "charlie's age (using find()) " << charliesAge << std::endl;
    } else {
        std::cout << "key charlie not found." << std::endl;
    }

    // another safe lookup, throws exception if key isn't found
    try {
        int evesAge = ageMap.at("Eve"); // looks up key and returns value.
        // if key not found throws out_of_range
        std::cout << "eve's age (using at()) " << evesAge << std::endl;
    } catch (const std::out_of_range& e) {
        // the & is creating a reference to the exception object rather than making a copy
        // const prevents accidental modification of the exception object
        // we get access to the original object thrown by at()
        std::cout << "error: key 'eve' not found (exception caught)" << std::endl;
    }

    // removing elements
    ageMap.erase("David"); // erasing by key. removes the entry for david

    std::map<std::string, int>::iterator it_erase = ageMap.find("Eve");
    // get iterator to eve
    if (it_erase != ageMap.end()) {
        ageMap.erase(it_erase); // erase using iterator, remove entry for eve
    }
    // agemap.clear() removes ALL entries from the map, gives us an empty map

    // iterating through map
    std::cout << "\nremaining entries in ageMap after the removals (iteration):" << std::endl;
    for (std::map<std::string, int>::iterator iter = ageMap.begin(); iter != ageMap.end(); ++iter){
        std::cout << iter->first << ": " << iter->second << std::endl;
    }

    std::cout << "\nrange based for loop, simpler" << std::endl;
    for (const auto& pair : ageMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // getting size
    std::cout << "\nsize of ageMap: " << ageMap.size() << std::endl;
    std::cout << "Is ageMap empty? " << (ageMap.empty() ? "Yes" : "No") << std::endl;

    // useful stuff
    std::cout << "iterating through productMap:" << std::endl;
    for (const auto& pair : productMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
