#ifndef QUEUE_H
#define QUEUE_H


class Queue
{
    public:
        Queue();
        Queue(int max_capacity);
        virtual ~Queue();
        void enqueue(int x);
        void dequeue();
        int peek();
        int size();
        bool isEmpty();
        bool isFull();
        int getCapacity();

    private:
        int *arr;
        int m_capacity;
        int m_backIndex;
        int m_frontIndex;
        int m_count;
};

#endif // QUEUE_H
