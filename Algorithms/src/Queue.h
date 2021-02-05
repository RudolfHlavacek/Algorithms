#pragma once

#include <iostream>


/******************************************************************************/
/*                                Declarations                                */
/******************************************************************************/
template <typename T>
class Queue
{
    public:
        Queue();
        Queue(int max_capacity);
        Queue(const Queue<T>& other);
        void operator=(const Queue<T>& other);
        virtual ~Queue();

        void enqueue(T x);
        void dequeue();
        T peek() const;

        int size() const;
        bool isEmpty() const;
        bool isFull() const;
        int getCapacity() const;
        bool copy(const Queue<T>& other);

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
template <typename T>
Queue<T>::Queue()
{
    const int max_capacity_default = 256;

    arr = new T[max_capacity_default];
    m_capacity = max_capacity_default;
    m_frontIndex = 0;
    m_backIndex = -1;
    m_count = 0;
}

template <typename T>
Queue<T>::Queue(int max_capacity)
{
    arr = new T[max_capacity];
    m_capacity = max_capacity;
    m_frontIndex = 0;
    m_backIndex = -1;
    m_count = 0;
}

template <typename T>
Queue<T>::Queue(const Queue<T>& other)
    : m_capacity(other.m_capacity), m_backIndex(other.m_backIndex),
      m_frontIndex(other.m_frontIndex), m_count(other.m_count)
{
    arr = new T[m_capacity];
    for (int i = 0; i < m_capacity; i++)
    {
        arr[i] = other.arr[i];
    }
}

template <typename T>
void Queue<T>::operator=(const Queue<T>& other)
{
    this->copy(other);
}

template <typename T>
Queue<T>::~Queue()
{
    delete[] arr;
}

template <typename T>
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

template <typename T>
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

template <typename T>
T Queue<T>::peek() const
{
    if (isEmpty())
    {
        std::cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[m_frontIndex];
}

template <typename T>
int Queue<T>::size() const
{
    return m_count;
}

template <typename T>
bool Queue<T>::isEmpty() const
{
    return (m_count == 0);
}

template <typename T>
bool Queue<T>::isFull() const
{
    return (m_count == m_capacity);
}

template <typename T>
int Queue<T>::getCapacity() const
{
    return m_capacity;
}

template <typename T>
bool Queue<T>::copy(const Queue<T>& other)
{
    if (m_capacity >= other.m_count)
    {
        m_backIndex = other.m_backIndex;
        m_frontIndex = other.m_frontIndex;
        m_count = other.m_count;
        for (int i = 0; i < other.m_count; i++)
        {
            arr[i] = other.arr[i];
        }
        return true;
    }
    else
        return false;
}
