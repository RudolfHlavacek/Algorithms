#include "pch.h"
#include "CppUnitTest.h"

#include "..\Algorithms\src\MaxHeap.h"
//#include "MinMaxHeap_Test_Utills.h"

#include <vector>
#include <random>

#include "privablic.h"
#include "Pokus.h"

#define HEAP_ALLOCATED_MARK (int)0xCDCDCDCD
#define HEAP_END_MARK (int)0xFDFDFDFD
#define HEAP_DEALLOCATED_MARK (int)0xDDDDDDDD

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace rh;


namespace AlgorithmsTests
{

	TEST_CLASS(MaxHeapTests)
	{

	public:

		TEST_METHOD(_Ctor)
		{
			const int max_capacity = 3;
			MaxHeap<int> maxheap(max_capacity);

			const int size = maxheap.*member<MaxHeap_m_size>::value;
			const int capacity = maxheap.*member<MaxHeap_m_capacity>::value;
			const int* const ptr_to_heap = maxheap.*member<MaxHeap_m_heap>::value;


			Assert::AreEqual(0, size);
			Assert::AreEqual(3, capacity);

			for (int i = 0; i < max_capacity; i++)
				Assert::AreEqual(HEAP_ALLOCATED_MARK, ptr_to_heap[i]);

			Assert::AreEqual(HEAP_END_MARK, ptr_to_heap[max_capacity]);
		}

		TEST_METHOD(_Ctor__negative_number)
		{
			MaxHeap<int> maxheap(-1);
			const int size = maxheap.*member<MaxHeap_m_size>::value;
			const int capacity = maxheap.*member<MaxHeap_m_capacity>::value;
			const int* const ptr_to_heap = maxheap.*member<MaxHeap_m_heap>::value;


			Assert::AreEqual(0, size);
			Assert::AreEqual(1, capacity);
			Assert::AreEqual(HEAP_ALLOCATED_MARK, ptr_to_heap[0]);
			Assert::AreEqual(HEAP_END_MARK, ptr_to_heap[1]);
		}

		TEST_METHOD(_Ctor__without_params)
		{
			MaxHeap<int> maxheap;
			const int size = maxheap.*member<MaxHeap_m_size>::value;
			const int capacity = maxheap.*member<MaxHeap_m_capacity>::value;
			const int* const ptr_to_heap = maxheap.*member<MaxHeap_m_heap>::value;


			Assert::AreEqual(0, size);
			Assert::AreEqual(1, capacity);
			Assert::AreEqual(HEAP_ALLOCATED_MARK, ptr_to_heap[0]);
			Assert::AreEqual(HEAP_END_MARK, ptr_to_heap[1]);
		}

		TEST_METHOD(_Ctor__zero_number)
		{
			MaxHeap<int> maxheap(0);
			const int size = maxheap.*member<MaxHeap_m_size>::value;
			const int capacity = maxheap.*member<MaxHeap_m_capacity>::value;
			const int* const ptr_to_heap = maxheap.*member<MaxHeap_m_heap>::value;

			
			Assert::AreEqual(0, size);
			Assert::AreEqual(1, capacity);
			Assert::AreEqual(HEAP_ALLOCATED_MARK, ptr_to_heap[0]);
			Assert::AreEqual(HEAP_END_MARK, ptr_to_heap[1]);
		}

		TEST_METHOD(_Destructor)
		{
			const int* ptr_to_heap;
			{
				MaxHeap<int> maxheap(5);
				ptr_to_heap = maxheap.*member<MaxHeap_m_heap>::value;
				maxheap.insert(9);
				maxheap.insert(10);
				maxheap.insert(11);
			}


			for (int i = 0; i < 6; i++)
				Assert::AreEqual(HEAP_DEALLOCATED_MARK, ptr_to_heap[i]);
		}

		TEST_METHOD(insert)
		{
			const std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1, 1, 0, 2, 3 };
			const std::vector<int> arranged_vec = { 101, 99, 100, 25, 75, 50, 3, -2, -3, -1, 1, 0, 2, -1 };
			MaxHeap<int> maxheap(14);

			for (int num : test_vec)
				maxheap.insert(num);

			const int size = maxheap.*member<MaxHeap_m_size>::value;
			const int capacity = maxheap.*member<MaxHeap_m_capacity>::value;
			const int* const ptr_to_heap = maxheap.*member<MaxHeap_m_heap>::value;



			Assert::AreEqual((int)arranged_vec.size(), size);
			Assert::AreEqual(14, capacity);

			for (int i = 0; i < arranged_vec.size(); i++)
				Assert::AreEqual(arranged_vec[i], ptr_to_heap[i]);
		}

		TEST_METHOD(peek)
		{
			const std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1, 1, 0, 2, 3 };
			const std::vector<int> arranged_vec = { 101, 99, 100, 25, 75, 50, 3, -2, -3, -1, 1, 0, 2, -1 };
			MaxHeap<int> maxheap(15);

			for (int num : test_vec)
				maxheap.insert(num);

			int size = maxheap.*member<MaxHeap_m_size>::value;
			int capacity = maxheap.*member<MaxHeap_m_capacity>::value;
			const int* const ptr_to_heap = maxheap.*member<MaxHeap_m_heap>::value;



			Assert::AreEqual(14, size);
			Assert::AreEqual(15, capacity);

			for (int i = 0; i < 10; i++)
			{
				size = maxheap.*member<MaxHeap_m_size>::value;
				capacity = maxheap.*member<MaxHeap_m_capacity>::value;

				Assert::AreEqual(101, maxheap.peek());

				for (unsigned int k = 0; k < arranged_vec.size(); k++)
					Assert::AreEqual(arranged_vec[k], ptr_to_heap[k]);
			}

		}

		TEST_METHOD(removeRoot)
		{
			const std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1, 1, 0, 2, 3 };
			const std::vector<std::vector<int>> arranged_vectors = { {100, 99, 50, 25, 75, 2, 3, -2, -3, -1, 1, 0, -1},
																	 {99, 75, 50, 25, 1, 2, 3, -2, -3, -1, -1, 0},
																	 {75, 25, 50, 0, 1, 2, 3, -2, -3, -1, -1},
																	 {50, 25, 3, 0, 1, 2, -1, -2, -3, -1},
																	 {25, 1, 3, 0, -1, 2, -1, -2, -3},
																	 {3, 1, 2, 0, -1, -3, -1, -2},
																	 {2, 1, -1, 0, -1, -3, -2},
																	 {1, 0, -1, -2, -1, -3},
																	 {0, -1, -1, -2, -3},//
																	 {-1, -2, -1, -3},
																	 {-1, -2, -3},
																	 {-2, -3},
																	 {-3} };
			MaxHeap<int> maxheap(15);
			for (int num : test_vec)
				maxheap.insert(num);

			const int* const ptr_to_heap = maxheap.*member<MaxHeap_m_heap>::value;



			for (std::vector<int> vec : arranged_vectors)
			{
				maxheap.removeRoot();
				const int size = maxheap.*member<MaxHeap_m_size>::value;
				const int capacity = maxheap.*member<MaxHeap_m_capacity>::value;


				Assert::AreEqual((int)vec.size(), size);
				Assert::AreEqual(15, capacity);
				for (unsigned int i = 0; i < vec.size(); i++)
					Assert::AreEqual(vec[i], ptr_to_heap[i]);
			}
		}

		TEST_METHOD(removeRoot__empty_heap)
		{
			MaxHeap<int> maxheap(5);
			for (int i = 0; i < 5; i++)
				maxheap.removeRoot();

			const int size = maxheap.*member<MaxHeap_m_size>::value;
			const int capacity = maxheap.*member<MaxHeap_m_capacity>::value;
			const int* const ptr_to_heap = maxheap.*member<MaxHeap_m_heap>::value;

			
			Assert::AreEqual(0, size);
		}

		TEST_METHOD(extractRoot)
		{
			const std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1, 1, 0, 2, 3 };
			const std::vector<int> res_vec = { 101, 100, 99, 75, 50, 25, 3, 2, 1, 0, -1, -1, -2, -3 };
			const std::vector<std::vector<int>> arranged_vectors = { {100, 99, 50, 25, 75, 2, 3, -2, -3, -1, 1, 0, -1},
																	 {99, 75, 50, 25, 1, 2, 3, -2, -3, -1, -1, 0},
																	 {75, 25, 50, 0, 1, 2, 3, -2, -3, -1, -1},
																	 {50, 25, 3, 0, 1, 2, -1, -2, -3, -1},
																	 {25, 1, 3, 0, -1, 2, -1, -2, -3},
																	 {3, 1, 2, 0, -1, -3, -1, -2},
																	 {2, 1, -1, 0, -1, -3, -2},
																	 {1, 0, -1, -2, -1, -3},
																	 {0, -1, -1, -2, -3},//
																	 {-1, -2, -1, -3},
																	 {-1, -2, -3},
																	 {-2, -3},
																	 {-3} };
			MaxHeap<int> maxheap(15);
			for (int num : test_vec)
				maxheap.insert(num);

			const int* const ptr_to_heap = maxheap.*member<MaxHeap_m_heap>::value;



			int i = 0;
			for (std::vector<int> vec : arranged_vectors)
			{
				Assert::AreEqual(res_vec[i++], maxheap.extractRoot());

				int size = maxheap.*member<MaxHeap_m_size>::value;
				Assert::AreEqual((int)vec.size(), size);

				int capacity = maxheap.*member<MaxHeap_m_capacity>::value;
				Assert::AreEqual(15, capacity);

				for (int k = 0; k < vec.size(); k++)
					Assert::AreEqual(vec[k], ptr_to_heap[k]);
			}
		}

		TEST_METHOD(no_reallocation)
		{
			MaxHeap<int> maxheap(10);
			const int* const ptr_to_heap_after_instantiation = maxheap.*member<MaxHeap_m_heap>::value;

			maxheap.insert(42);
			maxheap.insert(21);
			const int* ptr_to_heap = maxheap.*member<MaxHeap_m_heap>::value;
			Assert::AreEqual(ptr_to_heap_after_instantiation, ptr_to_heap);

			maxheap.peek();
			ptr_to_heap = maxheap.*member<MaxHeap_m_heap>::value;
			Assert::AreEqual(ptr_to_heap_after_instantiation, ptr_to_heap);

			maxheap.removeRoot();
			ptr_to_heap = maxheap.*member<MaxHeap_m_heap>::value;
			Assert::AreEqual(ptr_to_heap_after_instantiation, ptr_to_heap);

			maxheap.extractRoot();
			ptr_to_heap = maxheap.*member<MaxHeap_m_heap>::value;
			Assert::AreEqual(ptr_to_heap_after_instantiation, ptr_to_heap);

			maxheap.size();
			ptr_to_heap = maxheap.*member<MaxHeap_m_heap>::value;
			Assert::AreEqual(ptr_to_heap_after_instantiation, ptr_to_heap);

			maxheap.clear();
			ptr_to_heap = maxheap.*member<MaxHeap_m_heap>::value;
			Assert::AreEqual(ptr_to_heap_after_instantiation, ptr_to_heap);
		}

		TEST_METHOD(extractRoot__1000_runs)
		{
			const int max_runs = 1000;

			MaxHeap<int> maxheap(14);
			const int* const ptr_to_heap = maxheap.*member<MaxHeap_m_heap>::value;
			std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1, 1, 0, 2, 3 };
			const std::vector<int> res_vec = { 101, 100, 99, 75, 50, 25, 3, 2, 1, 0, -1, -1, -2, -3 };
			auto randgen = std::default_random_engine{};
			randgen.seed(time(NULL));


			for (int i = 0; i < max_runs; i++)
			{
				std::shuffle(test_vec.begin(), test_vec.end(), randgen);
				for (int num : test_vec)
					maxheap.insert(num);

				for (int res : res_vec)
					Assert::AreEqual(res, maxheap.extractRoot());

				const int size = maxheap.*member<MaxHeap_m_size>::value;
				const int capacity = maxheap.*member<MaxHeap_m_capacity>::value;

				Assert::AreEqual(0, size);
				Assert::AreEqual(14, capacity);
				Assert::AreEqual(ptr_to_heap, (const int* const)(maxheap.*member<MaxHeap_m_heap>::value));
			}
		}

		TEST_METHOD(size)
		{
			const int max_capacity = 10;
			MaxHeap<int> maxheap(max_capacity);

			for (int i = 0; i < max_capacity; i++)
			{
				maxheap.insert(42);
				const int size = maxheap.*member<MaxHeap_m_size>::value;
				Assert::AreEqual(i + 1, size);
			}
		}
		// resize(int new_size) OK
		// resize()             OK
		// clear()              OK
		// copy()
		// operator=()
		// check if heap is deallocate

		TEST_METHOD(resize__no_action)
		{
			// case 1: new_capacity is 0
			// case 2: new_capacity is negative number
			// case 3: new_capacity is lesser than number of elements
			// case 4: new_capacity is equal to current capacity
			MaxHeap<int> maxheap(5);
			const int* const ptr_to_init_heap = maxheap.*member<MaxHeap_m_heap>::value;
			maxheap.insert(10);
			maxheap.insert(11);


			// case 1:
			Assert::IsFalse(maxheap.resize(0));

			const int* ptr_new_heap = maxheap.*member<MaxHeap_m_heap>::value;
			Assert::AreEqual(ptr_to_init_heap, ptr_new_heap);

			int size = maxheap.*member<MaxHeap_m_size>::value;
			Assert::AreEqual(2, size);

			int capacity = maxheap.*member<MaxHeap_m_capacity>::value;
			Assert::AreEqual(5, capacity);



			// case 2:
			Assert::IsFalse(maxheap.resize(-1));

			ptr_new_heap = maxheap.*member<MaxHeap_m_heap>::value;
			Assert::AreEqual(ptr_to_init_heap, ptr_new_heap);

			size = maxheap.*member<MaxHeap_m_size>::value;
			Assert::AreEqual(2, size);

			capacity = maxheap.*member<MaxHeap_m_capacity>::value;
			Assert::AreEqual(5, capacity);



			// case 3:
			Assert::IsFalse(maxheap.resize(1));

			ptr_new_heap = maxheap.*member<MaxHeap_m_heap>::value;
			Assert::AreEqual(ptr_to_init_heap, ptr_new_heap);

			size = maxheap.*member<MaxHeap_m_size>::value;
			Assert::AreEqual(2, size);

			capacity = maxheap.*member<MaxHeap_m_capacity>::value;
			Assert::AreEqual(5, capacity);



			// case 4:
			Assert::IsFalse(maxheap.resize(5));

			ptr_new_heap = maxheap.*member<MaxHeap_m_heap>::value;
			Assert::AreEqual(ptr_to_init_heap, ptr_new_heap);

			size = maxheap.*member<MaxHeap_m_size>::value;
			Assert::AreEqual(2, size);

			capacity = maxheap.*member<MaxHeap_m_capacity>::value;
			Assert::AreEqual(5, capacity);
		}

		TEST_METHOD(resize)
		{
			// case 1: new_capacity is different than old capacity AND new_capacity is equal to number of elements
			// case 2: new_capacity is different than old capacity AND new_capacity is greater than number of element
			// case 3: new_capacity is greater than old capacity


			// case 1:
			{
				MaxHeap<int> maxheap(5);
				maxheap.insert(10);
				maxheap.insert(11);
				const int* const ptr_to_init_heap_alloc = maxheap.*member<MaxHeap_m_heap>::value;


				Assert::IsTrue(maxheap.resize(2));

				const int size = maxheap.*member<MaxHeap_m_size>::value;
				const int capacity = maxheap.*member<MaxHeap_m_capacity>::value;
				const int* const ptr_new_heap = maxheap.*member<MaxHeap_m_heap>::value;



				Assert::AreNotEqual(ptr_to_init_heap_alloc, ptr_new_heap);

				Assert::AreEqual(2, size);
				Assert::AreEqual(2, capacity);

				Assert::AreEqual(11, ptr_new_heap[0]);
				Assert::AreEqual(10, ptr_new_heap[1]);

				for (int i = 0; i < 6; i++) // Check for deallocation of old heap.
					Assert::AreEqual(HEAP_DEALLOCATED_MARK, ptr_to_init_heap_alloc[i]);
			}


			// case 2:
			{
				MaxHeap<int> maxheap(5);
				maxheap.insert(10);
				maxheap.insert(11);
				const int* const ptr_to_init_heap_alloc = maxheap.*member<MaxHeap_m_heap>::value;


				Assert::IsTrue(maxheap.resize(3));

				const int size = maxheap.*member<MaxHeap_m_size>::value;
				const int capacity = maxheap.*member<MaxHeap_m_capacity>::value;
				const int* const ptr_new_heap = maxheap.*member<MaxHeap_m_heap>::value;



				Assert::AreNotEqual(ptr_to_init_heap_alloc, ptr_new_heap);

				Assert::AreEqual(2, size);
				Assert::AreEqual(3, capacity);

				Assert::AreEqual(11, ptr_new_heap[0]);
				Assert::AreEqual(10, ptr_new_heap[1]);

				for (int i = 0; i < 6; i++) // Check for deallocation of old heap.
					Assert::AreEqual(HEAP_DEALLOCATED_MARK, ptr_to_init_heap_alloc[i]);
			}


			// case 3:
			{
				MaxHeap<int> maxheap(5);
				maxheap.insert(10);
				maxheap.insert(11);
				const int* const ptr_to_init_heap_alloc = maxheap.*member<MaxHeap_m_heap>::value;


				Assert::IsTrue(maxheap.resize(7));

				const int size = maxheap.*member<MaxHeap_m_size>::value;
				const int capacity = maxheap.*member<MaxHeap_m_capacity>::value;
				const int* const ptr_new_heap = maxheap.*member<MaxHeap_m_heap>::value;



				Assert::AreNotEqual(ptr_to_init_heap_alloc, ptr_new_heap);

				Assert::AreEqual(2, size);
				Assert::AreEqual(7, capacity);

				Assert::AreEqual(11, ptr_new_heap[0]);
				Assert::AreEqual(10, ptr_new_heap[1]);

				for (int i = 0; i < 6; i++) // Check for deallocation of old heap.
					Assert::AreEqual(HEAP_DEALLOCATED_MARK, ptr_to_init_heap_alloc[i]);
			}
		}

		TEST_METHOD(resize__without_params)
		{
			// case 1: m_size < m_capacity    resize
			// case 2: m_size == m_capacity   NO resize
			// case 3: m_size == 0;           resize to capacity of 1
			// case 4: m_size < 0;            Shall not happend.


			// case 1:
			{
				MaxHeap<int> maxheap(5);
				maxheap.insert(9);
				maxheap.insert(10);
				const int* const ptr_to_init_heap_alloc = maxheap.*member<MaxHeap_m_heap>::value;


				Assert::IsTrue(maxheap.resize());

				const int size = maxheap.*member<MaxHeap_m_size>::value;
				const int capacity = maxheap.*member<MaxHeap_m_capacity>::value;
				const int* const ptr_new_heap = maxheap.*member<MaxHeap_m_heap>::value;



				Assert::AreNotEqual(ptr_to_init_heap_alloc, ptr_new_heap);

				Assert::AreEqual(2, size);
				Assert::AreEqual(2, capacity);

				Assert::AreEqual(10, ptr_new_heap[0]);
				Assert::AreEqual(9, ptr_new_heap[1]);

				for (int i = 0; i < 6; i++) // Check for deallocation of old heap.
					Assert::AreEqual(HEAP_DEALLOCATED_MARK, ptr_to_init_heap_alloc[i]);
			}


			// case 2:
			{
				MaxHeap<int> maxheap(3);
				maxheap.insert(9);
				maxheap.insert(10);
				maxheap.insert(11);
				const int* const ptr_to_init_heap_alloc = maxheap.*member<MaxHeap_m_heap>::value;


				Assert::IsFalse(maxheap.resize());

				const int size = maxheap.*member<MaxHeap_m_size>::value;
				const int capacity = maxheap.*member<MaxHeap_m_capacity>::value;
				const int* const ptr_new_heap = maxheap.*member<MaxHeap_m_heap>::value;


				Assert::AreEqual(ptr_new_heap, ptr_to_init_heap_alloc);

				Assert::AreEqual(3, size);
				Assert::AreEqual(3, capacity);

				Assert::AreEqual(11, ptr_to_init_heap_alloc[0]);
				Assert::AreEqual(9, ptr_to_init_heap_alloc[1]);
				Assert::AreEqual(10, ptr_to_init_heap_alloc[2]);
			}


			// case 3:
			{
				MaxHeap<int> maxheap(5);
				const int* const ptr_to_init_heap_alloc = maxheap.*member<MaxHeap_m_heap>::value;


				Assert::IsTrue(maxheap.resize());

				const int size = maxheap.*member<MaxHeap_m_size>::value;
				const int capacity = maxheap.*member<MaxHeap_m_capacity>::value;
				const int* const ptr_new_heap = maxheap.*member<MaxHeap_m_heap>::value;



				Assert::AreNotEqual(ptr_to_init_heap_alloc, ptr_new_heap);

				Assert::AreEqual(0, size);
				Assert::AreEqual(1, capacity);

				for (int i = 0; i < 6; i++) // Check for deallocation of old heap.
					Assert::AreEqual(HEAP_DEALLOCATED_MARK, ptr_to_init_heap_alloc[i]);
			}
		}

		TEST_METHOD(clear)
		{
			MaxHeap<int> maxheap(3);
			const int* const ptr_to_init_heap_alloc = maxheap.*member<MaxHeap_m_heap>::value;

			maxheap.insert(42);
			maxheap.insert(21);
			maxheap.insert(12);


			maxheap.clear();

			const int size = maxheap.*member<MaxHeap_m_size>::value;
			const int capacity = maxheap.*member<MaxHeap_m_capacity>::value;
			const int* const ptr_new_heap = maxheap.*member<MaxHeap_m_heap>::value;



			Assert::AreEqual(0, size);
			Assert::AreEqual(3, capacity);
			Assert::AreEqual(ptr_to_init_heap_alloc, ptr_new_heap); // TODO mozna uz mam v no_reallocation
		}

		TEST_METHOD(_CopyCtor)
		{
			MaxHeap<int> mh_ori(15);
			const std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1, 1, 0, 2, 3 };
			const std::vector<int> arranged_vec = { 101, 99, 100, 25, 75, 50, 3, -2, -3, -1, 1, 0, 2, -1 };
			for (int num : test_vec)
				mh_ori.insert(num);


			MaxHeap<int> maxheap(mh_ori);
			mh_ori.clear();
			for (int i = 0; i < 20; i++)
				mh_ori.insert(42);
			Assert::AreEqual(42, mh_ori.peek());

			const int size = maxheap.*member<MaxHeap_m_size>::value;
			const int capacity = maxheap.*member<MaxHeap_m_capacity>::value;
			const int* const ptr_heap = maxheap.*member<MaxHeap_m_heap>::value;



			Assert::AreEqual(14, size);
			Assert::AreEqual(15, capacity);

			for (unsigned int i = 0; i < arranged_vec.size(); i++)
				Assert::AreEqual(arranged_vec[i], ptr_heap[i]);

			Assert::AreEqual(HEAP_ALLOCATED_MARK, ptr_heap[14]);
			Assert::AreEqual(HEAP_END_MARK, ptr_heap[15]);
		}
		// TODO Copy ctor deep copy

		TEST_METHOD(copy__without_resizing)
		{
			MaxHeap<int> mh_ori(15);
			const int* const ptr_to_original_heap = mh_ori.*member<MaxHeap_m_heap>::value;

			MaxHeap<int> maxheap(10);
			const int* const ptr_to_heap_in_maxheap = maxheap.*member<MaxHeap_m_heap>::value;

			const std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1 };
			const std::vector<int> arranged_vec = { 101, 99, 100, 25, 75, 50, -1, -2, -3, -1 };
			for (int num : test_vec)
				mh_ori.insert(num);


			maxheap.copy(mh_ori);
			mh_ori.clear();
			for (int i = 0; i < 20; i++)
				mh_ori.insert(42);
			Assert::AreEqual(42, mh_ori.peek());

			const int size = maxheap.*member<MaxHeap_m_size>::value;
			const int capacity = maxheap.*member<MaxHeap_m_capacity>::value;
			const int* const ptr_heap = maxheap.*member<MaxHeap_m_heap>::value;



			Assert::AreEqual(10, size);
			Assert::AreEqual(10, capacity);
			Assert::AreEqual(ptr_to_heap_in_maxheap, ptr_heap);

			for (int i = 0; i < arranged_vec.size(); i++)
				Assert::AreEqual(arranged_vec[i], ptr_heap[i]);

			Assert::AreEqual(HEAP_END_MARK, ptr_heap[10]);

			// Deep copy was created.
			Assert::AreNotEqual(ptr_to_original_heap, ptr_heap);
		}

		TEST_METHOD(copy__with_resizing)
		{
			MaxHeap<int> mh_ori(15);
			const int* ptr_to_original_heap = mh_ori.*member<MaxHeap_m_heap>::value;

			MaxHeap<int> maxheap(10);
			const int* ptr_to_heap_in_maxheap = maxheap.*member<MaxHeap_m_heap>::value;

			const std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1, 3, 42 };
			const std::vector<int> arranged_vec = { 101, 99, 100, 25, 75, 50, -1, -2, -3, -1, 3, 42 };
			for (int num : test_vec)
				mh_ori.insert(num);


			maxheap.copy(mh_ori);
			mh_ori.clear();
			for (int i = 0; i < 20; i++)
				mh_ori.insert(42);
			Assert::AreEqual(42, mh_ori.peek());

			const int size = maxheap.*member<MaxHeap_m_size>::value;
			const int capacity = maxheap.*member<MaxHeap_m_capacity>::value;
			const int* const ptr_heap = maxheap.*member<MaxHeap_m_heap>::value;



			Assert::AreEqual(12, size);
			Assert::AreEqual(12, capacity);
			Assert::AreNotEqual(ptr_to_heap_in_maxheap, ptr_heap);

			for (unsigned int i = 0; i < arranged_vec.size(); i++)
				Assert::AreEqual(arranged_vec[i], ptr_heap[i]);

			Assert::AreEqual(HEAP_END_MARK, ptr_heap[12]);

			// Deep copy was created.
			Assert::AreNotEqual(ptr_to_original_heap, ptr_to_heap_in_maxheap);
			Assert::AreNotEqual(ptr_to_original_heap, ptr_heap);
		}

		TEST_METHOD(operatorEqual__without_resizing)
		{
			MaxHeap<int> mh_ori(15);
			const int* const ptr_to_original_heap = mh_ori.*member<MaxHeap_m_heap>::value;

			MaxHeap<int> maxheap(10);
			const int* const ptr_to_heap_in_maxheap = maxheap.*member<MaxHeap_m_heap>::value;

			const std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1 };
			const std::vector<int> arranged_vec = { 101, 99, 100, 25, 75, 50, -1, -2, -3, -1 };
			for (int num : test_vec)
				mh_ori.insert(num);


			maxheap = mh_ori;
			mh_ori.clear();
			for (int i = 0; i < 20; i++)
				mh_ori.insert(42);
			Assert::AreEqual(42, mh_ori.peek());

			const int size = maxheap.*member<MaxHeap_m_size>::value;
			const int capacity = maxheap.*member<MaxHeap_m_capacity>::value;
			const int* const ptr_heap = maxheap.*member<MaxHeap_m_heap>::value;



			Assert::AreEqual(10, size);
			Assert::AreEqual(10, capacity);
			Assert::AreEqual(ptr_to_heap_in_maxheap, ptr_heap);

			for (unsigned int i = 0; i < arranged_vec.size(); i++)
				Assert::AreEqual(arranged_vec[i], ptr_heap[i]);

			Assert::AreEqual(HEAP_END_MARK, ptr_heap[10]);

			// Deep copy was created.
			Assert::AreNotEqual(ptr_to_original_heap, ptr_heap);
		}

		TEST_METHOD(operatorEqual__with_resizing)
		{
			MaxHeap<int> mh_ori(15);
			const int* ptr_to_original_heap = mh_ori.*member<MaxHeap_m_heap>::value;

			MaxHeap<int> maxheap(10);
			const int* ptr_to_heap_in_maxheap = maxheap.*member<MaxHeap_m_heap>::value;

			const std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1, 3, 42 };
			const std::vector<int> arranged_vec = { 101, 99, 100, 25, 75, 50, -1, -2, -3, -1, 3, 42 };
			for (int num : test_vec)
				mh_ori.insert(num);


			maxheap = mh_ori;
			mh_ori.clear();
			for (int i = 0; i < 20; i++)
				mh_ori.insert(42);
			Assert::AreEqual(42, mh_ori.peek());

			const int size = maxheap.*member<MaxHeap_m_size>::value;
			const int capacity = maxheap.*member<MaxHeap_m_capacity>::value;
			const int* const ptr_heap = maxheap.*member<MaxHeap_m_heap>::value;



			Assert::AreEqual(12, size);
			Assert::AreEqual(12, capacity);
			Assert::AreNotEqual(ptr_to_heap_in_maxheap, ptr_heap);

			for (int i = 0; i < arranged_vec.size(); i++)
				Assert::AreEqual(arranged_vec[i], ptr_heap[i]);

			Assert::AreEqual(HEAP_END_MARK, ptr_heap[12]);

			// Deep copy was created.
			Assert::AreNotEqual(ptr_to_original_heap, ptr_to_heap_in_maxheap);
			Assert::AreNotEqual(ptr_to_original_heap, ptr_heap);
		}

	};
}
