#include <iostream>
using namespace std;

// Structure for BST Node
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int item) {
        key = item;
        left = right = NULL;
    }
};

// Function to insert a new node in BST
Node* insert(Node* root, int key) {
    if (root == NULL) return new Node(key);
    
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Function to find the minimum value node in a subtree
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Function to delete a node from BST
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    // Search for the node to delete
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Case 1: Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: Node with two children
        Node* temp = findMin(root->right);  // Get inorder successor (smallest in right subtree)
        root->key = temp->key;  // Copy inorder successor's value to this node
        root->right = deleteNode(root->right, temp->key);  // Delete inorder successor
    }
    return root;
}

// Function for inorder traversal (prints BST in sorted order)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Driver Code
int main() {
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    // Delete node
    root = deleteNode(root, 50);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
