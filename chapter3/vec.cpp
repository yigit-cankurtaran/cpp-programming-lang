#include <vector>

template <class T> class Vec: public vector <T> {
    // declare a class template named Vec, can handle any data type T
    // public vector <T> means this inherits from std::vector<T>, gains functionality of vectors
    public:
        Vec() : vector<T>() { } // default constructor, create an empty vector
        // empty bc the initialization is handled by "member initializer list" : vector<T>()
        Vec(int s) : vector<T>(s) { }
        // initialize Vec by calling a vector with a size
        // creates a vector with s elements

        // 2 different constructors, both useful in different scenarios
        // no-size is good when we want to just create a blank thing and add elements as we go
        // size is good when we know the number of elements we want from the beginning

        T& operator[] (int i) { return at(i); } // we overload the [] operator
        // allows us to access Vec elements using array syntax (my_vec[5])
        // at performs bounds checking, returns at(i) method of the vector base class.

        const T& operator[] (int i) const { return at(i); } // same but const
        // const = we can't modify it, same as in js and whatnot
        // 2nd const means that this operator is called when we work w const Vecs
        // call at(i) for bounds checking again.
};
