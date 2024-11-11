/*
 * main.cpp
 *
 *  Created on: Nov 11, 2024
 *      Author: Jana Wael
 */
#include <bits/stdc++.h>
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

int main()
{
	Stack s,p;
	s.push(21);
	p.push(45);
	cout << s.isEqual(p) << endl;
	s.pop();
	p.pop();
	s.push(7);
	p.push(7);
	cout << s.isEqual(p) << endl;
	s.push(3);
	p.push(4);
	cout << s.isEqual(p) << endl;

}



