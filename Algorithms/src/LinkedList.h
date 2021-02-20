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
        void deleteAll();

        void display()
        {
            Node* temp = m_head;
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
            m_head = temp;
        else
            m_tail->next = temp;

        m_tail = temp;
    }

    void LinkedList::insertHead(int value) // TODO neresi, kdyz pouziji jako prvni, bez zavolani fce createNode().
    {
        Node* temp = new Node;
        temp->data = value;
        temp->next = m_head;

        if (m_head == nullptr)
            m_tail = temp;

        m_head = temp;
    }

    void LinkedList::insertTail(int value)
    {
        createNode(value);
    }

    void LinkedList::deleteHead()
    {
        if (m_head != nullptr)
        {
            Node* temp = m_head;
            m_head = m_head->next;
            delete temp;
            
            if (m_head == nullptr)
                m_tail = nullptr;
        }
    }

    void LinkedList::deleteTail() // TODO bude fungovat, kdyz je jenom jedno Node anebo zadny??
    {
        Node* current = m_head;
        Node* previous = nullptr;
        while (current->next != nullptr)
        {
            previous = current;
            current = current->next;
        }
        m_tail = previous;

        if (m_tail != nullptr)
            previous->next = nullptr;
        else
            m_head = nullptr;

        delete current;
    }

    void LinkedList::deleteAll()
    {
        while (m_head != nullptr)
        {
            deleteHead();
        }
    }
}
