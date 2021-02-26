#pragma once

#include "privablic.h"
#include "..\Algorithms\src\MaxHeap.h"


// int m_size
struct MaxHeap_m_size { typedef int(rh::MaxHeap<int>::* type); };
template class private_member<MaxHeap_m_size, &rh::MaxHeap<int>::m_size>;

// int m_capacity
struct MaxHeap_m_capacity { typedef int(rh::MaxHeap<int>::* type); };
template class private_member<MaxHeap_m_capacity, &rh::MaxHeap<int>::m_capacity>;

// T* m_heap, [T = int]
struct MaxHeap_m_heap { typedef int*(rh::MaxHeap<int>::* type); };
template class private_member<MaxHeap_m_heap, &rh::MaxHeap<int>::m_heap>;
