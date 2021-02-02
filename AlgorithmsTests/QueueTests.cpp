#include "pch.h"
#include "CppUnitTest.h"

#include "..\Algorithms\src\Queue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AlgorithmsTests
{
	TEST_CLASS(QueueTests)
	{
	public:

		TEST_METHOD(DefaultCtor)
		{
			Queue<int> q = Queue<int>();

			Assert::AreEqual(0, q.size());
			Assert::AreEqual(true, q.isEmpty());
			Assert::AreEqual(false, q.isFull());
			Assert::AreNotEqual(0, q.getCapacity());
		}

		TEST_METHOD(ParamCtor)
		{
			Queue<int> q = Queue<int>(42);

			Assert::AreEqual(0, q.size());
			Assert::AreEqual(true, q.isEmpty());
			Assert::AreEqual(false, q.isFull());
			Assert::AreEqual(42, q.getCapacity());
		}

		TEST_METHOD(Queue_enqueue)
		{
			Queue<int> q(3);

			Assert::AreEqual(0, q.size());

			q.enqueue(1);
			Assert::AreEqual(1, q.size());

			q.enqueue(2);
			Assert::AreEqual(2, q.size());

			q.enqueue(3);
			Assert::AreEqual(3, q.size());
		}

		TEST_METHOD(Queue_dequeue)
		{
			Queue<int> q(3);

			Assert::AreEqual(0, q.size());

			q.enqueue(1);
			q.enqueue(2);
			q.enqueue(3);

			Assert::AreEqual(3, q.size());
			
			q.dequeue();
			Assert::AreEqual(2, q.size());
		}

		TEST_METHOD(Queue_peek)
		{
			Queue<int> q(3);

			q.enqueue(1);
			q.enqueue(2);
			q.enqueue(2);

			Assert::AreEqual(1, q.peek());
			Assert::AreEqual(1, q.peek());

			q.peek();
			Assert::AreEqual(3, q.size());
		}

		TEST_METHOD(Queue_size)
		{
			Queue<int> q(10);

			Assert::AreEqual(0, q.size());
			Assert::AreEqual(10, q.getCapacity());

			q.enqueue(1);
			Assert::AreEqual(1, q.size());

			q.enqueue(1);
			Assert::AreEqual(2, q.size());

			q.dequeue();
			Assert::AreEqual(1, q.size());
		}

		TEST_METHOD(Queue_isEmpty)
		{
			Queue<int> q(5);

			Assert::AreEqual(true, q.isEmpty());

			q.enqueue(42);
			Assert::AreEqual(false, q.isEmpty());

			q.enqueue(42);
			Assert::AreEqual(false, q.isEmpty());

			q.dequeue();
			Assert::AreEqual(false, q.isEmpty());

			q.dequeue();
			Assert::AreEqual(true, q.isEmpty());
		}

		TEST_METHOD(Queue_isFull)
		{
			Queue<int> q(2);

			Assert::AreEqual(false, q.isFull());

			q.enqueue(42);
			Assert::AreEqual(false, q.isFull());

			q.enqueue(42);
			Assert::AreEqual(true, q.isFull());

			q.peek();
			Assert::AreEqual(true, q.isFull());

			q.dequeue();
			Assert::AreEqual(false, q.isFull());

			q.dequeue();
			Assert::AreEqual(false, q.isFull());
		}

		TEST_METHOD(Queue_getCapacity)
		{
			Queue<int> q(5);

			Assert::AreEqual(5, q.getCapacity());

			q.enqueue(42);
			Assert::AreEqual(5, q.getCapacity());

			q.enqueue(42);
			Assert::AreEqual(5, q.getCapacity());

			q.peek();
			Assert::AreEqual(5, q.getCapacity());

			q.dequeue();
			Assert::AreEqual(5, q.getCapacity());

			q.dequeue();
			Assert::AreEqual(5, q.getCapacity());
		}

		TEST_METHOD(CopyCtor)
		{
			Queue<int> q_1(5);

			q_1.enqueue(1);
			q_1.enqueue(11);
			q_1.enqueue(111);

			Queue<int> q_copy(q_1);

			Assert::AreEqual(3, q_1.size());
			Assert::AreEqual(3, q_copy.size());

			Assert::AreEqual(5, q_1.getCapacity());
			Assert::AreEqual(5, q_copy.getCapacity());

			Assert::AreEqual(1, q_1.peek());
			Assert::AreEqual(1, q_copy.peek());

			q_1.dequeue();
			Assert::AreEqual(11, q_1.peek());
			Assert::AreEqual(1, q_copy.peek());
		}

		TEST_METHOD(Queue_copy_true)
		{
			Queue<int> q_1(5);
			Queue<int> q_copy(3);

			q_1.enqueue(1);
			q_1.enqueue(11);
			q_1.enqueue(111);

			Assert::AreEqual(true, q_copy.copy(q_1));

			Assert::AreEqual(3, q_1.size());
			Assert::AreEqual(3, q_copy.size());

			Assert::AreEqual(1, q_1.peek());
			Assert::AreEqual(1, q_copy.peek());

			q_1.dequeue();
			Assert::AreEqual(11, q_1.peek());
			Assert::AreEqual(1, q_copy.peek());
		}

		TEST_METHOD(Queue_copy_false)
		{
			Queue<int> q_1(5);
			Queue<int> q_copy(2);

			q_1.enqueue(1);
			q_1.enqueue(11);
			q_1.enqueue(111);

			Assert::AreEqual(false, q_copy.copy(q_1));
			Assert::AreEqual(0, q_copy.size());
			Assert::AreEqual(true, q_copy.isEmpty());
		}

		TEST_METHOD(Queue_operatorEqual_true)
		{
			Queue<int> q_1(5);
			Queue<int> q_copy(3);

			q_1.enqueue(1);
			q_1.enqueue(11);
			q_1.enqueue(111);

			q_copy = q_1;

			Assert::AreEqual(5, q_1.getCapacity());
			Assert::AreEqual(3, q_copy.getCapacity());

			Assert::AreEqual(3, q_1.size());
			Assert::AreEqual(3, q_copy.size());

			Assert::AreEqual(1, q_1.peek());
			Assert::AreEqual(1, q_copy.peek());

			q_1.dequeue();
			Assert::AreEqual(11, q_1.peek());
			Assert::AreEqual(1, q_copy.peek());
		}

		TEST_METHOD(Queue_operatorEqual_false)
		{
			Queue<int> q_1(5);
			Queue<int> q_copy(2);

			q_1.enqueue(1);
			q_1.enqueue(11);
			q_1.enqueue(111);

			q_copy = q_1;

			Assert::AreEqual(3, q_1.size());
			Assert::AreEqual(1, q_1.peek());

			Assert::AreEqual(0, q_copy.size());
			Assert::AreEqual(true, q_copy.isEmpty());

		}

		TEST_METHOD(Queue_char)
		{
			Queue<char> q(3);

			q.enqueue('A');
			q.enqueue('B');
			q.enqueue('C');

			Assert::AreEqual(false, q.isEmpty());
			Assert::AreEqual(true, q.isFull());
			Assert::AreEqual('A', q.peek());
			Assert::AreEqual('A', q.peek());

			q.dequeue();
			Assert::AreEqual('B', q.peek());
			Assert::AreEqual(false, q.isEmpty());
			Assert::AreEqual(false, q.isFull());

			q.dequeue();
			Assert::AreEqual('C', q.peek());
			Assert::AreEqual(false, q.isEmpty());
			Assert::AreEqual(false, q.isFull());

			q.dequeue();
			Assert::AreEqual(true, q.isEmpty());
			Assert::AreEqual(false, q.isFull());
		}

		TEST_METHOD(Queue_string)
		{
			Queue<std::string> q(3);

			q.enqueue("One");
			q.enqueue("Two");
			q.enqueue("Three");

			Assert::AreEqual(false, q.isEmpty());
			Assert::AreEqual(true, q.isFull());
			Assert::AreEqual<std::string>("One", q.peek());
			Assert::AreEqual<std::string>("One", q.peek());

			q.dequeue();
			Assert::AreEqual<std::string>("Two", q.peek());

			q.dequeue();
			Assert::AreEqual<std::string>("Three", q.peek());
		}

		TEST_METHOD(Queue_string_copy)
		{
			Queue<std::string> q(3);

			q.enqueue("One");
			q.enqueue("Two");
			q.enqueue("Three");

			Queue<std::string> q_copy = q;
			q.dequeue();

			Assert::AreEqual<std::string>("Two", q.peek());
			Assert::AreEqual<std::string>("One", q_copy.peek());
		}

	};
}
