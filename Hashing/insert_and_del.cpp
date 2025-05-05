#include <iostream>
#include <list>
using namespace std;

class HashTable {
private:
    int BUCKET; // number of buckets
    list<int>* table;

public:
    // Constructor
    HashTable(int V) {
        BUCKET = V;
        table = new list<int>[BUCKET];
    }

    // Hash function to map values to key
    int hashFunction(int key) {
        return key % BUCKET;
    }

    // Insert a key into hash table
    void insertItem(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    // Delete a key from hash table
    void deleteItem(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    // Display hash table
    void displayHash() {
        for (int i = 0; i < BUCKET; i++) {
            cout << i << " --> ";
            for (int x : table[i])
                cout << x << " ";
            cout << endl;
        }
    }
};

int main() {
    // Create a hash table with 7 buckets
    HashTable ht(7);

    // Insert some keys
    ht.insertItem(10);
    ht.insertItem(20);
    ht.insertItem(15);
    ht.insertItem(7);
    ht.insertItem(22);
    ht.insertItem(17);

    // Display the hash table
    cout << "Initial table:\n";
    ht.displayHash();

    // Delete a key
    ht.deleteItem(15);

    // Display after deletion
    cout << "\nAfter deleting 15:\n";
    ht.displayHash();

    return 0;
}
