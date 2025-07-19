#include <iostream>
#include <list>
using namespace std;

const int SIZE = 10;

class HashTable {
    list<pair<int, int>> table[SIZE];

    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    void put(int key, int value) {
        int index = hashFunction(key);
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        table[index].emplace_back(key, value);
    }

    int get(int key) {
        int index = hashFunction(key);
        for (auto& pair : table[index]) {
            if (pair.first == key) return pair.second;
        }
        return -1; // not found
    }

    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove_if([key](const pair<int, int>& p) {
            return p.first == key;
        });
    }

    void display() {
        for (int i = 0; i < SIZE; ++i) {
            cout << i << ": ";
            for (auto& p : table[i])
                cout << "[" << p.first << ":" << p.second << "] ";
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    ht.put(1, 100);
    ht.put(11, 110);
    ht.put(21, 120);
    ht.display();

    cout << "Get key 11: " << ht.get(11) << endl;

    ht.remove(11);
    ht.display();

    return 0;
}
