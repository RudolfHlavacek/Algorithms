#include "pch.h"
#include "CppUnitTest.h"

#include "..\Algorithms\src\MaxHeap.h"
#include "MinMaxHeap_Test_Utills.h"

#include <vector>
#include <random>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AlgorithmsTests
{
	TEST_CLASS(MaxHeapTests)
	{
	public:

		TEST_METHOD(_Ctor)
		{
			const int max_capacity = 3;
			rh::MaxHeap<int> maxheap(max_capacity);
			
			Assert::AreEqual(0, rhTest::get_m_size(maxheap));
			Assert::AreEqual(max_capacity, rhTest::get_m_capacity(maxheap));
			
			const int * const ptr_to_heap = rhTest::get_ptr_to_heap(maxheap);
			int data;
			for (int i = 0; i < max_capacity; i++)
			{
				data = *(ptr_to_heap + i);
				Assert::AreEqual((int)0xCDCDCDCD, data);
			}
			data = *(ptr_to_heap + max_capacity);
			Assert::AreEqual((int)0xFDFDFDFD, data);
		}

		TEST_METHOD(_Ctor_negative_number)
		{
			rh::MaxHeap<int> maxheap(-1);

			Assert::AreEqual(0, rhTest::get_m_size(maxheap));
			Assert::AreEqual(1, rhTest::get_m_capacity(maxheap));

			const int* const ptr_to_heap = rhTest::get_ptr_to_heap(maxheap);
			int data = *(ptr_to_heap);
			Assert::AreEqual((int)0xCDCDCDCD, data);
			
			data = *(ptr_to_heap + 1);
			Assert::AreEqual((int)0xFDFDFDFD, data);
		}

		TEST_METHOD(_Ctor_without_params)
		{
			rh::MaxHeap<int> maxheap;

			Assert::AreEqual(0, rhTest::get_m_size(maxheap));
			Assert::AreEqual(1, rhTest::get_m_capacity(maxheap));

			const int* const ptr_to_heap = rhTest::get_ptr_to_heap(maxheap);
			int data = *(ptr_to_heap);
			Assert::AreEqual((int)0xCDCDCDCD, data);

			data = *(ptr_to_heap + 1);
			Assert::AreEqual((int)0xFDFDFDFD, data);
		}

		TEST_METHOD(_Ctor_zero_number)
		{
			rh::MaxHeap<int> maxheap(0);

			Assert::AreEqual(0, rhTest::get_m_size(maxheap));
			Assert::AreEqual(1, rhTest::get_m_capacity(maxheap));

			const int* const ptr_to_heap = rhTest::get_ptr_to_heap(maxheap);
			int data = *(ptr_to_heap);
			Assert::AreEqual((int)0xCDCDCDCD, data);

			data = *(ptr_to_heap + 1);
			Assert::AreEqual((int)0xFDFDFDFD, data);
		}

		TEST_METHOD(_Destructor)
		{
			const int* ptr_to_heap;
			{
				rh::MaxHeap<int> maxheap(5);
				maxheap.insert(9);
				maxheap.insert(10);
				maxheap.insert(11);
				ptr_to_heap = rhTest::get_ptr_to_heap(maxheap);
			}

			for (int i = 0; i < 6; i++)
			{
				int data = *(ptr_to_heap + i);
				Assert::AreEqual((int)0xDDDDDDDD, data);
			}
		}

		TEST_METHOD(insert)
		{
			const std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1, 1, 0, 2, 3 };
			const std::vector<int> arranged_vec = { 101, 99, 100, 25, 75, 50, 3, -2, -3, -1, 1, 0, 2, -1 };
			rh::MaxHeap<int> maxheap(14);

			for (int num : test_vec)
				maxheap.insert(num);

			const int* const ptr_to_heap = rhTest::get_ptr_to_heap(maxheap);
			for (int i = 0; i < arranged_vec.size(); i++)
			{
				int data = *(ptr_to_heap + i);
				Assert::AreEqual(arranged_vec[i], data);
			}
		}

		TEST_METHOD(peek)
		{
			const std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1, 1, 0, 2, 3 };
			const std::vector<int> arranged_vec = { 101, 99, 100, 25, 75, 50, 3, -2, -3, -1, 1, 0, 2, -1 };
			rh::MaxHeap<int> maxheap(15);

			for (int num : test_vec)
				maxheap.insert(num);

			Assert::AreEqual(14, rhTest::get_m_size(maxheap));
			Assert::AreEqual(15, rhTest::get_m_capacity(maxheap));

			const int* const ptr_to_heap = rhTest::get_ptr_to_heap(maxheap);
			for (int i = 0; i < 10; i++)
			{
				Assert::AreEqual(101, maxheap.peek());
				for (int k = 0; k < arranged_vec.size(); k++)
				{
					int data = *(ptr_to_heap + k);
					Assert::AreEqual(arranged_vec[k], data);
				}
			}

		}

		TEST_METHOD(deleteRoot)
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
			rh::MaxHeap<int> maxheap(15);

			for (int num : test_vec)
				maxheap.insert(num);

			const int* const ptr_to_heap = rhTest::get_ptr_to_heap(maxheap);
			for (std::vector<int> vec : arranged_vectors)
			{
				maxheap.deleteRoot();
				Assert::AreEqual((int)vec.size(), rhTest::get_m_size(maxheap));
				Assert::AreEqual(15, rhTest::get_m_capacity(maxheap));
				for (int i = 0; i < vec.size(); i++)
				{
					int data = *(ptr_to_heap + i);
					Assert::AreEqual(vec[i], data);
				}
			}
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
			rh::MaxHeap<int> maxheap(15);

			for (int num : test_vec)
				maxheap.insert(num);

			const int* const ptr_to_heap = rhTest::get_ptr_to_heap(maxheap);
			int i = 0;
			for (std::vector<int> vec : arranged_vectors)
			{
				Assert::AreEqual(res_vec[i++], maxheap.extractRoot());
				Assert::AreEqual((int)vec.size(), rhTest::get_m_size(maxheap));
				Assert::AreEqual(15, rhTest::get_m_capacity(maxheap));
				for (int i = 0; i < vec.size(); i++)
				{
					int data = *(ptr_to_heap + i);
					Assert::AreEqual(vec[i], data);
				}
			}
		}

		TEST_METHOD(no_reallocation)
		{
			rh::MaxHeap<int> maxheap(10);
			const int* const ptr_to_heap_after_instantiation = rhTest::get_ptr_to_heap(maxheap);

			maxheap.insert(42);
			maxheap.insert(21);
			const int* ptr_to_heap = rhTest::get_ptr_to_heap(maxheap);
			Assert::AreEqual(ptr_to_heap_after_instantiation, ptr_to_heap);

			maxheap.peek();
			ptr_to_heap = rhTest::get_ptr_to_heap(maxheap);
			Assert::AreEqual(ptr_to_heap_after_instantiation, ptr_to_heap);

			maxheap.deleteRoot();
			ptr_to_heap = rhTest::get_ptr_to_heap(maxheap);
			Assert::AreEqual(ptr_to_heap_after_instantiation, ptr_to_heap);

			maxheap.extractRoot();
			ptr_to_heap = rhTest::get_ptr_to_heap(maxheap);
			Assert::AreEqual(ptr_to_heap_after_instantiation, ptr_to_heap);

			maxheap.size();
			ptr_to_heap = rhTest::get_ptr_to_heap(maxheap);
			Assert::AreEqual(ptr_to_heap_after_instantiation, ptr_to_heap);

			maxheap.clear();
			ptr_to_heap = rhTest::get_ptr_to_heap(maxheap);
			Assert::AreEqual(ptr_to_heap_after_instantiation, ptr_to_heap);
		}

		TEST_METHOD(extractRoot_1000_runs)
		{
			const int max_runs = 1000;

			rh::MaxHeap<int> maxheap(14);
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

				Assert::AreEqual(0, maxheap.size());
			}
		}

		TEST_METHOD(size)
		{
			const int max_capacity = 10;
			rh::MaxHeap<int> maxheap(max_capacity);

			for (int i = 0; i < max_capacity; i++)
			{
				maxheap.insert(42);
				Assert::AreEqual(i + 1, maxheap.size());
			}
		}
		// resize(int new_size) OK
		// resize()             OK
		// clear()              OK
		// copy()
		// operator=()
		// check if heap is deallocate

		TEST_METHOD(resize_no_action)
		{
			// case 1: new_capacity is 0
			// case 2: new_capacity is negative number
			// case 3: new_capacity is lesser than number of elements
			// case 4: new_capacity is equal to current capacity
			rh::MaxHeap<int> maxheap(5);
			maxheap.insert(10);
			maxheap.insert(11);
			const int* const ptr_to_init_heap = rhTest::get_ptr_to_heap(maxheap);

			// case 1:
			Assert::IsFalse(maxheap.resize(0));
			
			Assert::AreEqual(ptr_to_init_heap, (const int* const)rhTest::get_ptr_to_heap(maxheap));
			Assert::AreEqual(2, rhTest::get_m_size(maxheap));
			Assert::AreEqual(5, rhTest::get_m_capacity(maxheap));

			// case 2:
			Assert::IsFalse(maxheap.resize(-1));

			Assert::AreEqual(ptr_to_init_heap, (const int* const)rhTest::get_ptr_to_heap(maxheap));
			Assert::AreEqual(2, rhTest::get_m_size(maxheap));
			Assert::AreEqual(5, rhTest::get_m_capacity(maxheap));

			// case 3:
			Assert::IsFalse(maxheap.resize(1));

			Assert::AreEqual(ptr_to_init_heap, (const int* const)rhTest::get_ptr_to_heap(maxheap));
			Assert::AreEqual(2, rhTest::get_m_size(maxheap));
			Assert::AreEqual(5, rhTest::get_m_capacity(maxheap));

			// case 4:
			Assert::IsFalse(maxheap.resize(5));

			Assert::AreEqual(ptr_to_init_heap, (const int* const)rhTest::get_ptr_to_heap(maxheap));
			Assert::AreEqual(2, rhTest::get_m_size(maxheap));
			Assert::AreEqual(5, rhTest::get_m_capacity(maxheap));
		}

		TEST_METHOD(resize)
		{
			// case 1: new_capacity is different than old capacity AND new_capacity is equal to number of elements
			// case 2: new_capacity is different than old capacity AND new_capacity is greater than number of element
			// case 3: new_capacity is greater than old capacity
			
			// case 1:
			{
				rh::MaxHeap<int> maxheap(5);
				maxheap.insert(10);
				maxheap.insert(11);
				const int* const ptr_to_init_heap_alloc = rhTest::get_ptr_to_heap(maxheap);


				Assert::IsTrue(maxheap.resize(2));


				Assert::AreNotEqual(ptr_to_init_heap_alloc, (const int* const)rhTest::get_ptr_to_heap(maxheap));

				Assert::AreEqual(2, rhTest::get_m_size(maxheap));
				Assert::AreEqual(2, rhTest::get_m_capacity(maxheap));

				Assert::AreEqual(11, *(rhTest::get_ptr_to_heap(maxheap) + 0));
				Assert::AreEqual(10, *(rhTest::get_ptr_to_heap(maxheap) + 1));
				for (int i = 0; i < 6; i++) // Check for deallocation of old heap.
				{
					int data = *(ptr_to_init_heap_alloc + i);
					Assert::AreEqual((int)0xDDDDDDDD, data);
				}
			}

			// case 2:
			{
				rh::MaxHeap<int> maxheap(5);
				maxheap.insert(10);
				maxheap.insert(11);
				const int* const ptr_to_init_heap_alloc = rhTest::get_ptr_to_heap(maxheap);


				Assert::IsTrue(maxheap.resize(3));


				Assert::AreNotEqual(ptr_to_init_heap_alloc, (const int* const)rhTest::get_ptr_to_heap(maxheap));

				Assert::AreEqual(2, rhTest::get_m_size(maxheap));
				Assert::AreEqual(3, rhTest::get_m_capacity(maxheap));

				Assert::AreEqual(11, *(rhTest::get_ptr_to_heap(maxheap) + 0));
				Assert::AreEqual(10, *(rhTest::get_ptr_to_heap(maxheap) + 1));
				for (int i = 0; i < 6; i++) // Check for deallocation of old heap.
				{
					int data = *(ptr_to_init_heap_alloc + i);
					Assert::AreEqual((int)0xDDDDDDDD, data);
				}
			}

			// case 3:
			{
				rh::MaxHeap<int> maxheap(5);
				maxheap.insert(10);
				maxheap.insert(11);
				const int* const ptr_to_init_heap_alloc = rhTest::get_ptr_to_heap(maxheap);


				Assert::IsTrue(maxheap.resize(7));


				Assert::AreNotEqual(ptr_to_init_heap_alloc, (const int* const)rhTest::get_ptr_to_heap(maxheap));

				Assert::AreEqual(2, rhTest::get_m_size(maxheap));
				Assert::AreEqual(7, rhTest::get_m_capacity(maxheap));

				Assert::AreEqual(11, *(rhTest::get_ptr_to_heap(maxheap) + 0));
				Assert::AreEqual(10, *(rhTest::get_ptr_to_heap(maxheap) + 1));
				for (int i = 0; i < 6; i++) // Check for deallocation of old heap.
				{
					int data = *(ptr_to_init_heap_alloc + i);
					Assert::AreEqual((int)0xDDDDDDDD, data);
				}
			}
		}

		TEST_METHOD(resize_without_params)
		{
			// case 1: m_size < m_capacity    resize
			// case 2: m_size == m_capacity   NO resize
			// case 3: m_size == 0;           resize to capacity of 1
			// case 4: m_size < 0;            Shall not happend.

			// case 1:
			{
				rh::MaxHeap<int> maxheap(5);
				maxheap.insert(9);
				maxheap.insert(10);
				const int* const ptr_to_init_heap_alloc = rhTest::get_ptr_to_heap(maxheap);


				Assert::IsTrue(maxheap.resize());


				Assert::AreNotEqual(ptr_to_init_heap_alloc, (const int* const)rhTest::get_ptr_to_heap(maxheap));

				Assert::AreEqual(2, rhTest::get_m_size(maxheap));
				Assert::AreEqual(2, rhTest::get_m_capacity(maxheap));

				Assert::AreEqual(10, *(rhTest::get_ptr_to_heap(maxheap) + 0));
				Assert::AreEqual(9, *(rhTest::get_ptr_to_heap(maxheap) + 1));
				for (int i = 0; i < 6; i++) // Check for deallocation of old heap.
				{
					int data = *(ptr_to_init_heap_alloc + i);
					Assert::AreEqual((int)0xDDDDDDDD, data);
				}
			}

			// case 2:
			{
				rh::MaxHeap<int> maxheap(3);
				maxheap.insert(9);
				maxheap.insert(10);
				maxheap.insert(11);
				const int* const ptr_to_init_heap_alloc = rhTest::get_ptr_to_heap(maxheap);


				Assert::IsFalse(maxheap.resize());


				Assert::AreEqual(ptr_to_init_heap_alloc, (const int* const)rhTest::get_ptr_to_heap(maxheap));

				Assert::AreEqual(3, rhTest::get_m_size(maxheap));
				Assert::AreEqual(3, rhTest::get_m_capacity(maxheap));

				Assert::AreEqual(11, *(rhTest::get_ptr_to_heap(maxheap) + 0));
				Assert::AreEqual(9, *(rhTest::get_ptr_to_heap(maxheap) + 1));
				Assert::AreEqual(10, *(rhTest::get_ptr_to_heap(maxheap) + 2));
			}

			// case 3:
			{
				rh::MaxHeap<int> maxheap(5);
				const int* const ptr_to_init_heap_alloc = rhTest::get_ptr_to_heap(maxheap);


				Assert::IsTrue(maxheap.resize());


				Assert::AreNotEqual(ptr_to_init_heap_alloc, (const int* const)rhTest::get_ptr_to_heap(maxheap));

				Assert::AreEqual(0, rhTest::get_m_size(maxheap));
				Assert::AreEqual(1, rhTest::get_m_capacity(maxheap));

				for (int i = 0; i < 6; i++) // Check for deallocation of old heap.
				{
					int data = *(ptr_to_init_heap_alloc + i);
					Assert::AreEqual((int)0xDDDDDDDD, data);
				}
			}
		}

		TEST_METHOD(clear)
		{
			rh::MaxHeap<int> maxheap(3);
			const int* const ptr_to_init_heap_alloc = rhTest::get_ptr_to_heap(maxheap);

			maxheap.insert(42);
			maxheap.insert(21);
			maxheap.insert(12);

			maxheap.clear();

			Assert::AreEqual(0, rhTest::get_m_size(maxheap));
			Assert::AreEqual(3, rhTest::get_m_capacity(maxheap));
			Assert::AreEqual(ptr_to_init_heap_alloc, (const int* const)rhTest::get_ptr_to_heap(maxheap));
		}

		TEST_METHOD(_CopyCtor)
		{
			rh::MaxHeap<int> mh_ori(15);
			const std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1, 1, 0, 2, 3 };
			const std::vector<int> arranged_vec = { 101, 99, 100, 25, 75, 50, 3, -2, -3, -1, 1, 0, 2, -1 };
			for (int num : test_vec)
				mh_ori.insert(num);


			rh::MaxHeap<int> maxheap(mh_ori);
			mh_ori.clear();
			for (int i = 0; i < 20; i++)
				mh_ori.insert(42);
			Assert::AreEqual(42, mh_ori.peek());


			Assert::AreEqual(14, rhTest::get_m_size(maxheap));
			Assert::AreEqual(15, rhTest::get_m_capacity(maxheap));
			const int* const ptr_to_heap_in_maxheap = rhTest::get_ptr_to_heap(maxheap);
			int data;
			for (int i = 0; i < arranged_vec.size(); i++)
			{
				data = *(ptr_to_heap_in_maxheap + i);
				Assert::AreEqual(arranged_vec[i], data);
			}
			data = *(ptr_to_heap_in_maxheap + 14);
			Assert::AreEqual((int)0xCDCDCDCD, data);
			data = *(ptr_to_heap_in_maxheap + 15);
			Assert::AreEqual((int)0xFDFDFDFD, data);
		}

		TEST_METHOD(copy_without_resizing)
		{
			rh::MaxHeap<int> mh_ori(15);
			rh::MaxHeap<int> maxheap(10);
			const int* const ptr_to_heap_in_maxheap = rhTest::get_ptr_to_heap(maxheap);
			const std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1 };
			const std::vector<int> arranged_vec = { 101, 99, 100, 25, 75, 50, -1, -2, -3, -1 };
			for (int num : test_vec)
				mh_ori.insert(num);


			maxheap.copy(mh_ori);
			mh_ori.clear();
			for (int i = 0; i < 20; i++)
				mh_ori.insert(42);
			Assert::AreEqual(42, mh_ori.peek());


			Assert::AreEqual(10, rhTest::get_m_size(maxheap));
			Assert::AreEqual(10, rhTest::get_m_capacity(maxheap));
			Assert::AreEqual(ptr_to_heap_in_maxheap, (const int* const)rhTest::get_ptr_to_heap(maxheap));
			int data;
			for (int i = 0; i < arranged_vec.size(); i++)
			{
				data = *(ptr_to_heap_in_maxheap + i);
				Assert::AreEqual(arranged_vec[i], data);
			}
			data = *(ptr_to_heap_in_maxheap + 10);
			Assert::AreEqual((int)0xFDFDFDFD, data);
		}

		TEST_METHOD(copy_with_resizing)
		{
			rh::MaxHeap<int> mh_ori(15);
			rh::MaxHeap<int> maxheap(10);
			const int* ptr_to_heap_in_maxheap = rhTest::get_ptr_to_heap(maxheap);
			const std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1, 3, 42 };
			const std::vector<int> arranged_vec = { 101, 99, 100, 25, 75, 50, -1, -2, -3, -1, 3, 42 };
			for (int num : test_vec)
				mh_ori.insert(num);


			maxheap.copy(mh_ori);
			mh_ori.clear();
			for (int i = 0; i < 20; i++)
				mh_ori.insert(42);
			Assert::AreEqual(42, mh_ori.peek());


			Assert::AreEqual(12, rhTest::get_m_size(maxheap));
			Assert::AreEqual(12, rhTest::get_m_capacity(maxheap));
			Assert::AreNotEqual(ptr_to_heap_in_maxheap, (const int* const)rhTest::get_ptr_to_heap(maxheap));
			int data;
			ptr_to_heap_in_maxheap = rhTest::get_ptr_to_heap(maxheap);
			for (int i = 0; i < arranged_vec.size(); i++)
			{
				data = *(ptr_to_heap_in_maxheap + i);
				Assert::AreEqual(arranged_vec[i], data);
			}
			data = *(ptr_to_heap_in_maxheap + 12);
			Assert::AreEqual((int)0xFDFDFDFD, data);
		}

		TEST_METHOD(operatorEqual_without_resizing)
		{
			rh::MaxHeap<int> mh_ori(15);
			rh::MaxHeap<int> maxheap(10);
			const int* const ptr_to_heap_in_maxheap = rhTest::get_ptr_to_heap(maxheap);
			const std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1 };
			const std::vector<int> arranged_vec = { 101, 99, 100, 25, 75, 50, -1, -2, -3, -1 };
			for (int num : test_vec)
				mh_ori.insert(num);


			maxheap = mh_ori;
			mh_ori.clear();
			for (int i = 0; i < 20; i++)
				mh_ori.insert(42);
			Assert::AreEqual(42, mh_ori.peek());


			Assert::AreEqual(10, rhTest::get_m_size(maxheap));
			Assert::AreEqual(10, rhTest::get_m_capacity(maxheap));
			Assert::AreEqual(ptr_to_heap_in_maxheap, (const int* const)rhTest::get_ptr_to_heap(maxheap));
			int data;
			for (int i = 0; i < arranged_vec.size(); i++)
			{
				data = *(ptr_to_heap_in_maxheap + i);
				Assert::AreEqual(arranged_vec[i], data);
			}
			data = *(ptr_to_heap_in_maxheap + 10);
			Assert::AreEqual((int)0xFDFDFDFD, data);
		}

		TEST_METHOD(operatorEqual_with_resizing)
		{
			rh::MaxHeap<int> mh_ori(15);
			rh::MaxHeap<int> maxheap(10);
			const int* ptr_to_heap_in_maxheap = rhTest::get_ptr_to_heap(maxheap);
			const std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1, 3, 42 };
			const std::vector<int> arranged_vec = { 101, 99, 100, 25, 75, 50, -1, -2, -3, -1, 3, 42 };
			for (int num : test_vec)
				mh_ori.insert(num);


			maxheap = mh_ori;
			mh_ori.clear();
			for (int i = 0; i < 20; i++)
				mh_ori.insert(42);
			Assert::AreEqual(42, mh_ori.peek());


			Assert::AreEqual(12, rhTest::get_m_size(maxheap));
			Assert::AreEqual(12, rhTest::get_m_capacity(maxheap));
			Assert::AreNotEqual(ptr_to_heap_in_maxheap, (const int* const)rhTest::get_ptr_to_heap(maxheap));
			int data;
			ptr_to_heap_in_maxheap = rhTest::get_ptr_to_heap(maxheap);
			for (int i = 0; i < arranged_vec.size(); i++)
			{
				data = *(ptr_to_heap_in_maxheap + i);
				Assert::AreEqual(arranged_vec[i], data);
			}
			data = *(ptr_to_heap_in_maxheap + 12);
			Assert::AreEqual((int)0xFDFDFDFD, data);
		}

	};
}
