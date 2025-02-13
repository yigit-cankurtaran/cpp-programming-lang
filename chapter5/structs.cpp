// structs are user defined data types that group together variables of
    // different data types under a single name. these vars are called members

struct address {
    char* name;
    long int number;
    char* street;
    char* town;
    char state [2];
    long zip;
};

// defines a new type called address consisting of the items we need
// do NOT forget the semicolon after the brace

// a struct is a simple form of a class
