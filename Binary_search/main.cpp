//#include <iostream>
#include <bits/stdc++.h>
using namespace std;

ifstream f("data.in");
ofstream g("data.out");

int A[1000], numberElements;
int BinarySearch(int X)
{
    int left = 1, right = numberElements, mid;

    while(left <= right)
    {
        mid = (left + right) / 2;

        if(X == A[mid]) return mid;
        else if(X < A[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

int BinarySearchFirstOccur(int *arr, int n, int x)
{
    int left = 1, right = n-1, mid;
    int result = -1;

    while(left <= right)
    {
        mid = (left + right) / 2;

        if(x == arr[mid])
        {
            result = mid;
            right = mid - 1;
        }
        else if(x < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return result;
}

int BinarySearchLastOccur(int *arr, int n, int x)
{
    int left = 1, right = n-1, mid;
    int result = -1;

    while(left <= right)
    {
        mid = (left + right) / 2;

        if(x == arr[mid])
        {
            result = mid;
            left = mid + 1;
        }
        else if(x < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return result;
}

int main()
{
    f >> numberElements;

    for(int i = 1; i<=numberElements; ++i)
    {
        f >> A[i];
    }

    int myRetVal = BinarySearch(19);
    cout << myRetVal << endl;
    cout << BinarySearch(21) << endl;

    int B[] = {1, 3, 20, 20, 20, 45, 78};
    cout << "Size of array B is: " << sizeof(B)/sizeof(*B) << endl;
    int n = sizeof(B)/sizeof(*B);

    cout << "First occurrence at index: "
         << BinarySearchFirstOccur(B, n, 20) << endl;

    cout << "Last occurrence at index:  "
         << BinarySearchLastOccur(B, n, 20) << endl;

    return 0;
}
