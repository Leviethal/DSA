#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int value){
        Node* head;
        Node* tail;

        data=value;
        next=NULL;
        prev=NULL;
    }
};
class List{
    Node* head;
    Node* tail;

    public:
    List(){
        head=tail=NULL;
    }
    void push_back(int val){
        Node* new_node=new Node(val);
        if(head==NULL){
            head=tail=new Node(val);
        }
        else{
            tail->next=new_node;
            tail=new_node;
        }
    }
    Node* gethead(){
        return head;
    }
    void printll(){
        while(head!=NULL){
        cout<< head->data<<" <-> ";
        head=head->next;
        }
        cout<<"NULL";
    }
    
};
int main(){
    int n;
    List dll;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        dll.push_back(x);
    }
    dll.printll();
}