#include "pch.h"
#include "CppUnitTest.h"

#include "..\Algorithms\src\MinHeap.h"

#include <vector>
#include <random>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AlgorithmsTests
{
	TEST_CLASS(MinHeapTests)
	{
	public:

		TEST_METHOD(Ctor)
		{
			rh::MinHeap<int> minheap(3);
			
			Assert::AreEqual(0, minheap.size());
			Assert::AreEqual(false, minheap.isFull());

			minheap.insert(5);
			minheap.insert(3);
			minheap.insert(4);
			Assert::AreEqual(3, minheap.size());
			Assert::AreEqual(true, minheap.isFull());
		}

		TEST_METHOD(Ctor_negative_number)
		{
			rh::MinHeap<int> minheap(-2);

			Assert::AreEqual(0, minheap.size());
			Assert::AreEqual(false, minheap.isFull());

			minheap.insert(5);
			Assert::AreEqual(1, minheap.size());
			Assert::AreEqual(true, minheap.isFull());
		}

		TEST_METHOD(Ctor_zero_number)
		{
			rh::MinHeap<int> minheap(0);

			Assert::AreEqual(0, minheap.size());
			Assert::AreEqual(false, minheap.isFull());

			minheap.insert(5);
			Assert::AreEqual(1, minheap.size());
			Assert::AreEqual(true, minheap.isFull());
		}

		// TODO getMIN bez insertovaneho prvku. deletemin a extract min to same

		TEST_METHOD(peekMin_deleteMin)
		{
			rh::MinHeap<int> minheap(14);
			std::vector<int> test_vec = {50, 25, 75, 100, 99, 101, -1, -2, -3, -1, 1, 0, 2, 3};
			const std::vector<int> res_vec = {-3, -2, -1, -1, 0, 1, 2, 3, 25, 50, 75, 99, 100, 101};

			for (int i = 0; i < test_vec.size(); i++)
				minheap.insert(test_vec[i]);

			for (int res_num : res_vec)
			{
				Assert::AreEqual(res_num, minheap.peekMin());
				minheap.deleteMin();
			}
			Assert::AreEqual(0, minheap.size());
		}

		TEST_METHOD(extractMin)
		{
			rh::MinHeap<int> minheap(14);
			std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1, 1, 0, 2, 3 };
			const std::vector<int> res_vec = { -3, -2, -1, -1, 0, 1, 2, 3, 25, 50, 75, 99, 100, 101 };

			for (int i = 0; i < test_vec.size(); i++)
				minheap.insert(test_vec[i]);

			for (int res_num : res_vec)
			{
				Assert::AreEqual(res_num, minheap.extractMin());
			}
			Assert::AreEqual(0, minheap.size());
		}

		TEST_METHOD(extractMin_10000_runs)
		{
			const int max_runs = 10000;

			rh::MinHeap<int> minheap(14);
			std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1, 1, 0, 2, 3 };
			const std::vector<int> res_vec = { -3, -2, -1, -1, 0, 1, 2, 3, 25, 50, 75, 99, 100, 101 };
			auto randgen = std::default_random_engine{};
			randgen.seed(time(NULL));


			for (int i = 0; i < max_runs; i++)
			{
				std::shuffle(test_vec.begin(), test_vec.end(), randgen);
				for (int num : test_vec)
					minheap.insert(num);

				for (int res : res_vec)
					Assert::AreEqual(res, minheap.extractMin());

				Assert::AreEqual(0, minheap.size());
			}
		}

		TEST_METHOD(size)
		{
			rh::MinHeap<int> minheap(10);

			for (int i = 0; i < 10; i++)
			{
				minheap.insert(42);
				Assert::AreEqual(i + 1, minheap.size());
			}
		}

		TEST_METHOD(isFull)
		{
			rh::MinHeap<int> minheap(1);
			int curr_capacity = 1;

			for (int i = 0; i < 10; i++)
			{
				int curr_size = minheap.size();
				for (int j = 0; j < curr_capacity - curr_size; j++)
					minheap.insert(42);

				Assert::AreEqual(true, minheap.isFull());
				curr_capacity *= 2;
			}
		}

		TEST_METHOD(resize_smaller)
		{
			rh::MinHeap<int> minheap(5);

			minheap.resize(1);
			minheap.insert(42);

			Assert::AreEqual(true, minheap.isFull());
		}

		TEST_METHOD(resize_smaller_than_one)
		{
			rh::MinHeap<int> minheap(5);

			minheap.resize(0);
			for (int i = 0; i < 5; i++)
				minheap.insert(42);

			Assert::AreEqual(true, minheap.isFull());
		}

		TEST_METHOD(resize_negative_number)
		{
			rh::MinHeap<int> minheap(5);

			minheap.resize(-2);
			for (int i = 0; i < 5; i++)
				minheap.insert(42);

			Assert::AreEqual(true, minheap.isFull());
		}

		TEST_METHOD(resize)
		{
			rh::MinHeap<int> minheap(5);

			minheap.resize(0);
			for (int i = 0; i < 5; i++)
				minheap.insert(42);

			Assert::AreEqual(true, minheap.isFull());

			minheap.resize(6);
			Assert::AreEqual(false, minheap.isFull());

			minheap.insert(42);
			Assert::AreEqual(true, minheap.isFull());
		}

	};
}
