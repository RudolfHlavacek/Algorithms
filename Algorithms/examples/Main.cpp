#include <iostream>

//#include "..\examples\stack_example.h"/*
//#include "..\examples\queue_example.h"
//#include "..\examples\binary_search_example.h"
//#include "..\examples\timer_example.h"
//#include "..\examples\min_heap_example.h"*/
#include "..\src\MaxHeap.h"


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

    {
        rh::MaxHeap<int> mh(1);

        std::cout << "Size of empty maxheap is: " << sizeof(mh) << "" << std::endl;

        mh.insert(2);
        mh.insert(3);
        mh.insert(4);

        int* ptr_to_mh = (int*)&mh;
        for (int i = 0; i < sizeof(mh) / sizeof(int); i++)
            std::cout << std::hex << *(ptr_to_mh + i) << " ";
        std::cout << std::endl;

        int addr_mh_heap = *((int*)&mh + 3);
        std::cout << std::hex << addr_mh_heap << std::endl;

        //int* ptr_mh_heap = (int*)addr_mh_heap;
        int* ptr_mh_heap = (int*)*((int*)&mh + 3);

        char* a;
        std::cout << "Size of pointer to char: " << sizeof(a) << std::endl;


        /*for (int i = 0; i < (mh.size() + 3); i++)
            *(ptr_mh_heap + i) = *(ptr_mh_heap + i) + 1;*/
            //std::cout << *(ptr_mh_heap + i) << " ";
        std::cout << std::endl;

        /*std::cout << mh.peek() << std::endl;
        std::cout << mh.extractRoot() << std::endl;*/
    }
    


    std::cin.get();
}
