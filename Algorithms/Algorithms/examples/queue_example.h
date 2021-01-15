#pragma once

#include <iostream>
#include <string>

#include "Queue.h"

int queue_example()
{
    Queue<int> q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    std::cout << "Front element is: " << q.peek() << std::endl;
    q.dequeue();

    q.enqueue(4);

    std::cout << "Queue size is: " << q.size() << std::endl;
    std::cout << "Queue maximum capacity is: " << q.getCapacity() << std::endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();

    if(q.isEmpty())
    {
        std::cout << "Queue is Empty\n";
    }
    else
    {
        std::cout << "Queue is NOT Empty\n";
    }

    std::cout << "\n\n" << std::endl;
    Queue<std::string> qs(3);
    qs.enqueue("Test 1");
    qs.enqueue("Test 2");

    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Queue of strings has maximum capacity: " << qs.getCapacity() << std::endl;
    std::cout << "Queue size is: " << qs.size() << std::endl;

    std::cout << "Front element is: " << qs.peek() << std::endl;
    qs.dequeue();
    std::cout << "Front element is: " << qs.peek() << std::endl;
    qs.enqueue("Test 3");
    std::cout << "Front element is: " << qs.peek() << std::endl;
    qs.dequeue();
    std::cout << "Front element is: " << qs.peek() << std::endl;
    qs.dequeue();

    qs.enqueue("Test 4");
    std::cout << "Front element is: " << qs.peek() << std::endl;
    qs.dequeue();

    if(qs.isEmpty())
    {
        std::cout << "Queue is Empty\n";
    }
    else
    {
        std::cout << "Queue is NOT Empty\n";
    }

    return 0;
}
