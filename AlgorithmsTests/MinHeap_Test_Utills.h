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
    struct MinHeap_for_reint
    {
        DUMMY;
        int m_size;
        int m_capacity;
        T* m_heap;
    };

}
