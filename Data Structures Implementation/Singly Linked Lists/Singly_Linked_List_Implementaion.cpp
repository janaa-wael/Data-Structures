/*
 * main.cpp
 *
 *  Created on: Nov 11, 2024
 *      Author: Jana Wael
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
	~LinkedList()
	{
		clear();
	}
};

int main()
{
	LinkedList l;
	l.push_front(1);
	l.push_front(5);
	l.push_back(0);
	l.push_back(100);
	l.push_back(4);
	l.print();
	cout << "length = " << l.length() << endl;
	cout << l.contains(1) << endl;
	l.bubble_sort();
	l.print();
	l.clear();
	l.push_front(7);
	l.push_front(10);
	l.pop_front();
	l.print();
}


