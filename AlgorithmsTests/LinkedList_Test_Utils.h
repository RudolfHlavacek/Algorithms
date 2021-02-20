#pragma once

#include "..\Algorithms\src\LinkedList.h"

namespace rhTest {

    struct LinkedList_for_reinterpret
    {
        rh::Node* m_head;
        rh::Node* m_tail;
    };

    ////int get_m_head(rh::LinkedList linkedList)
    ////{
    ////    return *((int*)&linkedList + 0);
    ////}

    ////int get_m_tail(rh::LinkedList linkedList)
    ////{
    ////    return *((int*)&linkedList + 1);
    ////}

    ////rh::Node getHeadNode(rh::LinkedList linkedList)
    ////{
    ////    return *(rh::Node*)&linkedList;
    ////}

    //rh::Node* getPtrToHeadNode(rh::LinkedList linkedList)
    //{
    //    return (rh::Node*)(*(int*)&linkedList);
    //}

    ////rh::Node* getPtrToTailNode(rh::LinkedList linkedList)
    ////{

    ////}

}
