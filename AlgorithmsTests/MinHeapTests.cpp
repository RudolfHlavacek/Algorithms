#include "pch.h"
#include "CppUnitTest.h"

#include "..\Algorithms\src\MinHeap.h"
#include "MinMaxHeap_Test_Utills.h"

#include <vector>
#include <random>


#define HEAP_ALLOCATED_MARK 0xCDCDCDCD
#define HEAP_END_MARK 0xFDFDFDFD
#define HEAP_DEALLOCATED_MARK 0xDDDDDDDD


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace rh;

namespace AlgorithmsTests
{
	TEST_CLASS(MinHeapTests)
	{
	public:

		TEST_METHOD(_Ctor)
		{
			const int max_capacity = 3;
			MinHeap<unsigned int> minheap(max_capacity);
			auto ptr_to_reint = reinterpret_cast<rhTest::MinMaxHeap_for_reint<unsigned int>*>(&minheap);

			ptr_to_reint;
			Assert::AreEqual(0, ptr_to_reint->m_size);
			Assert::AreEqual(3, ptr_to_reint->m_capacity);
			
			unsigned int* ptr_to_data = ptr_to_reint->m_heap;
			Assert::AreEqual(HEAP_ALLOCATED_MARK, *(ptr_to_data + 0));
			Assert::AreEqual(HEAP_ALLOCATED_MARK, *(ptr_to_data + 1));
			Assert::AreEqual(HEAP_ALLOCATED_MARK, *(ptr_to_data + 2));
			Assert::AreEqual(HEAP_END_MARK, *(ptr_to_data + 3));
		}

		TEST_METHOD(_Ctor_negative_number)
		{
			MinHeap<unsigned int> minheap(-1);
			auto ptr_to_reint = reinterpret_cast<rhTest::MinMaxHeap_for_reint<unsigned int>*>(&minheap);
			unsigned int* ptr_to_data = ptr_to_reint->m_heap;

			Assert::AreEqual(0, ptr_to_reint->m_size);
			Assert::AreEqual(1, ptr_to_reint->m_capacity);
			Assert::AreEqual(HEAP_ALLOCATED_MARK, *(ptr_to_data + 0));
			Assert::AreEqual(HEAP_END_MARK, *(ptr_to_data + 1));
		}

		TEST_METHOD(_Ctor_without_params)
		{
			MinHeap<unsigned int> minheap;
			auto ptr_to_reint = reinterpret_cast<rhTest::MinMaxHeap_for_reint<unsigned int>*>(&minheap);
			unsigned int* ptr_to_data = ptr_to_reint->m_heap;

			Assert::AreEqual(0, ptr_to_reint->m_size);
			Assert::AreEqual(1, ptr_to_reint->m_capacity);
			Assert::AreEqual(HEAP_ALLOCATED_MARK, *(ptr_to_data + 0));
			Assert::AreEqual(HEAP_END_MARK, *(ptr_to_data + 1));
		}

		TEST_METHOD(_Ctor_zero_number)
		{
			MinHeap<unsigned int> minheap(0);
			auto ptr_to_reint = reinterpret_cast<rhTest::MinMaxHeap_for_reint<unsigned int>*>(&minheap);
			unsigned int* ptr_to_data = ptr_to_reint->m_heap;

			Assert::AreEqual(0, ptr_to_reint->m_size);
			Assert::AreEqual(1, ptr_to_reint->m_capacity);
			Assert::AreEqual(HEAP_ALLOCATED_MARK, *(ptr_to_data + 0));
			Assert::AreEqual(HEAP_END_MARK, *(ptr_to_data + 1));
		}

		TEST_METHOD(_Destructor)
		{
			unsigned int* ptr_to_data = nullptr;
			{
				MinHeap<unsigned int> minheap(5);
				auto ptr_reint = reinterpret_cast<rhTest::MinMaxHeap_for_reint<unsigned int>*>(&minheap);
				minheap.insert(9);
				minheap.insert(10);
				minheap.insert(11);
				ptr_to_data = ptr_reint->m_heap;
			}

			for (int i = 0; i < 6; i++)
				Assert::AreEqual(HEAP_DEALLOCATED_MARK, ptr_to_data[i]);
		}

//		//// TODO getMIN bez insertovaneho prvku. removeRoot a extract min to same
		TEST_METHOD(insert)
		{
			const std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1, 1, 0, 2, 3 };
			const std::vector<int> arranged_vec = { -3, -2, 0, -1, -1, 2, 3, 100, 50, 99, 1, 101, 25, 75 };
			MinHeap<int> minheap(14);
			auto ptr_reint = reinterpret_cast<rhTest::MinMaxHeap_for_reint<int>*>(&minheap);

			for (int num : test_vec)
				minheap.insert(num);

			int* ptr_to_data = ptr_reint->m_heap;
			for (int i = 0; i < arranged_vec.size(); i++)
				Assert::AreEqual(arranged_vec[i], ptr_to_data[i]);
		}

		TEST_METHOD(peek)
		{
			const std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1, 1, 0, 2, 3 };
			const std::vector<int> arranged_vec = { -3, -2, 0, -1, -1, 2, 3, 100, 50, 99, 1, 101, 25, 75 };
			MinHeap<int> minheap(15);
			auto ptr_reint = reinterpret_cast<rhTest::MinMaxHeap_for_reint<int>*>(&minheap);

			for (int num : test_vec)
				minheap.insert(num);

			Assert::AreEqual(14, ptr_reint->m_size);
			Assert::AreEqual(15, ptr_reint->m_capacity);

			for (int i = 0; i < 10; i++)
			{
				Assert::AreEqual(-3, minheap.peek());
				int* ptr_to_heap = ptr_reint->m_heap;
				for (int k = 0; k < arranged_vec.size(); k++)
				{
					int data = *(ptr_to_heap + k);
					Assert::AreEqual(arranged_vec[k], data);
				}
			}
		}

//		TEST_METHOD(removeRoot)
//		{
//			const std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1, 1, 0, 2, 3 };
//			const std::vector<std::vector<int>> arranged_vectors = { {-2, -1, 0, 50, -1, 2, 3, 100, 75, 99, 1, 101, 25},
//																	 {-1, -1, 0, 50, 1, 2, 3, 100, 75, 99, 25, 101},
//																	 {-1, 1, 0, 50, 25, 2, 3, 100, 75, 99, 101},
//																	 {0, 1, 2, 50, 25, 101, 3, 100, 75, 99},
//																	 {1, 25, 2, 50, 99, 101, 3, 100, 75},
//																	 {2, 25, 3, 50, 99, 101, 75, 100},
//																	 {3, 25, 75, 50, 99, 101, 100},
//																	 {25, 50, 75, 100, 99, 101},
//																	 {50, 99, 75, 100, 101},
//																	 {75, 99, 101, 100},
//																	 {99, 100, 101},
//																	 {100, 101},
//																	 {101} };
//			rh::MinHeap<int> minheap(15);
//
//			for (int num : test_vec)
//				minheap.insert(num);
//
//			const int* const ptr_to_heap = rhTest::get_ptr_to_heap(minheap);
//			for (std::vector<int> vec : arranged_vectors)
//			{
//				minheap.removeRoot();
//				Assert::AreEqual((int)vec.size(), rhTest::get_m_size(minheap));
//				Assert::AreEqual(15, rhTest::get_m_capacity(minheap));
//				for (int i = 0; i < vec.size(); i++)
//				{
//					int data = *(ptr_to_heap + i);
//					Assert::AreEqual(vec[i], data);
//				}
//			}
//		}
//
//		TEST_METHOD(removeRoot_empty_heap)
//		{
//			rh::MinHeap<int> minheap(5);
//			for (int i = 0; i < 5; i++)
//				minheap.removeRoot();
//
//			Assert::AreEqual(0, rhTest::get_m_size(minheap));
//		}
//
//		TEST_METHOD(extractRoot)
//		{
//			const std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1, 1, 0, 2, 3 };
//			const std::vector<int> res_vec = { -3, -2, -1, -1, 0, 1, 2, 3, 25, 50, 75, 99, 100, 101 };
//			const std::vector<std::vector<int>> arranged_vectors = { {-2, -1, 0, 50, -1, 2, 3, 100, 75, 99, 1, 101, 25},
//																	 {-1, -1, 0, 50, 1, 2, 3, 100, 75, 99, 25, 101},
//																	 {-1, 1, 0, 50, 25, 2, 3, 100, 75, 99, 101},
//																	 {0, 1, 2, 50, 25, 101, 3, 100, 75, 99},
//																	 {1, 25, 2, 50, 99, 101, 3, 100, 75},
//																	 {2, 25, 3, 50, 99, 101, 75, 100},
//																	 {3, 25, 75, 50, 99, 101, 100},
//																	 {25, 50, 75, 100, 99, 101},
//																	 {50, 99, 75, 100, 101},
//																	 {75, 99, 101, 100},
//																	 {99, 100, 101},
//																	 {100, 101},
//																	 {101} };
//			rh::MinHeap<int> minheap(15);
//
//			for (int num : test_vec)
//				minheap.insert(num);
//
//			const int* const ptr_to_heap = rhTest::get_ptr_to_heap(minheap);
//			int i = 0;
//			for (std::vector<int> vec : arranged_vectors)
//			{
//				Assert::AreEqual(res_vec[i++], minheap.extractRoot());
//				Assert::AreEqual((int)vec.size(), rhTest::get_m_size(minheap));
//				Assert::AreEqual(15, rhTest::get_m_capacity(minheap));
//				for (int i = 0; i < vec.size(); i++)
//				{
//					int data = *(ptr_to_heap + i);
//					Assert::AreEqual(vec[i], data);
//				}
//			}
//		}
//
//		TEST_METHOD(no_reallocation)
//		{
//			rh::MinHeap<int> minheap(10);
//			const int* const ptr_to_heap_after_instantiation = rhTest::get_ptr_to_heap(minheap);
//
//			minheap.insert(42);
//			minheap.insert(21);
//			const int* ptr_to_heap = rhTest::get_ptr_to_heap(minheap);
//			Assert::AreEqual(ptr_to_heap_after_instantiation, ptr_to_heap);
//
//			minheap.peek();
//			ptr_to_heap = rhTest::get_ptr_to_heap(minheap);
//			Assert::AreEqual(ptr_to_heap_after_instantiation, ptr_to_heap);
//
//			minheap.removeRoot();
//			ptr_to_heap = rhTest::get_ptr_to_heap(minheap);
//			Assert::AreEqual(ptr_to_heap_after_instantiation, ptr_to_heap);
//
//			minheap.extractRoot();
//			ptr_to_heap = rhTest::get_ptr_to_heap(minheap);
//			Assert::AreEqual(ptr_to_heap_after_instantiation, ptr_to_heap);
//
//			minheap.size();
//			ptr_to_heap = rhTest::get_ptr_to_heap(minheap);
//			Assert::AreEqual(ptr_to_heap_after_instantiation, ptr_to_heap);
//
//			minheap.clear();
//			ptr_to_heap = rhTest::get_ptr_to_heap(minheap);
//			Assert::AreEqual(ptr_to_heap_after_instantiation, ptr_to_heap);
//		}
//
//		TEST_METHOD(extractRoot_1000_runs)
//		{
//			const int max_runs = 1000;
//
//			rh::MinHeap<int> minheap(14);
//			std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1, 1, 0, 2, 3 };
//			const std::vector<int> res_vec = { -3, -2, -1, -1, 0, 1, 2, 3, 25, 50, 75, 99, 100, 101 };
//			auto randgen = std::default_random_engine{};
//			randgen.seed(time(NULL));
//
//
//			for (int i = 0; i < max_runs; i++)
//			{
//				std::shuffle(test_vec.begin(), test_vec.end(), randgen);
//				for (int num : test_vec)
//					minheap.insert(num);
//
//				for (int res : res_vec)
//					Assert::AreEqual(res, minheap.extractRoot());
//
//				Assert::AreEqual(0, minheap.size());
//			}
//		}
//
//		TEST_METHOD(size)
//		{
//			const int max_capacity = 10;
//			rh::MinHeap<int> minheap(max_capacity);
//
//			for (int i = 0; i < max_capacity; i++)
//			{
//				minheap.insert(42);
//				Assert::AreEqual(i + 1, minheap.size());
//			}
//		}
//		// resize(int new_size) OK
//		// resize()             OK
//		// clear()              OK
//		// copy()
//		// operator=()
//		// check if heap is deallocate
//
//		TEST_METHOD(resize_no_action)
//		{
//			// case 1: new_capacity is 0
//			// case 2: new_capacity is negative number
//			// case 3: new_capacity is lesser than number of elements
//			// case 4: new_capacity is equal to current capacity
//			rh::MinHeap<int> minheap(5);
//			minheap.insert(10);
//			minheap.insert(11);
//			const int* const ptr_to_init_heap = rhTest::get_ptr_to_heap(minheap);
//
//			// case 1:
//			Assert::IsFalse(minheap.resize(0));
//			
//			Assert::AreEqual(ptr_to_init_heap, (const int* const)rhTest::get_ptr_to_heap(minheap));
//			Assert::AreEqual(2, rhTest::get_m_size(minheap));
//			Assert::AreEqual(5, rhTest::get_m_capacity(minheap));
//
//			// case 2:
//			Assert::IsFalse(minheap.resize(-1));
//
//			Assert::AreEqual(ptr_to_init_heap, (const int* const)rhTest::get_ptr_to_heap(minheap));
//			Assert::AreEqual(2, rhTest::get_m_size(minheap));
//			Assert::AreEqual(5, rhTest::get_m_capacity(minheap));
//
//			// case 3:
//			Assert::IsFalse(minheap.resize(1));
//
//			Assert::AreEqual(ptr_to_init_heap, (const int* const)rhTest::get_ptr_to_heap(minheap));
//			Assert::AreEqual(2, rhTest::get_m_size(minheap));
//			Assert::AreEqual(5, rhTest::get_m_capacity(minheap));
//
//			// case 4:
//			Assert::IsFalse(minheap.resize(5));
//
//			Assert::AreEqual(ptr_to_init_heap, (const int* const)rhTest::get_ptr_to_heap(minheap));
//			Assert::AreEqual(2, rhTest::get_m_size(minheap));
//			Assert::AreEqual(5, rhTest::get_m_capacity(minheap));
//		}
//
//		TEST_METHOD(resize)
//		{
//			// case 1: new_capacity is different than old capacity AND new_capacity is equal to number of elements
//			// case 2: new_capacity is different than old capacity AND new_capacity is greater than number of element
//			// case 3: new_capacity is greater than old capacity
//			
//			// case 1:
//			{
//				rh::MinHeap<int> minheap(5);
//				minheap.insert(10);
//				minheap.insert(11);
//				const int* const ptr_to_init_heap_alloc = rhTest::get_ptr_to_heap(minheap);
//
//
//				Assert::IsTrue(minheap.resize(2));
//
//
//				Assert::AreNotEqual(ptr_to_init_heap_alloc, (const int* const)rhTest::get_ptr_to_heap(minheap));
//
//				Assert::AreEqual(2, rhTest::get_m_size(minheap));
//				Assert::AreEqual(2, rhTest::get_m_capacity(minheap));
//
//				Assert::AreEqual(10, *(rhTest::get_ptr_to_heap(minheap) + 0));
//				Assert::AreEqual(11, *(rhTest::get_ptr_to_heap(minheap) + 1));
//				for (int i = 0; i < 6; i++) // Check for deallocation of old heap.
//				{
//					int data = *(ptr_to_init_heap_alloc + i);
//					Assert::AreEqual((int)0xDDDDDDDD, data);
//				}
//			}
//
//			// case 2:
//			{
//				rh::MinHeap<int> minheap(5);
//				minheap.insert(10);
//				minheap.insert(11);
//				const int* const ptr_to_init_heap_alloc = rhTest::get_ptr_to_heap(minheap);
//
//
//				Assert::IsTrue(minheap.resize(3));
//
//
//				Assert::AreNotEqual(ptr_to_init_heap_alloc, (const int* const)rhTest::get_ptr_to_heap(minheap));
//
//				Assert::AreEqual(2, rhTest::get_m_size(minheap));
//				Assert::AreEqual(3, rhTest::get_m_capacity(minheap));
//
//				Assert::AreEqual(10, *(rhTest::get_ptr_to_heap(minheap) + 0));
//				Assert::AreEqual(11, *(rhTest::get_ptr_to_heap(minheap) + 1));
//				for (int i = 0; i < 6; i++) // Check for deallocation of old heap.
//				{
//					int data = *(ptr_to_init_heap_alloc + i);
//					Assert::AreEqual((int)0xDDDDDDDD, data);
//				}
//			}
//
//			// case 3:
//			{
//				rh::MinHeap<int> minheap(5);
//				minheap.insert(10);
//				minheap.insert(11);
//				const int* const ptr_to_init_heap_alloc = rhTest::get_ptr_to_heap(minheap);
//
//
//				Assert::IsTrue(minheap.resize(7));
//
//
//				Assert::AreNotEqual(ptr_to_init_heap_alloc, (const int* const)rhTest::get_ptr_to_heap(minheap));
//
//				Assert::AreEqual(2, rhTest::get_m_size(minheap));
//				Assert::AreEqual(7, rhTest::get_m_capacity(minheap));
//
//				Assert::AreEqual(10, *(rhTest::get_ptr_to_heap(minheap) + 0));
//				Assert::AreEqual(11, *(rhTest::get_ptr_to_heap(minheap) + 1));
//				for (int i = 0; i < 6; i++) // Check for deallocation of old heap.
//				{
//					int data = *(ptr_to_init_heap_alloc + i);
//					Assert::AreEqual((int)0xDDDDDDDD, data);
//				}
//			}
//		}
//
//		TEST_METHOD(resize_without_params)
//		{
//			// case 1: m_size < m_capacity    resize
//			// case 2: m_size == m_capacity   NO resize
//			// case 3: m_size == 0;           resize to capacity of 1
//			// case 4: m_size < 0;            Shall not happend.
//
//			// case 1:
//			{
//				rh::MinHeap<int> minheap(5);
//				minheap.insert(9);
//				minheap.insert(10);
//				const int* const ptr_to_init_heap_alloc = rhTest::get_ptr_to_heap(minheap);
//
//
//				Assert::IsTrue(minheap.resize());
//
//
//				Assert::AreNotEqual(ptr_to_init_heap_alloc, (const int* const)rhTest::get_ptr_to_heap(minheap));
//
//				Assert::AreEqual(2, rhTest::get_m_size(minheap));
//				Assert::AreEqual(2, rhTest::get_m_capacity(minheap));
//
//				Assert::AreEqual(9, *(rhTest::get_ptr_to_heap(minheap) + 0));
//				Assert::AreEqual(10, *(rhTest::get_ptr_to_heap(minheap) + 1));
//				for (int i = 0; i < 6; i++) // Check for deallocation of old heap.
//				{
//					int data = *(ptr_to_init_heap_alloc + i);
//					Assert::AreEqual((int)0xDDDDDDDD, data);
//				}
//			}
//
//			// case 2:
//			{
//				rh::MinHeap<int> minheap(3);
//				minheap.insert(9);
//				minheap.insert(10);
//				minheap.insert(11);
//				const int* const ptr_to_init_heap_alloc = rhTest::get_ptr_to_heap(minheap);
//
//
//				Assert::IsFalse(minheap.resize());
//
//
//				Assert::AreEqual(ptr_to_init_heap_alloc, (const int* const)rhTest::get_ptr_to_heap(minheap));
//
//				Assert::AreEqual(3, rhTest::get_m_size(minheap));
//				Assert::AreEqual(3, rhTest::get_m_capacity(minheap));
//
//				Assert::AreEqual(9, *(rhTest::get_ptr_to_heap(minheap) + 0));
//				Assert::AreEqual(10, *(rhTest::get_ptr_to_heap(minheap) + 1));
//				Assert::AreEqual(11, *(rhTest::get_ptr_to_heap(minheap) + 2));
//			}
//
//			// case 3:
//			{
//				rh::MinHeap<int> minheap(5);
//				const int* const ptr_to_init_heap_alloc = rhTest::get_ptr_to_heap(minheap);
//
//
//				Assert::IsTrue(minheap.resize());
//
//
//				Assert::AreNotEqual(ptr_to_init_heap_alloc, (const int* const)rhTest::get_ptr_to_heap(minheap));
//
//				Assert::AreEqual(0, rhTest::get_m_size(minheap));
//				Assert::AreEqual(1, rhTest::get_m_capacity(minheap));
//
//				for (int i = 0; i < 6; i++) // Check for deallocation of old heap.
//				{
//					int data = *(ptr_to_init_heap_alloc + i);
//					Assert::AreEqual((int)0xDDDDDDDD, data);
//				}
//			}
//		}
//
//		TEST_METHOD(clear)
//		{
//			rh::MinHeap<int> minheap(3);
//			const int* const ptr_to_init_heap_alloc = rhTest::get_ptr_to_heap(minheap);
//
//			minheap.insert(42);
//			minheap.insert(21);
//			minheap.insert(12);
//
//			minheap.clear();
//
//			Assert::AreEqual(0, rhTest::get_m_size(minheap));
//			Assert::AreEqual(3, rhTest::get_m_capacity(minheap));
//			Assert::AreEqual(ptr_to_init_heap_alloc, (const int* const)rhTest::get_ptr_to_heap(minheap));
//		}
//
//		TEST_METHOD(_CopyCtor)
//		{
//			rh::MinHeap<int> mh_ori(15);
//			const std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1, 1, 0, 2, 3 };
//			const std::vector<int> arranged_vec = {-3, -2, 0, -1, -1, 2, 3, 100, 50, 99, 1, 101, 25, 75 };
//			for (int num : test_vec)
//				mh_ori.insert(num);
//
//
//			rh::MinHeap<int> minheap(mh_ori);
//			mh_ori.clear();
//			for (int i = 0; i < 20; i++)
//				mh_ori.insert(42);
//			Assert::AreEqual(42, mh_ori.peek());
//
//
//			Assert::AreEqual(14, rhTest::get_m_size(minheap));
//			Assert::AreEqual(15, rhTest::get_m_capacity(minheap));
//			const int* const ptr_to_heap_in_minheap = rhTest::get_ptr_to_heap(minheap);
//			int data;
//			for (int i = 0; i < arranged_vec.size(); i++)
//			{
//				data = *(ptr_to_heap_in_minheap + i);
//				Assert::AreEqual(arranged_vec[i], data);
//			}
//			data = *(ptr_to_heap_in_minheap + 14);
//			Assert::AreEqual((int)0xCDCDCDCD, data);
//			data = *(ptr_to_heap_in_minheap + 15);
//			Assert::AreEqual((int)0xFDFDFDFD, data);
//		}
//
//		TEST_METHOD(copy_without_resizing)
//		{
//			rh::MinHeap<int> mh_ori(15);
//			rh::MinHeap<int> minheap(10);
//			const int* const ptr_to_heap_in_minheap = rhTest::get_ptr_to_heap(minheap);
//			const std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1 };
//			const std::vector<int> arranged_vec = { -3, -2, 25, -1, -1, 101, 75, 100, 50, 99 };
//			for (int num : test_vec)
//				mh_ori.insert(num);
//
//
//			minheap.copy(mh_ori);
//			mh_ori.clear();
//			for (int i = 0; i < 20; i++)
//				mh_ori.insert(42);
//			Assert::AreEqual(42, mh_ori.peek());
//
//
//			Assert::AreEqual(10, rhTest::get_m_size(minheap));
//			Assert::AreEqual(10, rhTest::get_m_capacity(minheap));
//			Assert::AreEqual(ptr_to_heap_in_minheap, (const int* const)rhTest::get_ptr_to_heap(minheap));
//			int data;
//			for (int i = 0; i < arranged_vec.size(); i++)
//			{
//				data = *(ptr_to_heap_in_minheap + i);
//				Assert::AreEqual(arranged_vec[i], data);
//			}
//			data = *(ptr_to_heap_in_minheap + 10);
//			Assert::AreEqual((int)0xFDFDFDFD, data);
//		}
//
//		TEST_METHOD(copy_with_resizing)
//		{
//			rh::MinHeap<int> mh_ori(15);
//			rh::MinHeap<int> minheap(10);
//			const int* ptr_to_heap_in_minheap = rhTest::get_ptr_to_heap(minheap);
//			const std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1, 3 };
//			const std::vector<int> arranged_vec = { -3, -2, 25, -1, -1, 101, 75, 100, 50, 99, 3 };
//			for (int num : test_vec)
//				mh_ori.insert(num);
//
//
//			minheap.copy(mh_ori);
//			mh_ori.clear();
//			for (int i = 0; i < 20; i++)
//				mh_ori.insert(42);
//			Assert::AreEqual(42, mh_ori.peek());
//
//
//			Assert::AreEqual(11, rhTest::get_m_size(minheap));
//			Assert::AreEqual(11, rhTest::get_m_capacity(minheap));
//			Assert::AreNotEqual(ptr_to_heap_in_minheap, (const int* const)rhTest::get_ptr_to_heap(minheap));
//			int data;
//			ptr_to_heap_in_minheap = rhTest::get_ptr_to_heap(minheap);
//			for (int i = 0; i < arranged_vec.size(); i++)
//			{
//				data = *(ptr_to_heap_in_minheap + i);
//				Assert::AreEqual(arranged_vec[i], data);
//			}
//			data = *(ptr_to_heap_in_minheap + 11);
//			Assert::AreEqual((int)0xFDFDFDFD, data);
//		}
//
//		TEST_METHOD(operatorEqual_without_resizing)
//		{
//			rh::MinHeap<int> mh_ori(15);
//			rh::MinHeap<int> minheap(10);
//			const int* const ptr_to_heap_in_minheap = rhTest::get_ptr_to_heap(minheap);
//			const std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1 };
//			const std::vector<int> arranged_vec = { -3, -2, 25, -1, -1, 101, 75, 100, 50, 99 };
//			for (int num : test_vec)
//				mh_ori.insert(num);
//
//
//			minheap = mh_ori;
//			mh_ori.clear();
//			for (int i = 0; i < 20; i++)
//				mh_ori.insert(42);
//			Assert::AreEqual(42, mh_ori.peek());
//
//
//			Assert::AreEqual(10, rhTest::get_m_size(minheap));
//			Assert::AreEqual(10, rhTest::get_m_capacity(minheap));
//			Assert::AreEqual(ptr_to_heap_in_minheap, (const int* const)rhTest::get_ptr_to_heap(minheap));
//			int data;
//			for (int i = 0; i < arranged_vec.size(); i++)
//			{
//				data = *(ptr_to_heap_in_minheap + i);
//				Assert::AreEqual(arranged_vec[i], data);
//			}
//			data = *(ptr_to_heap_in_minheap + 10);
//			Assert::AreEqual((int)0xFDFDFDFD, data);
//		}
//
//		TEST_METHOD(operatorEqual_with_resizing)
//		{
//			rh::MinHeap<int> mh_ori(15);
//			rh::MinHeap<int> minheap(10);
//			const int* ptr_to_heap_in_minheap = rhTest::get_ptr_to_heap(minheap);
//			const std::vector<int> test_vec = { 50, 25, 75, 100, 99, 101, -1, -2, -3, -1, 3 };
//			const std::vector<int> arranged_vec = { -3, -2, 25, -1, -1, 101, 75, 100, 50, 99, 3 };
//			for (int num : test_vec)
//				mh_ori.insert(num);
//
//
//			minheap = mh_ori;
//			mh_ori.clear();
//			for (int i = 0; i < 20; i++)
//				mh_ori.insert(42);
//			Assert::AreEqual(42, mh_ori.peek());
//
//
//			Assert::AreEqual(11, rhTest::get_m_size(minheap));
//			Assert::AreEqual(11, rhTest::get_m_capacity(minheap));
//			Assert::AreNotEqual(ptr_to_heap_in_minheap, (const int* const)rhTest::get_ptr_to_heap(minheap));
//			int data;
//			ptr_to_heap_in_minheap = rhTest::get_ptr_to_heap(minheap);
//			for (int i = 0; i < arranged_vec.size(); i++)
//			{
//				data = *(ptr_to_heap_in_minheap + i);
//				Assert::AreEqual(arranged_vec[i], data);
//			}
//			data = *(ptr_to_heap_in_minheap + 11);
//			Assert::AreEqual((int)0xFDFDFDFD, data);
//		}
//
	};
}
