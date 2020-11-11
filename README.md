# Algorithms
Repository for common algorithms, e.g. Stack, Queue.

## Stack
Universal stack for any data types. Implementation file 'Stack.tpp' is included in header file 'Stack.h'.

    Public functions:
    - void push(T);         // Adds new element on the top of the stack.
    - T pop();              // Removes element from the top of the stack. Optionally can return popped element.
    - T peek();             // Shows element from the top of stack.
    - int size();           // Returns current number of items.
    - bool isEmpty();
    - bool isFull();
    - int getCapacity();    // Returns maximum capacity of the stack.

## Queue
Implementation file 'Stack.cpp' is using Explicit instantiations at the end of file.

It can be used same implementation as in class 'Stack'. Different aproach was choosed for educational purposes.

    Public functions:
    - void enqueue(T x);    // Adds new element at the back(rear) of the queue.
    - void dequeue();       // Removes element from the front of the queue.
    - T peek();             // Shows front element.
    - int size();           // Returns current number of items.
    - bool isEmpty();
    - bool isFull();
    - int getCapacity();


Queue supports following data types:
- short int
- unsigned short int
- int
- unsigned int
- long int
- unsigned long int
- long long int
- unsigned long long int
- signed char
- unsigned char
- std::string
- float
- double
- long double
    
