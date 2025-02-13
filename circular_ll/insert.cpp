#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;

    public:
    List(){
        head = tail = NULL;
    }

    Node* gethead(){
        return head;
    }

    void insert(int val, int pos){
        Node* new_node = new Node(val);
        if(pos == 0){
            if(head == NULL){
                head = tail = new_node;
                tail->next = head;
            } else {
                new_node->next = head;
                head = new_node;
                tail->next = head;
            }
        } else {
            Node* temp = head;
            for(int i = 0; i < pos - 1 && temp->next != head; i++){
                temp = temp->next;
            }
            if(temp->next == head){
                new_node->next = head;
                temp->next = new_node;
                tail = new_node;
            } else {
                new_node->next = temp->next;
                temp->next = new_node;
            }
        }
    }

    void push_back(int val){
        Node* new_node = new Node(val);
        if(tail == NULL){
            head = tail = new_node;
            tail->next = head;
        } else {
            tail->next = new_node;
            tail = new_node;
            tail->next = head;
        }
    }

    void print(){
        if(head == NULL) return;
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while(temp != head);
        cout << "NULL" << endl;
    }
};

int main(){
    int n;
    cin >> n;
    List cll;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cll.push_back(x);
    }
    cll.print();
    return 0;
}
