#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
int main(){
    Node* firstnode=new Node(1);
    Node* secondnode=new Node(2);
    Node* thirdnode=new Node(3);
    Node* fourthnode=new Node(4);
    Node* fifthnode=new Node(5);
    Node* sixthnode=new Node(6);

    firstnode->left=secondnode;
    firstnode->right=thirdnode;
    secondnode->left=fourthnode;
    secondnode->right=fifthnode;
    thirdnode->right=sixthnode;
}