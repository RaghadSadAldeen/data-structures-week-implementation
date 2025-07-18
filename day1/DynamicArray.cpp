#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;         // Pointer to the array
    int capacity;     // Total allocated size
    int size;         // Number of elements in array

    // Resize the array when it's full
    void resize() {
        int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    // Constructor with default initial capacity
    DynamicArray(int initialCapacity = 2) {
        capacity = initialCapacity;
        size = 0;
        arr = new int[capacity];
    }

    // Destructor to clean up dynamic memory
    ~DynamicArray() {
        delete[] arr;
    }

    // Add a new element to the end
    void push_back(int value) {
        if (size == capacity) {
            resize();
        }
        arr[size++] = value;
    }

    // Print all elements in the array
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Optional: Get number of elements
    int getSize() const {
        return size;
    }

    // Optional: Get current capacity
    int getCapacity() const {
        return capacity;
    }
};

// Demo usage
int main() {
    DynamicArray da;

    da.push_back(10);
    da.push_back(20);
    da.push_back(30);
    da.push_back(40);

    cout << "Array Elements: ";
    da.print(); // Output: 10 20 30 40

    cout << "Size: " << da.getSize() << endl;        // 4
    cout << "Capacity: " << da.getCapacity() << endl; // 4 or 8 depending on growth

    return 0;
}
