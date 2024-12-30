/*
 * main.cpp
 *
 *  Created on: Dec 29, 2024
 *      Author: hp
 */


#include <iostream>
using namespace std;

class Queue{
private:
	int size;
	int* arr;
	int front;
	int back;
public:
	Queue()
	{
		size = 1000;
		front = -1;
		back = -1;
		arr = new int[size];
	}

	~Queue()
	{
		delete[] arr;
	}
	int getFront(void)
	{
		if(!isEmpty())
			return arr[front];
		cout << "Empty queue" << endl;
		return -1;
	}

	int getBack(void)
	{
		if(!this->isEmpty())
			return arr[back];
		cout << "Empty queue" << endl;
		return -1;

	}

	int isEmpty()
	{
		return front == -1;
	}

	int isFull(void)
	{
		return back == size -1 ;
	}

	void enqueue(int element)
	{
		if(isEmpty())
		{
			front = 0;
			back = 0;
			arr[front] = element;
		}
		else if (isFull())
		{
		    size *= 2;
		    int* temp = new int[size];
		    for (int i = front; i <= back; i++) {
		        temp[i - front] = arr[i]; // Shift indices to start from 0
		    }
		    back = back - front; // Update back index
		    front = 0;           // Reset front index
		    delete[] arr;        // Delete old array
		    arr = temp;          // Point to the new array
		    arr[++back] = element;
		}

		else
		{
			arr[++back] = element;
		}
	}

	int dequeue(void)
	{
		int element;
		if(isEmpty())
		{
			cout << "Empty queue!" << endl;
			return -1;
		}
		else if(front == back)
		{
			element = arr[front];
			back = -1;
			front = -1;
		}
		else
		{
			element = arr[front];
			front++;
		}
		return element;
	}

	void print_queue()
	{
		Queue q;
		while(!isEmpty())
		{
			cout << getFront() << endl;
			q.enqueue(dequeue());
		}
		while(!q.isEmpty())
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

