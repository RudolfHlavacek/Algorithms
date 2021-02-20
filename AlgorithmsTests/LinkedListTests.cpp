#include "pch.h"
#include "CppUnitTest.h"

#include "..\Algorithms\src\LinkedList.h"
#include "LinkedList_Test_Utils.h"

////#include <random>
//#include <array>
//#include <vector>

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

		//TEST_METHOD(createNode_3_Nodes)
		//{
		//	LinkedList linkedList;

		//	linkedList.createNode(10);
		//	linkedList.createNode(11);
		//	linkedList.createNode(12);

		//	const int head = rhTest::get_m_head(linkedList);
		//	const int tail = rhTest::get_m_tail(linkedList);
		//	const Node* const head_node = (Node*)head;
		//	const Node* const middle_node = head_node->next;
		//	const Node* const tail_node = middle_node->next;


		//	Assert::AreEqual(10, head_node->data);
		//	Assert::AreEqual(11, middle_node->data);
		//	Assert::AreEqual(12, tail_node->data);
		//	Assert::AreEqual(0, (int)tail_node->next);
		//	Assert::AreEqual(tail, (const int)tail_node);
		//}

		//TEST_METHOD(insertHead)
		//{
		//	const std::array<int, 6> input_arr = {10, 11, 12, 13, 14, 15};
		//	const std::array<int, 6> res_arr = {15, 14, 13, 12, 11, 10};
		//	LinkedList linkedList;

		//	for (int num : input_arr)
		//		linkedList.insertHead(num);

		//	Node node = rhTest::getHeadNode(linkedList);
		//	std::vector<Node> nodes_vec;
		//	while (node.next != nullptr)
		//	{
		//		nodes_vec.push_back(node);
		//		node = *(node.next);
		//	}

		//	for (int i = 0; i < res_arr.size(); i++)
		//		Assert::AreEqual(res_arr[i], nodes_vec[i].data);
		//}

		//void insertHead(int value);
		//void insertTail(int value);
		//// void insertAtPosition(int pos, int value);
		//void deleteHead();
		////void delete_tail();
		//void deleteTail();
		////void deleteAtPosition(inr position);
		//void deleteAll();
	};
}
