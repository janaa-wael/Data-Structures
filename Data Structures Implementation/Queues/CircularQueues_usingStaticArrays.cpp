#include <iostream>

using namespace std;

#define ARR_SIZE 1000

class Circular_Queue {
private:
    int front;
    int back;
    int capacity;
    int arr[ARR_SIZE];
public:
    Circular_Queue() {
        capacity = 10;
        front = back = -1;
    }

    bool isFull() {
        // Queue is full when (back + 1) % capacity == front
        return (back + 1) % capacity == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    int getBack() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[back];
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        if (isEmpty()) {
            front = back = 0;
        }
        else {
            back = (back + 1) % capacity;
        }
        arr[back] = element;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int element = arr[front];
        if (front == back)
        {
            // Queue becomes empty after dequeuing
            front = back = -1;
        }
        else if (front == capacity - 1)
        {
            front = 0;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        return element;
    }

    int getSize() {
        if (isEmpty()) {
            return 0;
        }
        if (front <= back) {
            return back - front + 1;
        }
        return capacity - front + back + 1;
    }

    void print_queue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        int index = 1;
        int i = front;
        while (i != back) {
            cout << "Element " << index++ << ": " << arr[i] << endl;
            i = (i + 1) % capacity;
        }
        cout << "Element " << index << ": " << arr[back] << endl;
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
};

int main() {
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
    cqueue.enqueue(18);
    cqueue.enqueue(19);
    cqueue.debug();
    cout << "Dequeuing: " << cqueue.dequeue() << endl;
    cout << "Dequeuing: " << cqueue.dequeue() << endl;
    cout << "Dequeuing: " << cqueue.dequeue() << endl;
    cout << "Dequeuing: " << cqueue.dequeue() << endl;
    cout << "Dequeuing: " << cqueue.dequeue() << endl;
    cout << "Dequeuing: " << cqueue.dequeue() << endl;
    cout << "Dequeuing: " << cqueue.dequeue() << endl;

    cqueue.debug();

    return 0;
}
