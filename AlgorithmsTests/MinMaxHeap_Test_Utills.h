#pragma once

#ifdef _WIN64
#define DUMMY unsigned char dummy[8]
#else
#define DUMMY unsigned char dummy[4]
#endif

//#include "..\Algorithms\src\MinHeap.h"
//#include "..\Algorithms\src\MaxHeap.h"

#include "..\Algorithms\src\MaxHeap.h"


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
    struct access_by
    {
        rh::MaxHeap<T>* m_maxheap;
        access_by<T>(rh::MaxHeap<T>& other) { m_maxheap = other; };

        int get_m_size() const { return m_maxheap->m_size; };
    };*/
}
