#include <iostream>
#include <chrono>
#include <thread>

#include "Timer.h"

void Function()
{
    Timer timer;
    for (int i = 0; i < 100; i++)
        std::cout << "Hello World!" << std::endl;
}

int main()
{
    using namespace std::literals::chrono_literals;


    //    auto start = std::chrono::high_resolution_clock::now();
    //    std::this_thread::sleep_for(1s);
    //    auto end = std::chrono::high_resolution_clock::now();
    //
    //    std::chrono::duration<float> duration = end - start;
    //    std::cout << duration.count() << " s" << std::endl;

    Function();

    std::cin.get();
}

