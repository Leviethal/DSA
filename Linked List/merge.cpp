#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};
class List{
    Node *head;
    Node* tail;

    public:
    List(){
        head=tail=NULL;
    }
    void push_back(int val){
        Node* new_node=new Node(val);
        if(head==NULL)
        head=tail=new_node;
        else{
            tail->next=new_node;
            tail=new_node;
        }
    }

    Node* gethead(){
    return head;
    }
};
int main(){
    int n1,n2;
    cin>>n1;
    List l1,l2,l3;
    for(int i=0;i<n1;i++){
        int x;
        cin>>x;
        l1.push_back(x);
    }
    cin>>n2;
    for(int i=0;i<n2;i++){
        int x;
        cin>>x;
        l2.push_back(x);
    }
    Node* temp1=l1.gethead();
    Node* temp2=l2.gethead();
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data < temp2->data){
            l3.push_back(temp1->data);
            temp1=temp1->next;
        }
        else{
            l3.push_back(temp2->data);
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL){
        l3.push_back(temp1->data);
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        l3.push_back(temp2->data);
        temp2=temp2->next;
    }
    Node* temp3=l3.gethead();
    while (temp3!=NULL)
    {
        cout<<temp3->data<<" -> ";
        temp3=temp3->next;
    }
    cout<<"NULL"<<endl;
}
