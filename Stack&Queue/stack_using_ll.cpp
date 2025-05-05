#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

class List{
    public:
    node* head;
    node* tail;

    List(){
        head=tail=NULL;
    }
    void push_back(int x){
        node* new_node=new node(x);
        if(tail==NULL)
        head=tail=new_node;
        else{
            tail->next=new_node;
            tail=new_node;
        }
    }
    node* gethead(){
        return head;
    }
    void print(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL";
    }
};
int main(){
    List ll;
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        ll.push_back(x);
    }
    ll.print();
}
