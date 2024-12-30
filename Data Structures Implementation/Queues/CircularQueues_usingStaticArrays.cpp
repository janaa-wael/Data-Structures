/*
 * main.cpp
 *
 *  Created on: Dec 30, 2024
 *      Author: hp
 */

#include <iostream>

using namespace std;

class Circular_Queue {
private:
	int front;
	int back;
	int capacity;
	int* arr;
public:
	Circular_Queue()
	{
		capacity = 10;
		front = back = -1;
		arr = new int[capacity];
	}

	bool isFull(void)
	{
		if (front == 0 && back == capacity)
			return 1;
		else if (front > 0 && back == front - 1)
			return 1;
		else
			return 0;
	}

	bool isEmpty(void)
	{
		return front == -1;
	}

	int getFront(void)
	{
		return arr[front];
	}

	int getBack(void)
	{
		return arr[back];
	}

	void enqueue(int element)
	{
		if (isFull())
		{
			cout << "Queue is full" << endl;
			return;
		}
		else if (isEmpty())
		{
			front = back = 0;
			arr[front] = element;
		}
		else
		{
			if (back == capacity - 1)
			{
				back = 0;
			}
			else
			{
				back++;
			}
			arr[back] = element;
		}
	}

	int dequeue(void)
	{
		int element;
		if (isEmpty())
		{
			//throw runtime_error("Queue is empty");
			cout << "Queue is empty" << endl;

		}
		else
		{
			if (back == front)
			{
				cout << "Queue becomes empty" << endl;
				element = arr[front];
				front = back = -1;
			}
			else
			{
				element = arr[front++];
			}
		}
		return element;
	}

	int getSize(void)
	{
		if (isEmpty())
			return 0;
		else if (isFull())
			return capacity;
		else if (front < back)
		{
			return back - front + 1;
		}
		else if (front > back)
		{
			return capacity - front + back + 1;
		}
		else if (front == back && front == 0)
		{
			return 1;
		}
	}

	void print_queue(void)
	{
		int index = 0;
		if (front < back)
		{
			for (int i = front; i <= back; i++)
				cout << "Element " << ++index << ": " << arr[i] << endl;
			return;
		}
		else if (front > back)
		{
			int end = capacity - 1;
			for (int i = front; i <= end; i++)
			{
				cout << "Element " << ++index << ": " << arr[i] << endl;
			}
			for (int i = 0; i <= back; i++)
			{
				cout << "Element " << index + i + 1 << ": " << arr[i] << endl;
			}
		}
		else if (front == back && front == 0)
		{
			cout << "Element 1: " << arr[front];
		}
	}
	void debug(void)
	{
		cout << "******************************" << endl;
		cout << "* Front    : " << front << endl;
		cout << "* Back     : " << back << endl;
		cout << "* Capacity : " << capacity << endl;
		cout << "* Size     : " << getSize() << endl;
		cout << "******************************" << endl;
	}
	void clear(void)
	{
		front = -1;
		back = -1;
	}
};


int main()
{
	Circular_Queue cqueue;
	cqueue.enqueue(-1);
	cqueue.debug();
	cqueue.enqueue(100);
	cqueue.debug();
	cqueue.enqueue(17);
	cqueue.debug();
	cqueue.enqueue(1320);
	cqueue.debug();
	cqueue.enqueue(94);
	cqueue.debug();
	cqueue.enqueue(200);
	cqueue.debug();
	cqueue.enqueue(211);
	cqueue.debug();
	cqueue.print_queue();
	cout << "Dequeuing: " << cqueue.dequeue() << endl;
	cout << "Dequeuing: " << cqueue.dequeue() << endl;
	cout << "Dequeuing: " << cqueue.dequeue() << endl;
	cqueue.print_queue();
	cqueue.debug();
	cqueue.enqueue(11);
	cqueue.debug();
	cqueue.enqueue(12);
	cqueue.debug();
	cqueue.enqueue(13);
	cqueue.debug();
	cqueue.enqueue(14);
	cqueue.enqueue(15);
	cqueue.print_queue();
	cqueue.debug();
	cqueue.enqueue(16);
	cqueue.enqueue(17);
	cqueue.debug();
}
