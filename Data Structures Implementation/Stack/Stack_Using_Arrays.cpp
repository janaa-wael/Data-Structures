/*
 * main.cpp
 *
 *  Created on: Nov 11, 2024
 *      Author: Jana Wael
 */
#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE	1000

class Stack{
private:
	int arr[MAX_SIZE];
	int size;

public:
	Stack()
	{
		size = 0;
	}
	int top(void)
	{
		return arr[size-1];
	}
	void push(int x)
	{
		assert(size < MAX_SIZE);
		arr[size++] = x;
	}
	void pop(void)
	{
		assert(size > 0);
		size--;
	}
	bool empty(void)
	{
		return size == 0;
	}
	int peek(void)
	{
		assert(size > 0);
		return arr[size - 1];
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
	s.push(1);
	p.push(1);
	cout << s.isEqual(p) << endl;
	s.push(2);
	p.push(2);
	cout << s.isEqual(p) << endl;
	s.push(3);
	p.push(4);
	cout << s.isEqual(p) << endl;

}



