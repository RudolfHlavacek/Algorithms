#pragma once

#include <iostream>

#include "MinHeap.h"

int min_heap_example()
{
    // Create instance 'mh' of class MinHeap.
    rh::MinHeap<int> mh(5);

    // Inserts number 5.
    mh.insert(5);

    // peekMin() returns minimum number. The number remains in the MinHeap.
    std::cout << "Minimum in heap is: " << mh.peekMin() << std::endl;
    std::cout << "Number of elems in heap: " << mh.size() << std::endl;

    // deleteMin() deletes minimum number in the heap and heapify the rest.
    std::cout << "---------------------------" << std::endl;
    mh.deleteMin();
    std::cout << "Item deleted" << std::endl;
    std::cout << "Number of elems in heap: " << mh.size() << std::endl;

    mh.insert(42);
    mh.insert(5);
    mh.insert(21);
    mh.insert(-55);
    mh.insert(4);

    // extractMin() returns minimum number in the heap and remove it from the heap.
    std::cout << "---------------------------" << std::endl;
    std::cout << "Number of elems in heap: " << mh.size() << std::endl;
    std::cout << "Extracted number is: " << mh.extractMin() << std::endl;
    std::cout << "Number of elems in heap: " << mh.size() << std::endl;

    // isFull() return true if number of elements is equal to heap capacity.
    // If another element is inserted then heap is resized to double capacity.
    if (mh.isFull())
        std::cout << "Heap is full." << std::endl;
    else
        std::cout << "Heap is not full." << std::endl;

    // resize(X) shall resize the heap if new capacity (X) is at least as big as the number of stored elements.
    std::cout << "---------------------------" << std::endl;
    std::cout << "Number of elems in heap: " << mh.size() << std::endl;
    std::cout << "Heap is full: " << mh.isFull() << std::endl;
    mh.resize(4);
    std::cout << "Heap Resized to 4 .............." << std::endl;
    std::cout << "Heap is full: " << mh.isFull() << std::endl;


    std::cout << "---------------------------" << std::endl;
    mh.resize(6);
    std::cout << "Heap Resized to 6 .............." << std::endl;
    std::cout << "Heap is full: " << mh.isFull() << std::endl;
    std::cout << "Inserted two elements." << std::endl;
    mh.insert(1);
    mh.insert(2);
    std::cout << "Heap is full: " << mh.isFull() << std::endl;

    
    std::cout << "---------------------------" << std::endl;
    // clear() clears the heap.
    mh.clear();

    
    mh.insert(42);
    mh.insert(21);

    
    if (mh.isFull())
        std::cout << "Heap is full." << std::endl;
    else
        std::cout << "Heap is not full." << std::endl;

    // resize() without params shall adjust heap according to number of stored elements. If there is nothing then it shall resized to 1.
    // If heap is full then there shall be no resizing.
    // resize() return true is resizing took a place. If not it returns false.
    for (int i = 0; i < 5; i++)
    {
        if (mh.resize())
            std::cout << "Resized..." << "new size is: " << mh.size() << std::endl;
        else
            std::cout << "Not resized..." << "size is: " << mh.size() << std::endl;
    }

    if (mh.isFull())
        std::cout << "Heap is full." << std::endl;
    else
        std::cout << "Heap is not full." << std::endl;

    mh.insert(5);
    mh.insert(21);
    mh.insert(-42);
    mh.insert(42);
    mh.insert(-2);

    // Copy constructor can be used to create copy of the heap.
    // It creates exact copy.
    rh::MinHeap<int> mh_2(mh);


    // Copy can be created also by calling copy(heap_which_will_be_copied).
    // Heap mh will be copied to the mh_3.
    // If there is not enough room then mh_3 will be resized.
    rh::MinHeap<int> mh_3(1);
    mh_3.copy(mh);

    // Same effect (mh_3.copy(mh);) can be achieved by using = operator. See below.
    mh_3 = mh;


    return 1;
}
