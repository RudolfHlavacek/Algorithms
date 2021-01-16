#pragma once

#include <iostream>


/******************************************************************************/
/*                                Declarations                                */
/******************************************************************************/

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

/******************************************************************************/
/*                               Implementation                               */
/******************************************************************************/
template <class T>
Stack<T>::Stack()
{
    const int size_default = 256;

    m_arr = new T[size_default];
    m_capacity = size_default;
    m_top = -1;
}

template <class T>
Stack<T>::Stack(int size)
{
    m_arr = new T[size];
    m_capacity = size;
    m_top = -1;
}

template <class T>
Stack<T>::~Stack()
{
    delete[] m_arr;
}

template <class T>
void Stack<T>::push(T x)
{
    // Check for stack overflow.
    if (isFull())
    {
        std::cout << "Stack OverFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    std::cout << "Inserting " << x << std::endl;
    m_arr[++m_top] = x;
}

template <class T>
T Stack<T>::pop()
{
    // Check for stack underflow.
    if (isEmpty())
    {
        std::cout << "Stack UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    std::cout << "Removing " << peek() << std::endl;

    // Decrease stack size by 1 and (optionally) return the popped element.
    return m_arr[m_top--];
}

template <class T>
T Stack<T>::peek()
{
    if (!isEmpty())
    {
        return m_arr[m_top];
    }
    else
    {
        exit(EXIT_FAILURE);
    }
}

template <class T>
int Stack<T>::size()
{
    return m_top + 1;
}

template <class T>
bool Stack<T>::isEmpty()
{
    return (m_top == -1);
}

template <class T>
bool Stack<T>::isFull()
{
    return (m_top == (m_capacity - 1));
}

template <class T>
int Stack<T>::getCapacity()
{
    return m_capacity;
}
