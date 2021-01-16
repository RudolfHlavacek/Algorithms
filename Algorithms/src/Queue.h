#pragma once

#include <iostream>


/******************************************************************************/
/*                                Declarations                                */
/******************************************************************************/
template <class T>
class Queue
{
    public:
        Queue();
        Queue(int max_capacity);
        virtual ~Queue();

        void enqueue(T x);
        void dequeue();
        T peek();

        int size();
        bool isEmpty();
        bool isFull();
        int getCapacity();

    private:
        T *arr;
        int m_capacity;
        int m_backIndex;
        int m_frontIndex;
        int m_count;
};


/******************************************************************************/
/*                               Implementation                               */
/******************************************************************************/
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
    delete[] arr;
}

template <class T>
void Queue<T>::enqueue(T x)
{
    // Check for queue overflow.
    if (isFull())
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
    if (isEmpty())
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
    if (isEmpty())
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
