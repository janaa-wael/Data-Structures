/*
 * main.cpp
 *
 *  Created on: Dec 30, 2024
 *      Author: Jana Wael
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
    Circular_Queue() {
        capacity = 10;
        front = back = -1;
        arr = new int[capacity];
    }

    ~Circular_Queue() {
        delete[] arr;
    }

    bool isFull() {
        return (back + 1) % capacity == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    int getFront() {
        if (!isEmpty())
            return arr[front];
        throw runtime_error("Queue is empty");
    }

    int getBack() {
        if (!isEmpty())
            return arr[back];
        throw runtime_error("Queue is empty");
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full\nResizing..." << endl;
            resize();
        }

        if (isEmpty()) {
            front = back = 0;
        } else {
            back = (back + 1) % capacity;
        }

        arr[back] = element;
    }

    int dequeue() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }

        int element = arr[front];
        if (front == back) {
            front = back = -1; // Queue becomes empty
        } else {
            front = (front + 1) % capacity; // Move front forward with wraparound
        }

        return element;
    }

    int getSize() {
        if (isEmpty())
            return 0;
        if (isFull())
            return capacity;
        if (back >= front)
            return back - front + 1;
        return capacity - front + back + 1;
    }

    void print_queue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        int index = 1;
        int i = front;
        while (true) {
            cout << "Element " << index++ << ": " << arr[i] << endl;
            if (i == back)
                break;
            i = (i + 1) % capacity; // Move to the next index with wraparound
        }
    }

    void debug() {
        cout << "******************************" << endl;
        cout << "* Front    : " << front << endl;
        cout << "* Back     : " << back << endl;
        cout << "* Capacity : " << capacity << endl;
        cout << "* Size     : " << getSize() << endl;
        cout << "******************************" << endl;
    }

    void clear() {
        front = -1;
        back = -1;
    }

    void resize() {
        int* temp = new int[capacity * 2];
        int newIndex = 0;

        for (int i = front; ; i = (i + 1) % capacity) {
            temp[newIndex++] = arr[i];
            if (i == back)
                break;
        }

        delete[] arr;
        arr = temp;
        capacity *= 2;
        front = 0;
        back = newIndex - 1;
    }
};

int main() {
    Circular_Queue cqueue;

    // Testing enqueue and debug
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

    // Testing print_queue
    cqueue.print_queue();

    // Testing dequeue
    cout << "Dequeuing: " << cqueue.dequeue() << endl;
    cout << "Dequeuing: " << cqueue.dequeue() << endl;
    cout << "Dequeuing: " << cqueue.dequeue() << endl;

    cqueue.print_queue();
    cqueue.debug();

    // Enqueue more elements to test wraparound
    cqueue.enqueue(11);
    cqueue.enqueue(12);
    cqueue.enqueue(13);
    cqueue.enqueue(14);
    cqueue.enqueue(15);
    cqueue.print_queue();
    cqueue.debug();

    cqueue.enqueue(16);
    cqueue.print_queue();
    cqueue.debug();

    cqueue.enqueue(17);
    cqueue.print_queue();
    cqueue.debug();

    cqueue.enqueue(18);
    cqueue.print_queue();
    cqueue.debug();

    cqueue.enqueue(19);
    cqueue.debug();

    return 0;
}
