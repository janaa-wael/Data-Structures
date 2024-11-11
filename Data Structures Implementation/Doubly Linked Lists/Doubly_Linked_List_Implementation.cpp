/*
 * main.cpp
 *
 *  Created on: Nov 11, 2024
 *      Author: Jana Wael
 *
 *  Description:
 *      This program implements a doubly linked list with various functionalities, including 
 *      adding elements to the front and back, removing elements from both ends, checking if 
 *      an element exists, getting the length, and sorting the list using a bubble sort algorithm. 
 *      The program demonstrates the use of the doubly linked list through several test cases.
 */

#include <bits/stdc++.h>
using namespace std;

// Node class representing a single element in a doubly linked list.
class Node{
private:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the list
    Node* prev;     // Pointer to the previous node in the list

public:
    // Constructor initializes node with data and null pointers
    Node(int d)
    {
        this->data = d;
        this->next = nullptr;
        this->prev = nullptr;
    }

    // Sets the next pointer to a specified node
    void set_next(Node* n)
    {
        this->next = n;
    }

    // Returns the next node pointer
    Node* get_next(void)
    {
        return next;
    }

    // Granting DoublyLinkedList access to private members
    friend class DoublyLinkedList;
};

// DoublyLinkedList class for managing a list of nodes
class DoublyLinkedList{
private:
    Node* head; // Pointer to the first node in the list

public:
    // Constructor initializes the head to nullptr
    DoublyLinkedList()
    {
        head = nullptr;
    }

    // Checks if the list is empty
    bool empty()
    {
        return head == nullptr;
    }

    // Returns the length of the list
    int length()
    {
        int length = 0;
        Node* ptr = head;
        while(ptr)
        {
            length++;
            ptr = ptr->next;
        }
        return length;
    }

    // Adds a node to the front of the list
    void push_front(int d)
    {
        Node* ptr = new Node(d);
        if (head != nullptr)
        {
            ptr->next = head;
            head->prev = ptr; // Set the previous pointer of the old head
        }
        head = ptr;
    }

    // Removes a node from the front of the list
    void pop_front()
    {
        if(head == nullptr)
            return;
        head = head->next;
        Node* ptr = head->prev;
        head->prev = nullptr;
        delete ptr;
    }

    // Adds a node to the back of the list
    void push_back(int d)
    {
        Node* ptr = new Node(d);
        Node* curr_ptr = head;
        if(head == nullptr)
        {
            head = ptr;
            return;
        }
        while(curr_ptr->next != nullptr)
        {
            curr_ptr = curr_ptr->next;
        }
        curr_ptr->next = ptr;
        ptr->prev = curr_ptr;
        ptr->next = nullptr;
    }

    // Removes a node from the back of the list
    void pop_back()
    {
        if (head == nullptr)
            return;

        if (head->next == nullptr) // Only one node
        {
            delete head;
            head = nullptr;
            return;
        }

        Node* last_node = head;
        while (last_node->next != nullptr)
        {
            last_node = last_node->next;
        }
        last_node->prev->next = nullptr; // Set the second-to-last node's next to nullptr
        delete last_node;
    }

    // Prints all nodes in the list
    void print()
    {
        Node* curr_ptr = head;
        while(curr_ptr)
        {
            cout << curr_ptr->data << " ";
            curr_ptr = curr_ptr->next;
        }
    }

    // Checks if a node with specified data exists in the list
    bool contains(int d)
    {
        Node* curr_ptr = head;
        while(curr_ptr)
        {
            if(curr_ptr->data == d)
                return true;
            curr_ptr = curr_ptr->next;
        }
        return false;
    }

    // Clears the list by deleting all nodes
    void clear()
    {
        while(!empty())
            pop_front();
    }

    // Sorts the list in ascending order using the bubble sort algorithm
    void bubble_sort()
    {
        int size = length();
        for(int i = 0; i < size-1; i++)
        {
            Node* curr_ptr = head;
            for(int j = 0; j < size - i -1; j++)
            {
                if(curr_ptr->next && curr_ptr->data > curr_ptr->next->data)
                {
                    swap(curr_ptr->data, curr_ptr->next->data); // Swap data if out of order
                }
                curr_ptr = curr_ptr->next;
            }
        }
    }

    // Destructor clears the list to release memory
    ~DoublyLinkedList()
    {
        clear();
    }
};

// Main function to demonstrate the functionalities of the DoublyLinkedList
int main()
{
    DoublyLinkedList dl;

    // Add elements to the front and back of the list
    dl.push_front(41);
    dl.push_front(53);
    dl.push_back(50);
    dl.push_back(10);
    dl.push_back(101);
    dl.push_back(4);
    
    // Print the list and its length
    dl.print();
    cout << "\nlength = " << dl.length() << endl;

    // Check if the list contains a specific element
    cout << dl.contains(1) << endl;

    // Sort the list and print the sorted list
    dl.bubble_sort();
    cout << "Sorted list: ";
    dl.print();
    cout << endl;

    // Clear the list and test additional operations
    dl.clear();
    dl.push_front(77);
    dl.push_front(510);
    dl.push_front(90);
    dl.pop_front();
    dl.print();

    return 0;
}
