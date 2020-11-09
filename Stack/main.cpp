#include <iostream>

#include "Stack.h"

using namespace std;

int main()
{
    Stack<string> st(2);
    cout << st.getCapacity() << endl;;

    st.push("A");
    st.push("B");

    cout << st.peek() << '\n' << st.peek() << endl;
    st.pop();
    st.pop();

    st.push("C");

    cout << "Top element is: " << st.peek() << endl;

    cout << "Stack size is: " << st.size() << endl;

    cout << "-----------------" << endl;
    cout << "Popping element: " << st.pop() << endl;
    cout << "-----------------" << endl;

    if(st.isEmpty())
    {
        cout << "Stack is empty" << endl;;
    }
    else
    {
        cout << "Stack is NOT Empty" << endl;
    }

    return 0;
}
