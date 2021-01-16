#include <iostream>

#include "..\examples\stack_example.h"
#include "..\examples\queue_example.h"
#include "..\examples\binary_search_example.h"

int main()
{
    std::cout << "Hello World!" << std::endl;

    stack_example();
    queue_example();
    binary_search_example();


    std::cin.get();
}