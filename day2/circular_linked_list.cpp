#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* tail;

public:
    CircularLinkedList() {
        tail = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!tail) {
            tail = newNode;
            tail->next = newNode;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display() {
        if (!tail) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = tail->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << endl;
    }

    ~CircularLinkedList() {
        if (!tail) return;
        Node* head = tail->next;
        Node* temp;
        while (head != tail) {
            temp = head;
            head = head->next;
            delete temp;
        }
        delete tail;
    }
};

int main() {
    CircularLinkedList cll;
    cll.insert(1);
    cll.insert(2);
    cll.insert(3);
    cll.display();
    return 0;
}
