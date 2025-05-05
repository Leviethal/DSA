#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<int> table;  // Hash table storage
    int size;           // Size of the hash table

public:
    // Constructor to initialize the hash table
    HashTable(int s) {
        size = s;
        table.resize(size, -1);  // Fill the table with -1 (empty)
    }

    // Hash function to map a key to an index
    int hashFunction(int key) {
        return key % size;
    }

    // Insert a key into the hash table using linear probing
    void insert(int key) {
        int index = hashFunction(key);

        // If the spot is empty, place the key
        if (table[index] == -1) {
            table[index] = key;
        }
        else {
            // Linear probing: Keep checking the next index until an empty spot is found
            int originalIndex = index;
            while (table[index] != -1) {
                index = (index + 1) % size;  // Wrap around if needed
                if (index == originalIndex) {
                    cout << "Table is full. Cannot insert " << key << endl;
                    return;  // If we've wrapped around, the table is full
                }
            }
            table[index] = key;  // Insert at the found index
        }
    }

    // Delete a key from the hash table
    void remove(int key) {
        int index = hashFunction(key);

        // Search for the key and delete it
        while (table[index] != -1) {
            if (table[index] == key) {
                table[index] = -1;  // Set the spot to -1 (empty)
                cout << "Removed " << key << " from index " << index << endl;
                return;
            }
            index = (index + 1) % size;  // Linear probing
        }
        cout << key << " not found in the table." << endl;
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < size; i++) {
            if (table[i] != -1) {
                cout << "Index " << i << ": " << table[i] << endl;
            } else {
                cout << "Index " << i << ": [empty]" << endl;
            }
        }
    }
};

int main() {
    HashTable ht(7);  // Creating a hash table of size 7

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.insert(22);
    ht.insert(17);

    cout << "Hash Table after insertion:" << endl;
    ht.display();

    // Remove a key
    ht.remove(15);
    cout << "\nHash Table after removing 15:" << endl;
    ht.display();

    return 0;
}
     