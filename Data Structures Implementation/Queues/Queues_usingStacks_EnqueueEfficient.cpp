/*
 * main.cpp
 *
 *  Created on: Dec 30, 2024
 *      Author: Jana Wael
 */

#include <iostream>

using namespace std;


class Stack {
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
		return arr[size - 1];
	}
	void push(int x)
	{
		if (size == capacity)
		{
			capacity *= 2;
			int* ptr = new int[capacity];
			for (int i = 0; i < size; i++)
			{
				ptr[i] = arr[i];
			}
			delete[] arr;
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
		while (!c.empty() && !s.empty())
		{
			if (s.top() != c.top())
				return false;
			c.pop();
			s.pop();
		}
		return c.empty() && s.empty();
	}
};

//Enqueue Efficient
class Queue {
private:
	Stack s1;
	Stack s2;
	void transferFromS1ToS2(Stack& s1, Stack& s2)
	{
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
	}

	void transferFromS2ToS1(Stack& s1, Stack& s2)
	{
		while (!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
	}

public:
	bool isEmpty()
	{
		return s1.empty();
	}

	void enqueue(int element)
	{
		s1.push(element);
	}

	int dequeue(void)
	{
		transferFromS1ToS2(s1, s2);
		int element = s2.top();
		s2.pop();
		transferFromS2ToS1(s1, s2);
		return element;
	}

	int getBack()
	{
		return s1.top();
	}

	int getFront()
	{
		transferFromS1ToS2(s1, s2);
		int front = s2.top();
		transferFromS2ToS1(s1, s2);
		return front;
	}

	void clear(void)
	{
		while (!s1.empty())
		{
			s1.pop();
		}
	}

	void traverse(void)
	{
		int index = 1;
		cout << "********* Traversing *********" << endl;
		transferFromS1ToS2(s1, s2);
		while (!s2.empty())
		{
			s1.push(s2.top());
			cout << "Element " << index++ << ": " << s2.top() << endl;
			s2.pop();
		}
		cout << "******************************" << endl;

	}

	int getSize(void)
	{
		int size = 0;
		transferFromS1ToS2(s1, s2);
		while (!s2.empty())
		{
			s1.push(s2.top());
			size++;
			s2.pop();
		}
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
	q.enqueue(900);
	q.enqueue(500);
	q.enqueue(600);
	q.enqueue(400);
	q.enqueue(100);
	q.debug();
	q.enqueue(200);
	q.enqueue(1000);
	q.traverse();
	q.dequeue();
	q.traverse();
	q.enqueue(101);
	q.debug();
	q.dequeue();
	q.traverse();
}

