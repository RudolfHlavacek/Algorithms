#pragma once
// https://www.codementor.io/@codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr
// https://www.codesdope.com/blog/article/c-linked-lists-in-c-singly-linked-list/
// https://www.tutorialspoint.com/cplusplus-program-to-implement-singly-linked-list
// https://www.softwaretestinghelp.com/linked-list/

#include <iostream>

namespace rh {

    struct Node
    {
        int data;
        Node* next;
    };

    class LinkedList
    {

    private:
        Node* m_head;
        Node* m_tail;

    public:
        LinkedList();
        ~LinkedList();
        //insertAfter()
        //deleteNode()
        //
        void createNode(int value);
        void insertHead(int value);
        void insertTail(int value);
        // void insertAtPosition(int pos, int value);
        void deleteHead();
        //void delete_tail();
        void deleteTail();
        //void deleteAtPosition(inr position);

        void display() // TODO predelat, aby nevytvarel Node*, ale pouze vracel hodnotu.
        {
            Node* temp = new Node; // TODO nema byt new Node, staci pouze vytvorit pointer.
            temp = m_head;
            while (temp != nullptr)
            {
                std::cout << temp->data << "\t";
                temp = temp->next;
            }
        }
    };


    LinkedList::LinkedList()
        : m_head(nullptr), m_tail(nullptr)
    {
    }

    LinkedList::~LinkedList()
    {

    }

    void LinkedList::createNode(int value)
    {
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;
        if (m_head == nullptr)
        {
            m_head = temp;
            m_tail = temp;
            temp = nullptr; // TODO nemusi byt
        }
        else
        {
            m_tail->next = temp;
            m_tail = temp;
        }
    }

    void LinkedList::insertHead(int value) // TODO neresi, kdyz pouziji jako prvni, bez zavolani fce createNode().
    {
        Node* temp = new Node;
        temp->data = value;
        temp->next = m_head;
        m_head = temp;
    }

    void LinkedList::insertTail(int value)
    {
        createNode(value);
    }

    void LinkedList::deleteHead()
    {
        Node* temp; // TODO Prvni dva radky myzu mergenout do jednoho.?
        temp = m_head;
        m_head = m_head->next;
        delete temp;
    }

    void LinkedList::deleteTail() // TODO bude fungovat, kdyz je jenom jedno Node anebo zadny??
    {
        Node* current;
        Node* previous = nullptr;
        current = m_head;
        while (current->next != nullptr)
        {
            previous = current;
            current = current->next;
        }
        m_tail = previous;
        previous->next = nullptr;
        delete current;
    }
}
