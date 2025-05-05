#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class BSTArray {
private:
    vector<int> tree;
    int size;

public:
    // Constructor to initialize BST with a given size
    BSTArray(int capacity) {
        size = capacity;
        tree.resize(size, -1); // Initialize with -1 (empty node)
    }

    // Insert a value into BST
    void insert(int value) {
        int index = 0;
        while (index < size) {
            if (tree[index] == -1) { 
                tree[index] = value; // Insert value at empty position
                return;
            }
            if (value < tree[index]) 
                index = 2 * index + 1;  // Move to left child
            else 
                index = 2 * index + 2;  // Move to right child
        }
        cout << "Tree is full, cannot insert " << value << endl;
    }

    // Search for a value in BST
    bool search(int value) {
        int index = 0;
        while (index < size && tree[index] != -1) {
            if (tree[index] == value)
                return true;
            if (value < tree[index])
                index = 2 * index + 1;
            else
                index = 2 * index + 2;
        }
        return false;
    }

    // Find the minimum value in the right subtree (used for deletion)
    int findMinIndex(int index) {
        while (2 * index + 1 < size && tree[2 * index + 1] != -1) {
            index = 2 * index + 1;
        }
        return index;
    }

    // Delete a node from BST
    void deleteValue(int value) {
        int index = 0;
        int parent = -1;
        
        // Find the node to delete
        while (index < size && tree[index] != -1) {
            if (tree[index] == value)
                break;
            parent = index;
            if (value < tree[index])
                index = 2 * index + 1;
            else
                index = 2 * index + 2;
        }

        if (index >= size || tree[index] == -1) {
            cout << "Value not found in BST." << endl;
            return;
        }

        // Case 1: Node has no children (Leaf Node)
        if ((2 * index + 1 >= size || tree[2 * index + 1] == -1) && 
            (2 * index + 2 >= size || tree[2 * index + 2] == -1)) {
            tree[index] = -1;
        }
        // Case 2: Node has one child
        else if ((2 * index + 1 >= size || tree[2 * index + 1] == -1)) {
            tree[index] = tree[2 * index + 2];
            tree[2 * index + 2] = -1;
        }
        else if ((2 * index + 2 >= size || tree[2 * index + 2] == -1)) {
            tree[index] = tree[2 * index + 1];
            tree[2 * index + 1] = -1;
        }
        // Case 3: Node has two children
        else {
            int minIndex = findMinIndex(2 * index + 2);
            tree[index] = tree[minIndex];
            tree[minIndex] = -1;
        }
    }

    // Inorder traversal (Left, Root, Right)
    void inorder(int index) {
        if (index >= size || tree[index] == -1) return;
        inorder(2 * index + 1); // Left subtree
        cout << tree[index] << " "; // Root
        inorder(2 * index + 2); // Right subtree
    }

    // Wrapper function for inorder traversal
    void printInorder() {
        cout << "Inorder Traversal: ";
        inorder(0);
        cout << endl;
    }
};

int main() {
    BSTArray bst(15); // Capacity of 15 nodes
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    bst.printInorder();

    cout << "Search 40: " << (bst.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (bst.search(100) ? "Found" : "Not Found") << endl;

    cout << "Deleting 30..." << endl;
    bst.deleteValue(30);
    bst.printInorder();

    return 0;
}
