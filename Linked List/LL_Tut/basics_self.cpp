//make a linked and implement the following functions:
//1. push_front(int val) - add a node at the start of the list
//2. push_back(int val) - add a node at the end of the list
//3. pop_front() - delete a node from the start of the list
//4. pop_back() - delete a node from the end of the list
//5. insert(int val, int pos) - add a node with value val at the position pos
//6. pop(int val) - delete a node with value val
//7. search(int key) - search for a node with a specific value
//8. printLL() - print the linked list

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int value){
        data=value;
        next=NULL;
    }
};

class List{
    Node *head;
    Node *tail;

    public:
    List(){
        head=tail=NULL;
    }
    // Add a node to the start of the list
    void push_front(int val){
        Node* new_node=new Node(val);
        if(head==NULL)
        head=tail=new_node;
        else{
            new_node->next=head;
            head=new_node;
        }
    }
    //Add a node to the end of the list
    void push_back(int val){
        Node* new_node=new Node(val);
        if(tail==NULL)
        head=tail=new_node;
        else{
            tail->next=new_node;
            tail=new_node;
        }
    }
    // Delete a node from the start of the list
    void pop_front(){
        if(head==NULL)
        cout<<"List is empty"<<endl;
        else{
            Node* temp=head;
            head=head->next;
            delete temp;
        }
    }
    //Delete a node from the end of the list
    void pop_back(){
        if(head==NULL)
        cout<<"List is empty"<<endl;
        else{
            Node* temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            delete tail;
            tail=temp;
            temp->next=NULL;
        }
    }
    void insert(int val,int pos){
        Node* new_node=new Node(val);
        if(pos==0){
            new_node->next=head;
            head=new_node;
        }
        else{
            Node* temp=head;
            for(int i=0;i<pos-1 && temp!=NULL;i++){
                temp=temp->next;
            }
            if(temp!=NULL){
                new_node->next=temp->next;
                temp->next=new_node;
            }
            else{
                cout<<"Position not found"<<endl;
            }
        }
    }
    void pop(int val){
        if(head==NULL)
        cout<<"List is empty"<<endl;
        else{
            Node* temp=head;
            Node* prev=NULL;
            while(temp!=NULL && temp->data!=val){
                prev=temp;
                temp=temp->next;
            }
            if(temp==NULL){
                cout<<"Value not found"<<endl;
            }
            else if(temp==head){
                head=head->next;
                delete temp;
            }
            else if(temp==tail){
                prev->next=NULL;
                delete temp;
                tail=prev;
            }
            else{
                prev->next=temp->next;
                delete temp;
            }
        }
    }
    int search(int key){
        Node* temp=head;
        int i=0;
        while(temp!=NULL){
            if(temp->data==key)
            return i;
            else{
                i++;
                temp=temp->next;
            } 
        }
            cout<<"Value not found"<<endl;
            return -1;
    }
    void printLL(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main(){
    List ll;
    // Here a node is created for both head and tail in which both correspond to a null node
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ll.push_back(x);
    }
    ll.printLL();
    ll.push_back(0);
    ll.push_front(0);
    ll.printLL();
    ll.pop_front();
    ll.printLL();
    ll.pop_back();
    ll.printLL();
    ll.pop(3);
    ll.printLL();
    ll.insert(10, 3);
    ll.printLL();
    cout<<ll.search(10);
    return 0;
}