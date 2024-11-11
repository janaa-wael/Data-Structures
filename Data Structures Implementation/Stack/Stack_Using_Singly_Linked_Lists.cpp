/*
 * main.cpp
 *
 *  Created on: Nov 11, 2024
 *      Author: hp
 */

#include <bits/stdc++.h>
using namespace std;

class Node{
private:
	int data;
	Node* next;
public:
	Node(int d)
	{
		this->data = d;
		this->next = nullptr;
	}
	void set_next(Node* n)
	{
		this->next = n;
	}
	Node* get_next(void)
	{
		return next;
	}
	friend class LinkedList;
	friend class Stack;
};

class LinkedList{
private:
	Node* head;
public:
	LinkedList()
	{
		head = nullptr;
	}
	bool empty()
	{
		return head == nullptr;
	}
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
	void push_front(int d)
	{
		Node* ptr= new Node(d);
		if(head == nullptr)
		{
			head = ptr;
			head->next = nullptr;
			return;
		}
		ptr->next = head;
		head = ptr;
	}
	void pop_front()
	{
		if(head == nullptr)
			return;
		Node* ptr = head;
		head = head->next;
		delete ptr;
	}
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
		ptr->next = nullptr;
	}
	void pop_back()
	{
		Node* last_node = head;
		Node* delete_node = head;
		if(head == nullptr)
		{
			return;
		}
		if(head->next == nullptr)
		{
			delete delete_node;
			return;
		}
		while(last_node->next->next != nullptr)
		{
			last_node = last_node->next;
		}
		delete_node = last_node->next;
		last_node->next = nullptr;
		delete delete_node;

	}
	void print()
	{
		Node* curr_ptr = head;
		while(curr_ptr)
		{
			cout << curr_ptr->data << " " ;
			curr_ptr = curr_ptr->next;
		}
	}
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
	void clear()
	{
		while(!empty())
			pop_front();
	}
	void bubble_sort()
	{

		for(int i = 0 ; i < length()-1 ; i++)
		{
			Node* curr_ptr = head;
			Node* next_ptr = curr_ptr->next;
			for(int j = 0 ;  j < length() - i -1 ; j++)
			{
				if(curr_ptr->data > next_ptr->data)
				{
					swap(curr_ptr->data,next_ptr->data);
				}
				curr_ptr = curr_ptr->next;
				next_ptr = next_ptr->next;
			}
		}
	}
	void selection_sort() {
		Node* first = head;
		while (first) {
			Node* minNode = first;
			Node* last = first->next;

			while (last) {
				if (last->data < minNode->data) {
					minNode = last;
				}
				last = last->next;
			}

			int t = minNode->data;
			minNode->data = first->data;
			first->data = t;

			first = first->next;
		}
	}
	~LinkedList()
	{
		clear();
	}
	friend class Stack;
};

class Stack{
private:
	LinkedList l;
public:
	Stack()
	{
		l.head = nullptr;
	}
	int top(void)
	{
		if(l.head)
			return l.head->data;
		return -1;
	}
	void push(int x)
	{
		l.push_front(x);
	}
	void pop(void)
	{
		l.pop_front();
	}
	bool empty(void)
	{
		return l.empty();
	}
	bool isEqual(Stack s)
	{
		Stack c = *this;
		while(!c.empty() && !s.empty())
		{
			if(s.top() != c.top())
				return false;
			c.pop();
			s.pop();
		}
		return c.empty() && s.empty();
	}
};


int main() {
    Stack s1;
    Stack s2;

    // Test pushing elements onto the stack
    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << "Top element of stack s1: " << s1.top() << endl;  // Should print 30

    // Test popping elements from the stack
    s1.pop();
    cout << "Top element of stack s1 after pop: " << s1.top() << endl;  // Should print 20

    // Test empty function
    if (!s1.empty())
    {
        cout << "Stack s1 is not empty." << endl;
    }
    else
    {
        cout << "Stack s1 is empty." << endl;
    }

    // Test isEqual function
    s2.push(10);
    s2.push(20);
    if (s1.isEqual(s2))
    {
        cout << "Stack s1 is equal to stack s2." << endl;
    } else
    {
        cout << "Stack s1 is not equal to stack s2." << endl;
    }

    s2.push(30);
    cout << "After pushing 30 to s2, equality check: " << (s1.isEqual(s2) ? "Equal" : "Not Equal") << endl;

    // Test clearing the stack
    while (!s1.empty())
    {
        cout << "Popping from s1: " << s1.top() << endl;
        s1.pop();
    }
    cout << "Stack s1 is now " << (s1.empty() ? "empty." : "not empty.") << endl;

    return 0;
}

