#include <iostream>

#include "..\examples\stack_example.h"
#include "..\examples\queue_example.h"
#include "..\examples\binary_search_example.h"
#include "..\examples\timer_example.h"
#include "..\examples\min_heap_example.h"


int main()
{
    stack_example();
    std::cout << std::endl;

    queue_example();
    std::cout << std::endl;

    binary_search_example();
    std::cout << std::endl;

    timer_example();
    std::cout << std::endl;

    min_heap_example();
    std::cout << std::endl;



    std::cin.get();
}
