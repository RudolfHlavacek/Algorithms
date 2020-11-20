#ifndef BINARYSEARCH_H_INCLUDED
#define BINARYSEARCH_H_INCLUDED


/******************************************************************************/
/*                           Function declarations                            */
/******************************************************************************/
template <typename T>
int BinarySearch(T *sorted_arr, int arr_size, T searched_item);

template <typename T>
int BinarySearchFirstOccurrence(T *sorted_arr, int arr_size, T searched_item);

template <typename T>
int BinarySearchLastOccurrence(T *sorted_arr, int arr_size, T searched_item);



/******************************************************************************/
/*                          Function implementation                           */
/******************************************************************************/
template <typename T>
int BinarySearch(T *sorted_arr, int arr_size, T searched_item)
{
    int left = 0, right = arr_size - 1, mid;

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

template <typename T>
int BinarySearchFirstOccurrence(T *sorted_arr, int arr_size, T searched_item)
{
    int left = 0, right = arr_size - 1, mid;
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

template <typename T>
int BinarySearchLastOccurrence(T *sorted_arr, int arr_size, T searched_item)
{
    int left = 0, right = arr_size - 1, mid;
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
