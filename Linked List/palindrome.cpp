#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next;
};
int main() {
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();
    Node *fifth = new Node();
    
    head->data = 1;
    head->next = second;
    
    second->data = 2;
    second->next = third;

    third->data = 2;
    third->next = fourth;

    fourth->data = 2;
    fourth->next = fifth;

    fifth->data = 1;
    fifth->next = nullptr;
    
    Node *temp = head;
    
    vector<int> v;
    while (temp != nullptr) {
        v.push_back(temp->data);
        temp = temp->next;
    }

    bool r = true;
    for (int i = 0; i < v.size() / 2; i++) {
        if (v[i] != v[v.size() - i - 1]) {
            r = false;
            break;
        }
    }

    cout << (r ? "Palindrome" : "Not a Palindrome") << endl;
    return 0;
}
