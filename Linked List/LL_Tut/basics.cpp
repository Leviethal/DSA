#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int val){
        data=val;
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
        //firstly create a new node
        Node *new_node=new Node(val);
        //check for default conditon
        if(head==NULL){
            head=tail=new_node;
        }
        //here we first connect the head to the new node
        //and then we make that new new node the new head
        else{
            new_node->next = head;
            head=new_node;
        }
     }
//Add a node to the end of the list
     void push_back(int val){
        //firstly create a new node
        Node *new_node=new Node(val);
        //check for default conditon
        if(tail==NULL){
            head=tail=new_node;
        }
        //here we first connect the new node to the tail
        //and then we make that new new node the new tail
        else{
            tail->next=new_node;
            tail=new_node;
        }
     }
     //Print a node
     void printLL(){
            Node *temp=head;
            while(temp!=NULL){
                cout<<temp->data<<" -> ";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
     }
     //Delete a node from the start of the list
     void pop_front(){
            if(head==NULL){
                cout<<"List is empty"<<endl;
            }
            else{
                Node *temp=head;
                head=head->next;
                delete temp;
            }
     }
     //Delete a node from the end of the list
     void pop_back(){
            if(head==NULL){
                cout<<"List is empty"<<endl;
            }
            else{
                Node *temp=head;
                while(temp->next!=tail){
                    temp=temp->next;
                }
                delete tail;
                tail=temp;
                tail->next=NULL;
            }
     }
        //Delete a node with a specific value
     void pop(int val){
            if(head==NULL){
                cout<<"List is empty"<<endl;
            }
            else{
                Node *temp=head;
                Node *prev=NULL;
                while(temp!=NULL && temp->data!=val){
                    prev=temp;
                    temp=temp->next;
                }
                if(temp==NULL){
                    cout<<"Element not found"<<endl;
                }
                else if(temp==head){
                    head=head->next;
                    delete temp;
                }
                else if(temp==tail){
                    tail=prev;
                    tail->next=NULL;
                    delete temp;
                }
                else{
                    prev->next=temp->next;
                    delete temp;
                }
            }
     }
//Insert a node at a specific position
     void insert(int val,int pos){
        Node *new_node=new Node(val);
        if(pos==0){
            new_node->next=head;
            head=new_node;
        }
        else{
            Node *temp=head;
            for(int i=0;i<pos-1 && temp!=NULL;i++){
                temp=temp->next;
            }
            if(temp!=NULL){
                new_node->next=temp->next;
                temp->next=new_node;
            }
            else{
                cout<<"Invalid position"<<endl;
            }
        }
     }
     //Search for a node with a specific value
     int search(int key){
        Node *temp=head;
        int pos=0;
        while(temp!=NULL && temp->data!=key){
            pos++;
            temp=temp->next;
        }
        if(temp!=NULL){
            return pos;
        }
        else{
            return -1;
        }
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