#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insertNode(Node* root, int data){
    if(root==NULL) return new Node(data);
    if(data < root->data)
        root->left = insertNode(root->left, data);
    else if(data > root->data)
        root->right = insertNode(root->right, data);
    return root;
}

Node* findMin(Node* root) {
    while(root && root->left != NULL) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int target){
    if(!root) return NULL;
    if(target < root->data)
        root->left = deleteNode(root->left, target);
    else if(target > root->data)
        root->right = deleteNode(root->right, target);
    else {
        if(!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inOrderDFS(Node* root){
    if(!root) return;
    inOrderDFS(root->left);
    cout << root->data << " ";
    inOrderDFS(root->right);
}

void PreOrderDFS(Node* root){
    if(!root) return;
    cout << root->data << " ";
    PreOrderDFS(root->left);
    PreOrderDFS(root->right);
}

void PostOrderDFS(Node* root){
    if(!root) return;
    PostOrderDFS(root->left);
    PostOrderDFS(root->right);
    cout << root->data << " ";
}

void BFS(Node* root){
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front(); q.pop();
        cout << curr->data << " ";
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}

int findHeight(Node* root){
    if(!root) return 0;
    return 1 + max(findHeight(root->left), findHeight(root->right));
}

int findDiameter(Node* root, int& diameter) {
    if(!root) return 0;
    int lh = findDiameter(root->left, diameter);
    int rh = findDiameter(root->right, diameter);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}

int findDiameter(Node* root) {
    int diameter = 0;
    findDiameter(root, diameter);
    return diameter;
}

Node* searchNode(Node* root, int key) {
    if(!root || root->data == key) return root;
    if(key < root->data) return searchNode(root->left, key);
    return searchNode(root->right, key);
}

bool identicalTrees(Node* a, Node* b) {
    if(!a && !b) return true;
    if(!a || !b) return false;
    return (a->data == b->data &&
            identicalTrees(a->left, b->left) &&
            identicalTrees(a->right, b->right));
}

bool isBalanced(Node* root) {
    if(!root) return true;
    int lh = findHeight(root->left);
    int rh = findHeight(root->right);
    return abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

bool isBSTUtil(Node* root, Node* minNode, Node* maxNode) {
    if(!root) return true;
    if((minNode && root->data <= minNode->data) ||
       (maxNode && root->data >= maxNode->data))
        return false;
    return isBSTUtil(root->left, minNode, root) &&
           isBSTUtil(root->right, root, maxNode);
}

bool isBST(Node* root) {
    return isBSTUtil(root, NULL, NULL);
}

bool isMirror(Node* a, Node* b) {
    if(!a && !b) return true;
    if(!a || !b) return false;
    return (a->data == b->data &&
            isMirror(a->left, b->right) &&
            isMirror(a->right, b->left));
}

bool isSymmetric(Node* root) {
    if(!root) return true;
    return isMirror(root->left, root->right);
}

void leftView(Node* root) {
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int n = q.size();
        for(int i=0; i<n; ++i) {
            Node* curr = q.front(); q.pop();
            if(i == 0) cout << curr->data << " ";
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    cout << endl;
}

void rightView(Node* root) {
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int n = q.size();
        for(int i=0; i<n; ++i) {
            Node* curr = q.front(); q.pop();
            if(i == n-1) cout << curr->data << " ";
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    cout << endl;
}

void dfs(Node* node, int hd, int level, map<int, pair<int, int>>& topNode) {
    if (!node) return;

    // If this HD is not seen before or the current node is at a higher level (i.e., smaller depth)
    if (topNode.find(hd) == topNode.end() || level < topNode[hd].second) {
        topNode[hd] = {node->data, level};
    }

    dfs(node->left, hd - 1, level + 1, topNode);
    dfs(node->right, hd + 1, level + 1, topNode);
}

void topView(Node* root) {
    map<int, pair<int, int>> topNode;  // hd -> {value, level}
    dfs(root, 0, 0, topNode);
    for (auto& [hd, val] : topNode)
        cout << val.first << " ";
    cout << endl;
}

int maxPathSumUtil(Node* root, int& maxSum) {
    if(!root) return 0;
    int left = max(0, maxPathSumUtil(root->left, maxSum));
    int right = max(0, maxPathSumUtil(root->right, maxSum));
    maxSum = max(maxSum, root->data + left + right);
    return root->data + max(left, right);
}

int maxPathSum(Node* root) {
    int maxSum = INT_MIN;
    maxPathSumUtil(root, maxSum);
    return maxSum;
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 4);
    root = insertNode(root, 2);
    root = insertNode(root, 7);
    root = insertNode(root, 6);
    root = insertNode(root, 8);

    cout << "Inorder: "; inOrderDFS(root); cout << endl;
    cout << "Preorder: "; PreOrderDFS(root); cout << endl;
    cout << "Postorder: "; PostOrderDFS(root); cout << endl;
    cout << "Level Order (BFS): "; BFS(root); cout << endl;
    cout << "Height: " << findHeight(root) << endl;
    cout << "Diameter: " << findDiameter(root) << endl;
    cout << "Is Balanced: " << isBalanced(root) << endl;
    cout << "Is BST: " << isBST(root) << endl;
    cout << "Is Symmetric: " << isSymmetric(root) << endl;
    cout << "Left View: "; leftView(root);
    cout << "Right View: "; rightView(root);
    cout << "Top View: "; topView(root);
    cout << "Max Path Sum: " << maxPathSum(root) << endl;

    return 0;
}
