#pragma once

#include <iostream>
#include <fstream>

#include "BinarySearch.h"

std::ifstream f("binary_search_example_data.in");
std::ofstream g("binary_search_example_data.out");


int binary_search_example()
{
    int numberElements;
    f >> numberElements;

    int A[9];
    for(int i = 0; i<numberElements; ++i)
    {
        f >> A[i];
    }


    int myRetVal = BinarySearch(A, numberElements, 19);
    std::cout << myRetVal << std::endl;
    std::cout << BinarySearch(A, numberElements, 21) << "\n" << std::endl;

    int B[] = {1, 3, 20, 20, 20, 45, 78};
    int n = sizeof(B)/sizeof(*B);
    std::cout << "Size of array B is: " << n << "\n" << std::endl;


    std::cout << "First occurrence at index: "
         << BinarySearchFirstOccurrence(B, n, 20) << std::endl;

    std::cout << "Last occurrence at index:  "
         << BinarySearchLastOccurrence(B, n, 20) << std::endl;



    char ch_arr[] = {'A', 'B', 'C', 'D', 'D', 'D', 'X', 'Y', 'Z'};
    n = sizeof(ch_arr)/sizeof(*ch_arr);
    std::cout << "First occur of 'D': "
         << BinarySearchFirstOccurrence(ch_arr, n, 'D') << std::endl;

    std::cout << "Last occur of 'D':  "
         << BinarySearchLastOccurrence(ch_arr, n, 'D') << std::endl;



    std::string string_arr[] = {"Abe", "Bobby", "Cash", "Hannah", "Michael",
                                "Zack", "Zack", "Zack", "bob", "test",
                                "test", "test", "test", "test"};
    n = sizeof(string_arr)/sizeof(*string_arr);

    std::cout << "\n\n";
    std::cout << "Size of string array: " << n << std::endl;

    std::cout << "First occur of 'test': "
                << BinarySearchFirstOccurrence<std::string>(string_arr, n, "test")
                << std::endl;

    std::cout << "Last occur of 'test':  "
                << BinarySearchLastOccurrence<std::string>(string_arr, n, "test")
                << std::endl;

    return 0;
}
