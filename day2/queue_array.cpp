#include <iostream>
using namespace std;

class QueueArray {
private:
    int front, rear, capacity;
    int* queue;

public:
    QueueArray(int size) {
        capacity = size;
        queue = new int[capacity];
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (isEmpty()) front = 0;
        queue[++rear] = value;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Dequeued: " << queue[front++] << endl;
        if (front > rear) front = rear = -1; // reset if queue becomes empty
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }

    ~QueueArray() {
        delete[] queue;
    }
};

int main() {
    QueueArray q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
