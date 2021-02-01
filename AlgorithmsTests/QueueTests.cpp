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

		TEST_METHOD(Stack_isEmpty)
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

		TEST_METHOD(Stack_getCapacity)
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

		//TEST_METHOD(Stack_getCapacity_2)
		//{
		//	Stack<int> st(42);

		//	Assert::AreEqual(42, st.getCapacity());

		//	st.push(42);
		//	Assert::AreEqual(42, st.getCapacity());

		//	st.push(42);
		//	Assert::AreEqual(42, st.getCapacity());

		//	st.peek();
		//	Assert::AreEqual(42, st.getCapacity());

		//	st.pop();
		//	Assert::AreEqual(42, st.getCapacity());

		//	st.pop();
		//	Assert::AreEqual(42, st.getCapacity());
		//}

		//TEST_METHOD(CopyCtor)
		//{
		//	Stack<int> st_1(5);

		//	st_1.push(1);
		//	st_1.push(11);
		//	st_1.push(111);

		//	Stack<int> st_2(st_1);

		//	Assert::AreEqual(3, st_1.size());
		//	Assert::AreEqual(3, st_2.size());

		//	Assert::AreEqual(5, st_1.getCapacity());
		//	Assert::AreEqual(5, st_2.getCapacity());

		//	Assert::AreEqual(111, st_1.peek());
		//	Assert::AreEqual(111, st_2.peek());

		//	st_1.pop();
		//	Assert::AreEqual(11, st_1.peek());
		//	Assert::AreEqual(111, st_2.peek());
		//}

		//TEST_METHOD(Stack_copy_true)
		//{
		//	Stack<int> st_1(5);
		//	Stack<int> st_2(3);

		//	st_1.push(1);
		//	st_1.push(11);
		//	st_1.push(111);

		//	Assert::AreEqual(true, st_2.copy(st_1));

		//	Assert::AreEqual(3, st_1.size());
		//	Assert::AreEqual(3, st_2.size());

		//	Assert::AreEqual(111, st_1.peek());
		//	Assert::AreEqual(111, st_2.peek());

		//	st_1.pop();
		//	Assert::AreEqual(11, st_1.peek());
		//	Assert::AreEqual(111, st_2.peek());
		//}

		//TEST_METHOD(Stack_copy_false)
		//{
		//	Stack<int> st_1(5);
		//	Stack<int> st_2(2);

		//	st_1.push(1);
		//	st_1.push(11);
		//	st_1.push(111);

		//	Assert::AreEqual(false, st_2.copy(st_1));
		//	Assert::AreEqual(0, st_2.size());
		//	Assert::AreEqual(true, st_2.isEmpty());
		//}

		//TEST_METHOD(Stack_operatorEqual_true)
		//{
		//	Stack<int> st_1(5);
		//	Stack<int> st_2(3);

		//	st_1.push(1);
		//	st_1.push(11);
		//	st_1.push(111);

		//	st_2 = st_1;

		//	Assert::AreEqual(5, st_1.getCapacity());
		//	Assert::AreEqual(3, st_2.getCapacity());

		//	Assert::AreEqual(3, st_1.size());
		//	Assert::AreEqual(3, st_2.size());

		//	Assert::AreEqual(111, st_1.peek());
		//	Assert::AreEqual(111, st_2.peek());

		//	st_1.pop();
		//	Assert::AreEqual(11, st_1.peek());
		//	Assert::AreEqual(111, st_2.peek());
		//}

		//TEST_METHOD(Stack_operatorEqual_false)
		//{
		//	Stack<int> st_1(5);
		//	Stack<int> st_2(2);

		//	st_1.push(1);
		//	st_1.push(11);
		//	st_1.push(111);

		//	st_2 = st_1;

		//	Assert::AreEqual(3, st_1.size());
		//	Assert::AreEqual(111, st_1.peek());

		//	Assert::AreEqual(0, st_2.size());
		//	Assert::AreEqual(true, st_2.isEmpty());

		//}

		//TEST_METHOD(Stack_char)
		//{
		//	Stack<char> st(3);

		//	st.push('A');
		//	st.push('B');
		//	st.push('C');

		//	Assert::AreEqual(false, st.isEmpty());
		//	Assert::AreEqual(true, st.isFull());
		//	Assert::AreEqual('C', st.peek());
		//	Assert::AreEqual('C', st.pop());
		//	Assert::AreEqual('B', st.pop());
		//	Assert::AreEqual('A', st.pop());
		//	Assert::AreEqual(true, st.isEmpty());
		//	Assert::AreEqual(false, st.isFull());
		//}

		//TEST_METHOD(Stack_string)
		//{
		//	Stack<std::string> st(3);

		//	st.push("One");
		//	st.push("Two");
		//	st.push("Three");

		//	Assert::AreEqual(false, st.isEmpty());
		//	Assert::AreEqual(true, st.isFull());
		//	Assert::AreEqual<std::string>("Three", st.peek());
		//	Assert::AreEqual<std::string>("Three", st.pop());
		//	Assert::AreEqual<std::string>("Two", st.pop());
		//	Assert::AreEqual<std::string>("One", st.pop());
		//	Assert::AreEqual(true, st.isEmpty());
		//	Assert::AreEqual(false, st.isFull());

		//}

		//TEST_METHOD(Stack_string_copy)
		//{
		//	Stack<std::string> st(3);

		//	st.push("One");
		//	st.push("Two");
		//	st.push("Three");

		//	Stack<std::string> st_copy = st;
		//	st.pop();

		//	Assert::AreEqual<std::string>("Two", st.peek());
		//	Assert::AreEqual<std::string>("Three", st_copy.peek());
		//}

	};
}
