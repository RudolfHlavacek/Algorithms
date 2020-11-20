#ifndef BINARYSEARCH_H_INCLUDED
#define BINARYSEARCH_H_INCLUDED

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

#endif // BINARYSEARCH_H_INCLUDED
