#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class QueueLL {
private:
    Node *front, *rear;

public:
    QueueLL() {
        front = rear = nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (!front) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        cout << "Dequeued: " << temp->data << endl;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
    }

    void display() {
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~QueueLL() {
        while (front) dequeue();
    }
};

int main() {
    QueueLL q;
    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(25);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
