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

    // resize() shall resize the heap if new capacity is at least same as the number of stored elements.
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



    return 1;
}
