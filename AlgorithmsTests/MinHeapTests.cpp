#include "pch.h"
#include "CppUnitTest.h"

#include "..\Algorithms\src\MinHeap.h"

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

	};
}
