#include "Queue.h"

#include <iostream>


template <class T>
Queue<T>::Queue()
{
    const int max_capacity_default = 256;

    arr = new T[max_capacity_default];
    m_capacity = max_capacity_default;
    m_frontIndex = 0;
    m_backIndex = -1;
    m_count = 0;
}

template <class T>
Queue<T>::Queue(int max_capacity)
{
    arr = new T[max_capacity];
    m_capacity = max_capacity;
    m_frontIndex = 0;
    m_backIndex = -1;
    m_count = 0;
}

template <class T>
Queue<T>::~Queue()
{
    delete [] arr;
}

template <class T>
void Queue<T>::enqueue(T x)
{
    // Check for queue overflow.
    if(isFull())
    {
        std::cout << "OverFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    else
    {
        std::cout << "Inserting " << x << '\n';

        m_backIndex = (m_backIndex + 1) % m_capacity;
        arr[m_backIndex] = x;
        ++m_count;
    }
}

template <class T>
void Queue<T>::dequeue()
{
    // Check for queue underflow.
    if(isEmpty())
    {
        std::cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    else
    {
        std::cout << "Removing " << arr[m_frontIndex] << '\n';

        m_frontIndex = (m_frontIndex + 1) % m_capacity;
        --m_count;
    }
}

template <class T>
T Queue<T>::peek()
{
    if(isEmpty())
    {
        std::cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[m_frontIndex];
}

template <class T>
int Queue<T>::size()
{
    return m_count;
}

template <class T>
bool Queue<T>::isEmpty()
{
    return (m_count == 0);
}

template <class T>
bool Queue<T>::isFull()
{
    return (m_count == m_capacity);
}

template <class T>
int Queue<T>::getCapacity()
{
    return m_capacity;
}

// Explicit instantiations. (Can be in additional file, e.g. "Queue-impl.cpp".
// Than "Queue.cpp" file shall be included at top of "Queue-impl.cpp".)
//
// E.g.:
// // File "Queue-impl.cpp"
// #include "Queue.cpp"
// template class Queue<int>;

template class Queue<short int>;
template class Queue<unsigned short int>;
template class Queue<int>;
template class Queue<unsigned int>;
template class Queue<long int>;
template class Queue<unsigned long int>;
template class Queue<long long int>;
template class Queue<unsigned long long int>;

template class Queue<signed char>;
template class Queue<unsigned char>;

template class Queue<std::string>;

template class Queue<float>;
template class Queue<double>;
template class Queue<long double>;
// You will only be able to use Queue with above data types.
