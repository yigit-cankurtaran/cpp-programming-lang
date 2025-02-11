// this is not gonna work just typing out stuff in the chapter

namespace Stack { // define the namespace
    struct Rep; // struct Rep is declared but not defined here
    typedef Rep& stack; // type alias stack is created to reference Rep

    stack create(); // used to create and initialize a new stack
    void destroy(stack s); // used to destroy or reallocate the stack

    void push(stack s, char c); // push char c on stack s
    char pop(stack s); // pop stack s and return what pops
}
