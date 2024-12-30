/*
 * main.cpp
 *
 *  Created on: Dec 30, 2024
 *      Author: hp
 */

#include <iostream>

using namespace std;


class Stack{
private:
	int size;
	int capacity;
	int* arr;
public:
	Stack()
	{
		capacity = 1000;
		size = 0;
		arr = new int[capacity];
	}
	int top(void)
	{
		return arr[size-1];
	}
	void push(int x)
	{
		if(size == capacity)
		{
			capacity *= 2;
			int * ptr = new int[capacity];
			for(int i = 0 ; i < size ; i++)
			{
				ptr[i] = arr[i];
			}
			delete [] arr;
			arr = ptr;
		}
		arr[size++] = x;
	}
	void pop(void)
	{
		size--;
	}
	bool empty(void)
	{
		return (size == 0);
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

//Dequeue Efficient
class Queue{
private:
	Stack s1;
	Stack s2;
	void transferFromS1ToS2(Stack& s1, Stack& s2)
	{
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
	}

	void transferFromS2ToS1(Stack& s1, Stack& s2)
	{
		while(!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
	}

public:
	bool isEmpty()
	{
		return s1.empty() ;
	}

	void enqueue(int element)
	{
		transferFromS1ToS2(s1,s2);
		s2.push(element);
		transferFromS2ToS1(s1,s2);
	}

	int dequeue(void)
	{
		if(s1.empty())
			throw runtime_error("Empty queue.");
		int element = s1.top();
		s1.pop();
		return element;
	}

	int getFront()
	{
		return s1.top();
	}

	int getBack()
	{
		transferFromS1ToS2(s1,s2);
		int back = s2.top();
		transferFromS2ToS1(s1,s2);
		return back;
	}

	void clear(void)
	{
		while(!s1.empty())
		{
			s1.pop();
		}
	}

	void traverse(void)
	{
		int index = 1;
		cout << "********* Traversing *********" << endl;
		while(!s1.empty())
		{
			s2.push(s1.top());
			cout << "Element " << index++ << ": " << s1.top() << endl;
			s1.pop();
		}
		cout << "******************************" << endl;
		transferFromS2ToS1(s1,s2);
	}

	int getSize(void)
	{
		int size = 0;
		while(!s1.empty())
		{
			s2.push(s1.top());
			size++;
			s1.pop();
		}
		transferFromS2ToS1(s1,s2);
		return size;
	}

	void debug(void)
	{
		cout << "********* Debugging **********" << endl;
		cout << "* Front : " << getFront() << endl;
		cout << "* Back : " << getBack() << endl;
		cout << "* Size : " << getSize() << endl;
		cout << "******************************" << endl;
	}
};

int main()
{
	Queue q;
	q.enqueue(10);
	q.enqueue(12);
	q.enqueue(14);
	q.enqueue(16);
	q.enqueue(18);
	q.enqueue(22);
	q.debug();
	q.traverse();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.enqueue(111);
	q.enqueue(201);
	q.debug();
	q.traverse();

}

