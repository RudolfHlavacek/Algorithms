#include <iostream>

//#include "..\examples\stack_example.h"/*
//#include "..\examples\queue_example.h"
//#include "..\examples\binary_search_example.h"
//#include "..\examples\timer_example.h"
//#include "..\examples\min_heap_example.h"*/
//#include "..\src\MaxHeap.h"
#include "LinkedList.h"


int main()
{
    //stack_example();/*
    //std::cout << std::endl;

    //queue_example();
    //std::cout << std::endl;

    //binary_search_example();
    //std::cout << std::endl;

    //timer_example();
    //std::cout << std::endl;

    //min_heap_example();
    //std::cout << std::endl;*/


    rh::LinkedList ll;
    ll.createNode(42);
    ll.createNode(21);
    //ll.display();

    //for (int i = 0; i < sizeof/*(ll) / sizeof(long long int); i++)
    //{
    //    int addr = *((long long int*)&ll + i);
    //    std::cout << std::hex << addr << "\t";
    //}*/
    std::cout << "Hello World!!! HELLO" <<std::endl;

    std::cin.get();
}
