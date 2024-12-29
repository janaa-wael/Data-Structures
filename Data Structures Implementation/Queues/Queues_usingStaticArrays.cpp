/*
 * main.c
 *
 *  Created on: Dec 29, 2024
 *      Author: hp
 */

#include <iostream>
using namespace std;

#define ARR_SIZE 	1000
class Queue {
private:
	int arr[ARR_SIZE];
	int front;
	int back;
public:
	Queue()
	{
		front = -1;
		back = -1;
	}
	bool isFull()
	{
		if (back == ARR_SIZE - 1)
			return true;
		return false;
	}

	bool isEmpty()
	{
		return front == -1;
	}
	void enqueue(int element)
	{
		if (back < ARR_SIZE - 1 && front > -1)
		{
			arr[++back] = element;
			return;
		}
		else if (front == -1)
		{
			arr[++front] = element;
			back++;
		}
	}

	int dequeue()
	{
		int element;
		if (isEmpty()) {
			cout << "Empty queue" << endl;
			return -1;
		}
		else if (front < back)
		{
			element = arr[front++];
		}
		else if (front == back)
		{
			element = arr[front];
			front = -1;
			back = -1;
		}
		return element;

	}

	int getFront(void)
	{
		if (front != -1)
			return arr[front];
		cout << "Empty queue" << endl;
		return -1;
	}

	int getBack(void)
	{
		if (back != -1)
			return arr[back];
		cout << "Empty queue" << endl;
		return -1;
	}
	void print_queue()
	{
		Queue q;
		while (!this->isEmpty())
		{
			cout << this->getFront() << endl;
			q.enqueue(this->dequeue());
		}
		while (!q.isEmpty())
		{
			this->enqueue(q.dequeue());
		}

	}
};

int main()
{
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(7);
	q.enqueue(8);
	q.enqueue(11);
	q.enqueue(43);
	q.print_queue();
	cout << "Dequeuing: " << q.dequeue() << endl;
	cout << "Dequeuing: " << q.dequeue() << endl;
	cout << "Front: " << q.getFront() << endl;
}
