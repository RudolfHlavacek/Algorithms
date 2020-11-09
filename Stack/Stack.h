#ifndef STACK_H
#define STACK_H

template <class T>
class Stack
{
public:
    Stack();
    Stack(int size);
    virtual ~Stack();

    void push(T);
    T pop();
    T peek();

    int size();
    bool isEmpty();
    bool isFull();
    int getCapacity();

private:
    T *m_arr;
    int m_top;
    int m_capacity;
};

#endif // STACK_H

#include "Stack.tpp"
