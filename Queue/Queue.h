#pragma once

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
