#include <iostream>

#include "Queue.h"

using namespace std;

int main()
{
    Queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front element is: " << q.peek() << endl;
    q.dequeue();

    q.enqueue(4);

    cout << "Queue size is: " << q.size() << endl;
    cout << "Queue maximum capacity is: " << q.getCapacity() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();

    if(q.isEmpty())
    {
        cout << "Queue is Empty\n";
    }
    else
    {
        cout << "Queue is NOT Empty\n";
    }

    return 0;
}
