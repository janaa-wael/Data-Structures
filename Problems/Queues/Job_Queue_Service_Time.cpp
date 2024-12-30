/*
 * main.cpp
 *
 *  Created on: Dec 30, 2024
 *      Author: Jana Wael
 */
#include <iostream>
using namespace std;


class Node{
public:
	Node* next;
	int data;
	Node(int x)
	{
		next = NULL;
		data = x;
	}
};

class Queue{
private:
	Node* front;
	Node* back;
public:
	Queue(){
		front = NULL;
		back = NULL;
	}

	bool isEmpty(void)
	{
		return front == NULL;
	}

	void enqueue(int element)
	{
		Node* new_node = new Node(element);
		if(back == NULL)
		{
			back = new_node;
			front = back;
		}
		else
		{
			back->next = new_node;
			back = new_node;
		}
	}

	int dequeue(void)
	{
		if(front == NULL)
		{
			throw runtime_error("Empty queue");
		}
		Node *temp = front;
		int data = front->data;
		front = front->next;
		delete temp;
		return data;
	}

	void traverse(void)
	{
		if(front == NULL)
		{
			cout << "Empty queue" << endl;
			return;
		}
		Node* current_node = front;
		int index = 0;
		cout << "***************************************" << endl;
		while(current_node != NULL)
		{
			cout << "Element " << ++index << ": " << current_node->data << endl;
			current_node = current_node->next;
		}
		cout << "***************************************" << endl;
	}

	void clear(void)
	{
		if(front == NULL)
			return;
		Node* current_node = front->next;
		Node* prev_node = front;
		while(current_node != NULL)
		{
			delete prev_node;
			prev_node = current_node;
			current_node = current_node->next;
		}
		front = NULL;
		back = NULL;
	}

	int getFront(void)
	{
		if(front == NULL)
			throw runtime_error("Empty Queue");
		return front->data;
	}


	int getBack(void)
	{
		if(back == NULL)
			throw runtime_error("Empty Queue");
		return back->data;
	}

	int getSize(void)
	{
		Node* current_node = front;
		int size = 0;
		while(current_node != NULL)
		{
			size++;
			current_node = current_node->next;
		}
		return size;
	}

	void debug(void)
	{
		cout << "***************************************" << endl;
		cout << "* Front : " << getFront() << endl;
		cout << "* Back : " << getBack() << endl;
		cout << "*Size : " << getSize() << endl;
		cout << "***************************************" << endl;
	}
};

void job_statistics(Queue &q)
{
	int total_service_time = 0;
	float average_waiting_time = 0;
	int size = q.getSize();
	Queue temp_q;
	for(int i = 0 ; i < size; i++)
	{
		int front = q.getFront();
		total_service_time += front;
		average_waiting_time += front*(size-i-1);
		cout << "Current total service time: " << total_service_time << endl;
		cout << "Current total waiting time: " << average_waiting_time << endl;
		temp_q.enqueue(q.dequeue());
	}
	cout << "Total service time: " << total_service_time << endl;
	cout << "Average total waiting time: " << average_waiting_time/size << endl;
	while(!temp_q.isEmpty())
	{
		q.enqueue(temp_q.dequeue());
	}
}

int main()
{
	Queue jobs;
	jobs.enqueue(4);
	jobs.enqueue(3);
	jobs.enqueue(4);
	jobs.enqueue(3);
	job_statistics(jobs);
	jobs.traverse();
}

