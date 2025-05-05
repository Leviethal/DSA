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
    if(root==NULL){
        Node* new_node=new Node(data);
        return new_node;
    }
    if(data<root->data){
        root->left=insertNode(root->left,data);
    }
    else if(data>root->data){
        root->right=insertNode(root->right,data);
    }
    return root;
}

Node* deleteNode(Node* root, int target){
    if(!root)
    return NULL;
    else if(target<root->data)
    deleteNode(root->left,target);
    else if(target>root->data)
    deleteNode(root->right,target);
    else{
        
        }
    }


void inOrderDFS(Node* root){
    if(root == NULL) return;
    inOrderDFS(root->left);
    cout<<root->data<<" ";
    inOrderDFS(root->right);
}

void PreOrderDFS(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    PreOrderDFS(root->left);
    PreOrderDFS(root->right);
}

void PostOrderDFS(Node* root){
    if(root == NULL) return;
    PostOrderDFS(root->left);
    PostOrderDFS(root->right);
    cout<<root->data<<" ";
}

void BFS(Node* root){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}

int findHeight(Node* root){
    if(root==NULL) return 0;
    return 1+max(findHeight(root->left), findHeight(root->right));
}

int findDiameter() {

}

Node* searchNode() {

}

bool identicalTrees() {

}

bool isBalanced() {

}

bool isBST() {

}

bool isSymmetric() {

}

void leftView() {

}

void rightView() {

}

void topView() {

}

int maxPathSum() {

}

int main() {
    Node* root = NULL;
    root=insertNode(root, 5);
    root=insertNode(root, 3);
    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    root=insertNode(root, 4);
    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->left->right->data<<endl;
    cout<<root->left->left->data<<endl;
    
    return 0;
}
