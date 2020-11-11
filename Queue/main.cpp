#include <iostream>
#include <string>

#include "Queue.h"

using namespace std;

int main()
{
    Queue<int> q(5);

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

    cout << "\n\n" << endl;
    Queue<string> qs(3);
    qs.enqueue("Test 1");
    qs.enqueue("Test 2");

    cout << "---------------------------------------" << endl;
    cout << "Queue of strings has maximum capacity: " << qs.getCapacity() << endl;
    cout << "Queue size is: " << qs.size() << endl;

    cout << "Front element is: " << qs.peek() << endl;
    qs.dequeue();
    cout << "Front element is: " << qs.peek() << endl;
    qs.enqueue("Test 3");
    cout << "Front element is: " << qs.peek() << endl;
    qs.dequeue();
    cout << "Front element is: " << qs.peek() << endl;
    qs.dequeue();

    qs.enqueue("Test 4");
    cout << "Front element is: " << qs.peek() << endl;
    qs.dequeue();

    if(qs.isEmpty())
    {
        cout << "Queue is Empty\n";
    }
    else
    {
        cout << "Queue is NOT Empty\n";
    }

    return 0;
}
