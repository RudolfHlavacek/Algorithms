#include <iostream>

#include "..\examples\stack_example.h"
#include "..\examples\queue_example.h"
#include "..\examples\binary_search_example.h"
#include "..\examples\timer_example.h"

#include "..\src\MinHeap.h"

int main()
{
    std::cout << "Hello World!" << std::endl;

    stack_example();
    queue_example();
    binary_search_example();
    timer_example();

    rh::MinHeap<int> mh(8);
    mh.insert(20);
    mh.insert(15);
    mh.insert(30);
    mh.insert(5);
    mh.insert(10);
    mh.insert(7);
    mh.insert(7);
    mh.insert(42);
    mh.insert(21);
    mh.deleteMin();
    mh.insert(8);


    std::cin.get();
}