#include "pch.h"
#include "CppUnitTest.h"

#include "..\Algorithms\src\BinarySearch.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AlgorithmsTests
{
	TEST_CLASS(BinarySearchTests)
	{
	public:

		TEST_METHOD(BinarySearch)
		{
			int arr[9] = {2, 5, 5, 6, 9, 19, 26, 45, 69};

			int result = rh::BinarySearch(arr, 9, 9);
			Assert::AreEqual(4, result);
		}

		TEST_METHOD(BinarySearch_out_of_range)
		{
			int arr[9] = { 2, 5, 5, 6, 9, 19, 26, 45, 69 };

			int result = rh::BinarySearch(arr, 9, 10);
			Assert::AreEqual(-1, result);

			result = rh::BinarySearch(arr, 9, 72);
			Assert::AreEqual(-1, result);

			result = rh::BinarySearch(arr, 9, -12);
			Assert::AreEqual(-1, result);
		}

		TEST_METHOD(BinarySearch_chars)
		{
			char arr[] = {'A', 'B', 'C', 'D', 'E', 'F'};
			int n = sizeof(arr) / sizeof(*arr);

			int result = rh::BinarySearch(arr, n, 'C');
			Assert::AreEqual(2, result);
		}

		TEST_METHOD(BinarySearch_chars_out_of_range)
		{
			char arr[] = { 'A', 'B', 'D', 'E', 'F' };
			int n = sizeof(arr) / sizeof(*arr);

			int result = rh::BinarySearch(arr, n, 'C');
			Assert::AreEqual(-1, result);

			result = rh::BinarySearch(arr, n, 'X');
			Assert::AreEqual(-1, result);

			result = rh::BinarySearch(arr, n, '6');
			Assert::AreEqual(-1, result);
		}

		TEST_METHOD(BinarySearchFirstOccurence)
		{
			int arr[7] = {1, 3, 20, 20, 20, 45, 78};
			int n = sizeof(arr) / sizeof(*arr);

			int result = rh::BinarySearchFirstOccurrence(arr, n, 20);
			Assert::AreEqual(2, result);
		}

		TEST_METHOD(BinarySearchFirstOccurence_out_of_range)
		{
			int arr[7] = { 1, 3, 20, 20, 20, 45, 78 };
			int n = sizeof(arr) / sizeof(*arr);

			int result = rh::BinarySearchFirstOccurrence(arr, n, 21);
			Assert::AreEqual(-1, result);

			result = rh::BinarySearchFirstOccurrence(arr, n, -9);
			Assert::AreEqual(-1, result);

			result = rh::BinarySearchFirstOccurrence(arr, n, 92);
			Assert::AreEqual(-1, result);
		}

		TEST_METHOD(BinarySearchLastOccurence)
		{
			int arr[7] = { 1, 3, 20, 20, 20, 45, 78 };
			int n = sizeof(arr) / sizeof(*arr);

			int result = rh::BinarySearchLastOccurrence(arr, n, 20);
			Assert::AreEqual(4, result);
		}

		TEST_METHOD(BinarySearchLastOccurence_out_of_range)
		{
			int arr[7] = { 1, 3, 20, 20, 20, 45, 78 };
			int n = sizeof(arr) / sizeof(*arr);

			int result = rh::BinarySearchLastOccurrence(arr, n, 21);
			Assert::AreEqual(-1, result);

			result = rh::BinarySearchLastOccurrence(arr, n, -9);
			Assert::AreEqual(-1, result);

			result = rh::BinarySearchLastOccurrence(arr, n, 92);
			Assert::AreEqual(-1, result);
		}

	};
}
