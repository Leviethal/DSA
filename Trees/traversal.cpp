#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=right=NULL;
    }
};
void inOrderFPS(node* new_node){ //Left, Root, right
    if(new_node==NULL)
        return;
    inOrderFPS(new_node->left);
    cout<<new_node->data<<" ";
    inOrderFPS(new_node->right);
}
void preOrderFPS(node* new_node){ //Root, Left, Right   
    if(new_node==NULL)
        return;
    cout<<new_node->data<<" ";
    preOrderFPS(new_node->left);
    preOrderFPS(new_node->right);
}
void postOrderFPS(node* new_node){ //Left, Right, Root
    if(new_node==NULL)
        return;
    postOrderFPS(new_node->left);
    postOrderFPS(new_node->right);
    cout<<new_node->data<<" ";
}
void BFS(node* root){
    if(root==NULL)
        return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}

int main() {
    node* root = new node(2);
    root->left = new node(3);
    root->right = new node(4);
    root->left->left = new node(5);

    cout << "In-order DFS: ";
    inOrderFPS(root);

    cout << "\nPre-order DFS: ";
    preOrderFPS(root);
   
    cout << "\nPost-order DFS: ";
    postOrderFPS(root);
  
    cout << "\nLevel order: ";
    BFS(root);

    return 0;
}