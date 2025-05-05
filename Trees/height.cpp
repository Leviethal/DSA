#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to find depth of BST
int findDepth(Node* root) {
    if (!root) return -1; // Empty tree has depth -1
    int leftDepth = findDepth(root->left);
    int rightDepth = findDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}

// Insert into BST
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    
    cout << "Depth of BST: " << findDepth(root) << endl;
    return 0;
}
