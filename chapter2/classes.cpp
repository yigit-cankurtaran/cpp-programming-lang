#include <iostream>

class Stack
{
    char *v;      // pointer to dynamic array that holds the characters
    int top;      // index of the top element
    int max_size; // maximum capacity of the stack

public:
    class Underflow
    {
    }; // exception
    class Overflow
    {
    };
    class Bad_size
    {
    };
    // empty classes used for error handling

    Stack(int s); // constructor
    // we create this with Stack::Stack down below
    ~Stack(); // destructor
    // we create this with Stack::~Stack down below

    void push(char c);
    char pop();

    // encapsulation, we shouldn't let users modify the data directly
    // they can modify the data through these public methods
}; // we need the semicolon bc this is a class not a function

void Stack::push(char c)
{
    if (top == max_size)
        throw Overflow(); // if the array is full throw overflow
    v[top] = c;           // make c the top element
    top = top + 1;        // update indexes and size
    // top is both the next insert position and the current size
}

char Stack::pop()
{
    if (top == 0)
        throw Underflow(); // if the stack is empty throw underflow
    top = top - 1;         // update indexes and size
    return v[top];         // return the top element
}

// writing the constructor
Stack::Stack(int s)
{
    if (s <= 0)
        throw Bad_size();   // there can't be negative memory
    max_size = s;           // set size
    v = new char[max_size]; // memory allocation
    // in c++ we use new instead of malloc
    top = 0;
}

Stack::~Stack()
{
    delete[] v; // free memory
    // we need to delete the entire array, WITH the brackets
}

int main()
{
    Stack s_var1(3); // a stack of 3 elements

    s_var1.push('a');
    s_var1.push('b');
    s_var1.push('c');
    std::cout << "first popped element is " << s_var1.pop() << '\n';
    std::cout << "second popped element is " << s_var1.pop() << '\n';
    // LIFO, first pop is 'c', second pop is 'b'
}
