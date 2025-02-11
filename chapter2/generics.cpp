#include <iostream>
#include <array>

template<class T> class Stack { // T is a parameter of the declaration it prefixes
    // this is a generic, can work with whatever type we throw at it
    // T is a placeholder for a data type, if we create a Stack<int> T is an int
    T* v; // pointer to an array that will store the elements of the stack
    // T* = pointer to T, T is a template type
    // pointer bc we want to dynamically allocate memory at runtime
    int max_size;
    int top;

    public:
    class Underflow { };
    class Overflow { };
    class Bad_pop { };

    Stack(int s); // constructor
    // we need an int when we create a Stack
    ~Stack(); // destructor

    void push(T);
    T pop();
};

template <class T> Stack<T>::Stack(int s) {
    // we declared the constructor in the stack
    // but we're defining it here, if we don't define it doesn't work

    max_size = s;
    top = 0;
    v = new T[s]; // new instead of malloc, don't forget
}

template <class T> Stack<T>::~Stack() {
    // defining the destructor
    delete[] v; // freeing the memory for v
}

template <class T> void Stack<T>::push(T c) {
    if (top == max_size) throw Overflow();

    v[top] = c;
    top += 1;
}

template <class T> T Stack<T>::pop() { // seems confusing but its not
    // `template <class T>` reminds the compiler that this function is part of a template  
    // `T` is a placeholder type (set when the user creates a `Stack<int>`, `Stack<std::string>`, etc.)  
    // `T Stack<T>::pop()` means:  
    //   - this function returns a `T`  
    //   - it's a method of `Stack<T>` (not a regular function)  
    //   - we must write `Stack<T>::` because it's defined **outside** the class  
    if (top == 0) throw Underflow();

    top -= 1;
    return v[top];
}

int main(){
    Stack<char> sc(10); // a stack of chars with a max size 10
    Stack<int> si(20); // a stack of ints with a max size 20

    sc.push('c');
    std::cout << "the char array popped is " << sc.pop() << '\n';
    try {
        std::cout << "the char array popped while empty is " << sc.pop() << '\n';
    } catch (Stack<char>::Underflow) {
        std::cout << "stack underflow!\n";
    }

    int garbageNums[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
                       11, 12, 13, 14, 15, 16, 17, 18, 19, 20};  // Initialize with values

    for (auto i: garbageNums) { // p much a for num in array type thing
        si.push(i);
    }

    try {
        std::cout << "last element on stack is " << si.pop() << '\n';
        si.push(1);
        std::cout << "1 push successful\n";
        si.push(2);
        std::cout << "2 push successful\n";
    } catch (Stack<int>::Overflow) {
        std::cout << "stack overflow!\n";
    }
}
