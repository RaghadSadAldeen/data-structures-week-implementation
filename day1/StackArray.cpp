#include <iostream>
using namespace std;

class StackArray {
private:
    int* arr;
    int top;
    int capacity;

public:
    StackArray(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    int peek() {
        if (!isEmpty())
            return arr[top];
        cout << "Stack is empty\n";
        return -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void print() {
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~StackArray() {
        delete[] arr;
    }
};

int main() {
    StackArray s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.print();

    s.pop();
    s.print();

    cout << "Top element: " << s.peek() << endl;

    return 0;
}
