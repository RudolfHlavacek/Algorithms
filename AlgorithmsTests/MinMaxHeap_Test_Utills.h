#pragma once

#ifdef _WIN64
#define DUMMY unsigned char dummy[8]
#else
#define DUMMY unsigned char dummy[4]
#endif

//#include "..\Algorithms\src\MinHeap.h"
//#include "..\Algorithms\src\MaxHeap.h"

namespace rhTest {

    template <typename T>
    struct MinMaxHeap_for_reint
    {
        DUMMY;
        int m_size;
        int m_capacity;
        T* m_heap;
    };

    /*template <typename T>
    int get_m_size(const rh::MinHeap<T>& instance)
    {
        return *((int*)&instance + 1);
    }

    template <typename T>
    int get_m_size(const rh::MaxHeap<T>& instance)
    {
        return *((int*)&instance + 1);
    }

    template <typename T>
    int get_m_capacity(const rh::MinHeap<T>& instance)
    {
        return *((int*)&instance + 2);
    }

    template <typename T>
    int get_m_capacity(const rh::MaxHeap<T>& instance)
    {
        return *((int*)&instance + 2);
    }

    template <typename T>
    T* get_ptr_to_heap(const rh::MinHeap<T>& instance)
    {
        int addr_to_heap = *((int*)&instance + 3);
        T* ptr_to_heap = (T*)addr_to_heap;
        return ptr_to_heap;
    }

    template <typename T>
    T* get_ptr_to_heap(const rh::MaxHeap<T>& instance)
    {
        int addr_to_heap = *((int*)&instance + 3);
        T* ptr_to_heap = (T*)addr_to_heap;
        return ptr_to_heap;
    }*/

}
