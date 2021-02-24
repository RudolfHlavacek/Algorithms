#pragma once


namespace rh {
    /******************************************************************************/
    /*                                Declarations                                */
    /******************************************************************************/
    template <typename T>
    class MaxHeap
    {
    private:
        int m_size;
        int m_capacity;
        T* m_heap;

    private:
        int parent(int index) const { return (index <= 0) ? -1 : (index - 1) / 2; };
        int left(int index) const { return ((2 * index + 1) > (m_size - 1)) ? -1 : (2 * index + 1); };
        int right(int index) const { return (2 * index + 2) > (m_size - 1) ? -1 : (2 * index + 2); };
        void heapifyUp(int index);
        void heapifyDown(int index);
        void swap(int index_1, int index_2);

    public:
        MaxHeap() : m_size(0), m_capacity(1) { m_heap = new T[m_capacity]; };
        MaxHeap(int capacity);
        MaxHeap(const MaxHeap& other);
        virtual ~MaxHeap();

        void insert(T elem);
        T peek() const { return m_heap[0]; };
        void removeRoot();
        T extractRoot();

        int size() const { return m_size; };
        bool resize(int new_capacity);
        bool resize() { return (m_size == 0) ? resize(1) : resize(m_size); };
        void clear() { m_size = 0; };

        void copy(const MaxHeap<T>& other);
        void operator=(const MaxHeap<T>& other) { this->copy(other); };

    };


    /******************************************************************************/
    /*                               Implementation                               */
    /******************************************************************************/
    template <typename T>
    MaxHeap<T>::MaxHeap(int capacity)
        : m_size(0), m_capacity(capacity)
    {
        if (m_capacity < 1)
            m_capacity = 1;
        m_heap = new T[m_capacity];
    }

    template <typename T>
    MaxHeap<T>::MaxHeap(const MaxHeap<T>& other)
        : m_size(other.m_size), m_capacity(other.m_capacity)
    {
        m_heap = new T[m_capacity];
        for (int i = 0; i < m_size; i++)
            m_heap[i] = other.m_heap[i];
    }

    template <typename T>
    MaxHeap<T>::~MaxHeap()
    {
        delete[] m_heap;
    }

    template <typename T>
    void MaxHeap<T>::insert(T elem)
    {
        if (m_size >= m_capacity) // m_size >= m_capacity -> isFull()
            resize(2 * m_capacity);

        m_heap[m_size] = elem;

        heapifyUp(m_size);
        ++m_size;
    }

    template <typename T>
    void MaxHeap<T>::removeRoot()
    {
        if (m_size > 0)
        {
            swap(0, m_size - 1);
            --m_size;
            heapifyDown(0);
        }
    }

    template <typename T>
    T MaxHeap<T>::extractRoot()
    {
        T res = m_heap[0];
        removeRoot();
        return res;
    }

    template <typename T>
    bool MaxHeap<T>::resize(int new_capacity)
    {
        if (new_capacity >= m_size && new_capacity > 0 && new_capacity != m_capacity)
        {
            T* temp_heap = new T[new_capacity];
            for (int i = 0; i < m_size; i++)
            {
                temp_heap[i] = m_heap[i];
            }
            delete[] m_heap;
            m_heap = temp_heap;
            m_capacity = new_capacity;
            return true;
        }
        else
            return false;
    }

    template <typename T>
    void MaxHeap<T>::copy(const MaxHeap<T>& other)
    {
        if (other.m_size > m_capacity)
        {
            resize(other.m_size);
            m_capacity = other.m_size;
        }

        m_size = other.m_size;

        for (int i = 0; i < m_size; i++)
            m_heap[i] = other.m_heap[i];
    }


    /******************************************************************************/
    /*                       Private Methods Implementation                       */
    /******************************************************************************/
    template <typename T>
    void MaxHeap<T>::heapifyUp(int index)
    {
        while (index > 0 && m_heap[parent(index)] < m_heap[index])
        {
            swap(parent(index), index);
            index = parent(index);
        }
    }

    template <typename T>
    void MaxHeap<T>::heapifyDown(int index)
    {
        int child = left(index);
        int child2 = right(index);
        if (child >= 0 && child2 >= 0 && m_heap[child] < m_heap[child2])
            child = child2;

        if (child >= 0 && m_heap[index] < m_heap[child])
        {
            swap(index, child);
            heapifyDown(child);
        }
    }

    template <typename T>
    void MaxHeap<T>::swap(int index_1, int index_2)
    {
        int temp = m_heap[index_1];
        m_heap[index_1] = m_heap[index_2];
        m_heap[index_2] = temp;
    }

}
