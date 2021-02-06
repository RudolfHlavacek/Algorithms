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

			Assert::AreEqual(true, minheap.resize(1));
			minheap.insert(42);

			Assert::AreEqual(true, minheap.isFull());
		}

		TEST_METHOD(resize_smaller_than_one)
		{
			rh::MinHeap<int> minheap(5);

			Assert::AreEqual(false, minheap.resize(0));
			for (int i = 0; i < 5; i++)
				minheap.insert(42);

			Assert::AreEqual(true, minheap.isFull());
		}

		TEST_METHOD(resize_negative_number)
		{
			rh::MinHeap<int> minheap(5);

			Assert::AreEqual(false, minheap.resize(-2));
			for (int i = 0; i < 5; i++)
				minheap.insert(42);

			Assert::AreEqual(true, minheap.isFull());
		}

		TEST_METHOD(resize)
		{
			rh::MinHeap<int> minheap(5);

			Assert::AreEqual(false, minheap.resize(0));
			for (int i = 0; i < 5; i++)
				minheap.insert(42);

			Assert::AreEqual(true, minheap.isFull());

			Assert::AreEqual(true, minheap.resize(6));
			Assert::AreEqual(false, minheap.isFull());

			minheap.insert(42);
			Assert::AreEqual(true, minheap.isFull());
		}

		TEST_METHOD(resize_without_params)
		{
			rh::MinHeap<int> minheap(10);

			minheap.insert(42);
			minheap.insert(21);
			minheap.insert(12);

			Assert::AreEqual(true, minheap.resize());
			Assert::AreEqual(3, minheap.size());
			Assert::AreEqual(true, minheap.isFull());

			Assert::AreEqual(12, minheap.extractMin());
			Assert::AreEqual(21, minheap.extractMin());
			Assert::AreEqual(42, minheap.extractMin());
		}

		TEST_METHOD(resize_without_params_empty_heap)
		{
			rh::MinHeap<int> minheap(10);

			Assert::AreEqual(true, minheap.resize());
			Assert::AreEqual(0, minheap.size());
			Assert::AreEqual(false, minheap.isFull());

			minheap.insert(42);
			Assert::AreEqual(1, minheap.size());
			Assert::AreEqual(true, minheap.isFull());
		}

		TEST_METHOD(resize_without_params_full_heap)
		{
			rh::MinHeap<int> minheap(6);

			minheap.insert(2);
			minheap.insert(-3);
			minheap.insert(1);
			minheap.insert(12);
			minheap.insert(-21);
			minheap.insert(-42);

			Assert::AreEqual(false, minheap.resize());
			Assert::AreEqual(6, minheap.size());
			Assert::AreEqual(true, minheap.isFull());

			minheap.insert(42);
			Assert::AreEqual(7, minheap.size());
			Assert::AreEqual(false, minheap.isFull());

			Assert::AreEqual(-42, minheap.extractMin());
			Assert::AreEqual(-21, minheap.extractMin());
			Assert::AreEqual(-3, minheap.extractMin());
			Assert::AreEqual(1, minheap.extractMin());
			Assert::AreEqual(2, minheap.extractMin());
			Assert::AreEqual(12, minheap.extractMin());
			Assert::AreEqual(42, minheap.extractMin());
		}

		TEST_METHOD(clear)
		{
			rh::MinHeap<int> minheap(3);

			minheap.insert(42);
			minheap.insert(21);
			minheap.insert(12);

			Assert::AreEqual(3, minheap.size());

			minheap.clear();
			Assert::AreEqual(0, minheap.size());

			minheap.insert(42);
			minheap.insert(21);
			minheap.insert(12);
			Assert::AreEqual(3, minheap.size());
			Assert::AreEqual(true, minheap.isFull());
		}

		TEST_METHOD(CopyCtor)
		{
			rh::MinHeap<int> mh(3);
			mh.insert(42);
			mh.insert(21);

			rh::MinHeap<int> mh_copy(mh);
			mh.clear();
			for (int i = 0; i < 10; i++)
				mh.insert(1);

			Assert::AreEqual(10, mh.size());

			Assert::AreEqual(2, mh_copy.size());
			Assert::AreEqual(false, mh_copy.isFull());

			mh_copy.insert(12);
			Assert::AreEqual(3, mh_copy.size());
			Assert::AreEqual(true, mh_copy.isFull());
			Assert::AreEqual(12, mh_copy.extractMin());
			Assert::AreEqual(21, mh_copy.extractMin());
			Assert::AreEqual(42, mh_copy.extractMin());
		}

		TEST_METHOD(copy_without_resizing)
		{
			rh::MinHeap<int> mh_copy(3);
			mh_copy.insert(42);
			mh_copy.insert(21);

			rh::MinHeap<int> mh(10);
			mh.insert(3);
			mh.insert(2);
			mh.insert(1);

			mh_copy.copy(mh);
			
			mh.clear();
			for (int i = 0; i < 12; i++)
				mh.insert(1);
			Assert::AreEqual(12, mh.size());

			Assert::AreEqual(3, mh_copy.size());
			Assert::AreEqual(true, mh_copy.isFull());
			Assert::AreEqual(1, mh_copy.extractMin());
			Assert::AreEqual(2, mh_copy.extractMin());
			Assert::AreEqual(3, mh_copy.extractMin());
		}

		TEST_METHOD(copy_with_resizing)
		{
			rh::MinHeap<int> mh_copy(3);
			mh_copy.insert(42);
			mh_copy.insert(21);

			rh::MinHeap<int> mh(10);
			mh.insert(3);
			mh.insert(2);
			mh.insert(1);
			mh.insert(12);
			mh.insert(23);

			mh_copy.copy(mh);
			
			mh.clear();
			for (int i = 0; i < 12; i++)
				mh.insert(1);
			Assert::AreEqual(12, mh.size());

			Assert::AreEqual(5, mh_copy.size());
			Assert::AreEqual(true, mh_copy.isFull());
			Assert::AreEqual(1, mh_copy.extractMin());
			Assert::AreEqual(2, mh_copy.extractMin());
			Assert::AreEqual(3, mh_copy.extractMin());
			Assert::AreEqual(12, mh_copy.extractMin());
			Assert::AreEqual(23, mh_copy.extractMin());
		}

		TEST_METHOD(operatorEqual_without_resizing)
		{
			rh::MinHeap<int> mh_copy(3);
			mh_copy.insert(42);
			mh_copy.insert(-21);

			rh::MinHeap<int> mh(10);
			mh.insert(3);
			mh.insert(-2);

			mh_copy = mh;
			
			mh.clear();
			for (int i = 0; i < 12; i++)
				mh.insert(1);
			Assert::AreEqual(12, mh.size());

			Assert::AreEqual(2, mh_copy.size());
			Assert::AreEqual(false, mh_copy.isFull());

			mh_copy.insert(1);
			Assert::AreEqual(true, mh_copy.isFull());
			Assert::AreEqual(-2, mh_copy.extractMin());
			Assert::AreEqual(1, mh_copy.extractMin());
			Assert::AreEqual(3, mh_copy.extractMin());
		}

		TEST_METHOD(operatorEqual_with_resizing)
		{
			rh::MinHeap<int> mh_copy(3);
			mh_copy.insert(-42);
			mh_copy.insert(21);

			rh::MinHeap<int> mh(10);
			mh.insert(-3);
			mh.insert(2);
			mh.insert(-1);
			mh.insert(12);
			mh.insert(-23);

			mh_copy = mh;

			mh.clear();
			for (int i = 0; i < 12; i++)
				mh.insert(1);
			Assert::AreEqual(12, mh.size());

			Assert::AreEqual(5, mh_copy.size());
			Assert::AreEqual(true, mh_copy.isFull());
			Assert::AreEqual(-23, mh_copy.extractMin());
			Assert::AreEqual(-3, mh_copy.extractMin());
			Assert::AreEqual(-1, mh_copy.extractMin());
			Assert::AreEqual(2, mh_copy.extractMin());
			Assert::AreEqual(12, mh_copy.extractMin());
		}

	};
}
