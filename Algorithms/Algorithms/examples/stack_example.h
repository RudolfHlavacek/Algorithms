#pragma once
#include <iostream>

#include "Stack.h"


int stack_example()
{
    Stack<std::string> st(2);
    std::cout << st.getCapacity() << std::endl;

    st.push("A");
    st.push("B");

    std::cout << st.peek() << '\n' << st.peek() << std::endl;
    st.pop();
    st.pop();

    st.push("C");

    std::cout << "Top element is: " << st.peek() << std::endl;

    std::cout << "Stack size is: " << st.size() << std::endl;

    std::cout << "-----------------" << std::endl;
    std::cout << "Popping element: " << st.pop() << std::endl;
    std::cout << "-----------------" << std::endl;

    if (st.isEmpty())
    {
        std::cout << "Stack is empty" << std::endl;;
    }
    else
    {
        std::cout << "Stack is NOT Empty" << std::endl;
    }

    return 0;
}
