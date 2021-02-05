#pragma once

#include <iostream>


/******************************************************************************/
/*                                Declarations                                */
/******************************************************************************/

template <typename T>
class Stack
{
public:
    Stack();
    Stack(int size);
    Stack(const Stack<T>& other);
    void operator=(const Stack<T>& other);
    virtual ~Stack();

    void push(T);
    T pop();
    T peek() const;

    int size() const;
    bool isEmpty() const;
    bool isFull() const;
    int getCapacity() const;
    bool copy(const Stack<T>& other);

private:
    T *m_arr;
    int m_top;
    int m_capacity;
};

/******************************************************************************/
/*                               Implementation                               */
/******************************************************************************/
template <typename T>
Stack<T>::Stack()
{
    const int size_default = 256;

    m_arr = new T[size_default];
    m_capacity = size_default;
    m_top = -1;
}

template <typename T>
Stack<T>::Stack(int size)
{
    m_arr = new T[size];
    m_capacity = size;
    m_top = -1;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& other)
    : m_top(other.m_top), m_capacity(other.m_capacity)
{
    m_arr = new T[m_capacity];
    for (int i = 0; i < m_capacity; i++)
    {
        m_arr[i] = other.m_arr[i];
    }
}

template <typename T>
void Stack<T>::operator=(const Stack<T>& other)
{
    this->copy(other);
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] m_arr;
}

template <typename T>
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

template <typename T>
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

template <typename T>
T Stack<T>::peek() const
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

template <typename T>
int Stack<T>::size() const
{
    return m_top + 1;
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    return (m_top == -1);
}

template <typename T>
bool Stack<T>::isFull() const
{
    return (m_top == (m_capacity - 1));
}

template <typename T>
int Stack<T>::getCapacity() const
{
    return m_capacity;
}

template <typename T>
bool Stack<T>::copy(const Stack<T>& other)
{
    if (m_capacity >= other.m_top+1)
    {
        m_top = other.m_top;
        for (int i = 0; i < this->size(); i++)
        {
            m_arr[i] = other.m_arr[i];
        }
        return true;
    }
    else
        return false;
}
