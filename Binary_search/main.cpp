#include <iostream>
#include <fstream>

#include "BinarySearch.h"

std::ifstream f("data.in");
std::ofstream g("data.out");

//int A[1000], numberElements;
//int BinarySearch(int X)
//{
//    int left = 1, right = numberElements, mid;
//
//    while(left <= right)
//    {
//        mid = (left + right) / 2;
//
//        if(X == A[mid]) return mid;
//        else if(X < A[mid]) right = mid - 1;
//        else left = mid + 1;
//    }
//    return -1;
//}
//
//int BinarySearchFirstOccur(int *arr, int n, int x)
//{
//    int left = 1, right = n-1, mid;
//    int result = -1;
//
//    while(left <= right)
//    {
//        mid = (left + right) / 2;
//
//        if(x == arr[mid])
//        {
//            result = mid;
//            right = mid - 1;
//        }
//        else if(x < arr[mid])
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//    return result;
//}
//
//int BinarySearchLastOccur(int *arr, int n, int x)
//{
//    int left = 1, right = n-1, mid;
//    int result = -1;
//
//    while(left <= right)
//    {
//        mid = (left + right) / 2;
//
//        if(x == arr[mid])
//        {
//            result = mid;
//            left = mid + 1;
//        }
//        else if(x < arr[mid])
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//    return result;
//}

int main()
{
    int numberElements;
    f >> numberElements;

    int A[numberElements];
    for(int i = 0; i<numberElements; ++i)
    {
        f >> A[i];
    }


    int myRetVal = BinarySearch(A, numberElements, 19);
    std::cout << myRetVal << std::endl;
    std::cout << BinarySearch(A, numberElements, 21) << std::endl;

    int B[] = {1, 3, 20, 20, 20, 45, 78};
    std::cout << "Size of array B is: " << sizeof(B)/sizeof(*B) << std::endl;
    int n = sizeof(B)/sizeof(*B);

    std::cout << "First occurrence at index: "
         << BinarySearchFirstOccurrence(B, n, 20) << std::endl;

    std::cout << "Last occurrence at index:  "
         << BinarySearchLastOccurrence(B, n, 20) << std::endl;

    return 0;
}
