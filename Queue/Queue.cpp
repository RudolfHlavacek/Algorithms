#include <iostream>

#include "Queue.h"

Queue::Queue()
{
    const int max_capacity_default = 256;

    arr = new int[max_capacity_default];
    m_capacity = max_capacity_default;
    m_frontIndex = 0;
    m_backIndex = -1;
    m_count = 0;
}

Queue::Queue(int max_capacity)
{
    arr = new int[max_capacity];
    m_capacity = max_capacity;
    m_frontIndex = 0;
    m_backIndex = -1;
    m_count = 0;
}

Queue::~Queue()
{
    delete [] arr;
}

void Queue::enqueue(int x)
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

void Queue::dequeue()
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

        arr[m_frontIndex] = 0;
        m_frontIndex = (m_frontIndex + 1) % m_capacity;
        --m_count;
    }
}

int Queue::peek()
{
    if(isEmpty())
    {
        std::cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[m_frontIndex];
}

int Queue::size()
{
    return m_count;
}

bool Queue::isEmpty()
{
    return (m_backIndex < m_frontIndex);
    // OR:
    // return (size() == m_capacity);
}

bool Queue::isFull()
{
    return (m_count == m_capacity);
}

int Queue::getCapacity()
{
    return m_capacity;
}
