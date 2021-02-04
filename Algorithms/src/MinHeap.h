#pragma once

namespace rh {
/******************************************************************************/
/*                                Declarations                                */
/******************************************************************************/
    template <typename T>
    class MinHeap
    {
    private:
        int m_size;
        int m_capacity;
        T* m_heap;

    private:
        int parent(int index);
        int left(int index);
        int right(int index);
        void heapifyUp(int index);
        void heapifyDown(int index);
        void swap(int index_1, int index_2);

    public:
        MinHeap(int capacity);
        virtual ~MinHeap();

        void insert(T elem);
        T peekMin();
        void deleteMin();
        T extractMin();

        int size();
        bool isFull();
        void resize(int new_size);
    };


/******************************************************************************/
/*                               Implementation                               */
/******************************************************************************/
    template <typename T>
    MinHeap<T>::MinHeap(int capacity)
        : m_size(0), m_capacity(capacity)
    {
        if (m_capacity < 1)
            m_capacity = 1;
        m_heap = new T[m_capacity];
    }

    template <typename T>
    MinHeap<T>::~MinHeap()
    {
        delete[] m_heap;
    }

    template <typename T>
    void MinHeap<T>::insert(T elem)
    {
        if (isFull())
            resize(2 * m_capacity);

        m_heap[m_size] = elem;

        heapifyUp(m_size);
        ++m_size;
    }

    template <typename T>
    T MinHeap<T>::peekMin()
    {
        return m_heap[0];
    }

    template <typename T>
    void MinHeap<T>::deleteMin()
    {
        swap(0, m_size - 1);
        --m_size;
        heapifyDown(0);
    }

    template <typename T>
    T MinHeap<T>::extractMin()
    {
        T res = m_heap[0];
        deleteMin();
        return res;
    }


    template <typename T>
    int MinHeap<T>::size()
    {
        return m_size;
    }

    template <typename T>
    bool MinHeap<T>::isFull()
    {
        return m_size >= m_capacity;
    }

    template <typename T>
    void MinHeap<T>::resize(int new_size)
    {
        if (new_size > m_size)
        {
            T* temp_heap = new T[new_size];
            for (int i = 0; i < m_size; i++)
            {
                temp_heap[i] = m_heap[i];
            }
            delete[] m_heap;
            m_heap = temp_heap;
            m_capacity = new_size;
        }
    }

/******************************************************************************/
/*                       Private Methods Implementation                       */
/******************************************************************************/
    template <typename T>
    int MinHeap<T>::parent(int index)
    {
        if (index <= 0)
            return -1;
        else
            return (index - 1) / 2;
    }

    template <typename T>
    int MinHeap<T>::left(int index)
    {
        int l = 2 * index + 1;
        if (l > m_size - 1)
            return -1;
        else
            return l;
    }

    template <typename T>
    int MinHeap<T>::right(int index)
    {
        int r = 2 * index + 2;
        if (r > m_size - 1)
            return -1;
        else
            return r;
    }

    template <typename T>
    void MinHeap<T>::heapifyUp(int index)
    {
        while (index > 0 && m_heap[parent(index)] > m_heap[index])
        {
            swap(parent(index), index);
            index = parent(index);
        }
    }

    template <typename T>
    void MinHeap<T>::heapifyDown(int index)
    {
        int child = left(index);
        int child2 = right(index);
        if (child >= 0 && child2 >= 0 && m_heap[child] > m_heap[child2])
            child = child2;

        if (child >= 0 && m_heap[index] > m_heap[child])
        {
            swap(index, child);
            heapifyDown(child);
        }
    }

    template <typename T>
    void MinHeap<T>::swap(int index_1, int index_2)
    {
        int temp = m_heap[index_1];
        m_heap[index_1] = m_heap[index_2];
        m_heap[index_2] = temp;
    }

}
