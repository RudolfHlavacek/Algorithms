#include "pch.h"
#include "CppUnitTest.h"

#include "..\Algorithms\src\Stack.h"

//#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AlgorithmsTests
{
	TEST_CLASS(StackTests)
	{
	public:
		
		TEST_METHOD(DefaultCtor)
		{
			Stack<int> st = Stack<int>();

			Assert::AreEqual(0, st.size());
			Assert::AreEqual(true, st.isEmpty());
			Assert::AreEqual(false, st.isFull());
			Assert::AreNotEqual(0, st.getCapacity());
		}

		TEST_METHOD(ParamCtor)
		{
			Stack<int> st = Stack<int>(42);

			Assert::AreEqual(0, st.size());
			Assert::AreEqual(true, st.isEmpty());
			Assert::AreEqual(false, st.isFull());
			Assert::AreEqual(42, st.getCapacity());
		}

		TEST_METHOD(ParamCtor_2)
		{
			Stack<int> st(69);

			Assert::AreEqual(0, st.size());
			Assert::AreEqual(true, st.isEmpty());
			Assert::AreEqual(false, st.isFull());
			Assert::AreEqual(69, st.getCapacity());
		}

		TEST_METHOD(Stack_push)
		{
			Stack<int> st(3);

			Assert::AreEqual(0, st.size());
			
			st.push(1);
			Assert::AreEqual(1, st.size());

			st.push(2);
			Assert::AreEqual(2, st.size());

			st.push(3);
			Assert::AreEqual(3, st.size());
		}

		TEST_METHOD(Stack_pop)
		{
			Stack<int> st(3);

			Assert::AreEqual(0, st.size());

			st.push(1);
			st.push(2);
			st.push(3);
			
			Assert::AreEqual(3, st.size());
			Assert::AreEqual(3, st.pop());

			st.pop();
			Assert::AreEqual(1, st.size());
		}

		TEST_METHOD(Stack_peek)
		{
			Stack<int> st(3);

			st.push(1);
			st.push(2);
			st.push(2);

			Assert::AreEqual(2, st.peek());
			Assert::AreEqual(2, st.peek());

			st.peek();
			Assert::AreEqual(3, st.size());
		}

		TEST_METHOD(Stack_size)
		{
			Stack<int> st(10);

			Assert::AreEqual(0, st.size());

			st.push(1);
			Assert::AreEqual(1, st.size());

			st.push(1);
			Assert::AreEqual(2, st.size());

			st.pop();
			Assert::AreEqual(1, st.size());
		}

		TEST_METHOD(Stack_isEmpty)
		{
			Stack<int> st(5);

			Assert::AreEqual(true, st.isEmpty());

			st.push(42);
			Assert::AreEqual(false, st.isEmpty());

			st.push(42);
			Assert::AreEqual(false, st.isEmpty());

			st.pop();
			Assert::AreEqual(false, st.isEmpty());

			st.pop();
			Assert::AreEqual(true, st.isEmpty());
		}

		TEST_METHOD(Stack_isFull)
		{
			Stack<int> st(2);

			Assert::AreEqual(false, st.isFull());

			st.push(42);
			Assert::AreEqual(false, st.isFull());

			st.push(42);
			Assert::AreEqual(true, st.isFull());

			st.pop();
			Assert::AreEqual(false, st.isFull());

			st.pop();
			Assert::AreEqual(false, st.isFull());
		}

		TEST_METHOD(Stack_getCapacity)
		{
			Stack<int> st(5);

			Assert::AreEqual(5, st.getCapacity());

			st.push(42);
			Assert::AreEqual(5, st.getCapacity());

			st.push(42);
			Assert::AreEqual(5, st.getCapacity());

			st.pop();
			Assert::AreEqual(5, st.getCapacity());

			st.pop();
			Assert::AreEqual(5, st.getCapacity());
		}

		TEST_METHOD(Stack_getCapacity_2)
		{
			Stack<int> st(42);

			Assert::AreEqual(42, st.getCapacity());

			st.push(42);
			Assert::AreEqual(42, st.getCapacity());

			st.push(42);
			Assert::AreEqual(42, st.getCapacity());

			st.peek();
			Assert::AreEqual(42, st.getCapacity());

			st.pop();
			Assert::AreEqual(42, st.getCapacity());

			st.pop();
			Assert::AreEqual(42, st.getCapacity());
		}

		TEST_METHOD(CopyCtor)
		{
			Stack<int> st_1(5);

			st_1.push(1);
			st_1.push(11);
			st_1.push(111);

			Stack<int> st_2(st_1);

			Assert::AreEqual(3, st_1.size());
			Assert::AreEqual(3, st_2.size());

			Assert::AreEqual(5, st_1.getCapacity());
			Assert::AreEqual(5, st_2.getCapacity());

			Assert::AreEqual(111, st_1.peek());
			Assert::AreEqual(111, st_2.peek());

			st_1.pop();
			Assert::AreEqual(11, st_1.peek());
			Assert::AreEqual(111, st_2.peek());
		}

		TEST_METHOD(Stack_copy_true)
		{
			Stack<int> st_1(5);
			Stack<int> st_2(3);

			st_1.push(1);
			st_1.push(11);
			st_1.push(111);

			Assert::AreEqual(true, st_2.copy(st_1));

			Assert::AreEqual(3, st_1.size());
			Assert::AreEqual(3, st_2.size());

			Assert::AreEqual(111, st_1.peek());
			Assert::AreEqual(111, st_2.peek());

			st_1.pop();
			Assert::AreEqual(11, st_1.peek());
			Assert::AreEqual(111, st_2.peek());
		}

		TEST_METHOD(Stack_copy_false)
		{
			Stack<int> st_1(5);
			Stack<int> st_2(2);

			st_1.push(1);
			st_1.push(11);
			st_1.push(111);

			Assert::AreEqual(false, st_2.copy(st_1));
			Assert::AreEqual(0, st_2.size());
			Assert::AreEqual(true, st_2.isEmpty());
		}

		TEST_METHOD(Stack_operatorEqual_true)
		{
			Stack<int> st_1(5);
			Stack<int> st_2(3);

			st_1.push(1);
			st_1.push(11);
			st_1.push(111);

			st_2 = st_1;

			Assert::AreEqual(5, st_1.getCapacity());
			Assert::AreEqual(3, st_2.getCapacity());

			Assert::AreEqual(3, st_1.size());
			Assert::AreEqual(3, st_2.size());

			Assert::AreEqual(111, st_1.peek());
			Assert::AreEqual(111, st_2.peek());

			st_1.pop();
			Assert::AreEqual(11, st_1.peek());
			Assert::AreEqual(111, st_2.peek());
		}

		TEST_METHOD(Stack_operatorEqual_false)
		{
			Stack<int> st_1(5);
			Stack<int> st_2(2);

			st_1.push(1);
			st_1.push(11);
			st_1.push(111);

			st_2 = st_1;

			Assert::AreEqual(3, st_1.size());
			Assert::AreEqual(111, st_1.peek());
			
			Assert::AreEqual(0, st_2.size());
			Assert::AreEqual(true, st_2.isEmpty());

		}

		TEST_METHOD(Stack_char)
		{
			Stack<char> st(3);

			st.push('A');
			st.push('B');
			st.push('C');

			Assert::AreEqual(false, st.isEmpty());
			Assert::AreEqual(true, st.isFull());
			Assert::AreEqual('C', st.peek());
			Assert::AreEqual('C', st.pop());
			Assert::AreEqual('B', st.pop());
			Assert::AreEqual('A', st.pop());
			Assert::AreEqual(true, st.isEmpty());
			Assert::AreEqual(false, st.isFull());
		}

		TEST_METHOD(Stack_string)
		{
			Stack<std::string> st(3);

			st.push("One");
			st.push("Two");
			st.push("Three");

			Assert::AreEqual(false, st.isEmpty());
			Assert::AreEqual(true, st.isFull());
			Assert::AreEqual<std::string>("Three", st.peek());
			Assert::AreEqual<std::string>("Three", st.pop());
			Assert::AreEqual<std::string>("Two", st.pop());
			Assert::AreEqual<std::string>("One", st.pop());
			Assert::AreEqual(true, st.isEmpty());
			Assert::AreEqual(false, st.isFull());

		}

		TEST_METHOD(Stack_string_copy)
		{
			Stack<std::string> st(3);

			st.push("One");
			st.push("Two");
			st.push("Three");

			Stack<std::string> st_copy = st;
			st.pop();

			Assert::AreEqual<std::string>("Two", st.peek());
			Assert::AreEqual<std::string>("Three", st_copy.peek());
		}

	};
}
