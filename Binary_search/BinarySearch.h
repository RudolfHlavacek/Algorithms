#ifndef BINARYSEARCH_H_INCLUDED
#define BINARYSEARCH_H_INCLUDED

/******************************************************************************/
/*                           Function declarations                            */
/******************************************************************************/
int BinarySearch(int *sorted_arr, int arr_size, int searched_item);
int BinarySearchFirstOccurrence(int *sorted_arr, int arr_size, int searched_item);
int BinarySearchLastOccurrence(int *sorted_arr, int arr_size, int searched_item);



/******************************************************************************/
/*                          Function implementation                           */
/******************************************************************************/
int BinarySearch(int *sorted_arr, int arr_size, int searched_item)
{
    int left = 1, right = arr_size - 1, mid;

    while(left <= right)
    {
        mid = (left + right) / 2;

        if(searched_item == sorted_arr[mid])
            return mid;
        else if(searched_item < sorted_arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int BinarySearchFirstOccurrence(int *sorted_arr, int arr_size, int searched_item)
{
    int left = 1, right = arr_size - 1, mid;
    int result = -1;

    while(left <= right)
    {
        mid = (left + right) / 2;

        if(searched_item == sorted_arr[mid])
        {
            result = mid;
            right = mid - 1;
        }
        else if(searched_item < sorted_arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return result;
}

int BinarySearchLastOccurrence(int *sorted_arr, int arr_size, int searched_item)
{
    int left = 1, right = arr_size - 1, mid;
    int result = -1;

    while(left <= right)
    {
        mid = (left + right) / 2;

        if(searched_item == sorted_arr[mid])
        {
            result = mid;
            left = mid + 1;
        }
        else if(searched_item < sorted_arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return result;
}

#endif // BINARYSEARCH_H_INCLUDED
