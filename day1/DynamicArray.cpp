#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;        
    int capacity;    
    int size;        

    
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
    DynamicArray(int initialCapacity = 2) {
        capacity = initialCapacity;
        size = 0;
        arr = new int[capacity];
    }

    ~DynamicArray() {
        delete[] arr;
    }

    void push_back(int value) {
        if (size == capacity) {
            resize();
        }
        arr[size++] = value;
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    
    int getSize() const {
        return size;
        
    }


    int getCapacity() const {
        return capacity;
    }
};

int main() {
    DynamicArray da;

    da.push_back(10);
    da.push_back(20);
    da.push_back(30);
    da.push_back(40);

    cout << "Array Elements: ";
    da.print(); 

    cout << "Size: " << da.getSize() << endl;        
    cout << "Capacity: " << da.getCapacity() << endl; 

    return 0;
}
