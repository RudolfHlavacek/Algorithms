#include "pch.h"
#include "CppUnitTest.h"

#include "..\Algorithms\src\LinkedList.h"
#include "LinkedList_Test_Utils.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace rh;

namespace AlgorithmsTests
{
	TEST_CLASS(LinkedListTests)
	{
	public:

		TEST_METHOD(_Ctor)
		{
			LinkedList linkedList;
			auto ptr_to_reinterpret_linkedList = reinterpret_cast<rhTest::LinkedList_for_reinterpret*>(&linkedList);

			Assert::IsNull(ptr_to_reinterpret_linkedList->m_head);
			Assert::IsNull(ptr_to_reinterpret_linkedList->m_tail);
		}

		TEST_METHOD(createNode)
		{
			LinkedList linkedList;
			auto ptr_to_reint_linkedList = reinterpret_cast<rhTest::LinkedList_for_reinterpret*>(&linkedList);


			linkedList.createNode(42);


			Assert::IsNotNull(ptr_to_reint_linkedList->m_head);
			Assert::IsNotNull(ptr_to_reint_linkedList->m_tail);

			Assert::IsTrue(ptr_to_reint_linkedList->m_head == ptr_to_reint_linkedList->m_tail);

			Assert::AreEqual(42, ptr_to_reint_linkedList->m_head->data);
			Assert::AreEqual(42, ptr_to_reint_linkedList->m_tail->data);

			Assert::IsNull(ptr_to_reint_linkedList->m_head->next);
			Assert::IsNull(ptr_to_reint_linkedList->m_tail->next);
		}

		TEST_METHOD(createNode__3_nodes)
		{
			LinkedList linkedList;
			auto ptr_to_reint = reinterpret_cast<rhTest::LinkedList_for_reinterpret*>(&linkedList);
			//Node* ptr_to_node = ptr_to_reint->m_head;


			linkedList.createNode(10);
			linkedList.createNode(11);
			linkedList.createNode(12);


			Assert::AreEqual(10, ptr_to_reint->m_head->data);
			Assert::AreEqual(11, ptr_to_reint->m_head->next->data);
			Assert::AreEqual(12, ptr_to_reint->m_head->next->next->data);

			Assert::IsNull(ptr_to_reint->m_head->next->next->next);
		}

		TEST_METHOD(insertHead)
		{
			LinkedList linkedList;
			auto ptr_to_reint = reinterpret_cast<rhTest::LinkedList_for_reinterpret*>(&linkedList);


			linkedList.insertHead(10);
			linkedList.insertHead(11);
			linkedList.insertHead(12);
			linkedList.insertHead(13);
			linkedList.insertHead(14);


			Assert::AreEqual(14, ptr_to_reint->m_head->data);
			Assert::AreEqual(13, ptr_to_reint->m_head->next->data);
			Assert::AreEqual(12, ptr_to_reint->m_head->next->next->data);
			Assert::AreEqual(11, ptr_to_reint->m_head->next->next->next->data);
			Assert::AreEqual(10, ptr_to_reint->m_head->next->next->next->next->data);

			Assert::IsNull(ptr_to_reint->m_head->next->next->next->next->next);
		}

		TEST_METHOD(insertTail)
		{
			LinkedList linkedList;
			auto ptr_to_reint = reinterpret_cast<rhTest::LinkedList_for_reinterpret*>(&linkedList);


			linkedList.insertTail(1);
			linkedList.insertTail(2);
			linkedList.insertTail(4);
			linkedList.insertTail(8);
			linkedList.insertTail(16);
			linkedList.insertTail(32);


			Node* ptr_node = ptr_to_reint->m_head;

			Assert::AreEqual(1, ptr_node->data); ptr_node = ptr_node->next;
			Assert::AreEqual(2, ptr_node->data); ptr_node = ptr_node->next;
			Assert::AreEqual(4, ptr_node->data); ptr_node = ptr_node->next;
			Assert::AreEqual(8, ptr_node->data); ptr_node = ptr_node->next;
			Assert::AreEqual(16, ptr_node->data); ptr_node = ptr_node->next;
			Assert::AreEqual(32, ptr_node->data); ptr_node = ptr_node->next;

			Assert::IsNull(ptr_node);

			Assert::AreEqual(32, ptr_to_reint->m_tail->data);
		}

		TEST_METHOD(deleteHead)
		{
			LinkedList linkedList;
			auto ptr_to_reint = reinterpret_cast<rhTest::LinkedList_for_reinterpret*>(&linkedList);

			linkedList.insertTail(8);
			linkedList.insertTail(16);
			linkedList.insertTail(32);
			linkedList.insertTail(64);
			linkedList.insertTail(128);


			linkedList.deleteHead();


			Node* ptr_node = ptr_to_reint->m_head;
			Assert::AreEqual(16, ptr_node->data); ptr_node = ptr_node->next;
			Assert::AreEqual(32, ptr_node->data); ptr_node = ptr_node->next;
			Assert::AreEqual(64, ptr_node->data); ptr_node = ptr_node->next;
			Assert::AreEqual(128, ptr_node->data); ptr_node = ptr_node->next;
		}

		TEST_METHOD(deleteHead_empty_list)
		{
			LinkedList linkedList;
			auto ptr_to_reint = reinterpret_cast<rhTest::LinkedList_for_reinterpret*>(&linkedList);

			linkedList.deleteHead();
			linkedList.deleteHead();


			Node* ptr_node = ptr_to_reint->m_head;
			Assert::IsNull(ptr_node);;
		}

		TEST_METHOD(deleteTail)
		{
			LinkedList linkedList;
			auto ptr_to_reint = reinterpret_cast<rhTest::LinkedList_for_reinterpret*>(&linkedList);

			linkedList.insertTail(2);
			linkedList.insertTail(4);
			linkedList.insertTail(8);
			linkedList.insertTail(16);
			linkedList.insertTail(32);


			linkedList.deleteTail();
			linkedList.deleteTail();


			Node* ptr_node = ptr_to_reint->m_head;
			Assert::AreEqual(2, ptr_node->data); ptr_node = ptr_node->next;
			Assert::AreEqual(4, ptr_node->data); ptr_node = ptr_node->next;
			Assert::AreEqual(8, ptr_node->data); ptr_node = ptr_node->next;
			
			Assert::IsNull(ptr_node);
		}

		TEST_METHOD(deleteTail_empty_list)
		{
			LinkedList linkedList;
			auto ptr_to_reint = reinterpret_cast<rhTest::LinkedList_for_reinterpret*>(&linkedList);

			linkedList.deleteTail();
			linkedList.deleteTail();

			Node* ptr_node = ptr_to_reint->m_head;
			Assert::IsNull(ptr_node);
		}

		TEST_METHOD(deleteAll)
		{
			LinkedList linkedList;
			auto ptr_to_reint = reinterpret_cast<rhTest::LinkedList_for_reinterpret*>(&linkedList);

			linkedList.insertTail(1);
			linkedList.insertTail(4);
			linkedList.insertTail(16);
			linkedList.insertTail(64);
			linkedList.insertTail(256);


			linkedList.deleteAll();


			Node* ptr_node = ptr_to_reint->m_head;
			Assert::IsNull(ptr_node);
			
			ptr_node = ptr_to_reint->m_tail;
			Assert::IsNull(ptr_node);
		}

		TEST_METHOD(deleteHead_AND_deleteTail)
		{
			LinkedList linkedList;
			auto ptr_to_reint = reinterpret_cast<rhTest::LinkedList_for_reinterpret*>(&linkedList);

			linkedList.insertTail(-2);
			linkedList.insertTail(0);
			linkedList.insertTail(2);
			linkedList.insertTail(4);
			linkedList.insertTail(8);


			linkedList.deleteHead();

			linkedList.deleteTail();
			linkedList.deleteTail();

			
			Node* ptr_node = ptr_to_reint->m_head;
			Assert::AreEqual(0, ptr_node->data); ptr_node = ptr_node->next;
			Assert::AreEqual(2, ptr_node->data); ptr_node = ptr_node->next;
			Assert::IsNull(ptr_node);
		}

		//void insertHead(int value) + createNode();
		//void insertTail(int value) + createNode();
		//insertHead() + insertTail() + createNode();

		//// void insertAtPosition(int pos, int value);
		//void deleteHead(); + deleteTail();
		////void delete_tail();
		//void deleteTail();
		////void deleteAtPosition(inr position);
		//void deleteAll();
	};
}
