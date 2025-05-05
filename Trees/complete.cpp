#include <iostream>
#include <queue>
using namespace std;

// Definition of a BST Node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to check if the BST is complete
bool isCompleteBST(Node* root) {
    if (!root) return true;  // Empty tree is complete

    queue<Node*> q;
    q.push(root);
    
    bool foundNull = false;  // Flag to track NULL nodes

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current) {
            // If a NULL was found before a non-NULL, BST is incomplete
            if (foundNull) return false;

            // Push left and right children into queue
            q.push(current->left);
            q.push(current->right);
        } else {
            foundNull = true;  // NULL encountered, set flag
        }
    }
    return true;  // If no issues found, BST is complete
}

// Driver Code
int main() {
    // Creating a Complete BST
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(18);

    // Check if BST is complete
    if (isCompleteBST(root))
        cout << "The BST is Complete.\n";
    else
        cout << "The BST is NOT Complete.\n";

    return 0;
}
